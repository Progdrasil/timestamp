#ifndef OPTIONS_H
#define OPTIONS_H

#include <functional>
#include <string>
#include <unordered_map>
#include <vector>

namespace timestamp {

	template <class R, class T>
	struct OptionDetails {
		std::string short;
		std::string long;
		std::string desc;
		std::function<R(T)> fp;
	};

	class Options {
		typedef std::unordered_map<std::string, OptionDetails> OptionMap;

		public:

			Options(std::string program, std::string description = "")
				: m_program(std::move(program))
				, m_description(std::move(description)) {}

			template<class R, class T>
			void add (
				const std::string& group,
				const std::string& short,
				const std::string& long,
				const std::string& desc,
				std::function<R(T)> fp
			);

			void parse(int& argc, char**& argv);

			std::vector<std::string> get_options();

		private:
			OptionMap m_options;
			std::string m_program;
			std::string m_description;
	};
}

#endif
