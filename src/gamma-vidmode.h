#ifndef REDSHIFT_GAMMA_VIDMODE_H
#define REDSHIFT_GAMMA_VIDMODE_H

#include "redshift.h"

#include <stdio.h>
#include <stdint.h>

#include <X11/Xlib.h>

typedef struct {
	Display *display;
	int preserve;
	int screen_num;
	int ramp_size;
	uint16_t *saved_ramps;
} vidmode_state_t;


int vidmode_init(vidmode_state_t *state);
int vidmode_start(vidmode_state_t *state);
void vidmode_free(vidmode_state_t *state);

void vidmode_print_help(FILE *f);
int vidmode_set_option(vidmode_state_t *state, const char *key,
		       const char *value);

void vidmode_restore(vidmode_state_t *state);
int vidmode_set_temperature(vidmode_state_t *state,
			    const color_setting_t *setting);


#endif /* ! REDSHIFT_GAMMA_VIDMODE_H */
