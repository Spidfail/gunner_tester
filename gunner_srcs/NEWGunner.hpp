
#ifndef NEWGunner
# define NEWGunner

# include <vector>
# include <fstream>
# include <iostream>
# include "ft_random.hpp"
# include <limits>

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

template <typename T>
class Gunner {
	public:
		typedef		T													value_type;
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
			std::clog << "============NUMBER OF TIME TESTER============" << this->_number_of_times_tested << std::endl;
			for (typename armoury_type::iterator it = armoury.begin() ;
					it != armoury.end() ; ++it) {
				std::clog << " FILE NAME = [std : " << it->std_filename << "] [ft : " << it->ft_filename << "]" << std::endl;
				std::clog << "	TIME MIN = " << it->test->min_diff_time << std::endl;
				std::clog << "	TIME MAX = " << it->test->max_diff_time << std::endl;
				std::clog << "	TIME TOTAL = " << it->test->total_time << std::endl;
			}
		}

		void	fire_bench(const size_type &number_of_times_tested) {
			_number_of_times_tested = number_of_times_tested;
			for (typename armoury_type::iterator it = armoury.begin() ;
					it != armoury.end() ; ++it) {
				gun_type	*entry = &(*it);
				it->number_of_times_tested = number_of_times_tested;

				it->test->total_time = 0;
				for (size_type i = 0; i < _number_of_times_tested ; ++i) {
					(*entry->test) ();
				}
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
			}
		}
};

#endif
