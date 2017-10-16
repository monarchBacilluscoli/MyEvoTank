#ifndef TANK_H
#define TANK_H

#include <vector>

namespace my_tank {
	class tank {
	public:
		tank(const std::vector<int>& position) :m_position(position) {}
		tank() {}
		void set_position(const std::vector<int>& position) {
			m_position = position;
		}
		const std::vector<int>& position() {
			return m_position;
		}
		int& operator[](int index) {
			return m_position[index];
		}

	private:
		// TODO:fire_power and so on
		std::vector<int> m_position; // position in map
	};
}

#endif // !TANK_H
