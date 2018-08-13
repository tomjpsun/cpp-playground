#include <memory>     // for shared_ptr
#include <sys/mman.h> // for shared memory
#include <fcntl.h>
#include <unistd.h>
#include <cstring>    // for strerror()
#include <cerrno>     // for errno
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include "print.hpp"

using namespace std;

struct X
{
	int a;
};

template <typename T>
void vector_dump(vector<T> v)
{
	cout << "< ";
	for (const T& e : v) {
		cout << e << " ";
	}
	cout << " >" << endl;
}

void demo_shared_ptr()
{
	cout << endl << "shared_ptr test:" << endl << "sp1 is shared with sp2:" << endl;
	shared_ptr<X> sp1(new X);
	shared_ptr<X> sp2(sp1);
	cout<< "sp1 use count: " << sp1.use_count() << endl;
	cout<< "sp2 use count: " << sp2.use_count() << endl;
	sp1.reset();
	cout<< "after reset sp1:" << endl << "sp1 use count: " << sp1.use_count() << endl;
	cout<< "sp2 use count: " << sp2.use_count() << endl;
}

void demo_unique()
{
	cout << endl << "test std::unique" << endl;

	std::vector<int> v{1,2,3,1,2,3,3,4,5,4,5,6,7};
	PRINT_ELEMENTS(v, "v is initialized as:");

	std::sort(v.begin(), v.end());
	PRINT_ELEMENTS(v, "v after being sorted: ");

	auto last = std::unique(v.begin(), v.end());
	PRINT_ELEMENTS(v, "v after being uniquified: ");

	v.erase(last, v.end());
	PRINT_ELEMENTS(v, "v after being erased: ");
}

int demo_binder();
void demo_inheritance();

int main(int argc, char**argv)
{
	demo_shared_ptr();
	demo_unique();
	demo_binder();
	demo_inheritance();
	return 0;
}
