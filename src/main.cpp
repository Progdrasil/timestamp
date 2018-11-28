#include <iostream>
#include <string>
#include <vector>
#include "timestamp/options.h"

using namespace std;

int main(int argc, char* argv[]) {
	const std::string name = "Time Stamp";
	const std::string desc = "Utility application to help categorize, log and focus on your work";

	timestamp::Options opt(name, desc);

	opt.parse(argc, argv);

	for (auto val : vec) {
		cout << "A option passed is : " << val << endl;
	}

	return 0;
}
