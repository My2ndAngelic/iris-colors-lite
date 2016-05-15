/* systemtime.c -- Portable system time source */

#include <stdio.h>
#include <unistd.h>

#ifndef _WIN32
# if _POSIX_TIMERS > 0
#  include <time.h>
# else
#  include <time.h>
#  include <sys/time.h>
# endif
#else
# include <windows.h>
#endif

#include "systemtime.h"


/* Return current time in T as the number of seconds since the epoch. */
int
systemtime_get_time(double *t)
{
#if defined(_WIN32) /* Windows */
	FILETIME now;
	ULARGE_INTEGER i;
	GetSystemTimeAsFileTime(&now);
	i.LowPart = now.dwLowDateTime;
	i.HighPart = now.dwHighDateTime;

	/* FILETIME is tenths of microseconds since 1601-01-01 UTC */
	*t = (i.QuadPart / 10000000.0) - 11644473600.0;
#elif _POSIX_TIMERS > 0 /* POSIX timers */
	struct timespec now;
	int r = clock_gettime(CLOCK_REALTIME, &now);
	if (r < 0) {
		perror("clock_gettime");
		return -1;
	}

	*t = now.tv_sec + (now.tv_nsec / 1000000000.0);
#else /* other platforms */
	struct timeval now;
	int r = gettimeofday(&now, NULL);
	if (r < 0) {
		perror("gettimeofday");
		return -1;
	}

	*t = now.tv_sec + (now.tv_usec / 1000000.0);
#endif

	return 0;
}

/* Sleep for a number of milliseconds. */
void
systemtime_msleep(unsigned int msecs)
{
#ifndef _WIN32
	struct timespec sleep;
	sleep.tv_sec = msecs / 1000;
	sleep.tv_nsec = (msecs % 1000)*1000000;
	nanosleep(&sleep, NULL);
#else
	Sleep(msecs);
#endif
}
