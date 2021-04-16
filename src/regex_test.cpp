#include <regex>
#include <vector>
#include <iostream>
#include <sstream>
#include <string>

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

void regex_test2()
{
	string target0("\x0a@2021/04/16 16:25:29.390-Antenna1-U\x0d\x0a" );
	string target("\x0a@2021/04/16 16:25:29.388-Antenna1-U3000E28011606000020D6841ECBF4ABF\x0d\x0a");
	const regex reg( "\n(@?)(\\d{4}/\\d{2}/\\d{2} \\d{2}:\\d{2}:\\d{2}\\.\\d{3})-Antenna(\\d+)-U(.*)\r\n" );
	smatch index_match;
		if (std::regex_match(target, index_match, reg)) {
			// The first sub_match is the whole string; the next
			// sub_match is the first parenthesized expression.
			for (int i = 0; i < index_match.size(); i++) {
				std::ssub_match sub_match = index_match[i];
				std::string m = sub_match.str();
				cout << "index_match[" << i << "]= " << m << endl;
			}
		}
		string epc = index_match[4].str();
		if (epc.size()) {
			const regex epc_reg( "([0-9a-fA-F]{4})([0-9a-fA-F]*)([0-9a-fA-F]{4})" );
			smatch epc_match;
			if (std::regex_match(epc, epc_match, epc_reg)) {
				for (int j = 0; j < epc_match.size(); j++) {
					std::ssub_match sub_match = epc_match[j];
					std::string m = sub_match.str();
					cout << "epc_match[" << j << "]= " << m << endl;
				}
			}
		}


}
