
#ifndef MAPINSERTTESTS_HPP ////////////////////////////////////////////////////////////////// IFNDEF
# define MAPINSERTTESTS_HPP

# include <iostream>
# include "../../gunner_srcs/NEWGunner.hpp"
# include "../../../map/Map.hpp"
# include <map>

namespace ft {

		template <class Ct, typename T>
		struct UnitestMapInsert {

			typedef	typename	Ct::size_type						size_type;
			typedef				T									type_value;
			typedef typename 	Gunner<type_value>::file_reference	stream_type;

			static void	print_content(Ct map, bool is_print) {
				typedef		typename Ct::iterator			iterator_type;
				if (is_print)
					for (iterator_type it = map.begin() ; it != map.end() ; ++it)
						std::cout << it->first << " " << it->second << std::endl;
			}

			static void	print_reverse_content(Ct map, bool is_print) {
				typedef		typename Ct::reverse_iterator	reverse_iterator_type;
				if (is_print)
					for (reverse_iterator_type it = map.rbegin() ; it != map.rend() ; ++it)
						std::cout << it->first << " " << it->second << std::endl;
			}

				static void				insert_one_selected(stream_type &os) {
					typedef		ft::map<int, std::string>::value_type			value_type;
					ft::map<int, std::string>			test;
					test.insert(value_type(3, "caca"));
					os << "#### First state : ";
					os << "#### Insert 8: ";
					test.insert(value_type(8, "caca"));
					print_content(test, false);
					os << std::endl;
					os << "#### Insert 5: ";
					test.insert(value_type(5, "pipi"));
					print_reverse_content(test, false);
					os << std::endl;
					os << "#### Insert 1: ";
					test.insert(value_type(1, "crotte"));
					print_reverse_content(test, false);
					os << std::endl;
					os << "#### Insert 2: ";
					test.insert(value_type(2, "crotte"));
					print_reverse_content(test, false);
					os << std::endl;
					os << "#### Insert 7: ";
					test.insert(value_type(7, "zigouigoui"));
					print_reverse_content(test, false);
					os << std::endl;
					os << "#### Insert 9: ";
					test.insert(value_type(9, "popo"));
					print_content(test, false);
					os << std::endl;
					os << "#### Insert 4: ";
					test.insert(value_type(4, "popo"));
					print_content(test, false);
					os << std::endl;
					os << "#### Insert 7: ";
					test.insert(value_type(7, "popo"));
					print_content(test, false);
					os << std::endl;
					os << "#### Insert 6: ";
					test.insert(value_type(6, "popo"));
					print_content(test, false);
					os << std::endl;
				}

				static void				insert_define_range(stream_type &os, std::vector<int> &range) {
					typedef		ft::map<int, std::string>::value_type			value_type;
					typedef		std::vector<int>::iterator				iterator_vector;
					{
						os << "//////////////////////////INSERT AT BEGINING" << std::endl;
						ft::map<int, std::string>			test2;
						for (iterator_vector it = range.begin() ; it != range.end() ; ++it) {
							test2.insert(value_type(*it, "lol"));
							print_content(test2, false);
# ifdef DEBUG
							os << " IS VALID ? : " <<  test2._is_valid() << std::endl;
# endif
						}
					}
					{
						os << "//////////////////////////INSERT RANGE" << std::endl;
						ft::map<int, std::string>			test;
						for (iterator_vector it = range.begin() ; it != range.end() ; ++it) {
							test.insert(test.begin(), value_type(*it, "lol"));
							print_content(test, false);
# ifdef DEBUG
							os << " IS VALID ? : " <<  test._is_valid() << std::endl;
# endif
						}
					}
					os << std::endl;
				}

				static void				insert_random_range(stream_type &os, Ct &range) {
					os << "//////////////////////////RANDOM INSERT RANGE [1 - 20]" << std::endl;
					{
						ft::map<int, std::string>			test2;
						test2.insert(range.begin(), range.end());
						print_content(test2, false);
						os << std::endl;
					}
				}

