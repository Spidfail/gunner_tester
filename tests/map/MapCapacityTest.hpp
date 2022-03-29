
#ifndef MAPCAPACITYTESTS_HPP ////////////////////////////////////////////////////////////////// IFNDEF
# define MAPCAPACITYTESTS_HPP

# include <algorithm>
# include <iostream>
# include "../../gunner_srcs/NEWGunner.hpp"
# include "../../../map/Map.hpp"
# include <map>
#include <utility>

namespace ft {

		template <class Ct, class TVector, class Allocator = std::allocator<typename Ct::value_type> >
		struct UnitestMapCapacity {

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

			template< class T >
				struct MyAllocator {
					typedef	T 				value_type;
					typedef	T	*			pointer;
					typedef	const T *		const_pointer;
					typedef	T	&			reference;
					typedef	const T	&		const_reference;
					typedef	std::size_t		size_type;
					typedef	std::true_type	is_always_equal;

					template< class U > struct rebind { typedef MyAllocator<U> other; };

					MyAllocator() { }
					~MyAllocator() { }
					MyAllocator(const MyAllocator &) { }

					pointer		allocate(size_type n) {
						pointer new_allocation = new pointer[n];
						return new_allocation;
					}
					void		deallocate(pointer p, size_type n) {
						if (p)
							delete [](p, n);
					}
					// Call casted new() on T(val). Cast : (void *)p.
					void construct(pointer p, const_reference val) { new((void *)p) T(val); }
					// Call the destructer of p with 'operator->()'
					void destroy(pointer p) { ((pointer)p)->~T(); }
				};

			static void				get_allocator(stream_type &os, typename Ct::value_type content) {
				Ct		test;
				typename Ct::allocator_type alloc = test.get_allocator();
				for (size_type i = 1 ; i < 100 ; ++i) {
					typename Ct::pointer		pt_value = alloc.allocate(i);
					alloc.construct(pt_value, content);
					os << "success creation  ? " ;
					if (pt_value)
						os << pt_value->first << " | " << pt_value->second;
					os << std::endl;
					alloc.destroy(pt_value);
					alloc.deallocate(pt_value, i);
					pt_value = NULL;
				}
				os << std::endl;
			}

			static	void			empty(stream_type &os, vector_type range) {
				Ct		test;
				Ct		ct_empty;
				// Use of MapInserter class function to insert values from range of a differente type.
				MapInserter inserter(test);
				std::for_each(range.begin(), range.end(), inserter);
				if (test.empty())
					os << "WRONG : test is not empty because filled with range." << std::endl;
				if (ct_empty.empty())
					os << "RIGHT : ct_empty is indeed empty." << std::endl;
				os << "Copy of test in ct_empty" << std::endl;
				ct_empty = test;
				if (ct_empty.empty())
					os << "RIGHT : ct_empty is no more empty." << std::endl;
			}

			static void				size(stream_type &os, vector_type range) {
				Ct		test;
				Ct		ct_empty;
				// Use of MapInserter class function to insert values from range of a differente type.
				MapInserter inserter(test);
				std::for_each(range.begin(), range.end(), inserter);
				os << " SIZE of filled test() = " << test.size() << std::endl;
				os << " SIZE of ct_empty() = " << ct_empty.size() << std::endl;
				ct_empty = test;
				os << " SIZE of filled ct_empty() = " << ct_empty.size() << std::endl;
				test.clear();
				ct_empty.clear();
				os << " SIZE of cleared test() and ct_empty() = " << test.size() << " " << ct_empty.size() << std::endl;
				os << " SIZE in loop - Insert : ";
				for (typename vector_type::iterator it = range.begin() ; it != range.end() ; ++it) {
					test.insert(*it);
					os << test.size() << " ";
				}
				os << std::endl;
				os << " SIZE in loop - Erase : ";
				for (typename vector_type::iterator it = range.begin() ; it != range.end() ; ++it) {
					test.erase(it->first);
					os << test.size() << " ";
				}
				os << std::endl;
			}

			static void				max_size(stream_type &os, vector_type range) {
				Ct		test;
				Ct		ct_empty;
				// Use of MapInserter class function to insert values from range of a differente type.
				MapInserter inserter(test);
				std::for_each(range.begin(), range.end(), inserter);
				os << " MAX SIZE of filled test() = " << bool(test.max_size()) << std::endl;
				os << " MAX SIZE of ct_empty() = " << bool(ct_empty.max_size()) << std::endl;
				ct_empty = test;
				os << " MAX SIZE of filled ct_empty() = " << bool(ct_empty.max_size()) << std::endl;
				test.clear();
				ct_empty.clear();
				os << " MAX SIZE of cleared test() and ct_empty() = " << bool(test.max_size()) << " " << bool(ct_empty.max_size()) << std::endl;

			}
		};

