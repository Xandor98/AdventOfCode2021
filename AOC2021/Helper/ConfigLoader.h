#pragma ones

#include <fstream>
#include <map>
#include <windows.h>
#include <Shlobj.h>

#include <iostream>
#include <string>
#include <cstdio>

namespace aoc {
	namespace helper {

		
		class Config
		{
		public:
			static Config& getInstance() {
				static Config instance; // Guaranteed to be destroyed.
								  // Instantiated on first use.
				return instance;
			}
		private:

			std::string pathToSettings = "";
			std::map<std::string, std::string> configuration{};

			Config();
			~Config();

			void setPathToSettings();
			void loadSettings();
			void saveSettings();

		public:
			std::string get(std::string name);
			void set(std::string name, std::string value);
			bool settignExist(std::string name);

		};
	}
}