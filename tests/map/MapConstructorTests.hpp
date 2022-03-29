
#ifndef MAPCONSTRUCTORTESTS_HPP ////////////////////////////////////////////////////////////////// IFNDEF
# define MAPCONSTRUCTORTESTS_HPP

# include <iostream>
# include "../../gunner_srcs/NEWGunner.hpp"
# include "../../../map/Map.hpp"
# include <map>

namespace ft {

		template <class Ct, typename TVector>
		struct UnitestMapConstructor {

			typedef	typename	Ct::size_type									size_type;
			typedef	typename	Ct::key_type									key_type;
			typedef	typename	Ct::mapped_type									mapped_type;
			typedef typename 	Gunner<key_type, mapped_type>::file_reference	stream_type;
			typedef				TVector											vector_type;

			// Class function to insert elements into a map from different type range
			// using std::for_each.
			struct MapInserter: std::unary_function<typename Ct::value_type, void> {
				Ct& ct;
				MapInserter(Ct& ct): ct(ct) {}
				void operator()(const typename Ct::value_type& value) {
					ct.insert(value);
				}
			};

			static void				operator_constructor_copy(stream_type &os, const vector_type &random_value) {
				Ct	test;
				Ct	empty_fill(test);
				os << "TEST : compare map parameters : " << std::endl;
				os << "  empty = " <<  empty_fill.empty() << std::endl;
				os << "  size = " <<  empty_fill.size() << std::endl;

				MapInserter		inserter(test);
				std::for_each(random_value.begin(), random_value.end(), inserter);
				Ct	copy_test1(test);
				Ct	copy_test2 = copy_test1;
				os << std::boolalpha;
				os << "TEST : compare map parameters : " << std::endl;
				os << "  empty = " <<  (test.empty() == copy_test1.empty() && copy_test1.empty() == copy_test2.empty()) << std::endl;
				os << "  size = " <<  (test.size() == copy_test1.size() && copy_test1.size() == copy_test2.size()) << std::endl;
				os << "  it begin = " <<  (test.begin() == copy_test1.begin() && copy_test1.begin() == copy_test2.begin()) << std::endl;
				os << "  it end = " <<  (test.end() == copy_test1.end() && copy_test1.end() == copy_test2.end()) << std::endl;
				os << "TEST : compare content (iterators) : " << std::endl;
				for (typename Ct::iterator it1 = test.begin(), it2 = copy_test1.begin(), it3 = copy_test2.begin() ;
						it1 != test.end() && it2 != copy_test1.end() && it3 != copy_test2.end() ;
						++it1, ++it2, ++it3) {
					os << (it1 == it2 && it2 == it3) << std::endl;
					os << it1->first << " " << it2->first << " " << it3->first << " | ";
				}
				os << std::endl;
			}

			static void				map_fill(stream_type &os, const vector_type &random_value) {
				os << std::boolalpha;
				Ct	test;
				MapInserter		inserter(test);
				std::for_each(random_value.begin(), random_value.end(), inserter);
				Ct	fill(test.begin(), test.end());
				os << "TEST : compare fill parameters : " << std::endl;
				os << "  empty = " <<  (test.empty() == fill.empty()) << std::endl;
				os << "  size = " <<  (test.size() == fill.size()) << std::endl;
				os << "  it = " << (test.begin() == fill.begin()) << std::endl;
				os << "TEST : compare content (iterators) : " << std::endl;
				for (typename Ct::iterator it1 = test.begin(), it2 = fill.begin();
						it1 != test.end() && it2 != fill.end() ;
						++it1, ++it2) {
					os << (it1 == it2) << " ";
				}
				os << std::endl;
			}


			static void				operator_comparison(stream_type &os, vector_type random_range, typename Ct::value_type random_value) {
				os << "------------------------------------------------------" << std::endl;
				Ct	test;
				MapInserter		inserter(test);
				std::for_each(random_range.begin(), random_range.end(), inserter);
				os << std::boolalpha;
				os << "	OPERATOR == : " << std::endl;
				{
					Ct	equal(test);
					os << bool(equal == test) << " ";
					equal.clear();
					os << bool(equal == test) << " ";
					Ct	equal_empty(equal);
					os << bool(equal == equal_empty) << " ";

					equal = test;
					equal.erase(--equal.end());
					os << bool(equal == test) << " ";
					equal.insert(*(--equal.end()));
					equal.insert(random_value);
					os << bool(equal == test) << " ";
					os << std::endl;
				}

				os << "	OPERATOR != : " << std::endl;
				{
					Ct	equal(test);
					os << bool(equal != test) << " ";
					equal.clear();
					os << bool(equal != test) << " ";
					Ct	equal_empty(equal);
					os << bool(equal != equal_empty) << " ";

					equal = test;
					equal.erase(--equal.end());
					os << bool(equal != test) << " ";
					equal.insert(*(--equal.end()));
					equal.insert(random_value);
					os << bool(equal != test) << " ";
					os << std::endl;
				}

				os << "	OPERATOR < : " << std::endl;
				{
					Ct	equal(test);
					os << bool(equal < test) << " ";
					equal.clear();
					os << bool(equal < test) << " ";
					Ct	equal_empty(equal);
					os << bool(equal < equal_empty) << " ";

					equal = test;
					equal.erase(--equal.end());
					os << bool(equal < test) << " ";
					equal.insert(*(--equal.end()));
					equal.insert(random_value);
					os << bool(equal < test) << " ";
					os << std::endl;
				}

				os << "	OPERATOR > : " << std::endl;
				{
					Ct	equal(test);
					os << bool(equal > test) << " ";
					equal.clear();
					os << bool(equal > test) << " ";
					Ct	equal_empty(equal);
					os << bool(equal > equal_empty) << " ";

					equal = test;
					equal.erase(--equal.end());
					os << bool(equal > test) << " ";
					equal.insert(*(--equal.end()));
					equal.insert(random_value);
					os << bool(equal > test) << " ";
					os << std::endl;
				}

				os << "	OPERATOR >= : " << std::endl;
				{
					Ct	equal(test);
					os << bool(equal >= test) << " ";
					equal.clear();
					os << bool(equal >= test) << " ";
					Ct	equal_empty(equal);
					os << bool(equal >= equal_empty) << " ";

					equal = test;
					equal.erase(--equal.end());
					os << bool(equal >= test) << " ";
					equal.insert(*(--equal.end()));
					equal.insert(random_value);
					os << bool(equal >= test) << " ";
					os << std::endl;
				}

				os << "	OPERATOR <= : " << std::endl;
				{
					Ct	equal(test);
					os << bool(equal <= test) << " ";
					equal.clear();
					os << bool(equal <= test) << " ";
					Ct	equal_empty(equal);
					os << bool(equal <= equal_empty) << " ";

					equal = test;
					equal.erase(--equal.end());
					os << bool(equal <= test) << " ";
					equal.insert(*(--equal.end()));
					equal.insert(random_value);
					os << bool(equal <= test) << " ";
					os << std::endl;
				}
			}
		};

