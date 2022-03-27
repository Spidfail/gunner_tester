
#ifndef MAPERASETESTS_HPP ////////////////////////////////////////////////////////////////// IFNDEF
# define MAPERASETESTS_HPP

# include <iostream>
# include "../../gunner_srcs/NEWGunner.hpp"
# include "../../../map/Map.hpp"
# include <map>
# include "../Pair.hpp"
# include <algorithm>

namespace ft {

		template <class Ct, typename Key, typename Mapped, typename MakePair>
			struct UnitestMapErase {

				typedef	typename	Ct::size_type						size_type;
				typedef				Key									key_type;
				typedef				Mapped								mapped_type;
				typedef				std::vector<key_type>				vector_type;
				typedef typename 	Gunner<key_type, mapped_type>::file_reference	stream_type;

				static void				erase_random_tree(stream_type &os, vector_type &vec_values) {
					std::cout << "////////////// TEST WITH RANDOM TREE : SHUFFLED RANGE [1 - 20]" << std::endl;
					Ct			test;

					for (typename vector_type::iterator it = vec_values.begin() ; it != vec_values.end() ; ++it) {
						os << *it << " ";
					}

					os << std::endl;
					for (typename vector_type::iterator it = vec_values.begin() ;
							it != vec_values.end() ; ++it) {
						os << " ## Erase : " << *it << std::endl;
						test.erase(*it);
						// os.flush();
						// os << "RANGE = ";
						// for (typename Ct::iterator it = test.begin() ; it != test.end() ; ++it) {
							// os << it->first << " ";
						// }
# ifdef DEBUG
						os << " IS VALID ? " << test._is_valid() << std::endl << std::endl;
# endif
					}
					os << std::endl;
				}

				static void				erase_safe_iterator_1(stream_type &os, vector_type &vec_values, key_type nb_safe, MakePair mp) {

					os << std::endl << "//////////// TEST ERASE AND ITERATOR - Define tree - Print" << std::endl;
					os << std::endl;
					Ct			test;


					os << " RANGE = ";
					for (typename vector_type::iterator it = vec_values.begin() ; it != vec_values.end() ; ++it) {
						os << *it << " ";
					}
					os << std::endl;

					for (typename vector_type::iterator it = vec_values.begin() ; it != vec_values.end() ; ++it) {
						test.insert(mp(*it, "manger des chips"));
					}
# ifdef DEBUG
					os << " IS VALID ? : " <<  test._is_valid() << std::endl;
# endif
					os << std::endl;

					// Create safe iterator, shouldn't desappear
					typename Ct::iterator		safe_it = test.begin();
					while (safe_it->first != nb_safe)
						++safe_it;

					os << " ERASE RANGE, EXCEPT :" << nb_safe << std::endl;

					// TEST
					for (typename vector_type::iterator it = vec_values.begin() ; it != vec_values.end() ; ++it) {
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

				static void				erase_random(stream_type &os, vector_type &vec_values, key_type nb_safe, MakePair mp) {
					// Same test 
					os << std::endl << "//////////// TEST ERASE AND ITERATOR - Random & Print" << std::endl;
					os << std::endl;
					Ct			test;


					for (typename vector_type::iterator it = vec_values.begin() ; it != vec_values.end() ; ++it) {
						test.insert(mp(*it, "manger des chips"));
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

					os << " ERASE, EXCEPT :" << nb_safe << std::endl;

					// TEST
					for (typename vector_type::iterator it = vec_values.begin() ; it != vec_values.end() ; ++it) {
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

				static void				erase_random_range_2(stream_type &os, vector_type &vec_values, key_type nb_safe, MakePair mp) {
					os << std::endl << "//////////// TEST ERASE RANGE AND ITERATOR - Random Range !" << std::endl;
					os << std::endl;
					Ct			test;
					// Insert range, print content, check if the tree is balanced, print tree.
					os << "   RANGE INSERTED : ";
					for (typename vector_type::iterator it = vec_values.begin() ; it != vec_values.end() ; ++it) {
						test.insert(mp(*it, "manger des chips"));
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


					os << " ERASE, EXCEPT :" << nb_safe << std::endl;

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
					typedef				std::vector<Key>				vector_type;
					typedef 	typename Gunner<Key>::file_type  		file_type;
					typedef 	typename Gunner<Key>::file_reference	file_reference;
					BulletMapErase() {
						min_diff_time = std::numeric_limits<Key>::max();
						max_diff_time = std::numeric_limits<Key>::min();
					}
					virtual ~BulletMapErase() { }

					virtual void	operator() (file_reference std_file, file_reference ft_file) {
						std::srand(time(NULL));
						vector_type						vec_values;
						// Construction of random vector
						ft::Random<Key>		random_generator;
						random_generator.init_random_collection(Key());

						for (int i = 1 ; i < 150 ; ++i) {
							Key	new_nb = random_generator.generate(Key());
							vec_values.push_back(new_nb);
						}
						Key	value_safe = vec_values[rand() % 149];

						test<std::map<Key, Mapped> >(std_file, vec_values, value_safe, std::make_pair<Key, Mapped>);
						test<ft::map<Key, Mapped> >(ft_file, vec_values, value_safe, ft::make_pair<Key, Mapped>);
					}

					virtual void	operator() () {
						std::srand(time(NULL));
						vector_type						vec_values;

						ft::Random<Key>		random_generator;
						random_generator.init_random_collection(Key());

						for (int i = 1 ; i < 150 ; ++i) {
							Key random_val = random_generator.generate(Key());
							vec_values.push_back(random_val);
						}
						Key	value_safe = vec_values[rand() % 149];


						time_point start_time_std = clock_type::now();
						test<std::map<Key, Mapped> >(std::cout, vec_values, value_safe, std::make_pair<Key, Mapped>);
						time_point end_time_std = clock_type::now();

						time_point start_time_ft = clock_type::now();
						test<ft::map<Key, Mapped> >(std::cout, vec_values, value_safe, ft::make_pair<Key, Mapped>);
						time_point end_time_ft = clock_type::now();

						elapsed_type span_time = duration_type(end_time_ft - start_time_ft).count() / duration_type(end_time_std - start_time_std).count();
						total_time += duration_type(end_time_ft - start_time_ft).count();
						if (span_time < this->min_diff_time)
							this->min_diff_time = span_time;
						else if (span_time > this->max_diff_time)
							this->max_diff_time = span_time;
					}

					template <class Ct, class MakePair>
						void	test(file_reference os, vector_type collection, Key value_safe, MakePair mp) {
							std::cout << "//////////////////////////ERASE/////////////////////////////////" << std::endl;
							UnitestMapErase<Ct, Key, Mapped, MakePair>		instance_test;
							instance_test.erase_random_tree(os, collection);
							instance_test.erase_safe_iterator_1(os, collection, value_safe, mp);
							instance_test.erase_random(os, collection, value_safe, mp);
							instance_test.erase_random_range_2(os, collection, value_safe, mp);
						}
			};
}

#endif
