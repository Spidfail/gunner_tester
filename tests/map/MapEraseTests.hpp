
#ifndef MAPERASETESTS_HPP ////////////////////////////////////////////////////////////////// IFNDEF
# define MAPERASETESTS_HPP

# include <iostream>
# include "../../gunner_srcs/NEWGunner.hpp"
# include "../../../map/Map.hpp"
# include <map>
# include <algorithm>

namespace ft {

		template <class Ct, typename T>
			struct UnitestMapErase {

				typedef	typename	Ct::size_type						size_type;
				typedef				T									type_value;
				typedef typename 	Gunner<type_value>::file_reference	stream_type;

				static void				erase_random_tree(stream_type &os, std::vector<int> &vec_values) {
					std::cout << "////////////// TEST WITH RANDOM TREE : SHUFFLED RANGE [1 - 20]" << std::endl;
					Ct			test;
					std::map<int, std::string>			test_off;

					for (std::vector<int>::iterator it = vec_values.begin() ; it != vec_values.end() ; ++it) {
						os << *it << " ";
					}

					// ft::vector<int>::iterator	it = vec_values.begin();

					os << std::endl;
					for (std::vector<int>::iterator it = vec_values.begin() ;
							it != vec_values.end() ; ++it) {
						os << " ## Erase : " << *it << std::endl;
						test.erase(*it);
# ifdef DEBUG
						os << " IS VALID ? " << test._is_valid() << std::endl << std::endl;
# endif
					}
					os << std::endl;
				}

				static void				erase_safe_iterator_1(stream_type &os, std::vector<int> &vec_values, int nb_safe) {

					os << std::endl << "//////////// TEST ERASE AND ITERATOR - Define tree - Print" << std::endl;
					os << std::endl;
					Ct			test;


					os << " RANGE = ";
					for (std::vector<int>::iterator it = vec_values.begin() ; it != vec_values.end() ; ++it) {
						os << *it << " ";
					}
					os << std::endl;

					for (std::vector<int>::iterator it = vec_values.begin() ; it != vec_values.end() ; ++it) {
						test.insert(ft::make_pair(*it, "manger des chips"));
					}
# ifdef DEBUG
					os << " IS VALID ? : " <<  test._is_valid() << std::endl;
# endif
					os << std::endl;

					// Create safe iterator, shouldn't desappear
					typename Ct::iterator		safe_it = test.begin();
					while (safe_it->first != nb_safe)
						++safe_it;

					os << " ERASE RANGE, EXCEPT :" << nb_safe << ", with address = " << &(*safe_it) << std::endl;

					// TEST
					for (std::vector<int>::iterator it = vec_values.begin() ; it != vec_values.end() ; ++it) {
						if (*it != nb_safe) {
							os << "----Erase : " << *it << std::endl;
							test.erase(*it);
						}
# ifdef DEBUG
						os << "   IS VALID ? : " << test._is_valid() << std::endl;
# endif
						// Check by printing content
						os << "   Print value : ";
						for (typename Ct::iterator it_map = safe_it ;
								it_map != test.end() ; ++it_map)
							os << it_map->first << " ";
						os << " | ";
						for (typename Ct::iterator it_map = safe_it ;
								it_map != test.begin() ; --it_map)
							os << it_map->first << " ";
						os << std::endl;
					}
					os << std::endl;

					// Print map to check it's final content
					os << "Check map content : " << std::endl;
					for (typename Ct::iterator	it = test.begin() ;
							it != test.end() ; ++it) {
						os << it->first << " ";
					}
					os << std::endl;
				}

