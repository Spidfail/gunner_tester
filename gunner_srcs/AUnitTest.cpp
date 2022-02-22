
#include "AUnitTest.hpp"

#ifndef AUNITTEST_CPP
#define AUNITTEST_CPP

ft::ABullet::ABullet(const ft::ABullet::file_name_type &path, const ft::ABullet::file_name_type &name) 
 : _path(path), _name(name), _stream(NULL), _velocity(0) { }

 void		ft::ABullet::get_status() {
	std::cout.width(20);
	std::cout << " NAME = " << _name;
	std::cout.width(3);
	std::cout << "		|| FILE STATUS = " << bool(_stream);
	std::cout.width(9);
	std::cout << "		|| VELOCITY = " << _velocity << std::endl;
 }

ft::ABullet::~ABullet() {
	_velocity = 0;
	_name.clear();
	_path.clear();
	_stream->close();
}

ft::ABullet::enlapsed_type			ft::ABullet::get_velocity() { return _velocity; }

ft::ABullet::file_reference			ft::ABullet::get_bullet() { return _stream; }

ft::ABullet::file_name_type			ft::ABullet::get_bullet_name() { return _name; }

ft::ABullet::FailedToOpenFileException::FailedToOpenFileException(const char *file_name)
	: _file_name(file_name) { }

const char* ft::ABullet::FailedToOpenFileException::what() const throw() {
	char	*rtn;
	rtn = NULL;
	std::strcat(rtn, _file_name);
	std::strcat(rtn, "failed to open or create file ");
	return rtn;
}

#endif
