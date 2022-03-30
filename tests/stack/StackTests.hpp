
#ifndef STACKTESTS_HPP ////////////////////////////////////////////////////////////////// IFNDEF
# define STACKTESTS_HPP

# include <iostream>
# include "../../gunner_srcs/NEWGunner.hpp"
# include "../../../vector/Vector.hpp"
# include "../../../stack/Stack.hpp"
# include <list>

namespace ft {

		template <class Ct, typename TVector>
		struct UnitestStack {

			typedef	typename	Ct::size_type						size_type;
			typedef	typename	Ct::value_type						value_type;
			typedef				TVector								vector_type;
			typedef typename 	Gunner<value_type>::file_reference	stream_type;

			static	void		stack_all(stream_type &os, vector_type &range) {
				Ct	test;
				for (typename vector_type::iterator it = range.begin() ;
						it != range.end() ; ++it) {
					os << " Empty : " << test.empty() << " ";
					test.push(*it);
					os << " Content : " << test.top() << " ";
					os << " Size : " << test.size() << " ";
				}
				os << std::endl;
				while (!test.empty()) {
					os << " Content : " << test.top() << " ";
					os << " Size : " << test.size() << " ";
					test.pop();
				}
			}

		};

		template <typename T>
			class BulletStack : public ABullet {
				private:
					const BulletStack	&operator=(const BulletStack &) { return *this; }
					BulletStack(const BulletStack &) { }

				public:
					typedef		T											value_type;
					typedef		typename std::vector<T>						vector_off;
					typedef		typename ft::vector<T>						vector_cust;
					typedef		typename std::vector<const T>				const_vector_off;
					typedef		typename ft::vector<const T>				const_vector_cust;
					typedef 	typename Gunner<T>::file_type  				file_type;
					typedef 	typename Gunner<T>::file_reference			file_reference;

					BulletStack() {
						min_diff_time = std::numeric_limits<T>::max();
						max_diff_time = std::numeric_limits<T>::min();
					}
					virtual ~BulletStack() { }

					virtual void	operator() (file_reference std_file, file_reference ft_file) {
						vector_off				vec_off;
						vector_cust				vec_cust;
						std::vector<value_type>	vec;
						std::deque<value_type>	dq;
						std::list<value_type>	list;

						ft::Random<T>		value_generator;
						value_generator.init_random_collection(T());
						for (int i = 0 ; i < 150 ; ++i) {
							T random_value = value_generator.generate(T());
							vec_off.push_back(random_value);
							vec_cust.push_back(random_value);
						}
						test<std::stack<T>, vector_off>(std_file, vec_off);
						test<ft::stack<T>, vector_cust>(ft_file, vec_cust);

						test<std::stack<T, std::deque<value_type> > , vector_off>(std_file, vec_off);
						test<ft::stack<T, std::deque<value_type> >, vector_cust >(ft_file, vec_cust);

						test<std::stack<T, std::list<value_type> >, vector_off >(std_file, vec_off);
						test<ft::stack<T, std::list<value_type> >, vector_cust >(ft_file, vec_cust);
					}

					virtual void	operator() () {
						vector_off		vec_off;
						vector_cust		vec_cust;

						ft::Random<T>		value_generator;
						value_generator.init_random_collection(T());
						for (int i = 0 ; i < 150 ; ++i) {
							T random_value = value_generator.generate(T());
							vec_off.push_back(random_value);
							vec_cust.push_back(random_value);
						}

						time_point start_time_std = clock_type::now();
						test<std::stack<T>, vector_off>(std::cout, vec_off);
						test<std::stack<T, std::deque<value_type> > , vector_off>(std::cout, vec_off);
						test<std::stack<T, std::list<value_type> >, vector_off >(std::cout, vec_off);
						time_point end_time_std = clock_type::now();

						time_point start_time_ft = clock_type::now();
						test<ft::stack<T>, vector_cust>(std::cout, vec_cust);
						test<ft::stack<T, std::deque<value_type> >, vector_cust >(std::cout, vec_cust);
						test<ft::stack<T, std::list<value_type> >, vector_cust >(std::cout, vec_cust);
						time_point end_time_ft = clock_type::now();

						elapsed_type span_time = duration_type(end_time_ft - start_time_ft).count() / duration_type(end_time_std - start_time_std).count();
						total_time += duration_type(end_time_ft - start_time_ft).count();
						if (span_time < this->min_diff_time)
							this->min_diff_time = span_time;
						else if (span_time > this->max_diff_time)
							this->max_diff_time = span_time;
					}

					template <class Ct, class TVector>
						void	test(file_reference os, TVector vector_range) {
							UnitestStack<Ct, TVector>		instance_test;
							instance_test.stack_all(os, vector_range);
						}
			};
}

#endif
