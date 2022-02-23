
#include "NEWGunner.hpp"

int	main() {
	Gunner<int> 	silvector_stalone;
	std::string		path("../tests/vector/");
	silvector_stalone.add_bullet<BulletModifiers<int>> (path + "std::vector", path + "ft::vector");
	silvector_stalone.add_bullet<BulletIterators<int>> ("std::vector", "ft::vector");
	silvector_stalone.fire_all();
}

