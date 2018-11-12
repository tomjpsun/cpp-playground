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


using namespace std;

int main(int argc, char** argv)
{
	execution_path_comparison(argv[0]);
	std::forward_list<int> fwlist = { 1, 2, 3 };
// insert 77, 88, and 99 at the beginning:
	fwlist.insert_after (fwlist.before_begin(), // position
			     { 77, 88, 99 } ); // values
	PRINT_ELEMENTS(fwlist);
//	demo_inheritance();
	return 0;
}
