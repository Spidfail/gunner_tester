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

ft::Gunner::enlapsed_type			ft::Gunner::get_velocity_average() const {
	if (_equipement.size() == 0)
		return 0;
	ft::Gunner::enlapsed_type	all_vel = 0;
	ft::Gunner::size_type		nb_velocity = 0;
	for (ft::Gunner::const_iterator it = this->begin() ; it != this->end() ; it++) {
		ft::Gunner::enlapsed_type	tmp_vel = it->second.get_velocity_average();
		if (tmp_vel != 0) {
			all_vel += tmp_vel;
			nb_velocity++;
		}
	}
	if (all_vel != 0)
		return all_vel / nb_velocity;
	return 0;
}

ft::Gunner::enlapsed_type			ft::Gunner::get_velocity_worst() const {
	if (_equipement.size() == 0)
		return 0;
	ft::Gunner::enlapsed_type	worst_vel = std::numeric_limits<ft::Gunner::enlapsed_type>::min();
	for (ft::Gunner::const_iterator it = this->begin() ; it != this->end() ; it++) {
		ft::Gunner::enlapsed_type	tmp_vel = it->second.get_velocity_worst();
		if (tmp_vel != 0 && tmp_vel > worst_vel)
			worst_vel = tmp_vel;
	}
	if (worst_vel == std::numeric_limits<ft::Gunner::enlapsed_type>::min())
		return 0;
	return worst_vel;
}

ft::Gunner::enlapsed_type			ft::Gunner::get_velocity_best() const {
	if (_equipement.size() == 0)
		return 0;
	ft::Gunner::enlapsed_type	best_vel = std::numeric_limits<ft::Gunner::enlapsed_type>::max();
	for (ft::Gunner::const_iterator it = this->begin() ; it != this->end() ; it++) {
		ft::Gunner::enlapsed_type	tmp_vel = it->second.get_velocity_best();
		if (tmp_vel != 0 && tmp_vel < best_vel)
			best_vel = tmp_vel;
	}
	if (best_vel == std::numeric_limits<ft::Gunner::enlapsed_type>::max())
		return 0;
	return best_vel;
}
