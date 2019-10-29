#include "nlohmann/json.hpp"
#include <string>
#include <iostream>
#include <vector>

using namespace std;
using json  = nlohmann::json;

string jstr =
"{\
  \"rows\": 1,\
  \"data\": [\
{\
\"ok\": [\
        {\
          \"drug_id\": \"07248\",\
          \"tag_id\": \"8C8100000B\",\
          \"binding_id\": \"DB5C206DE4555BD99B0D03D19387C863\"\
}, {\
          \"drug_id\": \"07342\",\
          \"tag_id\": \"8A81000009\",\
          \"binding_id\": \"FF5767317A3D847C067D217ED98A94BF\"\
}, {\
          \"drug_id\": \"08413\",\
          \"tag_id\": \"8781000006\",\
          \"binding_id\": \"1F08642608C8F0C74BF8012ED6006A61\"\
} ],\
\"error\": [] }\
] }";

struct drug_t {
	string drug_id;
	string tag_id;
	string binding_id;
};

struct response_t {
	vector<drug_t> ok;
	vector<string> error;
};

struct backend_t {
	int rows;
	vector<response_t> data;
};



void json_test()
{
	json j = json::parse(jstr);
	json j2 = j["data"][0]["ok"];
	cout << __func__ << "(" << j2.size() << "), " << j2.dump(2) << endl;
}

void to_json(json& j, const drug_t& d) {
	j = json{ {"drug_id", d.drug_id},
		  {"tag_id", d.tag_id},
		  {"binding_id", d.binding_id}
	};
}

void from_json(const json& j, drug_t& d) {
	j.at("drug_id").get_to(d.drug_id);
	j.at("tag_id").get_to(d.tag_id);
	j.at("binding_id").get_to(d.binding_id);
}

void to_json(json& j, const response_t r)
{
	j = json { {"ok", r.ok},
		   {"error", r.error}
	};
}

void from_json(const json&j, response_t r)
{
	j.at("ok").get_to(r.ok);
	j.at("error").get_to(r.ok);
}

void to_json(json& j, const backend_t b)
{
	j = json{ {"rows", b.rows},
		  {"data", b.data}
	};
}

void from_json(const json& j, backend_t b)
{
	j.at("rows").get_to(b.rows);
	j.at("data").get_to(b.data);
}
