#include "Gunner.hpp"

ft::Gunner::~Gunner(){ }
ft::Gunner::Gunner(const ft::Gunner::name_type &name) : _nickname(name) { }
ft::Gunner::Gunner(const ft::Gunner &source) : _nickname(source._nickname), _equipement(source._equipement) { }

ft::Gunner	ft::Gunner::operator=(const Gunner &source) {
	this->_nickname = source._nickname;
	this->_equipement = source._equipement;
	return *this;
}

ft::Gunner::name_type				ft::Gunner::get_nickname() { return this->_nickname; }
ft::Gunner::equipement_type			&ft::Gunner::get_equipement() { return this->_equipement; }

ft::Gunner::iterator				ft::Gunner::begin() { return this->_equipement.begin(); }
ft::Gunner::iterator				ft::Gunner::end(){ return this->_equipement.end(); }
ft::Gunner::const_iterator			ft::Gunner::begin() const{ return this->_equipement.begin(); }
ft::Gunner::const_iterator			ft::Gunner::end() const{ return this->_equipement.end(); }

ft::Gunner::enlapsed_type			ft::Gunner::fire_all() {
	for (ft::Gunner::iterator it = this->begin() ; it != this->end() ; it++)
		this->fire(it->second);
	return this->get_velocity_average();
}

ft::Gunner::enlapsed_type			ft::Gunner::fire(ft::Gun &weapon) {
	for (ft::Gun::cylinder_iterator it = weapon.begin() ; it != weapon.end() ; it++)
		(*it)->launch_test();
	return weapon.get_velocity_average();
}

ft::Gunner::enlapsed_type			ft::Gunner::fire(ft::Gunner::iterator first, ft::Gunner::iterator last){
	ft::Gunner::enlapsed_type	total_speed = 0;
	ft::Gunner::size_type		shot_number = 0;
	while (first != last) {
		this->fire(first->second);
		total_speed = first->second.get_velocity_average();
		shot_number++;
	}
	return total_speed / shot_number;
}
ft::Gunner::enlapsed_type			ft::Gunner::fire_bullet(gun_type &weapon, const name_type &bullet_name) {
	weapon.find_bullet(bullet_name)->launch_test();
	return weapon.find_bullet(bullet_name)->get_velocity();
}

ft::Gunner::enlapsed_type			ft::Gunner::fire_bullet(ft::Gunner::gun_type &weapon,
		ft::Gunner::cylinder_iterator begin, ft::Gunner::cylinder_iterator last) {
	if (weapon.begin() <= begin && begin < weapon.end() && weapon.begin() <= last)
		throw std::out_of_range("You are targetting the wrong bullets my friend.");
	while (begin != last)
		(*begin)->launch_test();
	return weapon.get_velocity_average();
}

ft::Gunner::enlapsed_type			ft::Gunner::get_velocity_average() const;
ft::Gunner::enlapsed_type			ft::Gunner::get_velocity_worst() const;
ft::Gunner::enlapsed_type			ft::Gunner::get_velocity_best() const;
