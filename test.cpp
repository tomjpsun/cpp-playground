#include <iostream>
#include "print.hpp"
#include <cstdio>
#include <string>
#include <forward_list>


void demo_shared_ptr();
void demo_unique();
void demo_transform();
int demo_binder();
void demo_inheritance();
void execution_path_comparison(char* argv0);
int test_json_c();
void test_touple();
void timeout_test();
void vec_insert();
void pass_smartptr();
int is_little_endian();
void regex_test();
void json_test();
std::string curl_read(std::string url);

using namespace std;

int main(int argc, char** argv)
{

//	demo_inheritance();
//	test_json_c();
//	test_touple();
//	timeout_test();
//	vec_insert();
//	pass_smartptr();
//	regex_test();
//	json_test();
	std::string url_addr("https://www.csie.ntu.edu.tw/~htlin/mooc/datasets/mlfound_math/hw1_15_train.dat");
	std::cout << curl_read(url_addr);
}
