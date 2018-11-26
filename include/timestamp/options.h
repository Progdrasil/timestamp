#ifndef OPTIONS_H
#define OPTIONS_H

#include <string>
#include <vector>

namespace timestamp {
	class Options {
		public:
			Options(int argc, char* argv[]);
			std::vector<std::string> get_options();
		private:
			std::vector<std::string> m_options;
	};
}

#endif
