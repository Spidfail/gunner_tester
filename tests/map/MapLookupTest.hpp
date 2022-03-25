
#ifndef MAPLOOKUPTESTS_HPP ////////////////////////////////////////////////////////////////// IFNDEF
# define MAPLOOKUPTESTS_HPP

# include <iostream>
# include "../../gunner_srcs/NEWGunner.hpp"
# include "../../../map/Map.hpp"
# include <map>

namespace ft {

		template <class Ct, typename T>
		struct UnitestMapLookup {

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

			static void				count(stream_type &os, std::stack<int> stack) {
				os << "//////////////////////////COUNT" << std::endl;
				Ct			test;
				std::stack<int> 	stack_cpy(stack);
				while (!stack_cpy.empty()) {
					test[stack_cpy.top()] = "bashibouzouk";
					stack_cpy.pop();
				}
				while (!stack.empty()) {
					os << " #### count on : " << stack.top() << " = ";
					os << test.count(stack.top()) << " | ";
					stack.pop();
				}
				os << std::endl;
			}

			static void				find(stream_type &os, std::stack<int> stack) {
				os << "//////////////////////////FIND" << std::endl;
				Ct			test;
				std::stack<int> 	stack_cpy(stack);
				while (!stack_cpy.empty()) {
					test[stack_cpy.top()] = "bashibouzouk";
					stack_cpy.pop();
				}
				while (!stack.empty()) {
					os << "########## find on : " << stack.top() << std::endl;
					{
						os << "iterators : " << std::endl;
						typename Ct::iterator		it =	test.find(stack.top());
						os << " Reverse order [";
						for ( ; it != test.begin() ; --it)
							os << " | " << " " << it->first;
						os << "] " << std::endl;
						os << " Ordered [";
						for ( ; it != test.end() ; ++it)
							os << " | " << " " << it->first;
						os << "]" << std::endl;
					} {
						os << "const_iterators : " << std::endl;
						typename Ct::const_iterator		it =	test.find(stack.top());
						os << " Reverse order [";
						for ( ; it != test.begin() ; --it)
							os << " | " << " " << it->first;
						os << "] " << std::endl;
						os << " Ordered [";
						for ( ; it != test.end() ; ++it)
							os << " | " << " " << it->first;
						os << "]" << std::endl;
					}
					stack.pop();
					os << std::endl << std::endl;
				}
			}

			static void				equal_range(stream_type &os, std::stack<int> stack) {
				std::cout << "//////////////////////////EQUAL RANGE" << std::endl;
				typedef		typename Ct::iterator				iterator;
				typedef		typename Ct::const_iterator			const_iterator;
				Ct				test;
				std::stack<int> 	stack_cpy(stack);
				while (!stack_cpy.empty()) {
					test[stack_cpy.top()] = "bashibouzouk";
					stack_cpy.pop();
				}
				while (!stack.empty()) {
					{
						os << "########## equal range on : " << stack.top() << std::endl;
						os << " iterators : ";
						ft::pair<iterator, iterator>			pair =	test.equal_range(stack.top());
						os << " [";
						for ( ; pair.first != pair.second ; ++pair.first)
							if (pair.second != test.end())
								os << " | " <<  " " << pair.second->first;
							else
								os << " | " << " END " ;
						os << "] ";
					} {
						os << " const_iterators : ";
						ft::pair<const_iterator, const_iterator>			pair =	test.equal_range(stack.top());
						os << " [";
						for ( ; pair.first != pair.second ; ++pair.first)
							if (pair.second != test.end())
								os << " | " <<  " " << pair.second->first;
							else
								os << " | " << " END " ;
						os << "] ";
					}
					stack.pop();
					os << std::endl;
				}
			}

			static void				upper_bound(stream_type &os, std::stack<int> stack) {
				os << "//////////////////////////Upper Bound" << std::endl;
				typedef		typename Ct::iterator				iterator;
				typedef		typename Ct::const_iterator		const_iterator;
				Ct				test;
				std::stack<int> 	stack_cpy(stack);
				while (!stack_cpy.empty()) {
					test[stack_cpy.top()] = "panpanculcul";
					stack_cpy.pop();
				}
				while (!stack.empty()) {
					{
						os << "########## Upper Bound : " << stack.top() << std::endl;
						os << " iterators : ";
						iterator	it =	test.upper_bound(stack.top());
						os << " [";
						for ( ;it != test.end() ;++it)
							os << " | " << " " << it->first;
						os << "] " << std::endl;
					} {
						os << " const_iterators : ";
						const_iterator		it =	test.upper_bound(stack.top());
						os << " [";
						for ( ; it != test.end() ; ++it)
							os << " | " << " " << it->first;
						os << "] " << std::endl;
					}
					stack.pop();
					os << std::endl;
				}
			}

