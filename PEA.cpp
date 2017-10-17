#include "PEA.h"

namespace my_tank {
	PEA::PEA(const problem & p, int pop_size = 100, int max_gen = 100):m_pop_size(pop_size), m_max_gen(max_gen), m_problem(&p){
		m_dimension_size = p.dimension_size();
		m_tank_size = p.tank_size();
	}
	void PEA::initialization() {
		std::random_device rd;
		std::mt19937 gen(rd());
		//std::vector<std::uniform_int_distribution<>> dimension_rand;
		//TODO: multithreading
		//generate nonredundant random points (x,y)
		std::vector<std::pair<int, int>> random_points(m_tank_size);
		if (!nonredundant_random_2d_points(m_problem->map()[0], m_problem->map[1], m_tank_size, random_points)) {
			throw my_except("tank size is larger than points number of map@PEA::initialization");
		}
		for (size_t i = 0; i < m_tank_size; i++) {
			m_best_pop[i].solution()[i][0] = random_points[i].first;
			m_best_pop[i].solution()[i][1] = random_points[i].second;
		}
	}
}

