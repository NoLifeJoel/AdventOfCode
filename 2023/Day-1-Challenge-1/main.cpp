#include <iostream>
#include <fstream>
#include <string>

int isNumber (char c) {
	if (int(c) >= 48 && int(c) <= 57) {
		return int(c) - 48;
	}
	return -1;
}

int main () {
	int total = 0;
	int number;
	std::string line;
	std::ifstream input("input.txt");
	if (input.is_open()) {
		while (std::getline(input, line)) {
			for (int i = 0; i < line.length(); i++) {
				number = isNumber(line[i]);
				if (number != -1) break;
			}
			number *= 10;
			for (int i = line.length() - 1; i >= 0; i--) {
				if (isNumber(line[i]) != -1) {
					number += isNumber(line[i]);
					break;
				}
			}
			total += number;
		}
		std::cout << total << std::endl;
		input.close();
	} else {
		std::cout << "Unable to open file." << std::endl;
	}
	return 0;
}
