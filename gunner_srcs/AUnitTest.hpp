
#ifndef AUNITTEST_HPP
#define AUNITTEST_HPP

#include <string>
#include <ostream>
#include <fstream>
#include <exception>
#include <iostream>

namespace ft {

	class ABullet {

		public:
			typedef		size_t												size_type;
			typedef		typename std::ofstream	*							file_type;
			typedef		std::string											file_name_type;
			typedef		file_type&											file_reference;

			typedef		ABullet												bullet_type;
			typedef		bullet_type&										bullet_reference;
			typedef		bullet_type&										bullet_const_reference;

			typedef		double												enlapsed_type;
			typedef		std::chrono::duration<enlapsed_type, std::milli>	duration_type;
			typedef		std::chrono::steady_clock::time_point				time_point;
			typedef		std::chrono::high_resolution_clock					clock_type;

		private:
			ABullet();

		protected:
			file_name_type				_path;
			file_name_type				_name;
			file_type					_stream;
			enlapsed_type				_velocity;
			virtual file_type			_create_file(const file_name_type &impl_id) = 0;

		public:
			class FailedToOpenFileException : std::exception {
				FailedToOpenFileException();
				const char	*_file_name;
				public:
					FailedToOpenFileException(const char *file_name);
					virtual const char* what() const throw();
			};

			virtual ~ABullet();
			ABullet(const file_name_type &path, const file_name_type &name);
			ABullet(bullet_const_reference source);
			void						get_status();
			enlapsed_type				get_velocity();
			file_type					&get_bullet();
			file_name_type				get_bullet_name();
			virtual enlapsed_type		launch_test() = 0;
	};
}

#endif
