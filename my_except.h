#include<iostream>
#include<string>

namespace my_tank {
	class my_except {
	public:
		my_except(const std::string&& s) {
			std::cout << s << std::endl;
		}
	};
}

