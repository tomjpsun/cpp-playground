#define _GNU_SOURCE /* for tm_gmtoff and tm_zone */

#include <stdio.h>
#include <time.h>

/* Checking errors returned by system calls was omitted for the sake of readability. */
int time_zone_test(void)
{
	time_t t = time(NULL);
	struct tm lt = {0};

	localtime_r(&t, &lt);

	printf("Offset to GMT is %lds.\n", lt.tm_gmtoff);
	printf("The time zone is '%s'.\n", lt.tm_zone);

	return 0;
}
