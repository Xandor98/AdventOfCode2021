#pragma once
#include "../Helper/Days.h"

namespace aoc {
	namespace days {
		class Day01 : public Days
		{
		private:
			std::vector<int> day_input;
		public:
			Day01() : Days(){};

			std::string solvePart1();
			std::string solvePart2();
			void setInput(std::vector<std::string> input);
		};
	}
}
