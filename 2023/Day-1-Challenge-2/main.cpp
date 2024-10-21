#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>

int toNumber (std::string str) {
	if (str.length() == 1) return std::stoi(str);
	if (str == "one") return 1;
	if (str == "two") return 2;
	if (str == "three") return 3;
	if (str == "four") return 4;
	if (str.length() == 4) return 5;
	if (str.length() == 3) return 6;
	if (str == "seven") return 7;
	if (str.length() == 5) return 8;
	return 9;
}

int main () {
	int total = 0;
	int next;
	std::vector<std::string> matches;
	std::ifstream input("input.txt");
	std::smatch m;
	std::string line;
	std::string moddedLine;
	std::regex regexp("one|two|three|four|five|six|seven|eight|nine|[1-9]");
	if (input.is_open()) {
		while (std::getline(input, line)) {
			moddedLine = line;
			while (std::regex_search(moddedLine, m, regexp)) {
				matches.push_back(m.str());
				moddedLine.erase(0, m.position() + 1);
			}
			next = (toNumber(matches.front()) * 10 + toNumber(matches.back()));
			std::cout << "Total: " << total << " + " << next << " = ";
			total += next;
			std::cout << total << " From line: " << line << std::endl;
			matches.clear();
		}
		input.close();
	} else {
		std::cout << "Unable to open file." << std::endl;
	}
	return 0;
}
