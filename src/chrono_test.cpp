#include <chrono>
#include <thread>
#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;
using namespace std::chrono;

template<typename Clock, typename Duration>
std::ostream &operator<<(std::ostream &stream,
			 const std::chrono::time_point<Clock, Duration> &time_point) {
	const time_t time = Clock::to_time_t(time_point);
#if __GNUC__ > 4 ||							\
	((__GNUC__ == 4) && __GNUC_MINOR__ > 8 && __GNUC_REVISION__ > 1)
	// Maybe the put_time will be implemented later?
	struct tm tm;
	localtime_r(&time, &tm);
	return stream << std::put_time(&tm, "%c"); // Print standard date&time
#else
	char buffer[26];
	ctime_r(&time, buffer);
	buffer[24] = '\0';  // Removes the newline that is added
	return stream << buffer;
#endif
}

void print_timepoint(system_clock::time_point tpoint) {
	std::cout << tpoint << std::endl;
}


void chrono_test()
{
	auto start = std::chrono::system_clock::now();
	std::this_thread::sleep_for(std::chrono::milliseconds(100));
	auto end = std::chrono::system_clock::now();

	std::chrono::duration<double> diff = end - start;
	std::cout << "diff count (s) = " << diff.count() << std::endl;
	std::chrono::duration<double, std::milli> diffms = end - start;
	std::cout << "diff count (ms) = " << diffms.count() << std::endl;

	print_timepoint(system_clock::now());
}
