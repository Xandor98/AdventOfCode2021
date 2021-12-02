// AOC2021.cpp: Definiert den Einstiegspunkt für die Anwendung.
//

#include "AOC2021.h"

using namespace std;
using namespace aoc::days;

int main()
{
	string line;
	ifstream myfile("C:/Users/cevvo/Workspace/AOC2021/AOC2021/resources/Day01_in.txt");
	
	std::vector<std::string> lines;

    if (myfile.is_open()) {
        while (getline(myfile, line))
        {
            lines.push_back(line);
        }
        myfile.close();
    }
    else cout << "Unable to open file";

    Day01 day{};

    day.setInput(lines);

    cout << "Part 1: " << day.solvePart1() << endl;
    cout << "Part 2: " << day.solvePart2() << endl;

	return 0;
}
