
#include <iostream>
#include <string>
#include <curl/curl.h>
#include <sstream>
#include <vector>

using namespace std;

static size_t write_callback(void *contents, size_t size, size_t nmemb, void *userp)
{
	((std::string*)userp)->append((char*)contents, size * nmemb);
	return size * nmemb;
}

stringstream curl_read(std::string url)
{
	CURL *curl;
	std::string read_buffer;

	curl = curl_easy_init();
	if (curl) {
		curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &read_buffer);
		CURLcode res = curl_easy_perform(curl);
		(void)res; // Explicitly mark as intentionally unused
		curl_easy_cleanup(curl);
	}
	return stringstream{read_buffer};
}

struct record
{
	record(){};

	record(stringstream& ss) {
		ss >> x[0];
		ss >> x[1];
		ss >> x[2];
		ss >> x[3];
		ss >> y;
	}

	float x[4];
	int y;
	void dump() {
		for (int i = 0; i < 4; i++)
			cout << "x[" << i << "] = " << x[i] << ", ";
		cout << " y = " << y << endl;
	}
};

void curl_test()
{
	string url_addr("https://www.csie.ntu.edu.tw/~htlin/mooc/datasets/mlfound_math/hw1_15_train.dat");
	stringstream ss = curl_read(url_addr);
	vector<record> table;
	while (ss.rdbuf()->in_avail()) {
		record rec(ss);
		table.push_back(rec);
	}
	cout << "get #" << table.size() << " of records." << endl;
}