				static void				insert_random_iterator(stream_type &os, Ct &range) {
					typedef		ft::map<int, std::string>::value_type			value_type;
					os << "//////////////////////////RANDOM INSERT RANGE [1 - 21]" << std::endl;
					{
						ft::map<int, std::string>			test2;
						test2.insert(value_type(21, "shitty test, I hate this fucking project. I want to blow this fucking cursus and send to hell who ever wrote this subject."));
						typename Ct::iterator	it_focus = test2.begin();	
						for (typename Ct::iterator it = range.begin(); it != range.end() ; ++it) {
							test2.insert(*it);
							os << " Test with positionned iterator : ";
							for (typename Ct::iterator it2 = it_focus ; it2 != range.end() ; ++it2)
								os << it2->first << " ";
							os << std::endl;
							os << " reverse : ";
							for (typename Ct::iterator it2 = it_focus ; it2 != range.begin() ; --it2)
								os << it2->first << " ";
# ifdef DEBUG
							os << " IS VALID ? : " <<  test._is_valid() << std::endl;
# endif
						}
						os << std::endl;
						print_content(test2, false);
						os << std::endl;
					}
				}

		};

	template <typename Key, typename Mapped>
		class BulletMapInsert : public ABullet {
			private:
				const BulletMapInsert	&operator=(const BulletMapInsert &) { return *this; }
				BulletMapInsert(const BulletMapInsert &) { }
			public:
				typedef 	typename Gunner<Key>::file_type  		file_type;
				typedef 	typename Gunner<Key>::file_reference	file_reference;
				BulletMapInsert() {
					min_diff_time = std::numeric_limits<Key>::max();
					max_diff_time = std::numeric_limits<Key>::min();
				}
				virtual ~BulletMapInsert() { }

					virtual void	operator() (file_reference std_file, file_reference ft_file) {
						std::srand(time(NULL));
						// Construction of random vector

						int	array[] = {5, 11, 16, 1, 3, 7, 8, 10};
						// Create an vector from a static array.
						// The called constructor use 'array' pointers to instantiate template,
						// then copy the array's content.
						std::vector<int> vec_array(array, array + sizeof(array) / sizeof(array[0]));

						ft::map<int, std::string>			map_values;
						std::map<int, std::string>				map_values_off;
						for (int i = 1 ; i < 50 ; ++i) {
							int	new_nb = rand() % 20 + 1;
							std::cout << " #### insert " << new_nb << " : ";
							map_values[new_nb] = "mdr";
							map_values_off[new_nb] = "mdr";
#ifdef DEBUG
							std::cout << " IS VALID ? : " <<  map_values._is_valid() << std::endl;
#endif
						}

						test<std::map<Key, Mapped> >(std_file, vec_array, map_values_off);
						test<ft::map<Key, Mapped> >(ft_file, vec_array, map_values);
					}

					virtual void	operator() () {
						std::srand(time(NULL));
						int	array[] = {5, 11, 16, 1, 3, 7, 8, 10};
						// Create an vector from a static array.
						// The called constructor use 'array' pointers to instantiate template,
						// then copy the array's content.
						std::vector<int> vec_array(array, array + sizeof(array) / sizeof(array[0]));

						ft::map<int, std::string>			map_values;
						std::map<int, std::string>				map_values_off;
						for (int i = 1 ; i < 50 ; ++i) {
							int	new_nb = rand() % 20 + 1;
							std::cout << " #### insert " << new_nb << " : ";
							map_values[new_nb] = "mdr";
							map_values_off[new_nb] = "mdr";
#ifdef DEBUG
							std::cout << " IS VALID ? : " <<  map_values._is_valid() << std::endl;
#endif
						}

						time_point start_time_std = clock_type::now();
						test<std::map<Key, Mapped> >(std::cout, vec_array, map_values_off);
						time_point end_time_std = clock_type::now();

						time_point start_time_ft = clock_type::now();
						test<ft::map<Key, Mapped> >(std::cout, vec_array, map_values);
						time_point end_time_ft = clock_type::now();

						elapsed_type span_time = duration_type(end_time_ft - start_time_ft).count() / duration_type(end_time_std - start_time_std).count();
						total_time += duration_type(end_time_ft - start_time_ft).count();
						if (span_time < this->min_diff_time)
							this->min_diff_time = span_time;
						else if (span_time > this->max_diff_time)
							this->max_diff_time = span_time;
					}

				template <class Ct>
					void	test(file_reference os, std::vector<int> range_array, Ct map_values) {
					os << "//////////////////////////INSERT////////////////////////////////" << std::endl;
						UnitestMapInsert<Ct, Key>		instance_test;
						instance_test.insert_one_selected(os);
						instance_test.insert_define_range(os, range_array);
						instance_test.insert_random_range(os, map_values);
						instance_test.insert_random_iterator(os, map_values);
					}
		};
}

#endif
