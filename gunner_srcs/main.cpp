/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guhernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 19:21:21 by guhernan          #+#    #+#             */
/*   Updated: 2022/02/09 22:14:55 by guhernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NEWGunner.hpp"
#include "../tests/vector/VectorIteratorsTests.hpp"
#include "../tests/vector/VectorModifiersTests.hpp"
#include "../tests/vector/VectorAccessorsTests.hpp"
#include "../tests/vector/VectorConstructorTests.hpp"
#include "../tests/vector/VectorCapacityTests.hpp"

int	main(int ac, char **av) {
	if (ac != 3) {
		std::cerr << "[ERROR] arguments required : [std result ouput directory] [ft result ouput directory]" << std::endl;
		return 1;
	}
	Gunner<int> 	silvector_stalone;
	std::string		path_std(av[1]);
	std::string		path_ft(av[2]);
	if (path_ft.find_last_of("/") == path_ft.npos || path_ft.find_last_of("/") != path_ft.size() - 1)
		path_ft.append("/");
	if (path_std.find_last_of("/") == path_ft.npos || path_std.find_last_of("/") != path_std.size() - 1)
		path_std.append("/");
	silvector_stalone.add_bullet<ft::BulletConstructor<int>> (path_std + "vector_constructor", path_ft + "vector_constructor");
	silvector_stalone.add_bullet<ft::BulletAccessors<int>> (path_std + "vector_accessors", path_ft + "vector_accessors");
	silvector_stalone.add_bullet<ft::BulletCapacity<int>> (path_std + "vector_capacity", path_ft + "vector_capacity");
	silvector_stalone.add_bullet<ft::BulletModifiers<int>> (path_std + "vector_modifiers", path_ft + "vector_modifiers");
	silvector_stalone.add_bullet<ft::BulletIterators<int>> (path_std + "vector_iterators", path_ft + "vector_iterators");
	silvector_stalone.fire_all();
}
