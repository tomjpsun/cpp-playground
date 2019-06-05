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

using namespace std;

int main(int argc, char** argv)
{

//	demo_inheritance();
//	test_json_c();
//	test_touple();
//	timeout_test();
//	vec_insert();
	pass_smartptr();
	return 0;
}
