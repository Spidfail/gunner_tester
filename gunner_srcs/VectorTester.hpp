/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VectorTester.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guhernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 11:17:28 by guhernan          #+#    #+#             */
/*   Updated: 2022/02/11 00:34:20 by guhernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_HPP
# define MAIN_HPP

#include <string>
#include <memory>
#include <chrono>
#include <fstream>
#include <map>
#include <iostream>

#include <filesystem>

#include <algorithm>
#include <vector>

#include <cstdlib>
#include <time.h>

#include <ft_random.hpp>
#include <Vector.hpp>

#include <VectorConstructorTests.hpp>
#include <VectorCapacityTests.hpp>
#include <VectorAccessorsTests.hpp>
#include <VectorModifiersTests.hpp>
#include <VectorIteratorsTests.hpp>

#include <IsStd.hpp>

template < typename T = int, class Allocator = std::allocator<T> >
class VectorTester {

	public:
		typedef		std::size_t											size_type;
		typedef		typename std::ofstream	*							type_file;
		typedef		typename std::map< std::string, type_file>			type_f_map;
		typedef		typename std::map< std::string, std::string >		type_fnames_map;

		typedef		typename type_f_map::iterator						iterator_files;
		typedef		typename type_fnames_map::iterator					iterator_files_names;

		typedef		double												type_enlapsed;
		typedef		std::chrono::duration<double, std::milli>			type_duration;
		typedef		std::chrono::steady_clock::time_point				time_point;
		typedef		typename std::map< std::string, type_enlapsed >		type_exec_time;
		typedef		typename type_exec_time::iterator					iterator_exec_time;






		typedef		typename std::vector< T, Allocator >		vector_original;
		typedef		typename ft::vector< T, Allocator >			vector_custom;
		typedef		T											type_value;

		typedef		ft::UnitestConstructor<vector_custom, std::ofstream, type_value>	constructor_custom;
		typedef		ft::UnitestConstructor<vector_original, std::ofstream, type_value>	constructor_original;
		typedef		ft::UnitestCapacity<vector_custom, std::ofstream, type_value>		capacity_custom;
		typedef		ft::UnitestCapacity<vector_original, std::ofstream, type_value>		capacity_original;
		typedef		ft::UnitestAccessors<vector_custom, std::ofstream, type_value>		accessors_custom;
		typedef		ft::UnitestAccessors<vector_original, std::ofstream, type_value>	accessors_original;
		typedef		ft::UnitestModifiers<vector_custom, std::ofstream, type_value>		modifiers_custom;
		typedef		ft::UnitestModifiers<vector_original, std::ofstream, type_value>	modifiers_original;
		typedef		ft::UnitestIterators<vector_custom, std::ofstream, type_value>		iterators_custom;
		typedef		ft::UnitestIterators<vector_original, std::ofstream, type_value>	iterators_original;
		////////////////////////////////////////////////////////////////////////////////////////////////
		/////////////////////////////NESTED CLASSES FOLDER//////////////////////////////////////////////

		class Folder {

			private:
				Folder() : _files(), _files_names(), _container_name(), _end_id(), _turn_in_directory() { }

			protected:
				type_f_map			_files;
				type_fnames_map		_files_names;
				std::string			_container_name;
				std::string			_end_id;
				std::string			_turn_in_directory;

			public:
				///////////////////////////////////////CONSTRUCTORS////////////////////////////////////////////////
				//
				Folder(const Folder &source)
					: _files(source._files), _files_names(source._files_names),
					_container_name(source._container_name), _end_id(source._end_id),
					_turn_in_directory(source._turn_in_directory) { }

				Folder(const std::string &container_name, const std::string &end_id)
					: _files(), _files_names(), _container_name(container_name), _end_id(end_id),
					_turn_in_directory("./gunner_results/") { }

				Folder(const std::string &container_name, const std::string &end_id,
						const std::string &dir_path)
					: _files(), _files_names(), _container_name(container_name), _end_id(end_id),
					_turn_in_directory(dir_path) { }

				virtual ~Folder() {
					for (iterator_files it = _files.begin() ; it != _files.end() ; it++) {
						it->second->close();
						delete it->second;
					}
				}

				///////////////////////////////////////INITIALISATION//////////////////////////////////////////////
				//
				virtual Folder		&_init_folder() {
					this->_files_names["constructor"]=_container_name + "_constructor_results_";
					this->_files_names["accessors"]=_container_name + "_accessors_results_";
					this->_files_names["iterators"]=_container_name + "_iterators_results_";
					this->_files_names["capacity"]=_container_name + "_capacity_results_";
					this->_files_names["modifiers"]=_container_name + "_modifiers_results_";

					// Test if the file exists
					// If true : increment the end_id then try with bigger number
					// Repeat until the file id does doesn't exists
					// // (can be changed)
					for (iterator_files_names it = this->_files_names.begin() ;
							it != this->_files_names.end() ; it++) {
						std::string		test_filename = it->second
							+ _end_id + std::to_string(0);

						std::ifstream	test_file(this->_turn_in_directory + test_filename);

						for (int end_id = 0 ; test_file.is_open() ; ++end_id) {
							test_file.close();
							test_filename = it->second;
							test_filename.append(_end_id + std::to_string(end_id));
							test_file.open(this->_turn_in_directory + test_filename);
						}
						it->second = test_filename;

						this->_files[it->first]= new std::ofstream(this->_turn_in_directory + it->second);
					}
					return *this;
				}

				///////////////////////////////////////OPERATORS///////////////////////////////////////////////////
				//
				Folder	&operator=(const Folder &source) {
					this->_files = source._files;
					this->_files = source._files;
					this->_files_names = source._files_names;
					this->_files_names = source._files_names;
					return *this;
				}

				///////////////////////////////////////ACCESSORS///////////////////////////////////////////////////
				//
				Folder					*get_data() { return this; }
				std::string				get_file_name(const std::string &key) { return _files_names[key]; }
				type_file				get_file(const std::string &key) { return _files[key]; }
				std::string				get_directory_name() { return this->_turn_in_directory; }
				std::string				&get_end_id() { return this->_end_id; }

				///////////////////////////////////////ITERATORS///////////////////////////////////////////////////
				//
				iterator_files			begin_files() { return this->_files.begin(); }
				iterator_files_names	begin_files_names() { return this->_files_names.begin(); }
				iterator_files			end_files() { return this->_files.end(); }
				iterator_files_names	end_files_names() { return this->_files_names.end(); }
				///////////////////////////////////////////////////////////////////////////////////////////////////
			};
		typedef		Folder				type_folder;

	protected:
			int					_test_nb;
			type_exec_time		_exec_time;
			short int			_folder_nb;
			Folder				*_folder_std;
			Folder				*_folder_ft;

		void		_init_files(std::string container_name = "vector", std::string dir_path = "./gunner_results/") {
			this->_folder_std = new type_folder(container_name, "std", dir_path + "details_std/");
			this->_folder_ft = new type_folder(container_name, "ft", dir_path + "details_ft/");
			this->_folder_std->_init_folder();
			this->_folder_ft->_init_folder();
		}

		void		_init_exec_time() {
			for (iterator_files_names	it = _folder_ft->begin_files_names() ;
					it != _folder_ft->end_files_names(); it++) {
				std::pair< std::string, type_enlapsed >		pair_exec_time(it->first, type_enlapsed());
				this->_exec_time.insert(pair_exec_time);
			}
		}

	public:
		VectorTester() { std::cout << std::boolalpha; }

		VectorTester(const VectorTester &source) { *this = source; }

		VectorTester		&operator=(const VectorTester &source) {
			this->_test_nb = source._test_nb;
			this->_files_org = source._files_org;
			this->_files_cust = source._files_cust;
			this->_files_names_org = source._files_names_org;
			this->_files_names_cust = source._files_names_cust;
			this->_exec_time = source._exec_time;
			this->_turn_in_directory = source._turn_in_directory;
			return *this;
		}

		virtual ~VectorTester() {
			delete this->_folder_std;
			delete this->_folder_ft;
		}

		////////////////////////////////////////////////////////////////////////////////////
		//////////////////////////////////////INITIALISATION////////////////////////////////
		//
		void		init() {
			_init_files();
			_init_exec_time();
		}

		void	store_time(const std::string &file_name, const type_enlapsed &std, const type_enlapsed &ft) {
			get_exec_time(file_name) =  std / ft;
		}

		////////////////////////////////////////////////////////////////////////////////////
		//////////////////////////////////////GETTERS///////////////////////////////////////
		//
		int									get_test_nb() { return this->_test_nb; }

		type_folder							&get_folder_std() { return *this->_folder_std; }
		type_folder							&get_folder_ft() { return *this->_folder_ft; }

		type_exec_time						&get_exec_time() { return this->_exec_time; }
		type_enlapsed						&get_exec_time(const std::string &key) { return this->_exec_time[key]; }

		void								get_status() {
			{
				iterator_files_names	it = get_folder_std().begin_files_names();
				iterator_files			it2 = get_folder_std().begin_files();
				iterator_exec_time		it3 = get_exec_time().begin();

				while (it != get_folder_std().end_files_names() && it2 != get_folder_std().end_files()
						&& it3 != get_exec_time().end()) {
					std::cout << "	" << it->second;
					std::cout << "	||	IS_OPEN   " << it2->second->is_open();
					std::cout << "	||	EXEC_TIME   " << it3->second << std::endl;
					++it;
				}
				std::cout << " Number of tests passed : " << _test_nb << std::endl;
			} {
				iterator_files_names	it = get_folder_ft().begin_files_names();
				iterator_files			it2 = get_folder_ft().begin_files();
				iterator_exec_time		it3 = get_exec_time().begin();

				while (it != get_folder_ft().end_files_names() && it2 != get_folder_ft().end_files()
						&& it3 != get_exec_time().end()) {
					std::cout << "	" << it->second;
					std::cout << "	||	IS_OPEN   " << it2->second->is_open();
					std::cout << "	||	EXEC_TIME   " << it3->second << std::endl;
					++it;
				}
				std::cout << " Number of tests passed : " << _test_nb << std::endl;
			}
		}
	//////////////////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////TESTS///////////////////////////////////////////////

		////////////////////////////////////////////////////////////////////////////////////
		//////////////////////////////////////CONSTRUCTORS//////////////////////////////////
		//
		void		launch_constructor() {
			ft::Random<type_value>	random;
			type_value		random_value = random.generate(type_value());
			type_value		replacement = random.generate(type_value()) / 2;
			char			fname[] = "constructor";

			type_enlapsed	duration_std;
			type_enlapsed	duration_ft;
			{
				type_file		os_ft = this->get_folder_ft().get_file(fname);
				std::chrono::steady_clock::time_point		begin = std::chrono::high_resolution_clock::now();
				constructor_custom::vector_fill(*os_ft, random_value);
				constructor_custom::vector_range(*os_ft, random_value);
				constructor_custom::operator_assignation(*os_ft, random_value);
				constructor_custom::operator_comparison(*os_ft, random_value, replacement);
				duration_ft = type_duration(begin - std::chrono::high_resolution_clock::now()).count();
			} {
				type_file		os_std = this->get_folder_std().get_file(fname);
				std::chrono::steady_clock::time_point		begin = std::chrono::high_resolution_clock::now();
				constructor_original::vector_fill(*os_std, random_value);
				constructor_original::vector_range(*os_std, random_value);
				constructor_original::operator_assignation(*os_std, random_value);
				constructor_original::operator_comparison(*os_std, random_value, replacement);
				duration_std = type_duration(begin - std::chrono::high_resolution_clock::now()).count();
			}
			store_time(fname, duration_std, duration_ft);
		}

		////////////////////////////////////////////////////////////////////////////////////
		//////////////////////////////////////CAPACITY//////////////////////////////////////
		//
		void				launch_capacity() {
			ft::Random<type_value>	random;
			type_value		random_value = random.generate(type_value());
			char			fname[] = "capacity";

			type_enlapsed	duration_std;
			type_enlapsed	duration_ft;
			{
				type_file		os_ft = this->get_folder_ft().get_file(fname);
				std::chrono::steady_clock::time_point		begin = std::chrono::high_resolution_clock::now();
				capacity_custom::size(*os_ft, random_value);
				capacity_custom::max_size(*os_ft);
				capacity_custom::empty(*os_ft, random_value);
				capacity_custom::capacity(*os_ft, random_value);
				capacity_custom::reserve(*os_ft, random_value);
				duration_ft = type_duration(begin - std::chrono::high_resolution_clock::now()).count();
			} {
				type_file		os_std = this->get_folder_std().get_file(fname);
				std::chrono::steady_clock::time_point		begin = std::chrono::high_resolution_clock::now();
				capacity_original::size(*os_std, random_value);
				capacity_original::max_size(*os_std);
				capacity_original::empty(*os_std, random_value);
				capacity_original::capacity(*os_std, random_value);
				capacity_original::reserve(*os_std, random_value);
				duration_std = type_duration(begin - std::chrono::high_resolution_clock::now()).count();
			}
			store_time(fname, duration_std, duration_ft);
		}

		////////////////////////////////////////////////////////////////////////////////////
		//////////////////////////////////////ACCESSORS/////////////////////////////////////
		//
		void				launch_accessors() {
			ft::Random<type_value>	random;
			type_value		random_value = random.generate(type_value());
			char			fname[] = "accessors";

			type_enlapsed	duration_std;
			type_enlapsed	duration_ft;
			{
				type_file		os_ft = get_folder_ft().get_file(fname);
				std::chrono::steady_clock::time_point		begin = std::chrono::high_resolution_clock::now();
				accessors_custom::front(*os_ft, random_value);
				accessors_custom::at(*os_ft, random_value);
				accessors_custom::operator_bracket(*os_ft, random_value);
				duration_ft = type_duration(begin - std::chrono::high_resolution_clock::now()).count();
			} {
				type_file		os_std = get_folder_std().get_file(fname);
				std::chrono::steady_clock::time_point		begin = std::chrono::high_resolution_clock::now();
				accessors_original::front(*os_std, random_value);
				accessors_original::at(*os_std, random_value);
				accessors_original::operator_bracket(*os_std, random_value);
				duration_std = type_duration(begin - std::chrono::high_resolution_clock::now()).count();
			}
			store_time(fname, duration_std, duration_ft);
		}

		////////////////////////////////////////////////////////////////////////////////////
		//////////////////////////////////////MODIFIERS/////////////////////////////////////
		//
		void				launch_modifiers() {
			ft::Random<type_value>	random;
			type_value		random_value = random.generate(type_value());
			type_value		replacement = random.generate(type_value()) / 2;
			char			fname[] = "modifiers";

			type_enlapsed	duration_std;
			type_enlapsed	duration_ft;
			{
				type_file		os_ft = get_folder_ft().get_file(fname);
				std::chrono::steady_clock::time_point		begin = std::chrono::high_resolution_clock::now();
				modifiers_custom::assign(*os_ft, random_value, replacement);
				modifiers_custom::clear(*os_ft, random_value, replacement);
				modifiers_custom::insert(*os_ft, random_value, replacement);
				modifiers_custom::push_back(*os_ft, random_value, replacement);
				modifiers_custom::pop_back(*os_ft, random_value, replacement);
				modifiers_custom::swap(*os_ft, random_value, replacement);
				modifiers_custom::erase(*os_ft, random_value, replacement);
				modifiers_custom::resize(*os_ft, random_value, replacement);
				duration_ft = type_duration(begin - std::chrono::high_resolution_clock::now()).count();
			}
			{
				type_file		os_std = get_folder_std().get_file(fname);
				std::chrono::steady_clock::time_point		begin = std::chrono::high_resolution_clock::now();
				modifiers_original::assign(*os_std, random_value, replacement);
				modifiers_original::clear(*os_std, random_value, replacement);
				modifiers_original::insert(*os_std, random_value, replacement);
				modifiers_original::push_back(*os_std, random_value, replacement);
				modifiers_original::pop_back(*os_std, random_value, replacement);
				modifiers_original::swap(*os_std, random_value, replacement);
				modifiers_original::erase(*os_std, random_value, replacement);
				modifiers_original::resize(*os_std, random_value, replacement);
				duration_std = type_duration(begin - std::chrono::high_resolution_clock::now()).count();
			}
			store_time(fname, duration_std, duration_ft);
		}

		////////////////////////////////////////////////////////////////////////////////////
		//////////////////////////////////////ITERATORS/////////////////////////////////////
		//
		void				launch_iterators() {
			ft::Random<type_value>	random;
			type_value		random_value = random.generate(type_value());
			type_value		replacement = random.generate(type_value()) / 2;
			char			fname[] = "iterators";

			type_enlapsed	duration_std;
			type_enlapsed	duration_ft;
			{
				type_file		os_ft = get_folder_ft().get_file(fname);
				std::chrono::steady_clock::time_point		begin = std::chrono::high_resolution_clock::now();
				iterators_custom::constructors(*os_ft, random_value, replacement);
				iterators_custom::accessors(*os_ft, random_value, replacement);
				iterators_custom::increment_decrement(*os_ft, random_value, replacement);
				iterators_custom::comparison(*os_ft, random_value, replacement);
				iterators_custom::arithmetic(*os_ft, random_value, replacement);
				iterators_custom::assignation(*os_ft, random_value, replacement);
				iterators_custom::methods(*os_ft, random_value, replacement);
				duration_ft = type_duration(begin - std::chrono::high_resolution_clock::now()).count();
			}
			{
				type_file		os_std = get_folder_std().get_file(fname);
				std::chrono::steady_clock::time_point		begin = std::chrono::high_resolution_clock::now();
				iterators_original::constructors(*os_std, random_value, replacement);
				iterators_original::accessors(*os_std, random_value, replacement);
				iterators_original::increment_decrement(*os_std, random_value, replacement);
				iterators_original::comparison(*os_std, random_value, replacement);
				iterators_original::arithmetic(*os_std, random_value, replacement);
				iterators_original::assignation(*os_std, random_value, replacement);
				iterators_original::methods(*os_std, random_value, replacement);
				duration_std = type_duration(begin - std::chrono::high_resolution_clock::now()).count();
			}
			store_time(fname, duration_std, duration_ft);
		}
};
////////////////////////////////////////////////////////////////////////////////////////////
//

#endif
