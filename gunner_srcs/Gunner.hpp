/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ITester.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guhernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 19:38:05 by guhernan          #+#    #+#             */
/*   Updated: 2022/02/11 00:09:10 by guhernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUNNER_HPP
# define GUNNER_HPP

#include <string>
#include <memory>
#include <chrono>
#include <fstream>
#include <map>
#include <iostream>

#include <stdexcept>

#include "AUnitTest.hpp"
#include "Gun.hpp"


namespace ft {

	class	Gunner {

		public:
			typedef		std::size_t											size_type;
			typedef		typename std::ofstream	*							file_type;
			typedef		std::string											file_name_type;
			typedef		std::string											name_type;

			typedef		ABullet::bullet_type								bullet_type;
			typedef		ft::Gun												gun_type;
			typedef		gun_type::cylinder_iterator							cylinder_iterator;

			typedef		ABullet::enlapsed_type								enlapsed_type;

			typedef		std::map<file_name_type, gun_type>					equipement_type;
			typedef		equipement_type::iterator							iterator;
			typedef		equipement_type::const_iterator						const_iterator;
			typedef		equipement_type::reference							reference;

			////////////////////////////////////////////////////////////////////////////////////////////////

		private:
			Gunner();
			file_name_type			_nickname;

		protected:
			equipement_type			_equipement;

		public:
			Gunner	operator=(const Gunner &source);
			virtual ~Gunner();

			Gunner(const name_type &name);
			Gunner(const Gunner &source);
			name_type				get_nickname();
			equipement_type			&get_equipement();

			iterator				begin();
			iterator				end();
			const_iterator			begin() const;
			const_iterator			end() const;

			enlapsed_type			fire_all();
			enlapsed_type			fire(Gun &weapon);
			enlapsed_type			fire(iterator first, iterator last);
			enlapsed_type			fire_bullet(gun_type &weapon, const name_type &bullet_name);
			enlapsed_type			fire_bullet(gun_type &weapon, cylinder_iterator begin, cylinder_iterator last);

			// Each function return 0 if the velocity is not set in all Guns.
			// If one or more Gun has fired, the return value should be != 0.
			// The Gun class is working the same way with his bullets.
			enlapsed_type			get_velocity_average() const;
			enlapsed_type			get_velocity_worst() const;
			enlapsed_type			get_velocity_best() const;

			///////////////////////////////////////////////////////////////////////////////////////////////////

	};
}

#endif
