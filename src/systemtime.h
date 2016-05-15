/* systemtime.h -- Portable system time header */

#ifndef REDSHIFT_SYSTEMTIME_H
#define REDSHIFT_SYSTEMTIME_H


int systemtime_get_time(double *now);
void systemtime_msleep(unsigned int msecs);

#endif /* ! REDSHIFT_SYSTEMTIME_H */
