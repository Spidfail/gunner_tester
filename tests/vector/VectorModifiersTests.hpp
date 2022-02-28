/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VectorModifiersTests.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guhernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 12:16:25 by guhernan          #+#    #+#             */
/*   Updated: 2022/02/10 19:33:26 by guhernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORMODIFIERSTESTS_HPP ////////////////////////////////////////////////////////////////// IFNDEF
# define VECTORMODIFIERSTESTS_HPP

# include <iostream>
# include "../../gunner_srcs/NEWGunner.hpp"
# include "../../../vector/Vector.hpp"

namespace ft {

	template <class Ct, typename type_value>
		struct UnitestModifiers {

			typedef typename Ct::size_type						size_type;
			typedef typename Gunner<type_value>::file_reference	stream_type;

			static void					assign(stream_type &os, type_value random_value, type_value replacement) {
				os << "ASSIGN" << std::endl;
				{
					Ct	vec;
					vec.assign(20, random_value);
					for (size_type i = 0 ; i < vec.size() ; i++) { os << vec[i] << " "; }
					vec.assign(50, replacement);
					for (size_type i = 0 ; i < vec.size() ; i++) { os << vec[i] << " "; }
					vec.assign(10, random_value);
					for (size_type i = 0 ; i < vec.size() ; i++) { os << vec[i] << " "; }
					os << std::endl;
				} {
					Ct	vecfill(10, random_value);
					vecfill.assign(10, random_value);
					vecfill.assign(20, replacement);
					for (size_type i = 0 ; i < vecfill.size() ; i++) { os << vecfill[i] << " "; }
				} {
					Ct	vecfill(20, random_value);
					vecfill.assign(20, replacement);
					vecfill.assign(30, replacement);
					for (size_type i = 0 ; i < vecfill.size() ; i++) { os << vecfill[i] << " "; }
					os << std::endl;
				} { // range form
					Ct	vec;
					Ct	vecfill(20, random_value);
					for (size_type i = 2 ; i < vecfill.size() ; i++) {
						vec.assign(vecfill.begin(), vecfill.begin() + i);
						os << *(vecfill.begin() + i) << " "; }

					for (typename Ct::iterator it = vecfill.begin() ; it != vecfill.end(); it++) { os << *it << " "; }
					os << std::endl;
				} {
					Ct	vec;
					Ct	vecfill(20, replacement);
					for (size_type i = vecfill.size() - 1 ; i > 0 ; i--) {
						vec.assign(vecfill.begin(), vecfill.begin() + i);
						os << *(vecfill.begin() + i) << " "; }
					for (typename Ct::iterator it = vecfill.begin() ; it != vecfill.end(); it++) { os << *it << " "; }
					os << std::endl;
				} {
					Ct	vecfill(20, random_value);
					vecfill.assign(vecfill.begin(), vecfill.end());
					for (typename Ct::iterator it = vecfill.begin() ;
							it != vecfill.end(); it++)
						os << *it << " ";
				} {
					Ct	vecfill(20, random_value);
					vecfill.assign(vecfill.begin() + 5, vecfill.end() - 5);
					for (typename Ct::iterator it = vecfill.begin() ;
							it != vecfill.end(); it++)
						os << *it << " ";
				}
				os << std::endl;
			}

			static void					clear(stream_type &os, type_value random_value, type_value replacement) {
				os << "CLEAR" << std::endl;
				Ct	vecfill(10, random_value);
				os << vecfill.capacity() << " ";
				os << vecfill.size() << " ";
				vecfill.clear();
				os << vecfill.capacity() << " ";
				os << vecfill.size() << " ";
				(void)replacement;
				for (size_type i = 0 ; i < vecfill.capacity(); i++) {
					vecfill.push_back(replacement);
				}
				os << vecfill.capacity() << " ";
				os << vecfill.size() << " ";
				os << std::endl;
			}

			static void					insert(stream_type &os, type_value random_value, type_value replacement) {
				{
					os << "INSERT" << std::endl;
					Ct vecfill(10, random_value);
					vecfill.reserve(20);
					typename Ct::iterator	it_end = vecfill.end();
					for (typename Ct::iterator it = vecfill.begin() ; it != it_end ; it++) {
						typename Ct::iterator it_tmp = vecfill.insert(it, replacement);
						os << *it_tmp << " " << (vecfill.end() - it_tmp) << " "; }
					for (typename Ct::iterator it = vecfill.begin() ; it != vecfill.end() ; it++)
						os << *it << " ";
					os << std::endl;
				} {
					Ct vecfill(10, random_value);
					typename Ct::iterator	it_pos = vecfill.begin();
					vecfill.insert(it_pos, 10, replacement);
					for (typename Ct::iterator it = vecfill.begin() ; it != vecfill.end() ; it++)
						os << *it << " ";
					os << std::endl;
				} {
					Ct vecfill(10, random_value);
					typename Ct::iterator	it_pos = vecfill.begin() + 5;
					vecfill.insert(it_pos, 5, replacement);
					for (typename Ct::iterator it = vecfill.begin() ; it != vecfill.end() ; it++)
						os << *it << " ";
					os << std::endl;
				} {
					Ct vecfill(10, random_value);
					typename Ct::iterator	it_pos = vecfill.begin() + 10;
					vecfill.insert(it_pos, 10, replacement);
					for (typename Ct::iterator it = vecfill.begin() ; it != vecfill.end() ; it++)
						os << *it << " ";
					os << std::endl;
				} {
					Ct vecfill(10, random_value);
					typename Ct::iterator	it_pos = vecfill.begin() + 5;
					vecfill.insert(it_pos, 5, replacement);
					for (typename Ct::iterator it = vecfill.begin() ; it != vecfill.end() ; it++)
						os << *it << " ";
					os << std::endl;
				} {
					Ct vecfill(3, random_value);
					Ct rvecfill(3, replacement);
					typename Ct::iterator	fst_it = rvecfill.begin();
					typename Ct::iterator	end_it = rvecfill.begin();
					typename Ct::iterator	it_pos = vecfill.begin();
					for ( size_type i = vecfill.size(), j = 0 ; i && j < 4 ; --i, ++j ) {
						vecfill.insert(it_pos, fst_it, end_it + j);
						it_pos = vecfill.end() - i;
					}
					for (typename Ct::iterator it = vecfill.begin() ; it != vecfill.end() ; it++)
						os << *it << " ";
					os << std::endl;
				} {
					Ct vecfill(10, random_value);
					Ct rvecfill(10, replacement);
					typename Ct::iterator	fst_it = rvecfill.begin();
					typename Ct::iterator	end_it = rvecfill.end() - 5;
					typename Ct::iterator	it_pos = vecfill.begin() + 5;
					vecfill.insert(it_pos, fst_it, end_it);
					for (typename Ct::iterator it = vecfill.begin() ; it != vecfill.end() ; it++)
						os << *it << " ";
					os << std::endl;
				} {
					Ct vecfill(10, random_value);
					Ct rvecfill(10, replacement);
					typename Ct::iterator	fst_it = rvecfill.begin();
					typename Ct::iterator	end_it = rvecfill.end();
					typename Ct::iterator	it_pos = vecfill.end();
					vecfill.insert(it_pos, fst_it, end_it);
					for (typename Ct::iterator it = vecfill.begin() ; it != vecfill.end() ; it++)
						os << *it << " ";
					os << std::endl;
				} {
					Ct	vecfill(10, 50);
					vecfill.insert(vecfill.end(), vecfill.begin(), vecfill.end());
					for (typename Ct::iterator it = vecfill.begin() ; it != vecfill.end() ; it++)
						os << *it << std::endl;
				} {
					Ct	vecfill(10, 50);
					vecfill.insert(vecfill.begin() + 5, vecfill.begin(), vecfill.end());
					for (typename Ct::iterator it = vecfill.begin() ; it != vecfill.end() ; it++)
						os << *it << std::endl;
				} {
					Ct	vecfill(10, 50);
					vecfill.insert(vecfill.begin() + 5, vecfill.begin() + 2, vecfill.end() - 2);
					for (typename Ct::iterator it = vecfill.begin() ; it != vecfill.end() ; it++)
						os << *it << std::endl;
				} {
					Ct	vecfill(10, 50);
					vecfill.insert(vecfill.begin(), vecfill.begin(), vecfill.end());
					for (typename Ct::iterator it = vecfill.begin() ; it != vecfill.end() ; it++)
						os << *it << std::endl;
				}
				os << std::endl;
			}

			static void					push_back(stream_type &os, type_value random_value, type_value replacement) {
				size_type	max_size;
				{
					Ct	vec;
					max_size = vec.max_size();
					for (size_type i = 0 ; i < 20 ; i++) {
						if (i % 2 == 0)
							vec.push_back(random_value);
						else
							vec.push_back(replacement);
						os << vec[i] << "|" << vec.capacity() << "|" << vec.size() << " ";
					}
					vec.clear();
					for (size_type i = 0 ; i < 30 ; i++) {
						vec.push_back(replacement);
						os << vec.capacity() << "|" << vec.size() << " ";
					}
				}
				os << std::endl;
			}

			static void					pop_back(stream_type &os, type_value random_value, type_value replacement) {
				{
					Ct	vecfill(10, random_value);
					for ( ; vecfill.size() ; vecfill.pop_back() ) {
						os << vecfill.size() << " ";
						for (typename Ct::size_type i = 0 ; i < vecfill.size() ; i++) { os << vecfill[i] << " "; }
					}
					os << std::endl;
					for ( ; vecfill.size() < 20 ; vecfill.push_back(replacement) ) { os << vecfill.size() << " "; }
					for (typename Ct::size_type j = 0 ; j < vecfill.size() ; j++) { os << vecfill[j] << " "; }
					for ( ; vecfill.size() ; vecfill.pop_back() ) {
						os << vecfill.size() << " ";
						for (typename Ct::size_type i = 0 ; i < vecfill.size() ; i++) { os << vecfill[i] << " "; }
					}
				}
				os << std::endl;
			}

			static void					resize(stream_type &os, type_value random_value, type_value replacement) {
				{
					Ct	vecfill(10, random_value);
					vecfill.resize(10);
					for (size_type i = 0 ; i < vecfill.size() ; ++i)
						os << vecfill[i] << " ";
					vecfill.resize(20);
					os << vecfill.size() << " ";
					for (size_type i = 0 ; i < vecfill.size() ; ++i)
						os << vecfill[i] << " ";
					vecfill.resize(20);
					os << vecfill.size() << " ";
					for (size_type i = 0 ; i < vecfill.size() ; ++i)
						os << vecfill[i] << " ";
					vecfill.resize(30, replacement);
					os << vecfill.size() << " ";
					for (size_type i = 0 ; i < vecfill.size() ; ++i)
						os << vecfill[i] << " ";
					vecfill.resize(30);
					os << vecfill.size() << " ";
					for (size_type i = 0 ; i < vecfill.size() ; ++i)
						os << vecfill[i] << " ";
					vecfill.resize(20);
					os << vecfill.size() << " ";
					for (size_type i = 0 ; i < vecfill.size() ; ++i)
						os << vecfill[i] << " ";
					vecfill.resize(20);
					os << vecfill.size() << " ";
					for (size_type i = 0 ; i < vecfill.size() ; ++i)
						os << vecfill[i] << " ";
					vecfill.resize(0);
					os << vecfill.size() << " ";
					os << std::endl;
				}
			}

			static void					swap(stream_type &os, type_value random_value, type_value replacement) {
				{
					Ct vecfill(10, random_value);
					Ct vecfill_other(10, replacement);
					vecfill.swap(vecfill_other);
					for (typename Ct::iterator it = vecfill.begin() ; it != vecfill.end() ; ++it)
						os << *it << " ";
					std::swap(vecfill_other, vecfill);
					for (typename Ct::iterator it = vecfill.begin() ; it != vecfill.end() ; ++it)
						os << *it << " ";
				} {
					Ct vecfill(10, random_value);
					Ct vecfill_other(20, replacement);
					vecfill.swap(vecfill_other);
					for (typename Ct::iterator it = vecfill.begin() ; it != vecfill.end() ; ++it)
						os << *it << " ";
					std::swap(vecfill_other, vecfill);
					for (typename Ct::iterator it = vecfill.begin() ; it != vecfill.end() ; ++it)
						os << *it << " ";
				} {
					Ct vecfill(30, random_value);
					Ct vecfill_other(20, replacement);
					vecfill.swap(vecfill_other);
					for (typename Ct::iterator it = vecfill.begin() ; it != vecfill.end() ; ++it)
						os << *it << " ";
					std::swap(vecfill_other, vecfill);
					for (typename Ct::iterator it = vecfill.begin() ; it != vecfill.end() ; ++it)
						os << *it << " ";
				}
				os << std::endl;
			}

			static void					erase(stream_type &os, type_value random_value, type_value replacement) {
				os << " ERASE " << std::endl;
				{
					Ct	vecfill(20, random_value);
					int i = 0;
					while (i < 20) {
						vecfill.erase(vecfill.begin());
						os << vecfill.size() << " ";
						++i;
					}
					os << std::endl;
				} {
					Ct	vecfill(20, random_value);
					size_type	pos_array[3] = {0, 5, 17};
					for ( int i = 0 ; i < 3 ; ++i ) {
						vecfill.erase(vecfill.begin() + pos_array[i]);
						os << vecfill.size() << " ";
					}
					for ( size_type i = 0 ; i < vecfill.size() ; ++i )
						os << *(vecfill.begin() + i) << " ";
					os << std::endl;
				} {
					Ct	vecfill(20, random_value);
					int i = 0;
					while (i < 20) {
						vecfill.erase(vecfill.end() - 1);
						os << vecfill.size() << " ";
						++i;
					}
					os << std::endl;
				} {
					os << "random_value : " <<  random_value << " replacement : " << replacement << std::endl;
					Ct	vecfill(10, random_value);
					vecfill.insert(vecfill.end(), 10, replacement);
					for ( size_type i = 0 ; i < vecfill.size() ; ++i )
						os << *(vecfill.begin() + i) << " ";
					os << std::endl;
					vecfill.erase(vecfill.begin(), vecfill.begin() + 10);
					os << vecfill.size() << " ";
					for ( size_type i = 0 ; i < vecfill.size() ; ++i )
						os << *(vecfill.begin() + i) << " ";
					os << std::endl;
				} {
					os << "random_value : " <<  random_value << " replacement : " << replacement << std::endl;
					Ct	vecfill(10, random_value);
					vecfill.insert(vecfill.end(), 10, replacement);
					for ( size_type i = 0 ; i < vecfill.size() ; ++i )
						os << *(vecfill.begin() + i) << " ";
					os << std::endl;
					vecfill.erase(vecfill.begin() + 10, vecfill.end());
					os << vecfill.size() << " ";
					for ( size_type i = 0 ; i < vecfill.size() ; ++i )
						os << *(vecfill.begin() + i) << " ";
					os << std::endl;
				} {
					os << "random_value : " <<  random_value << " replacement : " << replacement << std::endl;
					Ct	vecfill(10, random_value);
					vecfill.insert(vecfill.end(), 10, replacement);
					for ( size_type i = 0 ; i < vecfill.size() ; ++i )
						os << *(vecfill.begin() + i) << " ";
					os << std::endl;
					vecfill.erase(vecfill.begin() + 5, vecfill.end() - 5);
					os << vecfill.size() << " ";
					for ( size_type i = 0 ; i < vecfill.size() ; ++i )
						os << *(vecfill.begin() + i) << " ";
					os << std::endl;
				}
			}
		};

	template <typename T>
		class BulletModifiers : public ABullet {
			private:
				const BulletModifiers	&operator=(const BulletModifiers &) { return *this; }
				BulletModifiers(const BulletModifiers &) { }
			public:
				typedef 	typename Gunner<T>::file_type  		file_type;
				typedef 	typename Gunner<T>::file_reference	file_reference;
				BulletModifiers() { }
				virtual ~BulletModifiers() { }

				virtual void	operator() (file_reference std_file, file_reference ft_file) {
					ft::Random<T>	random_generator;
					random_generator.init_random_collection(T());
					T random1 = random_generator.generate(T());
					T random2 = random_generator.generate(T()) / 2;
					test<std::vector<T>>(std_file, random1, random2);
					test<ft::vector<T>>(ft_file, random1, random2);
				}

				virtual void	operator() () {
					test<std::vector<T>>(std::cout, 0, 0);
					test<ft::vector<T>>(std::cout, 0, 0); 				// PUT FT
				}

				template <class Ct>
					void	test(file_reference os, T random1, T random2) {
						UnitestModifiers<Ct, T>		instance_test;
						instance_test.assign(os, random1, random2);
						instance_test.clear(os, random1, random2);
						instance_test.insert(os, random1, random2);
						instance_test.push_back(os, random1, random2);
						instance_test.pop_back(os, random1, random2);
						instance_test.resize(os, random1, random2);
						instance_test.swap(os, random1, random2);
						instance_test.erase(os, random1, random2);
					}
		};

}

#endif///////////////////////////////////////////////////////////////////////////////////////////////// ENDIF
