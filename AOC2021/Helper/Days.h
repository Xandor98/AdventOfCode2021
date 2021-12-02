#pragma ones

#include <vector>
#include <string>

namespace aoc {
	namespace days {

		class Days
		{
		private:
			std::vector<std::string> day_input;
		public:
			Days();
			virtual ~Days();

			virtual void setInput(std::vector<std::string> input);

			virtual std::string solvePart1() = 0;
			virtual std::string solvePart2() = 0;
		};
	}
}