				static void				erase_random(stream_type &os, std::vector<int> &vec_values, int nb_safe) {
					// Same test 
					os << std::endl << "//////////// TEST ERASE AND ITERATOR - Random & Print" << std::endl;
					os << std::endl;
					Ct			test;


					for (std::vector<int>::iterator it = vec_values.begin() ; it != vec_values.end() ; ++it) {
						test.insert(ft::make_pair(*it, "manger des chips"));
						// print_content(test, false);
					}
# ifdef DEBUG
					os << " IS VALID ? : " <<  test._is_valid() << std::endl;
# endif

					os << std::endl;

					// Create and set a safe iterator, shouldn't desappear.
					typename Ct::iterator		safe_it = test.begin();
					while (safe_it->first != nb_safe)
						++safe_it;

					os << " ERASE, EXCEPT :" << nb_safe << ", with address = " << &(*safe_it) << std::endl;

					// TEST
					for (std::vector<int>::iterator it = vec_values.begin() ; it != vec_values.end() ; ++it) {
						if (*it != nb_safe) {
							os << "----Erase : " << *it << std::endl;
							test.erase(*it);
						}
# ifdef DEBUG
						os << "   IS VALID ? : " << test._is_valid() << std::endl;
# endif
						// Check by printing content
						os << "   Print value : ";
						for (typename Ct::iterator it_map = safe_it ;
								it_map != test.end() ; ++it_map)
							os << it_map->first << " ";
						os << " | ";
						os.flush();
						for (typename Ct::iterator it_map = safe_it ;
								it_map != test.begin() ; --it_map)
							os << it_map->first << " ";
						os << std::endl;
					}
					os << " ERASE SAFE NUMBER : ";
					test.erase(nb_safe);
					os << std::endl;
				}

				static void				erase_random_range_2(stream_type &os, std::vector<int> &vec_values, int nb_safe) {
					os << std::endl << "//////////// TEST ERASE RANGE AND ITERATOR - Random Range !" << std::endl;
					os << std::endl;
					Ct			test;
					// Insert range, print content, check if the tree is balanced, print tree.
					os << "   RANGE INSERTED : ";
					for (std::vector<int>::iterator it = vec_values.begin() ; it != vec_values.end() ; ++it) {
						test.insert(ft::make_pair(*it, "manger des chips"));
						// print_content(test, false);
					}
					for (typename Ct::iterator it = test.begin() ;
							it != test.end() ; ++it)
						os << it->first << " ";
# ifdef DEBUG
					os << std::endl << " IS VALID ? : " <<  test._is_valid() << std::endl;
# endif
					os << std::endl;

					// Create safe iterator, shouldn't desappear
					typename Ct::iterator		safe_it = test.begin();
					while (safe_it->first != nb_safe)
						++safe_it;


					os << " ERASE, EXCEPT :" << nb_safe << ", with address = " << &(*safe_it) << std::endl;

					os << "-----Range to erase : ";
					for (typename Ct::iterator it = test.begin() ; it != safe_it ; ++it)
						os << it->first << " ";
					os << std::endl;

					os << "-----Erase the range !" << std::endl;
					test.erase(test.begin(), safe_it);

					os << "   Print value : ";
					for (typename Ct::iterator it_map = safe_it ;
							it_map != test.end() ; ++it_map)
						os << it_map->first << " ";
					os << " | ";
					os.flush();
					for (typename Ct::iterator it_map = safe_it ;
							it_map != test.begin() ; --it_map)
						os << it_map->first << " ";
					os << std::endl;
					os << std::endl;

					os << "-----Range to erase : ";
					{
						typename Ct::iterator it = safe_it;
						++it;
						for ( ; it != test.end() ; ++it)
							os << it->first << " ";
						os << std::endl;
					}

					os << "-----Erase the range !" << std::endl;
					test.erase(++(typename Ct::iterator(safe_it)), test.end());

					// Finale print
					os << "   Print value : ";
					for (typename Ct::iterator it_map = safe_it ;
							it_map != test.end() ; ++it_map)
						os << it_map->first << " ";
					os << " | ";
					os.flush();
					for (typename Ct::iterator it_map = safe_it ;
							it_map != test.begin() ; --it_map)
						os << it_map->first << " ";
					os << std::endl;

					os << " ERASE SAFE NUMBER ";
					test.erase(nb_safe);
					os << std::endl;
				}

			};

