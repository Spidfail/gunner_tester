
#ifndef MAPINSERTTESTS_HPP ////////////////////////////////////////////////////////////////// IFNDEF
# define MAPINSERTTESTS_HPP

# include <iostream>
# include "../../gunner_srcs/NEWGunner.hpp"
# include "../../../map/Map.hpp"
# include <map>

namespace ft {

		template <class Ct, typename Key>
		struct UnitestMapInsert {

			typedef	typename	Ct::size_type						size_type;
			typedef				Key									type_value;
			typedef typename 	Gunner<type_value>::file_reference	stream_type;
			typedef	typename	Ct::value_type						value_type;
			typedef				std::vector<int>::iterator			iterator_vector;

			static void	print_content(Ct map, stream_type &os) {
				typedef		typename Ct::iterator			iterator_type;
				for (iterator_type it = map.begin() ; it != map.end() ; ++it)
					os << it->first << " " << it->second << " | ";
				os << std::endl;
			}

			static void	print_reverse_content(Ct map, stream_type &os) {
				typedef		typename Ct::reverse_iterator	reverse_iterator_type;
				for (reverse_iterator_type it = map.rbegin() ; it != map.rend() ; ++it)
					os << it->first << " " << it->second << " | ";
				os << std::endl;
			}

				static void				insert_one_selected(stream_type &os) {
					Ct			test;
					test.insert(value_type(3, "caca"));
					os << "#### First state : ";
					os << "#### Insert 8: ";
					test.insert(value_type(8, "caca"));
					print_content(test, os);
					os << std::endl;
					os << "#### Insert 5: ";
					test.insert(value_type(5, "pipi"));
					print_reverse_content(test, os);
					os << std::endl;
					os << "#### Insert 1: ";
					test.insert(value_type(1, "crotte"));
					print_reverse_content(test, os);
					os << std::endl;
					os << "#### Insert 2: ";
					test.insert(value_type(2, "crotte"));
					print_reverse_content(test, os);
					os << std::endl;
					os << "#### Insert 7: ";
					test.insert(value_type(7, "zigouigoui"));
					print_reverse_content(test, os);
					os << std::endl;
					os << "#### Insert 9: ";
					test.insert(value_type(9, "popo"));
					print_content(test, os);
					os << std::endl;
					os << "#### Insert 4: ";
					test.insert(value_type(4, "popo"));
					print_content(test, os);
					os << std::endl;
					os << "#### Insert 7: ";
					test.insert(value_type(7, "popo"));
					print_content(test, os);
					os << std::endl;
					os << "#### Insert 6: ";
					test.insert(value_type(6, "popo"));
					print_content(test, os);
					os << std::endl;
				}

				static void				insert_define_range(stream_type &os, std::vector<Key> &range) {
					{
						os << "//////////////////////////INSERT AT BEGINING" << std::endl;
						Ct			test2;
						for (iterator_vector it = range.begin() ; it != range.end() ; ++it) {
							test2.insert(value_type(*it, "lol"));
							print_content(test2, os);
# ifdef DEBUG
							os << " IS VALID ? : " <<  test2._is_valid() << std::endl;
# endif
						}
					}
					{
						os << "//////////////////////////INSERT RANGE" << std::endl;
						Ct			test;
						for (iterator_vector it = range.begin() ; it != range.end() ; ++it) {
							test.insert(test.begin(), value_type(*it, "lol"));
							print_content(test, os);
# ifdef DEBUG
							os << " IS VALID ? : " <<  test._is_valid() << std::endl;
# endif
						}
					}
					os << std::endl;
				}

				static void				insert_define_operator(stream_type &os, std::vector<Key> &range) {
					{
						os << "//////////////////////////INSERT AT BEGINING" << std::endl;
						Ct			test2;
						for (iterator_vector it = range.begin() ; it != range.end() ; ++it) {
							test2[*it] = "lol";
							print_content(test2, os);
# ifdef DEBUG
							os << " IS VALID ? : " <<  test2._is_valid() << std::endl;
# endif
						}
					}
					os << std::endl;
				}

				static void				insert_random_range(stream_type &os, Ct &range) {
					os << "//////////////////////////RANDOM INSERT RANGE [1 - 50]" << std::endl;
					{
						Ct			test2;
						test2.insert(range.begin(), range.end());
						// Test with same range
						test2.insert(range.begin(), range.end());
						print_content(test2, os);
						os << std::endl;
					}
				}

				static void				insert_random_and_iterator(stream_type &os, Ct &range) {
					os << "//////////////////////////RANDOM INSERT RANGE [1 - 50]" << std::endl;
					{
						Ct			test2;
						typename Ct::iterator it = range.begin();
						for (int i = 0 ; i < 27 ; ++i)
							++it;
						test2.insert(range.begin(), it);
						// Create iterator before insert
						typename Ct::iterator it_test = test2.begin();
						++it_test;
						// Test with same range
						test2.insert(range.begin(), range.end());
						print_content(test2, os);
						os << " Print content with previous iterator : ";
						for (; it_test != test2.end() ; ++it_test)
							os << it_test->first << " ";
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
						ft::Random<Key>		random_generator;
						random_generator.init_random_collection(Key());

						ft::map<Key, Mapped>			map_values;
						std::map<Key, Mapped>				map_values_off;
						for (int i = 1 ; i < 50 ; ++i) {
							Key		new_value = random_generator.generate(Key());
							std_file << " #### insert " << new_value << " : ";
							ft_file << " #### insert " << new_value << " : ";
							map_values[new_value] = "mdr";
							map_values_off[new_value] = "mdr";
#ifdef DEBUG
							std::cout << " IS VALID ? : " <<  map_values._is_valid() << std::endl;
#endif
						}
						std::vector<Key>		vec_array;
						for (int i = 1 ; i < 50 ; ++i)
							vec_array.push_back(random_generator.generate(Key()));

						test<std::map<Key, Mapped> >(std_file, vec_array, map_values_off);
						test<ft::map<Key, Mapped> >(ft_file, vec_array, map_values);
					}

					virtual void	operator() () {
						std::srand(time(NULL));

						ft::Random<Key>		random_generator;
						random_generator.init_random_collection(Key());

						ft::map<Key, Mapped>					map_values;
						std::map<Key, Mapped>					map_values_off;
						for (int i = 1 ; i < 50 ; ++i) {
							Key		new_value = random_generator.generate(Key());
							std::cout << " #### insert " << new_value << " : ";
							map_values[new_value] = "mdr";
							map_values_off[new_value] = "mdr";
#ifdef DEBUG
							std::cout << " IS VALID ? : " <<  map_values._is_valid() << std::endl;
#endif
						}

						std::vector<Key>		vec_array;
						for (int i = 1 ; i < 50 ; ++i)
							vec_array.push_back(random_generator.generate(Key()));

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
					void	test(file_reference os, std::vector<Key> range_array, Ct map_values) {
					os << "//////////////////////////INSERT////////////////////////////////" << std::endl;
						UnitestMapInsert<Ct, Key>		instance_test;
						instance_test.insert_one_selected(os);
						instance_test.insert_define_range(os, range_array);
						instance_test.insert_define_operator(os, range_array);
						instance_test.insert_random_range(os, map_values);
						instance_test.insert_random_and_iterator(os, map_values);
					}
		};
}

#endif
