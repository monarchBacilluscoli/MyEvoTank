#ifndef UTILITY_H
#define UTILITY_H

namespace my_tank {
	static bool nonredundant_random_2d_points(int range_x, int range_y, int number, std::vector<std::pair<int, int>>& user) {
		if (number > range_x*range_y) {
			return false;
		}
		std::vector<std::pair<int, int>> all_points(range_y*range_x);
		for (size_t i = 0; i < range_y; i++) {
			for (size_t j = 0; j < range_x; j++) {
				all_points[i*range_x + j].first = i;
				all_points[i*range_x + j].second = j;
			}
		}
		std::random_device rd;
		std::mt19937 g(rd());
		std::random_shuffle(all_points.begin(), all_points.end());
		std::copy(all_points.begin(), all_points.begin() + number, user.begin());
		return true;
	}
}

#endif // !UTILITY_H

