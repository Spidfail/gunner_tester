#include "Gun.hpp"

ft::Gun::Gun() { }

//////////////////////////////////////////////////////////////////////////////////////////////////////

ft::Gun::Gun(const Gun &source) : _data(source._data), _name(source._name) { }

ft::Gun						ft::Gun::operator=(const ft::Gun &source) {
	this->_data = source._data;
	this->_name = source._name;
	return *this;
}

ft::Gun::~Gun() {
	if (this->mag_size() < 1)
		return ;
	for (Gun::cylinder_iterator it = this->begin() ; it != this->end() ; it++) {
		delete *it;
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////

ft::Gun::Gun(gun_name_type name) : _name(name) { }
ft::Gun::Gun(gun_name_type name, ft::Gun::reference bullet) : _name(name) { this->push_back(bullet); }
ft::Gun::Gun(gun_name_type name, ft::Gun::cylinder_iterator begin, ft::Gun::cylinder_iterator end)
	: _name(name) { this->assign(begin, end); }

//////////////////////////////////////////////////////////////////////////////////////////////////////

ft::Gun::reference					ft::Gun::operator[](ft::Gun::size_type number) { return _data[number]; }
ft::Gun::reference					ft::Gun::at(ft::Gun::size_type number){ return _data.at(number); }
ft::Gun::cylinder_iterator			ft::Gun::begin() { return _data.begin(); }
ft::Gun::cylinder_iterator			ft::Gun::end() { return _data.end(); }
ft::Gun::cylinder_const_iterator	ft::Gun::begin() const { return _data.begin(); }
ft::Gun::cylinder_const_iterator	ft::Gun::end() const { return _data.end(); }

void								ft::Gun::push_back(ft::Gun::const_reference new_bullet) { _data.push_back(new_bullet); }
void						ft::Gun::pop_back(){ _data.pop_back(); }

ft::Gun::cylinder_iterator	ft::Gun::insert(ft::Gun::cylinder_iterator pos, ft::Gun::const_reference new_bullet) { 
	_data.insert(pos, new_bullet);
	return pos;
}
void						ft::Gun::resize(ft::Gun::size_type number){ _data.resize(number); }

//////////////////////////////////////////////////////////////////////////////////////////////////////

ft::Gun::size_type			ft::Gun::mag_size() const { return _data.size(); }
ft::Gun::size_type			ft::Gun::mag_capacity() const { return _data.capacity(); }
void						ft::Gun::clear_mag(){ _data.clear(); }
bool						ft::Gun::empty() const { return !_data.size(); }

//////////////////////////////////////////////////////////////////////////////////////////////////////
//
ft::Gun::reference			ft::Gun::find_bullet(const ft::Gun::name_type &bullet_name) {
	for (ft::Gun::cylinder_iterator it = this->begin() ; it != this->end() ; it++)
		if ((*it)->get_bullet_name() == bullet_name)
			return *it;
	return *this->end();
}

ft::Gun::enlapsed_type		ft::Gun::get_velocity_average() const {
	ft::Gun::enlapsed_type	all_vel = 0;
	for (ft::Gun::cylinder_const_iterator it = this->begin() ; it != this->end() ; it++)
		if ((*it)->get_velocity() != 0)
		all_vel += (*it)->get_velocity();
	if (all_vel != 0)
		return all_vel / this->mag_size();
	return 0;
}

ft::Gun::enlapsed_type		ft::Gun::get_velocity_worst() const {
	ft::Gun::enlapsed_type	all_vel = std::numeric_limits<ft::Gun::enlapsed_type>::min();
	for (ft::Gun::cylinder_const_iterator it = this->begin() ; it != this->end() ; it++)
		if ((*it)->get_velocity() != 0 && (*it)->get_velocity() > all_vel)
			all_vel = (*it)->get_velocity();
	return all_vel;
}

ft::Gun::enlapsed_type		ft::Gun::get_velocity_best() const {
	ft::Gun::enlapsed_type	all_vel = std::numeric_limits<double>::max();
	for (ft::Gun::cylinder_const_iterator it = this->begin() ; it != this->end() ; it++)
		if ((*it)->get_velocity() != 0 && (*it)->get_velocity() < all_vel)
			all_vel = (*it)->get_velocity();
	if (all_vel == std::numeric_limits<double>::max())
		return 0;
	return all_vel;
}

void						ft::Gun::get_status() const {
	for (ft::Gun::cylinder_const_iterator it = this->begin() ; it != this->end() ; it++)
		(*it)->get_status();
}
