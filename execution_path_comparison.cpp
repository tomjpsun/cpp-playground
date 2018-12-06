#include <iostream>
#include <unistd.h>

using namespace std;

void execution_path_comparison(char* argv0)
{
	cout << __func__ << "():" << endl << "arg[0] = " << argv0 << endl;

        char pwd[FILENAME_MAX];
        getcwd( pwd, FILENAME_MAX );
	cout << "cwd: " << pwd << endl;

	char buf[1024] = {};
	readlink("/proc/self/exe", buf, sizeof(buf));
	printf("Program binary path is: %s\n", buf);

}
