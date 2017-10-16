#ifndef FORMATION_H
#define FORMATION_H

#include<vector>
#include"tank.h"


namespace my_tank {
	class formation {
	public:
		formation() = default;
		formation(const std::vector<std::vector<int>> formation);
		// TODO:use tank_size and dimension_size to initialize a formation randomly
		formation(int tank_size, int dimension_size) {}

		void set_formation(const std::vector<std::vector<int>>& formation);
		const std::vector<tank>& tanks() {
			return m_tanks;
		}
		tank& operator[](int index) {
			return m_tanks[index];
		}

		~formation() = default;
		
	private:
		std::vector<tank> m_tanks;
	};
}

#endif // !FORMATION_H