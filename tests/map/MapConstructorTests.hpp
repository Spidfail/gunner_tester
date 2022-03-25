
#ifndef MAPCONSTRUCTORTESTS_HPP ////////////////////////////////////////////////////////////////// IFNDEF
# define MAPCONSTRUCTORTESTS_HPP

# include <iostream>
# include "../../gunner_srcs/NEWGunner.hpp"
# include "../../../map/Map.hpp"
# include <map>

namespace ft {

		template <class Ct, typename T>
		struct UnitestMapConstructor {

			typedef	typename	Ct::size_type						size_type;
			typedef				T									type_value;
			typedef typename 	Gunner<type_value>::file_reference	stream_type;

				static void				map_fill(stream_type &os, type_value random_value) {
				}

				static void				map_range(stream_type &os, type_value random_value) {
				}

				static void				operator_assignation(stream_type &os, type_value random_value) {
				}

				static void				operator_comparison(stream_type &os, type_value random_value, type_value replacement) {
					(void)replacement;
					os << "------------------------------------------------------" << std::endl;
					os << " Values : random = " << random_value << ", replacement = " << replacement << std::endl;
					os << "	OPERATOR == : " << std::endl;
					{
					} {
					} {
					} {
					}

					os << "	OPERATOR != : " << std::endl;
					{
					}

					os << "	OPERATOR > : " << std::endl;
					{
					}

					os << "	OPERATOR < : " << std::endl;
					{
					}

					os << "	OPERATOR >= : " << std::endl;
					{
					}

					os << "	OPERATOR <= : " << std::endl;
					{
					}
				}
		};

	template <typename Key, typename Mapped>
		class BulletMapConstructor : public ABullet {
			private:
				const BulletMapConstructor	&operator=(const BulletMapConstructor &) { return *this; }
				BulletMapConstructor(const BulletMapConstructor &) { }
			public:
				typedef 	typename Gunner<Key>::file_type  		file_type;
				typedef 	typename Gunner<Key>::file_reference	file_reference;
				BulletMapConstructor() {
					min_diff_time = std::numeric_limits<Key>::max();
					max_diff_time = std::numeric_limits<Key>::min();
				}
				virtual ~BulletMapConstructor() { }

				virtual void	operator() (file_reference std_file, file_reference ft_file) {
					ft::Random<Key>	random_generator;
					random_generator.init_random_collection(Key());
					Key random1 = random_generator.generate(Key());
					Key random2 = random_generator.generate(Key()) / 2;
					test<std::map<Key, Mapped> >(std_file, random1, random2);
					test<ft::map<Key, Mapped> >(ft_file, random1, random2);
				}

				virtual void	operator() () {
					ft::Random<Key>	random_generator;
					random_generator.init_random_collection(Key());
					Key random1 = random_generator.generate(Key());
					Key random2 = random_generator.generate(Key());

					time_point start_time_std = clock_type::now();
					test<std::map<Key,Mapped> >(std::cout, random1, random2);
					time_point end_time_std = clock_type::now();

					time_point start_time_ft = clock_type::now();
					test<ft::map<Key,Mapped> >(std::cout, random1, random2);
					time_point end_time_ft = clock_type::now();

					elapsed_type span_time = duration_type(end_time_ft - start_time_ft).count() / duration_type(end_time_std - start_time_std).count();
					total_time += duration_type(end_time_ft - start_time_ft).count();
					if (span_time < this->min_diff_time)
						this->min_diff_time = span_time;
					else if (span_time > this->max_diff_time)
						this->max_diff_time = span_time;
				}

				template <class Ct>
					void	test(file_reference os, Key random1, Key random2) {
						UnitestMapConstructor<Ct, Key>		instance_test;
						instance_test.map_fill(os, random1);
						instance_test.map_range(os, random1);
						instance_test.operator_assignation(os, random1);
						instance_test.operator_comparison(os, random1, random2);
					}
		};
}

#endif