		template <typename Key, typename Mapped >
			class BulletMapCapacity : public ABullet {
				private:
					const BulletMapCapacity	&operator=(const BulletMapCapacity &) { return *this; }
					BulletMapCapacity(const BulletMapCapacity &) { }

				public:
					typedef 	typename Gunner<Key>::file_type  						file_type;
					typedef 	typename Gunner<Key>::file_reference					file_reference;
					typedef 	typename ft::map<Key, Mapped>::iterator					iterator_cust;
					typedef 	typename std::map<Key, Mapped>::iterator				iterator_offi;
					typedef 	typename ft::map<Key, Mapped>::const_iterator			const_iterator_cust;
					typedef 	typename std::map<Key, Mapped>::const_iterator			const_iterator_offi;

					typedef 	typename ft::map<Key, Mapped>							map_cust;
					typedef 	typename std::map<Key, Mapped>							map_off;
					typedef		typename std::vector<typename map_off::value_type>		vector_type_off;
					typedef		typename std::vector<typename map_cust::value_type>		vector_type_cust;

					BulletMapCapacity() {
						min_diff_time = std::numeric_limits<Key>::max();
						max_diff_time = std::numeric_limits<Key>::min();
					}
					virtual ~BulletMapCapacity() { }

					virtual void	operator() (file_reference std_file, file_reference ft_file) {
						std::srand(time(NULL));
						vector_type_off						vector_range_off;
						vector_type_cust			   		vector_range_cust;
						ft::Random<Key>						rd_key;
						ft::Random<Mapped>					rd_mapped;
						rd_key.init_random_collection(Key());
						rd_mapped.init_random_collection(Mapped());
						for (int i = 1 ; i < 50 ; ++i) {
# ifdef DEBUG
							ft_file << " IS VALID ? : " <<  test._is_valid() << std::endl;
# endif
							Key		random_key = rd_key.generate(Key());
							Mapped	random_mapped = rd_mapped.generate(Mapped());
							vector_range_off.push_back(typename std::map<Key, Mapped>::value_type(random_key, random_mapped));
							vector_range_cust.push_back(typename ft::map<Key, Mapped>::value_type(random_key, random_mapped));
						}

						test<std::map<Key, Mapped>, typename std::map<Key, Mapped>::allocator_type,
							vector_type_off >(std_file, vector_range_off);
						test<ft::map<Key, Mapped>, typename ft::map<Key, Mapped>::allocator_type,
							vector_type_cust >(ft_file, vector_range_cust);
					}

					virtual void	operator() () {
						std::srand(time(NULL));
						vector_type_off						vector_range_off;
						vector_type_cust			   		vector_range_cust;
						ft::Random<Key>						rd_key;
						ft::Random<Mapped>					rd_mapped;
						rd_key.init_random_collection(Key());
						rd_mapped.init_random_collection(Mapped());
						for (int i = 1 ; i < 50 ; ++i) {
# ifdef DEBUG
							ft_file << " IS VALID ? : " <<  test._is_valid() << std::endl;
# endif
							Key		random_key = rd_key.generate(Key());
							Mapped	random_mapped = rd_mapped.generate(Mapped());
							vector_range_off.push_back(typename std::map<Key, Mapped>::value_type(random_key, random_mapped));
							vector_range_cust.push_back(typename ft::map<Key, Mapped>::value_type(random_key, random_mapped));
						}

						time_point start_time_std = clock_type::now();
						test_bench<std::map<Key, Mapped>, std::allocator<typename map_off::value_type >, vector_type_off >(std::cout, vector_range_off);
						time_point end_time_std = clock_type::now();

						time_point start_time_ft = clock_type::now();
						test_bench<ft::map<Key, Mapped>, std::allocator<typename map_cust::value_type >, vector_type_cust >(std::cout, vector_range_cust);
						time_point end_time_ft = clock_type::now();

						elapsed_type span_time = duration_type(end_time_ft - start_time_ft).count() / duration_type(end_time_std - start_time_std).count();
						total_time += duration_type(end_time_ft - start_time_ft).count();
						if (span_time < this->min_diff_time)
							this->min_diff_time = span_time;
						else if (span_time > this->max_diff_time)
							this->max_diff_time = span_time;
					}

					template <class Ct, class Allocator, class TVector>
						void	test(file_reference os, TVector collection) {
							UnitestMapCapacity<Ct, TVector, Allocator>		instance_test;
							instance_test.get_allocator(os, collection[0]);
							instance_test.empty(os, collection);
							instance_test.size(os, collection);
							instance_test.max_size(os, collection);
						}
					template <class Ct, class Allocator, class TVector>
						void	test_bench(file_reference os, TVector collection) {
							UnitestMapCapacity<Ct, TVector, Allocator>		instance_test;
							instance_test.empty(os, collection);
							instance_test.size(os, collection);
							instance_test.max_size(os, collection);
						}
			};
}

#endif
