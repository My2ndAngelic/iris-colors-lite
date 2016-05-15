/* location-corelocation.h -- CoreLocation (OSX) location provider header */

#ifndef REDSHIFT_LOCATION_CORELOCATION_H
#define REDSHIFT_LOCATION_CORELOCATION_H

#include <stdio.h>

#include "redshift.h"


int location_corelocation_init(void *state);
int location_corelocation_start(void *state);
void location_corelocation_free(void *state);

void location_corelocation_print_help(FILE *f);
int location_corelocation_set_option(void *state,
				     const char *key, const char *value);

int location_corelocation_get_location(void *state,
				       location_t *location);


#endif /* ! REDSHIFT_LOCATION_CORELOCATION_H */
