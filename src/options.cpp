#include "timestamp/options.h"

namespace timestamp {

	template <class R, class T>
	void add (
		const std::string& group,
		const std::string& short,
		const std::string& long,
		std::string desc,
		std::function<R(T)> fp
	){
		OptionDetails details = {
			short,
			long,
			desc,
			fp,
		};

		auto in_s = m_options.emplace(short, details);
		auto in_l = m_options.emplace(long, details);

		if (!in_s || !in_l) {
			throw "Option already exists error!";
		}
	}

	void Options::parse(int &argc, char**& argv) {

		std::vector<std::string> opts(argv, argv + argc);
		for (int i = 0; i < argc; i++) {
			if (opts[i].compare("--") == 0) {
				break;
			}
			else if (opts[i].substr(0,2).compare("--") == 0) {
				try {
					m_options[opts[i].substr(2)].fp(opts[i + 1]);
				}
				catch (...) {
					// TODO: do something here
				}
			}
			else if (opts[i].substr(0,1).compare("-") == 0) {
				for (size_t j = 1; j < opts[i].length(); j++) {
					try {
						m_options[opts[i].substr(j,1)].fp(opts[i + 1]);
					}
					catch (...) {
						// TODO: do something here
					}
				}
			}
		}

		return m_options;
	}

	std::vector<std::string> Options::get_options() {
		return m_options;
	}

}
