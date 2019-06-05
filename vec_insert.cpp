#include <vector>
#include <iostream>

using namespace std;
using buffer_t = std::vector<int>;

void vec_insert() {
	int b[9] = {1,2,3,4,5,6,7,8,9};
	buffer_t buf{};
	cout << "buf initial size: " << buf.size() << endl;
	cout << "buf capacity: " << buf.capacity() << endl;
	buf.insert(buf.end(), (int *)b, (int *)b + 9);
	for (auto elem : buf) {
		cout << elem << ",";
	}
	cout << endl;

	cout << endl << "buf final size: " << buf.size() << endl;
	cout << "buf capacity: " << buf.capacity() << endl;
}
