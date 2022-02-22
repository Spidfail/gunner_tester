
#ifndef UNITTEST_HPP
#define UNITTEST_HPP

#include <vector>
#include <map>
#include <stack>
#include <set>
#include "AUnitTest.hpp"
#include "ft_random.hpp"
#include <../vector/Vector.hpp>

namespace ft {

	template<typename Ct>
		class ACtBullet : ft::ABullet { };

	template <typename T, typename Alloc>
		class ACtBullet < std::vector<T, Alloc> >  : ft::ABullet {

			public:
				typedef		T							value_type;
				typedef		Alloc						allocator_type;
				typedef		std::vector<T, Alloc>		vector_original;
				typedef		ft::vector<T, Alloc>		vector_custom;
				typedef		ft::Random<T>				random_type;

			private:
				template <typename Ct>
				void	_tests(file_type os, T random_value, T replacement);

			protected:
				virtual file_type		_create_file(const file_name_type &impl_id) {
					_name.append("_vector_" + impl_id);
					_stream = new std::ofstream(_path + _name);
					if (_stream->is_open() == false)
						throw (ft::ABullet::FailedToOpenFileException(_name));
					return _stream;
				}

			public:
				virtual enlapsed_type	launch_test() {
					random_type		rand_generator;
					rand_generator.init_random_collection();
					time_point		begin_org = clock_type::now();
					_tests<vector_original>(_create_file("std"), rand_generator.generate(), rand_generator.generate / 2);
					enlapsed_type	time_org = duration_type(begin_org - clock_type::now()).count(); 

					time_point		begin_cust = clock_type::now();
					_tests<vector_custom>(_create_file("std"), rand_generator.generate(), rand_generator.generate / 2);
					enlapsed_type	time_cust = duration_type(begin_cust - clock_type::now()).count(); 
					_velocity = time_org / time_cust;
				}
		};

	// template <typename Key, typename MappedType,
			 // typename KeyCompare, typename Alloc>
		 // class ACtBullet< std::map<Key, MappedType, KeyCompare, Alloc> >  : ft::ABullet {
			// public:
				// typedef		Key																key_type;
				// typedef		MappedType														mapped_type;
				// typedef		std::pair<const key_type,mapped_type>							value_type;
				// typedef		KeyCompare														key_compare;
				// typedef		Alloc															allocator_type;
				// typedef		std::map<key_type, mapped_type, key_compare, allocator_type>	map_original;
				// typedef		ft::map<key_type, mapped_type, key_compare, allocator_type>		map_custom;
				// typedef		ft::Random<mapped_type>											random_type;
//
			// private:
				// template <typename Ct>
				// void	_tests(file_type os, mapped_type random_value, mapped_type replacement);
//
			// protected:
				// virtual file_type		_create_file(const file_name_type &impl_id) {
					// _name.append("_vector_" + impl_id);
					// _stream = new std::ofstream(_path + _name);
					// if (_stream->is_open() == false)
						// throw (ft::ABullet::FailedToOpenFileException(_name));
					// return _stream;
				// }
//
			// public:
				// virtual enlapsed_type	launch_test() {
					// random_type		rand_generator;
					// rand_generator.init_random_collection();
					// time_point		begin_org = clock_type::now();
					// _tests<map_original>(_create_file("std"), rand_generator.generate(), rand_generator.generate / 2);
					// enlapsed_type	time_org = duration_type(begin_org - clock_type::now()).count();
//
					// time_point		begin_cust = clock_type::now();
					// _tests<map_custom>(_create_file("std"), rand_generator.generate(), rand_generator.generate / 2);
					// enlapsed_type	time_cust = duration_type(begin_cust - clock_type::now()).count();
					// _velocity = time_org / time_cust;
				// }
		// };
//
	// template <typename T, typename Ct>
		// class ACtBullet< std::stack<T, Ct> >  : ft::ABullet {
		// };
//
	// template< class Key, class Compare, class Allocator>
		// class ACtBullet< class std::set<Key, Compare, Allocator> >  : ft::ABullet {
		// };

}

#endif
