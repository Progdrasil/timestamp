#include <iostream>
#include <string>
#include <vector>
#include "timestamp/options.h"

using namespace std;

int main(int argc, char* argv[]) {

	timestamp::Options opt(argc, argv);

	vector<string> vec = opt.get_options();

	for (auto val : vec) {
		cout << "A option passed is : " << val << endl;
	}

	return 0;
}
