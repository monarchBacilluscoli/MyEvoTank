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
		~problem() = default;

		//TODO: check if the input position is valid
		bool check_formation(const std::vector<std::vector<int>>& tank_position);
		// print the map and enemy tanks
		void print();

		int dimension_size() const {
			return m_dimension_size;
		}
		int tank_size() const {
			return m_tank_size;
		}
		const std::vector<int>& map() const {
			return m_map;
		}

	private:
		// map parameters
		int m_dimension_size; //TODO:support higher dimensions in the future
		std::vector<int> m_map; // [0] is x range, [1] is y range 

		// individual parameters
		int m_tank_size;
		formation m_enemy_formation;
	};

}
#endif // !PROBLEM_H
