#include "ConfigLoader.h"

using namespace aoc::helper;

Config::Config() {
	setPathToSettings();
	loadSettings();
}

Config::~Config()
{
	// Does not Work
	// saveSettings();
}

void Config::setPathToSettings()
{
	char documentDirStr[260];
	if (SUCCEEDED(SHGetFolderPath(NULL, CSIDL_MYDOCUMENTS, NULL, 0, documentDirStr))) {
		pathToSettings.append(documentDirStr);
		pathToSettings += + "\\";
	}
	else {
		pathToSettings = "";
		//WARNING No Path to Doc looking next to EXE
	}

	pathToSettings += "AOC2021\\settings.conf";
}

void Config::loadSettings()
{
	std::ifstream cFile(pathToSettings);
	if (cFile.good()) {
		if (cFile.is_open()) {
			std::string line;
			while (getline(cFile, line)) {
				line.erase(std::remove_if(line.begin(), line.end(), isspace), line.end());
				
				if (line[0] == '#' || line.empty())
					continue;

				auto delimiterPos = line.find("=");
				auto name = line.substr(0, delimiterPos);
				auto value = line.substr(delimiterPos + 1);
				configuration[name] = value;
			}
		}
		else {
			std::cout << "Coud not Read Config" << std::endl;
		}
	}
	else {
		std::cout << "NO CONFIG EXIST" << std::endl;
	}
}

void Config::saveSettings()
{
	std::ofstream cFile(pathToSettings);

	if (cFile.good()) {
		std::remove(pathToSettings.c_str());
	}

	cFile.open(pathToSettings);
	if (cFile.is_open()) {
		for (auto const& x : configuration)
		{
			cFile << x.first << "=" << x.second << std::endl;
		}
		cFile.close();
	}
}

std::string Config::get(std::string name)
{
	return configuration[name];
}

void Config::set(std::string name, std::string value)
{
	if (!settignExist(name)) {
		std::cout << "Key " << name << " does not exist " << std::endl;
	}
	else
	{
		configuration[name] = value;
	}
}

bool aoc::helper::Config::settignExist(std::string name)
{
	return configuration.find(name) != configuration.end();
}