			static void				lower_bound(stream_type &os, std::stack<int> stack) {
				os << "//////////////////////////Upper Bound" << std::endl;
				typedef		typename Ct::iterator				iterator;
				typedef		typename Ct::const_iterator		const_iterator;
				Ct				test;
				std::stack<int> 	stack_cpy(stack);
				while (!stack_cpy.empty()) {
					test[stack_cpy.top()] = "panpanculcul";
					stack_cpy.pop();
				}
				while (!stack.empty()) {
					{
						os << "########## Upper Bound : " << stack.top() << std::endl;
						os << " iterators : ";
						iterator	it =	test.lower_bound(stack.top());
						os << " [";
						for ( ;it != test.end() ;++it)
							os << " | " << " " << it->first;
						os << "] " << std::endl;
					} {
						os << " const_iterators : ";
						const_iterator		it =	test.lower_bound(stack.top());
						os << " [";
						for ( ; it != test.end() ; ++it)
							os << " | " << " " << it->first;
						os << "] " << std::endl;
					}
					stack.pop();
					os << std::endl;
				}
			}

		};

	template <typename Key, typename Mapped>
		class BulletMapLookup : public ABullet {
			private:
				const BulletMapLookup	&operator=(const BulletMapLookup &) { return *this; }
				BulletMapLookup(const BulletMapLookup &) { }
			public:
				typedef 	typename Gunner<Key>::file_type  		file_type;
				typedef 	typename Gunner<Key>::file_reference	file_reference;
				BulletMapLookup() {
					min_diff_time = std::numeric_limits<Key>::max();
					max_diff_time = std::numeric_limits<Key>::min();
				}
				virtual ~BulletMapLookup() { }

					virtual void	operator() (file_reference std_file, file_reference ft_file) {
						std::srand(time(NULL));

						std::stack<int>						stack;
						for (int i = 1 ; i < 50 ; ++i) {
							int	new_nb = rand() % 40 + 1;
# ifdef DEBUG
							ft_file << " IS VALID ? : " <<  test._is_valid() << std::endl;
# endif
							stack.push(new_nb);
						}

						test<std::map<Key, Mapped> >(std_file, stack);
						test<ft::map<Key, Mapped> >(ft_file, stack);
					}

					virtual void	operator() () {
						std::srand(time(NULL));
						// Construction of random map 

						std::stack<int>						stack;
						for (int i = 1 ; i < 50 ; ++i) {
							int	new_nb = rand() % 40 + 1;
# ifdef DEBUG
							ft_file << " IS VALID ? : " <<  test._is_valid() << std::endl;
# endif
							stack.push(new_nb);
						}

						time_point start_time_std = clock_type::now();
						test<std::map<Key, Mapped> >(std::cout, stack);
						time_point end_time_std = clock_type::now();

						time_point start_time_ft = clock_type::now();
						test<ft::map<Key, Mapped> >(std::cout, stack);
						time_point end_time_ft = clock_type::now();

						elapsed_type span_time = duration_type(end_time_ft - start_time_ft).count() / duration_type(end_time_std - start_time_std).count();
						total_time += duration_type(end_time_ft - start_time_ft).count();
						if (span_time < this->min_diff_time)
							this->min_diff_time = span_time;
						else if (span_time > this->max_diff_time)
							this->max_diff_time = span_time;
					}

				template <class Ct>
					void	test(file_reference os, std::stack<int> stack) {
						os << "//////////////////////////LOOKUP////////////////////////////////" << std::endl;
						UnitestMapLookup<Ct, Key>		instance_test;
						instance_test.count(os, stack);
						instance_test.find(os, stack);
						instance_test.equal_range(os, stack);
						instance_test.upper_bound(os, stack);
						instance_test.lower_bound(os, stack);
					}
		};
}

#endif
