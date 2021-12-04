// AOC2021.cpp: Definiert den Einstiegspunkt für die Anwendung.
//

#include "AOC2021.h"
#include "ConfigLoader.h"

using namespace std;
using namespace aoc::days;
using namespace aoc::helper;

int main()
{
	string line;

    Config &conf = Config::getInstance();

    if (!conf.settignExist("pathToResource")) {
        std::cout << "No Resource Setting Found" << std::endl;
        return 1;
    }

	ifstream myfile(conf.get("pathToResource") + "/Day01_in.txt");

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
