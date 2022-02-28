
#ifndef NEWGunner
# define NEWGunner

# include <vector>
# include <fstream>
# include <iostream>
# include "ft_random.hpp"

class ABullet {
	private:
		const ABullet	&operator=(const ABullet &) { return *this; }
	public:
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
			elapsed_type	total_time;
			elapsed_type	min_time;
			elapsed_type	max_time;
			name_type		std_filename;
			name_type		ft_filename;
			ABullet			*test;
		};
		std::vector<Gun_entry>	ammo;

	public:
		template<class BulletType>
			void add_bullet(name_const_reference std_filename, name_const_reference ft_filename) {
				Gun_entry	entry;
				entry.std_filename = std_filename;
				entry.ft_filename = ft_filename;
				entry.test = new BulletType;
				ammo.push_back(entry);
			}
		Gunner() { }
		Gunner(const Gunner &source);
		~Gunner() { }

		void fire_all ()
		{
			for (size_type i = 0; i < ammo.size (); ++i)
			{
				Gun_entry *entry = &ammo[i];
				entry->number_of_times_tested = 1000;
				std::filebuf	std_fbuff;
				std::filebuf	ft_fbuff;
				std_fbuff.open(entry->std_filename.c_str(), std::ios_base::out);
				ft_fbuff.open(entry->ft_filename.c_str(), std::ios_base::out);
				std::ostream 	std_os (&std_fbuff);
				std::ostream 	ft_os (&ft_fbuff);
				(*entry->test) (std_os, ft_os);

				for (size_type j = 0; j < entry->number_of_times_tested; ++j )
				{
					time_point start_time = clock_type::now();
					(*entry->test) ();
					time_point end_time = clock_type::now();
					elapsed_type span_time = duration_type(end_time - start_time).count();
					if (span_time < entry->min_time)
						entry->min_time = span_time;
					else if (span_time > entry->max_time)
						entry->max_time = span_time;
				}
			}
		}
};

#endif
