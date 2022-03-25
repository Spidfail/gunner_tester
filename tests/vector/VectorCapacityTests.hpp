/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VectorCapacityTests.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guhernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 22:12:50 by guhernan          #+#    #+#             */
/*   Updated: 2022/02/08 12:21:26 by guhernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORCAPACITYTESTS_HPP //////////////////////////////////////////////////////////IFNDEF
# define VECTORCAPACITYTESTS_HPP

# include <iostream>
# include "../../gunner_srcs/NEWGunner.hpp"
# include "../../../vector/Vector.hpp"


namespace ft {

		template <class Ct, typename T>
		struct UnitestCapacity {

			typedef	typename	Ct::size_type						size_type;
			typedef				T									type_value;
			typedef	typename	Gunner<type_value>::file_reference	stream_type;
	
				static void				empty(stream_type &os, type_value random_value) {
					{
						Ct	vec;
						os << vec.empty() << " ";
						vec.push_back(random_value);
						os << vec.empty() << " ";
					} {
						Ct	vecfill(20, random_value);
						os << vecfill.empty() << " ";
					}
				}

				static void				size(stream_type &os, type_value random_value) {
					{
						Ct	vec;
						os << vec.size() << " ";
					} {
						Ct	vecfill(20, random_value);
						os << vecfill.size() << " ";
					}
					os << std::endl;
				}

				static void				reserve(stream_type &os, type_value random_value) {
					(void) random_value;
					{
						Ct	vec;
						vec.reserve(100);
						os << vec.capacity() << " " ;
					} {
						Ct	vecfill(20, random_value);
						vecfill.reserve(100);
						os << vecfill.capacity() << " " ;
					} {
						Ct	vecfill(200, random_value);
						vecfill.reserve(100);
						os << vecfill.capacity() << " " ;
					} try {
						Ct	vecfill(20, random_value);
						vecfill.reserve(vecfill.max_size() + 1);
						os << vecfill.capacity() << " WRONG : AN EXCEPTION MUST BE THROWN " ;
					} catch (std::exception &e) {
						os << e.what() << " ";
					}
					os << std::endl;
				}

				static void				max_size(stream_type &os) {
					Ct	vec;
					os << vec.max_size() << " ";
					os << std::endl;
				}

				static void				capacity(stream_type &os, type_value random_value) {
					{
						Ct	vec;
						os << vec.capacity() << " ";
					} {
						Ct	vecfill(20, random_value);
						os << vecfill.capacity() << " ";
					}
				}
		};

	template <typename T>
		class BulletCapacity : public ABullet {
			private:
				const BulletCapacity	&operator=(const BulletCapacity &) { return *this; }
				BulletCapacity(const BulletCapacity &) { }
			public:
				typedef 	typename Gunner<T>::file_type  		file_type;
				typedef 	typename Gunner<T>::file_reference	file_reference;
				BulletCapacity() {
					min_diff_time = std::numeric_limits<T>::max();
					max_diff_time = std::numeric_limits<T>::min();
				}
				virtual ~BulletCapacity() { }

				virtual void	operator() (file_reference std_file, file_reference ft_file) {
					ft::Random<T>	random_generator;
					random_generator.init_random_collection(T());
					T random1 = random_generator.generate(T());
					test<std::vector<T> >(std_file, random1);
					test<ft::vector<T> >(ft_file, random1);
				}

				virtual void	operator() () {
					ft::Random<T>	random_generator;
					random_generator.init_random_collection(T());
					T random1 = random_generator.generate(T());

					time_point start_time_std = clock_type::now();
					test<std::vector<T> >(std::cout, random1);
					time_point end_time_std = clock_type::now();

					time_point start_time_ft = clock_type::now();
					test<ft::vector<T> >(std::cout, random1);
					time_point end_time_ft = clock_type::now();

					elapsed_type span_time = duration_type(end_time_ft - start_time_ft).count() / duration_type(end_time_std - start_time_std).count();
					total_time += duration_type(end_time_ft - start_time_ft).count();
					if (span_time < this->min_diff_time)
						this->min_diff_time = span_time;
					else if (span_time > this->max_diff_time)
						this->max_diff_time = span_time;
				}

				template <class Ct>
					void	test(file_reference os, T random1) {
						UnitestCapacity<Ct, T>		instance_test;
						instance_test.empty(os, random1);
						instance_test.size(os, random1);
						instance_test.reserve(os, random1);
						instance_test.max_size(os);
						instance_test.capacity(os, random1);
					}
		};

}

#endif //////////////////////////////////////////////////////////////////////////////////////////ENDIF
