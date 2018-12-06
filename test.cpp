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

using namespace std;

int main(int argc, char** argv)
{
	execution_path_comparison(argv[0]);
	cout << "sizeof (uint8_t *) = " << sizeof(uint8_t*) << endl;
//	demo_inheritance();
	test_json_c();
	return 0;
}
