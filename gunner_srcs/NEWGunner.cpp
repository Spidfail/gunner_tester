
#include "NEWGunner.hpp"

int	main() {
	Gunner<int> silvester;
	silvester.add_bullet<BulletModifiers<int>> ("std::vector", "ft::vector");
	silvester.add_bullet<BulletIterators<int>> ("std::vector", "ft::vector");
	silvester.fire_all();
}