		template <typename Key, typename Mapped>
			class BulletMapConstructor : public ABullet {
				private:
					const BulletMapConstructor	&operator=(const BulletMapConstructor &) { return *this; }
					BulletMapConstructor(const BulletMapConstructor &) { }

				public:
					typedef 	typename Gunner<Key>::file_type  					file_type;
					typedef 	typename Gunner<Key>::file_reference				file_reference;
					typedef		typename std::map<Key, Mapped>						map_off;
					typedef		typename ft::map<Key, Mapped>						map_cust;
					typedef		typename map_off::value_type						value_type_off;
					typedef		typename map_cust::value_type						value_type_cust;
					typedef		typename std::vector<value_type_off>				vector_off;
					typedef		typename std::vector<value_type_cust>				vector_cust;

					BulletMapConstructor() {
						min_diff_time = std::numeric_limits<Key>::max();
						max_diff_time = std::numeric_limits<Key>::min();
					}
					virtual ~BulletMapConstructor() { }

					virtual void	operator() (file_reference std_file, file_reference ft_file) {
						vector_off		vec_off;
						vector_cust		vec_cust;
						ft::Random<Key>		key_generator;
						ft::Random<Mapped>	mapped_generator;
						key_generator.init_random_collection(Key());
						mapped_generator.init_random_collection(Mapped());

						for (int i = 0 ; i < 150 ; ++i) {
							Key	rand_key = key_generator.generate(Key());
							Mapped	rand_mapped = mapped_generator.generate(Mapped());
							vec_off.push_back(std::make_pair(rand_key, rand_mapped));
							vec_cust.push_back(ft::make_pair(rand_key, rand_mapped));
						}
						test<std::map<Key, Mapped>, vector_off>(std_file, vec_off,
								std::make_pair(key_generator.generate(Key()), mapped_generator.generate(Mapped())));
						test<ft::map<Key, Mapped>, vector_cust>(ft_file, vec_cust,
								ft::make_pair(key_generator.generate(Key()), mapped_generator.generate(Mapped())));
					}

					virtual void	operator() () {
						vector_off		vec_off;
						vector_cust		vec_cust;
						ft::Random<Key>		key_generator;
						ft::Random<Mapped>	mapped_generator;
						key_generator.init_random_collection(Key());
						mapped_generator.init_random_collection(Mapped());

						for (int i = 0 ; i < 150 ; ++i) {
							Key	rand_key = key_generator.generate(Key());
							Mapped	rand_mapped = mapped_generator.generate(Mapped());
							vec_off.push_back(std::make_pair(rand_key, rand_mapped));
							vec_cust.push_back(ft::make_pair(rand_key, rand_mapped));
						}

						time_point start_time_std = clock_type::now();
						test<std::map<Key, Mapped>, vector_off>(std::cout, vec_off,
								std::make_pair(key_generator.generate(Key()), mapped_generator.generate(Mapped())));
						time_point end_time_std = clock_type::now();

						time_point start_time_ft = clock_type::now();
						test<ft::map<Key, Mapped>, vector_cust>(std::cout, vec_cust,
								ft::make_pair(key_generator.generate(Key()), mapped_generator.generate(Mapped())));
						time_point end_time_ft = clock_type::now();

						elapsed_type span_time = duration_type(end_time_ft - start_time_ft).count() / duration_type(end_time_std - start_time_std).count();
						total_time += duration_type(end_time_ft - start_time_ft).count();
						if (span_time < this->min_diff_time)
							this->min_diff_time = span_time;
						else if (span_time > this->max_diff_time)
							this->max_diff_time = span_time;
					}

					template <class Ct, class TVector, typename T>
						void	test(file_reference os, const TVector &vector_range, const T &random_value) {
							UnitestMapConstructor<Ct, TVector>		instance_test;
							instance_test.operator_constructor_copy(os, vector_range);
							instance_test.map_fill(os, vector_range);
							instance_test.operator_comparison(os, vector_range, random_value);
						}
			};
}

#endif
