/* location-geoclue2.h -- Geoclue2 location provider header */

#ifndef REDSHIFT_LOCATION_GEOCLUE2_H
#define REDSHIFT_LOCATION_GEOCLUE2_H

#include <stdio.h>

#include "redshift.h"


int location_geoclue2_init(void *state);
int location_geoclue2_start(void *state);
void location_geoclue2_free(void *state);

void location_geoclue2_print_help(FILE *f);
int location_geoclue2_set_option(void *state,
				 const char *key, const char *value);

int location_geoclue2_get_location(void *state,
				   location_t *loc);


#endif /* ! REDSHIFT_LOCATION_GEOCLUE2_H */
