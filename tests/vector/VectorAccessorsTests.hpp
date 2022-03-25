/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VectorAccessorsTests.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guhernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 12:14:07 by guhernan          #+#    #+#             */
/*   Updated: 2022/02/08 12:20:11 by guhernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORACCESSORSTESTS_HPP ///////////////////////////////////////////////////////////IFNDEF
# define VECTORACCESSORSTESTS_HPP

# include <iostream>
# include "../../gunner_srcs/NEWGunner.hpp"
# include "../../../vector/Vector.hpp"


#include <iostream>

namespace ft {


		template <class Ct, typename type_value>

			struct UnitestAccessors {

			typedef typename Ct::size_type							size_type;
			typedef typename Gunner<type_value>::file_reference		stream_type;

				static void				operator_bracket(stream_type &os, type_value random_value) {
					for (int j = 0 ; j < 100 ; j++) {
						Ct	vecfill(j, random_value);
						for (int i = 0 ; i < j ; i++) {os << vecfill[i] << " ";}
					}
					for (int j = 0 ; j < 10 ; j++) {
						const Ct	vecfill(j, random_value);
						for (int i = 0 ; i < j ; i++) {os << vecfill[i] << " ";}
					}
					os << std::endl;
				}

				static void				at(stream_type &os, type_value random_value) {
					for (int j = 0 ; j < 100 ; j++) {
						Ct	vecfill(j, random_value);
						for (int i = 0 ; i < j ; i++) {os << vecfill.at(i) << " ";}
					}
					for (int j = 0 ; j < 10 ; j++) {
						const Ct	vecfill(j, random_value);
						for (int i = 0 ; i < j ; i++) {os << vecfill.at(i) << " ";}
					}
					os << std::endl;
				}

				static void				front(stream_type &os, type_value random_value) {
					{
						Ct	vecfill(100, random_value); os << vecfill.front() << " "; 
					} {
						Ct	const vecfill(100, random_value);
						os << vecfill.front() << " ";
					}
					os << std::endl;
				}

				static void				back(stream_type &os, type_value random_value) {
					{
						Ct	vecfill(100, random_value); os << vecfill.back() << " "; 
					} {
						Ct	const vecfill(100, random_value);
						os << vecfill.back() << " ";
					}
					os << std::endl;
				}
			};

	template <typename T>
		class BulletAccessors : public ABullet {
			private:
				const BulletAccessors	&operator=(const BulletAccessors &) { return *this; }
				BulletAccessors(const BulletAccessors &) { }
			public:
				typedef 	typename Gunner<T>::file_type  		file_type;
				typedef 	typename Gunner<T>::file_reference	file_reference;
				BulletAccessors() {
					min_diff_time = std::numeric_limits<T>::max();
					max_diff_time = std::numeric_limits<T>::min();
				}
				virtual ~BulletAccessors() { }

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
						UnitestAccessors<Ct, T>		accessors_test;
						accessors_test.operator_bracket(os, random1);
						accessors_test.at(os, random1);
						accessors_test.front(os, random1);
						accessors_test.back(os, random1);
					}
		};


}

#endif ////////////////////////////////////////////////////////////////////////////////////////ENDIF
