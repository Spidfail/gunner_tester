
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
		virtual void operator() (std::ofstream &std_os, std::ofstream &ft_os) = 0;
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
		typedef 	std::ofstream										file_type;
		typedef 	std::ofstream&										file_reference;

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
				std::ofstream std_os (entry->std_filename);
				std::ofstream ft_os (entry->ft_filename);
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

template <typename T>
class BulletIterators : public ABullet {
	private:
		const BulletIterators	&operator=(const BulletIterators &) { return *this; }
		BulletIterators(const BulletIterators &) { }
	public:
		typedef 	typename Gunner<T>::file_type  		file_type;
		typedef 	typename Gunner<T>::file_reference	file_reference;
		BulletIterators() { }
		virtual ~BulletIterators() { }

		virtual void	operator() (file_reference std_file, file_reference ft_file) {
			ft::Random<T>	random_generator;
			random_generator.init_random_collection(T());
			T random1 = random_generator.generate(T());
			T random2 = random_generator.generate(T()) / 2;
			test<T>(std_file, random1, random2);
			test<T>(ft_file, random1, random2);
		}

		virtual void	operator() () {
			test<std::vector<T>>(file_reference("/dev/null"), 0, 0);
			test<std::vector<T>>(file_reference("/dev/null"), 0, 0); 							// PUT FT
		}

		template <class Ct>
			void	test(file_reference os, T random1, T random2) {
				(void)os;
				(void)random1;
				(void)random2;
				std::cout << " FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF " << std::endl;
			}
};

template <typename T>
class BulletModifiers : public ABullet {
	private:
		const BulletModifiers	&operator=(const BulletModifiers &) { return *this; }
		BulletModifiers(const BulletModifiers &) { }
	public:
		typedef 	typename Gunner<T>::file_type  		file_type;
		typedef 	typename Gunner<T>::file_reference	file_reference;
		BulletModifiers() { }
		virtual ~BulletModifiers() { }

		virtual void	operator() (file_reference std_file, file_reference ft_file) {
			ft::Random<T>	random_generator;
			random_generator.init_random_collection(T());
			T random1 = random_generator.generate(T());
			T random2 = random_generator.generate(T()) / 2;
			test<std::vector<T>>(std_file, random1, random2);
			test<std::vector<T>>(ft_file, random1, random2);									// PUT FT
		}

		virtual void	operator() () {
			test<std::vector<T>>(file_reference("/dev/null"), 0, 0);
			test<std::vector<T>>(file_reference("/dev/null"), 0, 0); 							// PUT FT
		}

		template <class Ct>
			void	test(file_reference os, T random1, T random2) {
				(void)os;
				(void)random1;
				(void)random2;
				std::cout << " LLLLLLLLLLLLLLLLLLLLLLOOOOOOOOOOOOOOOOOOOLLLLLLLLLLL " << std::endl;
			}
};


#endif
