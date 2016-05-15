/* location-geoclue.h -- Geoclue location provider header */

#ifndef REDSHIFT_LOCATION_GEOCLUE_H
#define REDSHIFT_LOCATION_GEOCLUE_H

#include <stdio.h>
#include <geoclue/geoclue-position.h>

#include "redshift.h"

typedef struct {
	GeocluePosition *position;  /* main geoclue object */
	char *provider;             /* name of a geoclue provider */
	char *provider_path;        /* path of the geoclue provider */
} location_geoclue_state_t;

int location_geoclue_init(location_geoclue_state_t *state);
int location_geoclue_start(location_geoclue_state_t *state);
void location_geoclue_free(location_geoclue_state_t *state);

void location_geoclue_print_help(FILE *f);
int location_geoclue_set_option(location_geoclue_state_t *state,
				const char *key, const char *value);

int location_geoclue_get_location(location_geoclue_state_t *state,
				  location_t *loc);


#endif /* ! REDSHIFT_LOCATION_GEOCLUE_H */
