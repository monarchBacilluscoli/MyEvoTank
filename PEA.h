#ifndef PEA_H
#define PEA_H

#include<vector>
#include"formation.h"

namespace my_tank {

	class individual {
	public:
		individual();
		~individual();
		const formation& solution() {
			return m_formation;
		}
		void set_formation(const std::vector<std::vector<int>>& form) {
			m_formation.set_formation(form);
		}

	private:
		formation m_formation;
	};

	class PEA {
	public:
		PEA(int pop_size);
		~PEA();

		void initialization();
		double evaluate();
	private:
		std::vector<individual> best_pop;
		std::vector<std::vector<double>> m_probability_matrix; // the items show the quality of a position (x,y...)
		const int m_pop_size;
		const int m_max_gen;
		const int m_dimension_size;
		const int m_tank_size;
	};
}

#endif // !PEA_H



