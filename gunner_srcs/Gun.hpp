
#ifndef GUN_HPP
# define GUN_HPP

# include <vector>

# include "AUnitTest.hpp"

namespace ft {

	class Gun {
		public:
			typedef		ABullet::size_type						size_type;
			typedef		ABullet::bullet_type					bullet_type;
			typedef		ABullet::file_name_type					name_type;
			typedef		ABullet::enlapsed_type					enlapsed_type;

			typedef		std::vector<bullet_type*>				cylinder_type;
			typedef		cylinder_type::value_type				value_type;
			typedef		cylinder_type::reference				reference;
			typedef		cylinder_type::pointer					pointer;
			typedef		cylinder_type::const_pointer			const_pointer;
			typedef		cylinder_type::const_reference			const_reference;
			typedef		cylinder_type::iterator					cylinder_iterator;
			typedef		cylinder_type::const_iterator			cylinder_const_iterator;
			typedef		std::string								gun_name_type;

		private:
			Gun();
			cylinder_type		_data;
			gun_name_type		_name;

		public:
			Gun(const Gun &source);
			Gun		operator=(const Gun &source);
			virtual ~Gun();
			Gun(gun_name_type name);
			Gun(gun_name_type name, reference bullet);
			Gun(gun_name_type name, cylinder_iterator begin, cylinder_iterator end);

			reference				operator[](size_type number);
			reference				at(size_type number);

			cylinder_iterator		begin();
			cylinder_iterator		end();
			cylinder_const_iterator	begin() const;
			cylinder_const_iterator	end() const;

			void					push_back(const_reference new_bullet);
			void					pop_back();
			cylinder_iterator		insert(cylinder_iterator pos, const_reference new_bullet);

			template <class InputIterator>
			cylinder_iterator		insert(InputIterator begin, InputIterator end) { _data.insert(begin, end); }

			template <class InputIterator>
				void assign (InputIterator first, InputIterator last) { _data.assign(first, last); }

			void					resize(size_type number);
			size_type				mag_size() const;
			size_type				mag_capacity() const;
			void					clear_mag();
			bool					empty() const;

			reference				find_bullet(const name_type &);
			enlapsed_type			get_velocity_average() const;
			enlapsed_type			get_velocity_worst() const;
			enlapsed_type			get_velocity_best() const;
			void					get_status() const;
	};
}

#endif
