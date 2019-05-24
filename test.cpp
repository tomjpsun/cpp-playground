#include <iostream>
#include "print.hpp"
#include <cstdio>
#include <string>
#include <forward_list>
#include <vector>

void demo_shared_ptr();
void demo_unique();
void demo_transform();
int demo_binder();
void demo_inheritance();
void execution_path_comparison(char* argv0);
int test_json_c();
void test_touple();
void timeout_test();

using namespace std;

using buffer_t = std::vector<int>;



int main(int argc, char** argv)
{
	int b[9] = {1,2,3,4,5,6,7,8,9};
	buffer_t buf{};
	cout << "buf initial size: " << buf.size() << endl;
	cout << "buf capacity: " << buf.capacity() << endl;
	buf.insert(buf.end(), (int *)b, (int *)b + 9);
	for (buffer_t::iterator i = buf.begin(); i != buf.end(); i++) {
		cout << " *i = " << *i;
	}

	cout << endl << "buf final size: " << buf.size() << endl;
	cout << "buf capacity: " << buf.capacity() << endl;
//	demo_inheritance();
//	test_json_c();
//	test_touple();
	timeout_test();
	return 0;
}
