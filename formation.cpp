#include "formation.h"

namespace my_tank {
	formation::formation(const std::vector<std::vector<int>> formation) {
		for (size_t i = 0; i < formation.size(); i++) {
			m_tanks[i].set_position(formation[i]);
		}
	}

	void formation::set_formation(const std::vector<std::vector<int>>& formation) {
		m_tanks.resize(formation.size());
		for (size_t i = 0; i < formation.size(); i++) {
			m_tanks[i].set_position(formation[i]);
		}
	}
}


