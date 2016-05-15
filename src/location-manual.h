/* location-manual.h -- Manual location provider header */

#ifndef REDSHIFT_LOCATION_MANUAL_H
#define REDSHIFT_LOCATION_MANUAL_H

#include <stdio.h>

#include "redshift.h"


typedef struct {
	location_t loc;
} location_manual_state_t;


int location_manual_init(location_manual_state_t *state);
int location_manual_start(location_manual_state_t *state);
void location_manual_free(location_manual_state_t *state);

void location_manual_print_help(FILE *f);
int location_manual_set_option(location_manual_state_t *state,
			       const char *key, const char *value);

int location_manual_get_location(location_manual_state_t *state,
				 location_t *loc);


#endif /* ! REDSHIFT_LOCATION_MANUAL_H */