		template <typename Key, typename Mapped>
			class BulletMapErase : public ABullet {
				private:
					const BulletMapErase	&operator=(const BulletMapErase &) { return *this; }
					BulletMapErase(const BulletMapErase &) { }
				public:
					typedef 	typename Gunner<Key>::file_type  		file_type;
					typedef 	typename Gunner<Key>::file_reference	file_reference;
					BulletMapErase() {
						min_diff_time = std::numeric_limits<Key>::max();
						max_diff_time = std::numeric_limits<Key>::min();
					}
					virtual ~BulletMapErase() { }

					virtual void	operator() (file_reference std_file, file_reference ft_file) {
						std::srand(time(NULL));
						// Construction of random vector
						std::vector<int>						vec_values;
						for (int i = 1 ; i < 30 ; ++i) {
							int	new_nb = rand() % 20 + 1;
							vec_values.push_back(new_nb);
						}
						int	nb_safe = vec_values[rand() % 29];
						std::random_shuffle(vec_values.begin(), vec_values.end());

						int	array[] = {8, 2, 10, 16, 5, 15, 17, 1, 6, 9};
						// Create an vector from a static array.
						// The called constructor use 'array' pointers to instantiate template,
						// then copy the array's content.
						std::vector<int> vec_array(array, array + sizeof(array) / sizeof(array[0]));
						// Safe number within the range, randomly selected.
						int	nb_safe_array = array[rand() % 10];

						test<std::map<Key, Mapped> >(std_file, vec_values, vec_array, nb_safe, nb_safe_array);
						test<ft::map<Key, Mapped> >(ft_file, vec_values, vec_array, nb_safe, nb_safe_array);
					}

					virtual void	operator() () {
						std::srand(time(NULL));
						std::vector<int>						vec_values;

						for (int i = 1 ; i < 30 ; ++i) {
							int	new_nb = rand() % 20 + 1;
							vec_values.push_back(new_nb);
						}
						int	nb_safe = vec_values[rand() % 29];
						std::random_shuffle(vec_values.begin(), vec_values.end());

						int	array[] = {8, 2, 10, 16, 5, 15, 17, 1, 6, 9};
						// Create an vector from a static array.
						// The called constructor use 'array' pointers to instantiate template,
						// then copy the array's content.
						std::vector<int> vec_array(array, array + sizeof(array) / sizeof(array[0]));
						// Safe number within the range, randomly selected.
						int	nb_safe_array = array[rand() % 10];

						time_point start_time_std = clock_type::now();
						test<std::map<Key, Mapped> >(std::cout, vec_values, vec_array, nb_safe, nb_safe_array);
						time_point end_time_std = clock_type::now();

						time_point start_time_ft = clock_type::now();
						test<ft::map<Key, Mapped> >(std::cout, vec_values, vec_array, nb_safe, nb_safe_array);
						time_point end_time_ft = clock_type::now();

						elapsed_type span_time = duration_type(end_time_ft - start_time_ft).count() / duration_type(end_time_std - start_time_std).count();
						total_time += duration_type(end_time_ft - start_time_ft).count();
						if (span_time < this->min_diff_time)
							this->min_diff_time = span_time;
						else if (span_time > this->max_diff_time)
							this->max_diff_time = span_time;
					}

					template <class Ct>
						void	test(file_reference os, std::vector<int> collection,
								std::vector<int> collection_array, int nb_safe, int nb_safe_array) {
							std::cout << "//////////////////////////ERASE/////////////////////////////////" << std::endl;
							UnitestMapErase<Ct, Key>		instance_test;
							instance_test.erase_random_tree(os, collection);
							instance_test.erase_safe_iterator_1(os, collection_array, nb_safe_array);
							instance_test.erase_random(os, collection, nb_safe);
							instance_test.erase_random_range_2(os, collection, nb_safe);
						}
			};
}

#endif
