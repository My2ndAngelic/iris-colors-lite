////////////////////////////////////////////////////////////
#ifndef IRIS_GAMMA_DUMMY_H
#define IRIS_GAMMA_DUMMY_H
////////////////////////////////////////////////////////////
/* gamma-dummy.h -- No-op gamma adjustment header */

#include "redshift.h"


int gamma_dummy_init(void *state);
int gamma_dummy_start(void *state);
void gamma_dummy_free(void *state);

void gamma_dummy_print_help(FILE *f);
int gamma_dummy_set_option(void *state, const char *key, const char *value);

void gamma_dummy_restore(void *state);
int gamma_dummy_set_temperature(void *state,
				const color_setting_t *setting);

////////////////////////////////////////////////////////////
#endif /* ! IRIS_GAMMA_DUMMY_H */
////////////////////////////////////////////////////////////
