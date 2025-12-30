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
void curl_test();
int llvm_jit_test();
int run_task_q();
int verify_sign_convert();
void linear_regression_test();
int armadillo_test();

using namespace std;

// write a TEST macro, input the test function name,
// the macro will first print the function name, then
// call the function

#define TEST(func)							\
	do {								\
		std::cout << "====================\n";			\
		std::cout << "Testing " << #func << " ---\n";		\
	  func();							\
	} while(0)


int main(int argc, char** argv)
{
    TEST(demo_inheritance);
    TEST(test_json_c);
    TEST(test_touple);
    TEST(timeout_test);
    TEST(vec_insert);
    TEST(pass_smartptr);
    TEST(regex_test);
    TEST(json_test);
    TEST(curl_test);
    TEST(llvm_jit_test);
    TEST(run_task_q);
    TEST(verify_sign_convert);
    TEST(linear_regression_test);
    TEST(armadillo_test);
    //std::string url_addr("https://www.csie.ntu.edu.tw/~htlin/mooc/datasets/mlfound_math/hw1_15_train.dat");
    //std::cout << curl_read(url_addr);

    return 0;
}
