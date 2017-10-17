#ifndef PEA_H
#define PEA_H

#include<vector>
#include"problem.h"
#include"formation.h"
#include<time.h> 
#include<random>
#include"utility.h"

namespace my_tank {

	class individual {
	public:
		individual();
		~individual() = default;
		formation& solution() {
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
		PEA(const problem & p, int pop_size, int max_gen);
		~PEA() = default;
		void run();

		// initialize the population randomly
		void initialization();
		double evaluate();
	private:
		std::vector<individual> m_best_pop;
		std::vector<std::vector<double>> m_probability_matrix; // the items show the quality of a position (x,y...)
		int m_pop_size;
		int m_max_gen;
		int m_dimension_size;
		int m_tank_size;
		const problem* m_problem;
	};
}

#endif // !PEA_H



