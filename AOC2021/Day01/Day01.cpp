#include "Day01.h"

using namespace aoc::days;

void Day01::setInput(std::vector<std::string> input) {
	for (int i = 0; i < input.size(); i++)
	{
		std::string str = input[i];
		day_input.push_back(std::stoi(str));
	}
}

std::string Day01::solvePart1() {
	int last_number = -1;
	int counter = 0;

	for (int num = 0; num < day_input.size(); num++)
	{
		int i = day_input[num];
		if (last_number == -1) {
			last_number = i;
			continue;
		}

		if (last_number < i) {
			counter++;
		}
		last_number = i;
	}

	return std::to_string(counter);
}

std::string Day01::solvePart2() {

	int last_number = -1;
	int counter = 0;
	for (int i = 0; i < day_input.size() - 2; i++) {
		int current_number = day_input[i] + day_input[i + 1] + day_input[i + 2];

		if (last_number != -1)
		{
			if (current_number > last_number)
			{
				counter++;
			}
			last_number = current_number;
		}
		else
		{
			last_number = current_number;
		}
	}

	return std::to_string(counter);
}
