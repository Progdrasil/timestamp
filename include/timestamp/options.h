#ifndef OPTIONS_H
#define OPTIONS_H

#include <string>
#include <vector>

namespace timestamp {
	class Options {
		public:
			Options(std::string program, std::string description = "")
				: m_program(std::move(program))
				, m_description(std::move(description)) {}
			std::vector<std::string> parse(int argc, char* argv[]);
			std::vector<std::string> get_options();
		private:
			std::vector<std::string> m_options;
			std::string m_program;
			std::string m_description;
	};
}

#endif
