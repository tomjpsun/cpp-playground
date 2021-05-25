#include <string>
#include <iostream>
#include <vector>
#include <map>

#include "nlohmann/json.hpp"

using namespace std;
using json  = nlohmann::json;

/* nlohmann requires auto converting classes that are in namespace */
namespace rfid {
	class ServiceRfidCommand
	{
	public: ServiceRfidCommand() {}
	        string token;
		int command_id;
		string reader_id;
		map<string, string> parameters;
		int reserved;
	};

	void to_json(json& j, const ServiceRfidCommand& s);
	void from_json(const json& j, ServiceRfidCommand& s);
} // namespace rfid

namespace rfid {
	void to_json(json& j, const ServiceRfidCommand& s) {
		j = json{ {"token", s.token},
			  {"command_id", s.command_id},
			  {"reader_id", s.reader_id},
			  {"parameters", s.parameters},
			  {"reserved", s.reserved}};
	}

	void from_json(const json& j, ServiceRfidCommand& s) {
		j.at("token").get_to(s.token);
                j.at("command_id").get_to(s.command_id);
                j.at("reader_id").get_to(s.reader_id);
		j.at("parameters").get_to(s.parameters);
		j.at("reserved").get_to(s.reserved);
	}
}

void json_test()
{
	// create and print a JSON from the map
	rfid::ServiceRfidCommand svc;
	svc.token = "rfidtokenex";
	svc.command_id = 3;
	svc.reader_id =	"rknj48";
	svc.parameters = { { "start", "2" }, {"offset", "6"} };

	json j = svc;
	std::cout << j << std::endl;

	// get the map out of JSON
	rfid::ServiceRfidCommand m2 = j;

}
