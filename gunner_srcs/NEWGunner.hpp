
#ifndef NEWGUNNER
# define NEWGUNNER

# include <vector>
# include <fstream>
# include <iostream>
# include "ft_random.hpp"
# include <limits>
# include <stdlib.h>
# include <sstream>

# include "PrintText.hpp"

class ABullet {
	private:
		const ABullet	&operator=(const ABullet &) { return *this; }
	protected:
		typedef 	double												elapsed_type;
		typedef		std::chrono::duration<elapsed_type, std::milli>		duration_type;
		typedef		std::chrono::steady_clock::time_point				time_point;
		typedef		std::chrono::high_resolution_clock					clock_type;

	public:
		elapsed_type	total_time;
		elapsed_type	min_diff_time;
		elapsed_type	max_diff_time;
		ABullet() { }
		virtual void operator() (std::ostream &std_os, std::ostream &ft_os) = 0;
		virtual void operator() () = 0;
		virtual ~ABullet() { }
};

template <typename T, typename Mapped = std::string>
class Gunner {
	public:
		typedef		T													value_type;
		typedef		Mapped												mapped_type;
		typedef 	size_t												size_type;
		typedef 	double												elapsed_type;
		typedef 	std::string											name_type;
		typedef 	std::string											name_const_reference;
		typedef 	std::ostream										file_type;
		typedef 	std::ostream&										file_reference;

		typedef		std::chrono::duration<elapsed_type, std::milli>		duration_type;
		typedef		std::chrono::steady_clock::time_point				time_point;
		typedef		std::chrono::high_resolution_clock					clock_type;

	private:
		struct Gun_entry {
			size_type		number_of_times_tested;
			name_type		std_filename;
			name_type		ft_filename;
			ABullet			*test;
		};
		typedef		Gun_entry											gun_type;
		typedef		std::vector<gun_type>								armoury_type;
		size_type	_number_of_times_tested;

		armoury_type	armoury;

	public:
		Gunner() { }
		Gunner(const Gunner &source) : armoury(source.armoury) { }
		~Gunner() {
			for (typename armoury_type::iterator	it = armoury.begin();
					it != armoury.end() ; it++)
				delete it->test;
		}

		template<class BulletType>
			void add_bullet(name_const_reference std_filename, name_const_reference ft_filename) {
				gun_type	entry;
				entry.std_filename = std_filename;
				entry.ft_filename = ft_filename;
				entry.test = new BulletType;
				armoury.push_back(entry);
			}

		void	get_bench() {
			print::PrintText<std::string>	title(std::clog, print::WHITE, print::B_RED, print::BOLD);
			print::PrintText<std::string>	file_name(std::clog, print::YELLOW, print::B_BLACK, print::UNDERLINE);
			print::PrintText<std::string>	path_name(std::clog, print::MAGENTA, print::B_BLACK, print::BOLD);
			print::PrintText<std::string>	okay_time(std::clog, print::GREEN, print::B_BLACK, print::BOLD);
			print::PrintText<std::string>	wrong_time(std::clog, print::RED, print::B_BLACK, print::BOLD);
			print::PrintText<std::string>	total_time(std::clog, print::BLUE, print::B_BLACK, print::BOLD);

			std::clog << std::endl << std::endl;
			std::clog << " NUMBER OF TIME TESTER : ";
			title(std::to_string(this->_number_of_times_tested));
			std::clog << std::endl << std::endl;
			for (typename armoury_type::iterator it = armoury.begin() ;
					it != armoury.end() ; ++it) {
				std::string		filename_str = it->std_filename;
				filename_str.erase(0, filename_str.find_last_of("/") + 1);
				std::clog << "	";
				file_name(filename_str);
				std::clog << std::endl;

				std::clog << std::endl;
				std::clog << "TIME MIN = ";
				if (it->test->min_diff_time >= 20.0)
					wrong_time(std::to_string(it->test->min_diff_time));
				else
					okay_time(std::to_string(it->test->min_diff_time));
				std::clog << std::endl;
				std::clog << "TIME MAX = ";
				if (it->test->max_diff_time >= 20.0)
					wrong_time(std::to_string(it->test->max_diff_time));
				else
					okay_time(std::to_string(it->test->max_diff_time));
				std::clog << std::endl;
				std::clog << "TIME TOTAL = "; total_time(std::to_string(it->test->total_time));
				std::clog << std::endl;
				std::string		path_str = it->std_filename;
				path_str.erase(path_str.find_last_of("/"), path_str.size());
				std::clog << "Path : "; path_name(path_str);
				std::clog << std::endl << std::endl << std::endl;
			}
		}

		void	fire_bench(const size_type &number_of_times_tested) {
			print::PrintText<std::string>	loading(std::clog, print::BLACK, print::B_BLUE, print::BOLD);
			_number_of_times_tested = number_of_times_tested;
			for (typename armoury_type::iterator it = armoury.begin() ;
					it != armoury.end() ; ++it) {
				std::clog << " ";
				gun_type	*entry = &(*it);
				it->number_of_times_tested = number_of_times_tested;

				it->test->total_time = 0;
				for (size_type i = 0; i < _number_of_times_tested ; ++i) {
					(*entry->test) ();
					if (i == (_number_of_times_tested / 2))
					loading("	");
				}
				loading("	");
			}
		}

		void fire () {
			for (size_type i = 0; i < armoury.size (); ++i)
			{
				gun_type *entry = &armoury[i];
				entry->number_of_times_tested = 1000;
				std::filebuf	std_fbuff;
				std::filebuf	ft_fbuff;
				std_fbuff.open(entry->std_filename.c_str(), std::ios_base::out);
				ft_fbuff.open(entry->ft_filename.c_str(), std::ios_base::out);
				std::ostream 	std_os (&std_fbuff);
				std::ostream 	ft_os (&ft_fbuff);
				(*entry->test) (std_os, ft_os);
				std_fbuff.close();
				ft_fbuff.close();
			}
		}

};


#endif
