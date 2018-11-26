#include "timestamp/options.h"

namespace timestamp {
	Options::Options(int argc, char* argv[]) {

		std::vector<std::string> opts(argv, argv + argc);
		for (int i = 0; i < argc; i++) {
			if (opts[i].substr(0,2).compare("--") == 0) {
				m_options.push_back(opts[i].substr(2));
			}
			else if (opts[i].substr(0,1).compare("-") == 0) {
				for (size_t j = 1; j < opts[i].length(); j++) {
					m_options.push_back(opts[i].substr(j,1));
				}
			}
		}
	}

	std::vector<std::string> Options::get_options() {
		return m_options;
	}

}
