#include <algorithm>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <chrono>
#include <vector>

using namespace std;

void report(vector<int> &perm)
{
	static int line = 0;
	cout << "[" << line++ << "]: ";

	for (auto element : perm)
		 cout << element << ", ";

	cout << endl;
}


void permutation(vector<int> src, int start, int end)
{
        if ( start == end ) {
		report( src );
	} else {
		for ( int i = start; i <= end; i++) {
			swap( src[0] , src[i] );
			permutation( src, start + 1, end );
		}
	}
}


void start_long_task(vector<int> src)
{
	vector<int> result;
	int start = 0;
	int end = int(src.size() - 1);
	permutation( src, start, end);
}


int long_task()
{
	using namespace std::literals; // enables the usage of 24h, 1ms, 1s instead of
	// e.g. std::chrono::hours(24), accordingly

	const std::chrono::time_point<std::chrono::system_clock> now =
		std::chrono::system_clock::now();

	const std::time_t t_c = std::chrono::system_clock::to_time_t(now - 24h);
	std::cout << "24 hours ago, the time was "
		  << std::put_time(std::localtime(&t_c), "%F %T.\n") << std::flush;

	const std::chrono::time_point<std::chrono::steady_clock> start =
		std::chrono::steady_clock::now();

        vector<int> a{1, 2, 3, 4, 5, 6, 7, 8};
        start_long_task(a);

	const auto end = std::chrono::steady_clock::now();

	std::cout
		<< "Permutation took "
		<< std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << "µs ≈ "
		<< (end - start) / 1ms << "ms ≈ " // almost equivalent form of the above, but
		<< (end - start) / 1s << "s.\n";  // using milliseconds and seconds accordingly
	return 0;
}
