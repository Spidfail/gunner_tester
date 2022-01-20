/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guhernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 19:21:21 by guhernan          #+#    #+#             */
/*   Updated: 2022/01/20 14:10:05 by guhernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstring>
#include <memory>
#include <algorithm>

#include "ft_vector.hpp"
#include "main.hpp"
#include "ITester.hpp"


int		main(int ac, char **av) {

	(void)av;
	(void)ac;

	ft::ITester	*test = new VectorTester<int>;
	test->init();
	test->get_status();
	test->unitest_accessors_all();

}
