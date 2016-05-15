/* gamma-quartz.h -- Quartz (OSX) gamma adjustment header */

#ifndef REDSHIFT_GAMMA_QUARTZ_H
#define REDSHIFT_GAMMA_QUARTZ_H

#include <stdint.h>

#include <ApplicationServices/ApplicationServices.h>

#include "redshift.h"


typedef struct {
	CGDirectDisplayID display;
	uint32_t ramp_size;
	float *saved_ramps;
} quartz_display_state_t;

typedef struct {
	quartz_display_state_t *displays;
	uint32_t display_count;
	int preserve;
} quartz_state_t;


int quartz_init(quartz_state_t *state);
int quartz_start(quartz_state_t *state);
void quartz_free(quartz_state_t *state);

void quartz_print_help(FILE *f);
int quartz_set_option(quartz_state_t *state, const char *key,
		      const char *value);

void quartz_restore(quartz_state_t *state);
int quartz_set_temperature(quartz_state_t *state,
			   const color_setting_t *setting);


#endif /* ! REDSHIFT_GAMMA_QUARTZ_H */
