#include "problem.h"
namespace my_tank {
	problem::problem(const std::vector<int>& map_size, const std::vector<std::vector<int>>& tank_position) {
		check_formation(tank_position);
		m_dimension_size = map_size.size();
		m_tank_size = tank_position.size();
		m_map = map_size;
		m_enemy_formation.set_formation(tank_position);
	}

	//TODO:maybe the complexity can be reduced
	bool problem::check_formation(const std::vector<std::vector<int>>& tank_position) {
		for (size_t i = 0; i < m_enemy_formation.tanks().size(); i++) {
			for (size_t j = 0; j < m_enemy_formation.tanks().size() + 1; j++) {
				if (m_enemy_formation[i].position() == m_enemy_formation[j].position()) {
					throw my_except("there are two same enemy tank positions input@problem::check_formation");
					return false;
				}
			}
			for (size_t j = 0; j < m_enemy_formation[i].position().size(); j++) {
				if (m_enemy_formation[i].position()[j]<0 || m_enemy_formation[i].position()[j]>m_map[j]) {
					throw my_except("enemy tank position out of range@problem::check_formation");
				}
			}
		}
		return true;
	}

	void problem::print() {
		if (m_dimension_size > 2) throw my_except("console can not print a problem which dimension larger than 2@problem::print()");
		for (size_t i = 0; i < m_map[1]; i++) {
			for (size_t j = 0; j < m_map[0]; j++) {
				std::cout << ". ";
				for (size_t k = 0; k < m_enemy_formation.tanks().size(); k++) {
					if ((m_enemy_formation[k])[0] == i&&m_enemy_formation[k][1] == j) {
						std::cout << "\b\b" << "* ";
						break;
					}
				}
			}
			std::cout << std::endl;
		}
	}

}
