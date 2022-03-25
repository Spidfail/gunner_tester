/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VectorConstructorTests.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guhernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 22:02:42 by guhernan          #+#    #+#             */
/*   Updated: 2022/02/09 19:58:15 by guhernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORCONSTRUCTORTESTS_HPP ////////////////////////////////////////////////////////////////// IFNDEF
# define VECTORCONSTRUCTORTESTS_HPP

# include <iostream>
# include "../../gunner_srcs/NEWGunner.hpp"
# include "../../../vector/Vector.hpp"

namespace ft {

		template <class Ct, typename T>
		struct UnitestConstructor {

			typedef	typename	Ct::size_type						size_type;
			typedef				T									type_value;
			typedef typename 	Gunner<type_value>::file_reference	stream_type;

				static void				vector_fill(stream_type &os, type_value random_value) {
					{
						Ct	vecfill(20, random_value);
						os << vecfill.size() << std::endl;
					} {
						Ct	vecfill(0, random_value);
						os << vecfill.size() << std::endl;
					} {
						try {
							Ct	vec;
							Ct	vecfill(vec.max_size() + 1, random_value);
							os << vecfill.size() << std::endl;
						} catch (std::exception &e) { os << e.what() << std::endl; }
					} {
						try {
							Ct	vec;
							Ct	vecfill(-1, random_value);
							os << vecfill.size() << std::endl;
						} catch (std::exception &e) { os << e.what() << std::endl; }
					}
				}

				static void				vector_range(stream_type &os, type_value random_value) {
					{
						Ct	vectill(20, random_value);
						Ct	vecrange(vectill.begin(), vectill.end());
						for (size_type i = 0 ; i < vectill.size() ; i++) { os << vecrange[i] << " "; }
						os << std::endl;
					} {
						Ct	vecfill(20, random_value);
						Ct	vecrange(vecfill.begin(), vecfill.begin());
						os << vecrange.size() << std::endl;
					} {
						Ct	vecfill(20, random_value);
						Ct	vecrange(vecfill.begin(), vecfill.begin() + 1);
						for (size_type i = 0 ; i < vecrange.size() ; i++) { os << vecrange[i] << " "; }
						os << vecfill.size() << std::endl;
					} {
						Ct	vecfill(20, random_value);
						Ct	vecrange(vecfill.rbegin(), vecfill.rend());
						for (size_type i = 0 ; i < vecfill.size() ; i++) { os << vecrange[i] << " "; }
						os << std::endl;
					} {
						Ct	vecfill(20, random_value);
						Ct	vecrange(vecfill.rbegin(), vecfill.rbegin() + 1);
						for (size_type i = 0 ; i < vecrange.size() ; i++) { os << vecrange[i] << " "; }
						os << vecfill.size() << std::endl;
					} 
				}

				static void				operator_assignation(stream_type &os, type_value random_value) {
					{
						Ct	vecfill(20, random_value);
						Ct	vec;
						vec = vecfill;
						for (size_type i = 0 ; i < vecfill.size() ; i++) { os << vec[i] << " "; }
						os << vecfill.size() << std::endl;
					} {
						Ct	vecfill(20, random_value);
						Ct	vec;
						vecfill = vec;
						for (size_type i = 0 ; i < vecfill.size() ; i++) { os << vecfill[i] << " "; }
						os << vecfill.size() << std::endl;
					}
				}

				static void				operator_comparison(stream_type &os, type_value random_value, type_value replacement) {
					(void)replacement;
					os << "------------------------------------------------------" << std::endl;
					os << " Values : random = " << random_value << ", replacement = " << replacement << std::endl;
					os << "	OPERATOR == : " << std::endl;
					{
						Ct vecfill(20, random_value);
						Ct vecfill2(10, random_value);
						Ct vecfill3(30, random_value);
  						os << bool(vecfill == vecfill2) << " " << bool(vecfill2 == vecfill) << " ";
						os << bool(vecfill == vecfill3) << " " << bool(vecfill3 == vecfill) << " ";
						os << bool(vecfill2 == vecfill3) << " " << bool(vecfill2 == vecfill3) << " ";
						os << std::endl;
					} {
						Ct vecfill(20, replacement);
						Ct vecfill2(10, replacement);
						Ct vecfill3(30, replacement);
  						os << bool(vecfill == vecfill2) << " " << bool(vecfill2 == vecfill) << " ";
						os << bool(vecfill == vecfill3) << " " << bool(vecfill3 == vecfill) << " ";
						os << bool(vecfill2 == vecfill3) << " " << bool(vecfill2 == vecfill3) << " ";
						os << std::endl;
					} {
						Ct rvecfill(20, replacement);
						Ct vecfill(20, random_value);
						Ct rvecfill2(10, replacement);
						Ct vecfill2(10, random_value);
						Ct rvecfill3(30, replacement);
						Ct vecfill3(30, random_value);
  						os << bool(vecfill == vecfill2) << " " << bool(vecfill2 == vecfill) << " ";
						os << bool(vecfill2 == rvecfill2) << " " << bool(vecfill2 == rvecfill2) << " ";
						os << bool(vecfill3 == rvecfill3) << " " << bool(vecfill3 == rvecfill3) << " ";
						os << bool(vecfill == vecfill3) << " " << bool(vecfill3 == vecfill) << " ";
						os << bool(vecfill2 == vecfill3) << " " << bool(vecfill2 == vecfill3) << " ";
						os << std::endl;
					} {
						Ct vecfill(20, random_value);
						Ct cp_vec(vecfill);
						os << bool(vecfill == cp_vec) << " " << bool(cp_vec == vecfill) << " ";
						os << std::endl;
					}

					os << "	OPERATOR != : " << std::endl;
					{
						Ct vecfill(20, random_value);
						Ct vecfill2(10, random_value);
						Ct vecfill3(30, random_value);
  						os << bool(vecfill != vecfill2) << " " << bool(vecfill2 != vecfill) << " ";
						os << bool(vecfill != vecfill3) << " " << bool(vecfill3 != vecfill) << " ";
						os << bool(vecfill2 != vecfill3) << " " << bool(vecfill2 != vecfill3) << " ";
						os << std::endl;
					} {
						Ct vecfill(20, replacement);
						Ct vecfill2(10, replacement);
						Ct vecfill3(30, replacement);
  						os << bool(vecfill != vecfill2) << " " << bool(vecfill2 != vecfill) << " ";
						os << bool(vecfill != vecfill3) << " " << bool(vecfill3 != vecfill) << " ";
						os << bool(vecfill2 != vecfill3) << " " << bool(vecfill2 != vecfill3) << " ";
						os << std::endl;
					} {
						Ct rvecfill(20, replacement);
						Ct vecfill(20, random_value);
						Ct rvecfill2(10, replacement);
						Ct vecfill2(10, random_value);
						Ct rvecfill3(30, replacement);
						Ct vecfill3(30, random_value);
  						os << bool(vecfill != vecfill2) << " " << bool(vecfill2 != vecfill) << " ";
						os << bool(vecfill2 != rvecfill2) << " " << bool(vecfill2 != rvecfill2) << " ";
						os << bool(vecfill3 != rvecfill3) << " " << bool(vecfill3 != rvecfill3) << " ";
						os << bool(vecfill != vecfill3) << " " << bool(vecfill3 != vecfill) << " ";
						os << bool(vecfill2 != vecfill3) << " " << bool(vecfill2 != vecfill3) << " ";
						os << std::endl;
					} {
						Ct vecfill(20, random_value);
						Ct cp_vec(vecfill);
						os << bool(vecfill != cp_vec) << " " << bool(cp_vec != vecfill) << " ";
						os << std::endl;
					}

					os << "	OPERATOR > : " << std::endl;
					{
						Ct vecfill(20, random_value);
						Ct vecfill2(10, random_value);
						Ct vecfill3(30, random_value);
  						os << bool(vecfill > vecfill2) << " " << bool(vecfill2 > vecfill) << " ";
						os << bool(vecfill > vecfill3) << " " << bool(vecfill3 > vecfill) << " ";
						os << bool(vecfill2 > vecfill3) << " " << bool(vecfill2 > vecfill3) << " ";
						os << std::endl;
					} {
						Ct vecfill(20, replacement);
						Ct vecfill2(10, replacement);
						Ct vecfill3(30, replacement);
  						os << bool(vecfill > vecfill2) << " " << bool(vecfill2 > vecfill) << " ";
						os << bool(vecfill > vecfill3) << " " << bool(vecfill3 > vecfill) << " ";
						os << bool(vecfill2 > vecfill3) << " " << bool(vecfill2 > vecfill3) << " ";
						os << std::endl;
					} {
						Ct rvecfill(20, replacement);
						Ct vecfill(20, random_value);
						Ct rvecfill2(10, replacement);
						Ct vecfill2(10, random_value);
						Ct rvecfill3(30, replacement);
						Ct vecfill3(30, random_value);
  						os << bool(vecfill > vecfill2) << " " << bool(vecfill2 > vecfill) << " ";
						os << bool(vecfill2 > rvecfill2) << " " << bool(vecfill2 > rvecfill2) << " ";
						os << bool(vecfill3 > rvecfill3) << " " << bool(vecfill3 > rvecfill3) << " ";
						os << bool(vecfill > vecfill3) << " " << bool(vecfill3 > vecfill) << " ";
						os << bool(vecfill2 > vecfill3) << " " << bool(vecfill2 > vecfill3) << " ";
						os << std::endl;
					} {
						Ct vecfill(20, random_value);
						Ct cp_vec(vecfill);
						os << bool(vecfill > cp_vec) << " " << bool(cp_vec > vecfill) << " ";
						os << std::endl;
					}

					os << "	OPERATOR < : " << std::endl;
					{
						Ct vecfill(20, random_value);
						Ct vecfill2(10, random_value);
						Ct vecfill3(30, random_value);
  						os << bool(vecfill < vecfill2) << " " << bool(vecfill2 < vecfill) << " ";
						os << bool(vecfill < vecfill3) << " " << bool(vecfill3 < vecfill) << " ";
						os << bool(vecfill2 < vecfill3) << " " << bool(vecfill2 < vecfill3) << " ";
						os << std::endl;
					} {
						Ct vecfill(20, replacement);
						Ct vecfill2(10, replacement);
						Ct vecfill3(30, replacement);
  						os << bool(vecfill < vecfill2) << " " << bool(vecfill2 < vecfill) << " ";
						os << bool(vecfill < vecfill3) << " " << bool(vecfill3 < vecfill) << " ";
						os << bool(vecfill2 < vecfill3) << " " << bool(vecfill2 < vecfill3) << " ";
						os << std::endl;
					} {
						Ct rvecfill(20, replacement);
						Ct vecfill(20, random_value);
						Ct rvecfill2(10, replacement);
						Ct vecfill2(10, random_value);
						Ct rvecfill3(30, replacement);
						Ct vecfill3(30, random_value);
  						os << bool(vecfill < vecfill2) << " " << bool(vecfill2 < vecfill) << " ";
						os << bool(vecfill2 < rvecfill2) << " " << bool(vecfill2 < rvecfill2) << " ";
						os << bool(vecfill3 < rvecfill3) << " " << bool(vecfill3 < rvecfill3) << " ";
						os << bool(vecfill < vecfill3) << " " << bool(vecfill3 < vecfill) << " ";
						os << bool(vecfill2 < vecfill3) << " " << bool(vecfill2 < vecfill3) << " ";
						os << std::endl;
					} {
						Ct vecfill(20, random_value);
						Ct cp_vec(vecfill);
						os << bool(vecfill < cp_vec) << " " << bool(cp_vec < vecfill) << " ";
						os << std::endl;
					}

					os << "	OPERATOR >= : " << std::endl;
					{
						Ct vecfill(20, random_value);
						Ct vecfill2(10, random_value);
						Ct vecfill3(30, random_value);
  						os << bool(vecfill >= vecfill2) << " " << bool(vecfill2 >= vecfill) << " ";
						os << bool(vecfill >= vecfill3) << " " << bool(vecfill3 >= vecfill) << " ";
						os << bool(vecfill2 >= vecfill3) << " " << bool(vecfill2 >= vecfill3) << " ";
						os << std::endl;
					} {
						Ct vecfill(20, replacement);
						Ct vecfill2(10, replacement);
						Ct vecfill3(30, replacement);
  						os << bool(vecfill >= vecfill2) << " " << bool(vecfill2 >= vecfill) << " ";
						os << bool(vecfill >= vecfill3) << " " << bool(vecfill3 >= vecfill) << " ";
						os << bool(vecfill2 >= vecfill3) << " " << bool(vecfill2 >= vecfill3) << " ";
						os << std::endl;
					} {
						Ct rvecfill(20, replacement);
						Ct vecfill(20, random_value);
						Ct rvecfill2(10, replacement);
						Ct vecfill2(10, random_value);
						Ct rvecfill3(30, replacement);
						Ct vecfill3(30, random_value);
  						os << bool(vecfill >= vecfill2) << " " << bool(vecfill2 >= vecfill) << " ";
						os << bool(vecfill2 >= rvecfill2) << " " << bool(vecfill2 >= rvecfill2) << " ";
						os << bool(vecfill3 >= rvecfill3) << " " << bool(vecfill3 >= rvecfill3) << " ";
						os << bool(vecfill >= vecfill3) << " " << bool(vecfill3 >= vecfill) << " ";
						os << bool(vecfill2 >= vecfill3) << " " << bool(vecfill2 >= vecfill3) << " ";
						os << std::endl;
					} {
						Ct vecfill(20, random_value);
						Ct cp_vec(vecfill);
						os << bool(vecfill >= cp_vec) << " " << bool(cp_vec >= vecfill) << " ";
						os << std::endl;
					}

					os << "	OPERATOR <= : " << std::endl;
					{
						Ct vecfill(20, random_value);
						Ct vecfill2(10, random_value);
						Ct vecfill3(30, random_value);
  						os << bool(vecfill <= vecfill2) << " " << bool(vecfill2 <= vecfill) << " ";
						os << bool(vecfill <= vecfill3) << " " << bool(vecfill3 <= vecfill) << " ";
						os << bool(vecfill2 <= vecfill3) << " " << bool(vecfill2 <= vecfill3) << " ";
						os << std::endl;
					} {
						Ct vecfill(20, replacement);
						Ct vecfill2(10, replacement);
						Ct vecfill3(30, replacement);
  						os << bool(vecfill <= vecfill2) << " " << bool(vecfill2 <= vecfill) << " ";
						os << bool(vecfill <= vecfill3) << " " << bool(vecfill3 <= vecfill) << " ";
						os << bool(vecfill2 <= vecfill3) << " " << bool(vecfill2 <= vecfill3) << " ";
						os << std::endl;
					} {
						Ct rvecfill(20, replacement);
						Ct vecfill(20, random_value);
						Ct rvecfill2(10, replacement);
						Ct vecfill2(10, random_value);
						Ct rvecfill3(30, replacement);
						Ct vecfill3(30, random_value);
  						os << bool(vecfill <= vecfill2) << " " << bool(vecfill2 <= vecfill) << " ";
						os << bool(vecfill2 <= rvecfill2) << " " << bool(vecfill2 <= rvecfill2) << " ";
						os << bool(vecfill3 <= rvecfill3) << " " << bool(vecfill3 <= rvecfill3) << " ";
						os << bool(vecfill <= vecfill3) << " " << bool(vecfill3 <= vecfill) << " ";
						os << bool(vecfill2 <= vecfill3) << " " << bool(vecfill2 <= vecfill3) << " ";
						os << std::endl;
					} {
						Ct vecfill(20, random_value);
						Ct cp_vec(vecfill);
						os << bool(vecfill <= cp_vec) << " " << bool(cp_vec <= vecfill) << " ";
						os << std::endl;
					}
				}
		};

	template <typename T>
		class BulletConstructor : public ABullet {
			private:
				const BulletConstructor	&operator=(const BulletConstructor &) { return *this; }
				BulletConstructor(const BulletConstructor &) { }
			public:
				typedef 	typename Gunner<T>::file_type  		file_type;
				typedef 	typename Gunner<T>::file_reference	file_reference;
				BulletConstructor() {
					min_diff_time = std::numeric_limits<T>::max();
					max_diff_time = std::numeric_limits<T>::min();
				}
				virtual ~BulletConstructor() { }

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
						UnitestConstructor<Ct, T>		instance_test;
						instance_test.vector_fill(os, random1);
						instance_test.vector_range(os, random1);
						instance_test.operator_assignation(os, random1);
						instance_test.operator_comparison(os, random1, random2);
					}
		};
}

#endif
