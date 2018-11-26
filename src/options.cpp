#include "timestamp/options.h"

namespace timestamp {
	Options::Options(int argc, char* argv[]) {
		for (int i = 1; i < argc && argv[i][0] == '-'; i++) {
			std::string temp(argv[i]);
			m_options.insert(m_options.end(), temp.begin() + 1 , temp.end());
		}
	}

	std::vector<std::string> Options::get_options() {
		return m_options;
	}

}
