#include<iostream>
#include"PEA.h"
#include"problem.h"

int main() {
	// for test
	std::vector<int> map = { 11,18 };
	std::vector<std::vector<int>> tanks = { {5,4},{5,5},{5,6},{5,7},{5,8},{5,9},{5,10},{5,11},{5,12},{5,13} };
	my_tank::problem p(map, tanks);
	p.print();

	system("pause");
}