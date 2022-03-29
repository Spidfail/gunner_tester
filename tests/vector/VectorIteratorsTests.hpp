/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VectorIteratorsTests.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guhernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 12:22:33 by guhernan          #+#    #+#             */
/*   Updated: 2022/02/08 12:23:57 by guhernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORITERATORSTESTS_HPP ///////////////////////////////////////////////////////////////// IFNDEF
# define VECTORITERATORSTESTS_HPP

#include <iostream>
#include <cstdio>
#include "../../gunner_srcs/NEWGunner.hpp"
#include "../../../vector/Vector.hpp"

namespace ft {

		template <class Ct, typename type_value>
		struct UnitestIterators {

			typedef typename Ct::size_type						size_type;
			typedef typename Gunner<type_value>::file_reference	stream_type;

			static void		constructors(stream_type &os, type_value random_value, type_value replacement) {
				{
					Ct	vecfill(10, random_value);
					typename Ct::iterator it;
					it = vecfill.begin();
					Ct	vecfill2(20, replacement);
					vecfill = vecfill2;
					typename Ct::iterator it2 = vecfill.begin();
					os << std::boolalpha << (it == it2) << " ";
				} {
					Ct	vecfill(10, random_value);
					Ct	vecfill2(20, replacement);
					typename Ct::reverse_iterator it = vecfill.rbegin();
					vecfill = vecfill2;
					typename Ct::reverse_iterator it2 = vecfill.rbegin();
					os << std::boolalpha << (it == it2) << " ";
				}
				os << std::endl;
			}

			static void		accessors(stream_type &os, type_value random_value, type_value replacement) {
				{
					Ct	vecfill(1, random_value);
					vecfill.push_back(replacement);
					typename Ct::iterator it = vecfill.begin();
					typename Ct::iterator it2 = it;
					os << *it << "|" << *it2;
				} {
					Ct	vecfill(10, random_value);
					typename Ct::iterator it = vecfill.begin();
					for (size_type i = 0 ; i < vecfill.size() ; i++){ os << it[i] << " "; }
					for (size_type i = 0 ; i < vecfill.size() ; i++){ os << (it[i] = replacement) << " "; }
				} {
					Ct	vecfill(1, random_value);
					vecfill.push_back(replacement);
					typename Ct::reverse_iterator it = vecfill.rbegin();
					typename Ct::reverse_iterator it2 = it;
					os << *it << "|" << *it2;
				} {
					Ct	vecfill(10, random_value);
					typename Ct::reverse_iterator it = vecfill.rbegin();
					for (size_type i = 0 ; i < vecfill.size() ; i++){ os << it[i] << " "; }
					for (size_type i = 0 ; i < vecfill.size() ; i++){ os << (it[i] = replacement) << " "; }
				}
				os << std::endl;
			}

			static void		increment_decrement(stream_type &os, type_value random_value, type_value replacement) {
				{
					Ct	vecfill(10, random_value);
					for (typename Ct::iterator it = vecfill.begin() ; it != vecfill.end() ; it++) {
						os << *it << " "; *it = replacement; }
					for (typename Ct::iterator it = vecfill.begin() ; it != vecfill.end() ; it++)
						os << *it << " ";
					os << std::endl;
				} {
					Ct	vecfill(10, random_value);
					for (typename Ct::iterator it = vecfill.begin() ; it != vecfill.end() ; ++it) {
						os << *it << " "; *it = replacement; }
					for (typename Ct::iterator it = vecfill.begin() ; it != vecfill.end() ; ++it)
						os << *it << " ";
					os << std::endl;
				} {
					os << " DECREMENT : org_random [" << random_value << "] - replacement [" << replacement << std::endl;;
					Ct	vecfill(10, random_value);
					for (typename Ct::iterator it = vecfill.end() - 1 ; it != vecfill.begin(); --it) {
						os << *it << " "; *it = replacement; }
					for (typename Ct::iterator it = vecfill.end() - 1 ; it != vecfill.begin(); --it)
						os << *it << " ";
					os << std::endl;
				} 
				////	Reverse test
				{
					Ct	vecfill(10, random_value);
					for (typename Ct::reverse_iterator it = vecfill.rbegin() ; it != vecfill.rend() ; it++) {
						os << *it << " "; *it = replacement; }
					for (typename Ct::reverse_iterator it = vecfill.rbegin() ; it != vecfill.rend() ; it++)
						os << *it << " ";
				} {
					Ct	vecfill(10, random_value);
					for (typename Ct::reverse_iterator it = vecfill.rbegin() ; it != vecfill.rend() ; ++it) {
						os << *it << " "; *it = replacement; }
					for (typename Ct::reverse_iterator it = vecfill.rbegin() ; it != vecfill.rend() ; ++it)
						os << *it << " ";
				} {
					Ct	vecfill(10, random_value);
					for (typename Ct::reverse_iterator it = vecfill.rend() - 1 ; it != vecfill.rbegin() ; it--) {
						os << *it << " "; *it = replacement; }
					for (typename Ct::reverse_iterator it = vecfill.rend() - 1 ; it != vecfill.rbegin() ; it--)
						os << *it << " ";
				} {
					Ct	vecfill(10, random_value);
					for (typename Ct::reverse_iterator it = vecfill.rend() - 1 ; it != vecfill.rbegin() ; --it) {
						os << *it << " "; *it = replacement; }
					for (typename Ct::reverse_iterator it = vecfill.rend() - 1 ; it != vecfill.rbegin() ; --it)
						os << *it << " ";
				}
				os << std::endl;
			}

			static void		comparison(stream_type &os, type_value random_value, type_value replacement) {
				{
					Ct	vecfill(10, random_value);
					for (typename Ct::iterator it = vecfill.begin(), it2 = it ; it != vecfill.end() && (it == it2) ; it++, it2++) {
						os << *it << " "; *it = replacement; os << (it == it2) << " "; }
					for (typename Ct::iterator it = vecfill.begin(), it2 = it + 1 ; it != vecfill.end() && it != it2 ; it++, it2++) {
						os << *it << " " << (it != it2) << " "; }
				} {
					Ct	vecfill(10, random_value);
					for (typename Ct::iterator it = vecfill.begin(), it2 = it ; it != vecfill.end() && (it == it2) ; it++, it2++) {
						os << *it << " "; *it = replacement; os << (it == it2) << " "; }
					for (typename Ct::const_iterator it = vecfill.begin(), it2 = it + 1 ; it != vecfill.end() && it != it2 ; it++, it2++) {
						os << *it << " " << (it != it2) << " "; }
				} {
					Ct	vecfill(10, random_value);
					for (typename Ct::iterator it = vecfill.begin() ; it < vecfill.end() ; it++)
						os << *it << " ";
				} {
					Ct	vecfill(10, random_value);
					for (typename Ct::reverse_iterator it = vecfill.rbegin() ; it < vecfill.rend() ; it++) {
						os << *it << " "; } }
				{
					Ct	vecfill(10, random_value);
					for (typename Ct::iterator it = vecfill.begin() ; it <= vecfill.end() - 1 ; it++)
						os << *it << " ";
				} {
					Ct	vecfill(10, random_value);
					for (typename Ct::reverse_iterator it = vecfill.rbegin() ; it <= vecfill.rend() - 1 ; it++) {
						os << *it << " "; }
				} {
					Ct	vecfill(10, random_value);
					for (typename Ct::iterator it = vecfill.end() - 1 ; it > vecfill.begin() ; it--)
						os << *it << " ";
				} {
					Ct	vecfill(10, random_value);
					for (typename Ct::reverse_iterator it = vecfill.rend() - 1 ; it > vecfill.rbegin() ; it--) {
						os << *it << " "; }
				} {
					Ct	vecfill(10, random_value);
					for (typename Ct::iterator it = vecfill.end() - 1 ; it >= vecfill.begin() ; it--)
						os << *it << " ";
				} {
					Ct	vecfill(10, random_value);
					for (typename Ct::reverse_iterator it = vecfill.rend() - 1 ; it >= vecfill.rbegin(); it--) {
						os << *it << " "; }
				}
				os << std::endl;
			}

			static void		arithmetic(stream_type &os, type_value random_value, type_value replacement) {
				{
					Ct	vecfill(20, random_value);
					typename Ct::iterator	it = vecfill.begin();
					for (size_type i = 0 ; (it + i) != vecfill.end() ; i++) {
						os << *(it + i) << " "; os << (*(it + i) = replacement); os << *(it + i) << " ";
						os << (it + i) - vecfill.begin() << " || " << typeid((it + i) - vecfill.begin()).name(); }
				} {
					Ct	vecfill(20, replacement);
					typename Ct::iterator	it = vecfill.begin();
					for (size_type i = vecfill.size() - 1 ; (i + it) >= vecfill.begin() ; i-- ) {
						os << *(i + it) << " "; os << (*(i + it) = random_value); os << *(i + it) << " "; 
						os << (it + i) - vecfill.begin() << " || " << typeid((it + i) - vecfill.begin()).name(); }
				} {
					Ct	vecfill(20, random_value);
					typename Ct::iterator	it = vecfill.end() - 1;
					for (size_type i = 0 ; i < vecfill.size() ; i++) {
						os << *(it - i) << " "; os << (*(it - i) = replacement); os << *(it - i) << " ";
						os << (it - i) - vecfill.begin() << " || " << typeid((it - i) - vecfill.begin()).name(); }
				} {
					Ct	vecfill(20, random_value);
					typename Ct::reverse_iterator	it = vecfill.rbegin();
					for (size_type i = 0 ; (it + i) != vecfill.rend() ; i++) {
						os << *(it + i) << " "; os << (*(it + i) = replacement); os << *(it + i) << " ";
						os << (it + i) - vecfill.rbegin() << " || " << typeid((it + i) - vecfill.rbegin()).name(); }
				} {
					Ct	vecfill(20, replacement);
					typename Ct::reverse_iterator	it = vecfill.rbegin();
					for (size_type i = vecfill.size() - 1 ; (i + it) >= vecfill.rbegin() ; i-- ) {
						os << *(i + it) << " "; os << (*(i + it) = random_value); os << *(i + it) << " "; 
						os << (it + i) - vecfill.rbegin() << " || " << typeid((it + i) - vecfill.rbegin()).name(); }
				} {
					Ct	vecfill(20, random_value);
					typename Ct::reverse_iterator	it = vecfill.rend() - 1;
					for (size_type i = 0 ; i < vecfill.size() ; i++) {
						os << *(it - i) << " "; os << (*(it - i) = replacement); os << *(it - i) << " ";
						os << (it - i) - vecfill.rbegin() << " || " << typeid((it - i) - vecfill.rbegin()).name(); }
				}
				os << std::endl;
			}

			static void		assignation(stream_type &os, type_value random_value, type_value replacement) {
				{
					Ct	vecfill(21, random_value);
					typename Ct::iterator	it = vecfill.begin();
					for (int i = 2, j = 0, result = 0 ; j < 5 ; j++, i++, result = *it + (*(it - 1) + *(it - 2))) {
						os << *(it += i) << " " ; *it = replacement ; os << *it << " i = " << i << " " << result ;}
				} {
					Ct	vecfill(21, random_value);
					typename Ct::iterator	it = vecfill.end() - 1;
					for (int i = 2, j = 0 ; j < 10 ; j++ ) {
						os << *(it -= i) << " " ; *it = replacement ; os << *it << " i = " << i << " "; }
				} {
					Ct	vecfill(21, random_value);
					typename Ct::reverse_iterator	it = vecfill.rbegin();
					for (int i = 2, j = 0, result = 0 ; j < 5 ; j++, i++, result = *it + (*(it - 1) + *(it - 2))) {
						os << *(it += i) << " " ; *it = replacement ; os << *it << " i = " << i << " " << result ;}
				} {
					Ct	vecfill(21, random_value);
					typename Ct::reverse_iterator	it = vecfill.rend() - 1;
					for (int i = 2, j = 0 ; j < 10 ; j++ ) {
						os << *(it -= i) << " " ; *it = replacement ; os << *it << " i = " << i << " "; }
				}
				os << std::endl;
			}

			static void		methods(stream_type &os, type_value random_value, type_value replacement) {
				{
					Ct	vec;
					vec.push_back(random_value);
					os << *vec.begin() << " ";
					for (int i = 0 ; i < 20 ; i++) {
						os << *vec.begin() << " ";
						vec.push_back(replacement);
						os << *(vec.begin() + i) << " ";
					}
				} {
					Ct vec;
					vec.push_back(random_value);
					os << *vec.begin() << " ";
					for (int i = 0 ; i < 20 ; i++) {
						vec.reserve(i);
						vec.insert(vec.begin() + i, replacement);
						os << *vec.begin() << " ";
						os << vec.end() - vec.begin() << " ";
						os << *vec.begin() + i << " ";
					}
				} {
					Ct vec;
					vec.push_back(random_value);
					os << *vec.begin() << " ";
					vec.reserve(10);
					for (int i = 0 ; i < 20 ; i++) {
						vec.insert(vec.begin() + i, replacement);
						os << *vec.begin() << " ";
						os << vec.end() - vec.begin() << " ";
						os << *vec.begin() + i << " ";
					}
				}
			}

			static void		cast_iterators(stream_type	&os, type_value random_value, type_value replacement) {
				typedef		typename Ct::iterator				iterator;
				typedef		typename Ct::const_iterator			const_iterator;
				typedef		typename Ct::reverse_iterator		reverse_iterator;
				typedef		typename Ct::const_reverse_iterator	const_reverse_iterator;
				{ // It tests : instanciation of const_iterator and comparison const/non_const
					Ct	vecfill(10, random_value);
					iterator			it_beg = vecfill.begin();
					iterator			it_end = vecfill.end();
					const_iterator		it_beg_const = vecfill.begin();
					const_iterator		it_end_const = vecfill.end();
					while (it_beg_const != it_end_const
							&& it_beg != it_end) {
						os << *it_beg_const << " ";
						++it_beg_const;
						++it_beg;
					}
					os << std::endl;
				} { // Tests : same as before but with reverse_iterator
					Ct	vecfill(10, random_value);
					reverse_iterator			it_beg = vecfill.rbegin();
					reverse_iterator			it_end = vecfill.rend();
					const_reverse_iterator		it_beg_const = vecfill.rbegin();
					const_reverse_iterator		it_end_const = vecfill.rend();
					while (it_beg_const != it_end_const
							&& it_beg != it_end) {
						os << *it_beg_const << " ";
						++it_beg_const;
						++it_beg;
					}
					os << std::endl;
				} { // Tests : operator=() from const_it to iterator + comparison const/non_const
					Ct	vecfill(10, random_value);
					Ct	vecfill_replace(10, replacement);
					iterator	it	= vecfill.begin();
					for (const_iterator it_const = vecfill.begin() ; it_const != vecfill.end() ; ++it_const) {
						os << *it << " ";
						*it = *it_const;
						os << *it << " ";
					}
				} { // Tests : same as before but with reverse_iterator
					Ct	vecfill(10, random_value);
					Ct	vecfill_replace(10, replacement);
					reverse_iterator	it	= vecfill.rbegin();
					for (const_reverse_iterator it_const = vecfill.rbegin() ; it_const != vecfill.rend() ; ++it_const) {
						os << *it << " ";
						*it = *it_const;
						os << *it << " ";
					}
				}
			}
		};

	template <typename T>
		class BulletIterators : public ABullet {
			private:
				const BulletIterators	&operator=(const BulletIterators &) { return *this; }
				BulletIterators(const BulletIterators &) { }
			public:
				typedef 	typename Gunner<T>::file_type  		file_type;
				typedef 	typename Gunner<T>::file_reference	file_reference;
				BulletIterators() {
					min_diff_time = std::numeric_limits<T>::max();
					max_diff_time = std::numeric_limits<T>::min();
				}
				virtual ~BulletIterators() { }

				virtual void	operator() (file_reference std_file, file_reference ft_file) {
					ft::Random<T>	random_generator;
					random_generator.init_random_collection(T());
					T random1 = random_generator.generate(T());
					T random2 = random_generator.generate(T()) / 2;
					test<std::vector<T> >(std_file, random1, random2);
					test<ft::vector<T> >(ft_file, random1, random2);
				}

				virtual void	operator() () {
					ft::Random<T>	random_generator;
					random_generator.init_random_collection(T());
					T random1 = random_generator.generate(T());
					T random2 = random_generator.generate(T());

					time_point start_time_std = clock_type::now();
					test<std::vector<T> >(std::cout, random1, random2);
					time_point end_time_std = clock_type::now();

					time_point start_time_ft = clock_type::now();
					test<ft::vector<T> >(std::cout, random1, random2);
					time_point end_time_ft = clock_type::now();

					elapsed_type span_time = duration_type(end_time_ft - start_time_ft).count() / duration_type(end_time_std - start_time_std).count();
					total_time += duration_type(end_time_ft - start_time_ft).count();
					if (span_time < this->min_diff_time)
						this->min_diff_time = span_time;
					else if (span_time > this->max_diff_time)
						this->max_diff_time = span_time;
				}

				template <class Ct>
					void	test(file_reference os, T random1, T random2) {
						UnitestIterators<Ct, T>		iterator_test;
						iterator_test.constructors(os, random1, random2);
						iterator_test.accessors(os, random1, random2);
						iterator_test.increment_decrement(os, random1, random2);
						iterator_test.comparison(os, random1, random2);
						iterator_test.arithmetic(os, random1, random2);
						iterator_test.assignation(os, random1, random2);
						iterator_test.methods(os, random1, random2);
						iterator_test.cast_iterators(os, random1, random2);
					}
		};

}

#endif ////////////////////////////////////////////////////////////////////////////////////////// ENDIF
