#ifndef PROBLEM_H
#define PROBLEM_H

#include"formation.h"
#include"my_except.h"
#include<utility>
namespace my_tank {
	class problem {
	public:
		// the unit_size and dimension_size is avblread known from vector
		problem(const std::vector<int>& map_size, const std::vector<std::vector<int>>& tank_position);
		~problem() {}

		//TODO: check if the input position is valid
		bool check_formation(const std::vector<std::vector<int>>& tank_position);
		// print the map and enemy tanks
		void print();

	private:
		// map parameters
		int m_dimension_size;
		std::vector<int> m_map; // size of map

								// individual parameters
		int m_tank_size;
		formation m_enemy_formation;
	};

}
#endif // !PROBLEM_H
