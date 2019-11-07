#include <regex>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

void regex_test()
{
	vector<string> filenames;
	for (int i=0; i<100; i++) {
		stringstream ss;
		ss << "image-" << to_string(i) << ".bin";
		filenames.emplace_back(ss.str());
	}

	const regex re_index(".*-(\\d*)\\.bin");
	smatch index_match;

	for (string& s : filenames) {
		if (std::regex_match(s, index_match, re_index)) {
			// The first sub_match is the whole string; the next
			// sub_match is the first parenthesized expression.
			if (index_match.size() == 2) {
				std::ssub_match sub_match = index_match[1];
				int index = std::stoi(sub_match.str());
				cout << s << ", index = " << index << endl;
			}
		}
	}
}

/*
	src::severity_logger< severity_level > lg;

	BOOST_LOG_SEV(lg, debug) << __func__ << "():";
	for (tag_refresh_list::reference e : *refresh_list) {
		boost::filesystem::path path_name(e.tag_image_path);
		path_name /= e.tag_image_name;
		e.tag_image_size = (uint64_t)get_file_size(path_name.string());
		BOOST_LOG_SEV(lg, debug) << path_name.string() << ", size = " << e.tag_image_size;

		int index = 0;
		if (std::regex_match(e.tag_image_name, index_match, re_index)) {
			// The first sub_match is the whole string; the next
			// sub_match is the first parenthesized expression.
			if (index_match.size() == 2) {
				std::ssub_match sub_match = index_match[1];
				index = std::stoi(sub_match.str());
			}
		}
		e.info.index = index;

	}
	return refresh_list;
*/
