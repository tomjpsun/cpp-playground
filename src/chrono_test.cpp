#include <chrono>
#include <thread>
#include <iostream>

//using namespace std;
//using namespace std::chrono;

void chrono_test()
{
	auto start = std::chrono::system_clock::now();
	std::this_thread::sleep_for(std::chrono::milliseconds(100));
	auto end = std::chrono::system_clock::now();

	std::chrono::duration<double> diff = end - start;
	std::cout << "diff count (s) = " << diff.count() << std::endl;
	std::chrono::duration<double, std::milli> diffms = end - start;
	std::cout << "diff count (ms) = " << diffms.count() << std::endl;
}
