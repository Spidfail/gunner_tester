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
#include "PrintText.hpp"

#include "../tests/vector/VectorIteratorsTests.hpp"
#include "../tests/vector/VectorModifiersTests.hpp"
#include "../tests/vector/VectorAccessorsTests.hpp"
#include "../tests/vector/VectorConstructorTests.hpp"
#include "../tests/vector/VectorCapacityTests.hpp"

#include "../tests/map/MapEraseTests.hpp"
#include "../tests/map/MapInsertTest.hpp"
#include "../tests/map/MapCapacityTest.hpp"
#include "../tests/map/MapLookupTest.hpp"
#include "../tests/map/MapConstructorTests.hpp"

#include "../tests/stack/StackTests.hpp"

#include <stdlib.h>

int	main(int ac, char **av) {
	if (ac != 3) {
		std::cerr << "[ERROR] arguments required : [std result ouput directory] [ft result ouput directory]" << std::endl;
		return 1;
	}
	std::string		path_std(av[1]);
	std::string		path_ft(av[2]);
	print::PrintText<std::string>	big_titles(std::clog, print::RED, print::B_BLACK, print::UNDERLINE);
	print::PrintText<std::string>	title(std::clog, print::YELLOW, print::B_BLACK, print::BOLD);
	print::PrintText<std::string>	success(std::clog, print::GREEN, print::B_WHITE, print::BOLD);
	print::PrintText<std::string>	failure(std::clog, print::RED, print::B_WHITE, print::BOLD);

	std::clog << "		";
	big_titles("LAUNCHING SILVECTOR STALONE");
	std::clog << std::endl << std::endl;

	Gunner<int> 	silvector_stalone;
	if (path_ft.find_last_of("/") == path_ft.npos || path_ft.find_last_of("/") != path_ft.size() - 1)
		path_ft.append("/");
	if (path_std.find_last_of("/") == path_ft.npos || path_std.find_last_of("/") != path_std.size() - 1)
		path_std.append("/");
	silvector_stalone.add_bullet<ft::BulletConstructor<int> > (path_std + "vector_constructor", path_ft + "vector_constructor");
	silvector_stalone.add_bullet<ft::BulletAccessors<int> > (path_std + "vector_accessors", path_ft + "vector_accessors");
	silvector_stalone.add_bullet<ft::BulletCapacity<int> > (path_std + "vector_capacity", path_ft + "vector_capacity");
	silvector_stalone.add_bullet<ft::BulletModifiers<int> > (path_std + "vector_modifiers", path_ft + "vector_modifiers");
	silvector_stalone.add_bullet<ft::BulletIterators<int> > (path_std + "vector_iterators", path_ft + "vector_iterators");

	std::clog << std::endl;
	title("============ LAUNCHING TESTS ============");
	std::clog << std::endl << std::endl;
	silvector_stalone.fire();

	std::clog << std::endl;
	title("============ LAUNCHING BENCHMARK ============");
	std::clog << std::endl << std::endl;
	silvector_stalone.fire_bench(1000);
	silvector_stalone.get_bench();


	std::clog << std::endl << "		";
	big_titles("LAUNCHING TERMAPITOR");
	std::clog << std::endl << std::endl;

	Gunner<int>		termapitor;
	termapitor.add_bullet<ft::BulletMapInsert<int, std::string> > (path_std + "map_insert", path_ft + "map_insert");
	termapitor.add_bullet<ft::BulletMapLookup<int, std::string> > (path_std + "map_lookup", path_ft + "map_lookup");
	termapitor.add_bullet<ft::BulletMapErase<int, std::string> > (path_std + "map_erase", path_ft + "map_erase");
	termapitor.add_bullet<ft::BulletMapCapacity<int, std::string> > (path_std + "map_capacity", path_ft + "map_capacity");
	termapitor.add_bullet<ft::BulletMapConstructor<int, std::string> > (path_std + "map_constructor", path_ft + "map_constructor");
	std::clog << std::endl;
	title("============ LAUNCHING TESTS ============");
	std::clog << std::endl << std::endl;
	termapitor.fire();
	std::clog << std::endl << std::endl;
	title("============ LAUNCHING BENCHMARK ============");
	std::clog << std::endl << std::endl;
	termapitor.fire_bench(1000);
	termapitor.get_bench();


	std::clog << std::endl << "		";
	big_titles("LAUNCHING LIL STACK, MY MAN");
	std::clog << std::endl << std::endl;

	Gunner<int>		lil_stack;
	lil_stack.add_bullet<ft::BulletStack<int> > (path_std + "stack", path_ft + "stack");
	std::clog << std::endl;
	title("============ LAUNCHING TESTS ============");
	std::clog << std::endl << std::endl;
	lil_stack.fire();
	std::clog << std::endl << std::endl;
	title("============ LAUNCHING BENCHMARK ============");
	std::clog << std::endl << std::endl;
	lil_stack.fire_bench(1000);
	lil_stack.get_bench();
}
