#include <iostream>
#include <string>
#include <curl/curl.h>


static size_t write_callback(void *contents, size_t size, size_t nmemb, void *userp)
{
	((std::string*)userp)->append((char*)contents, size * nmemb);
	return size * nmemb;
}

std::string curl_read(std::string url)
{
	CURL *curl;
	CURLcode res;
	std::string read_buffer;

	curl = curl_easy_init();
	if(curl) {
		curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &read_buffer);
		res = curl_easy_perform(curl);
		curl_easy_cleanup(curl);

		//std::cout << readBuffer << std::endl;
	}
	return read_buffer;
}
