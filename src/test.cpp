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
void regex_test2();
void json_test();
std::string curl_read(std::string url);
void curl_test();
int llvm_jit_test();
int run_task_q();
int verify_sign_convert();
void linear_regression_test();
int armadillo_test();
int gnuplot_demo1();
int gnuplot_demo2();
void serial_test();
void async_handler_test();
void chrono_test();


using namespace std;

int main(int argc, char** argv)
{

//	demo_inheritance();
//	test_json_c();
//	test_touple();
//	timeout_test();
//	vec_insert();
//	pass_smartptr();
//	json_test();
//	curl_test();
//	llvm_jit_test();
//	run_task_q();
//	verify_sign_convert();
//	linear_regression_test();
//	std::string url_addr("https://www.csie.ntu.edu.tw/~htlin/mooc/datasets/mlfound_math/hw1_15_train.dat");
//	std::cout << curl_read(url_addr);
//	armadillo_test();
//	regex_test2();
//	gnuplot_demo1();
//	async_handler_test();
	chrono_test();
}
