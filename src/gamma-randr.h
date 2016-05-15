#ifndef REDSHIFT_GAMMA_RANDR_H
#define REDSHIFT_GAMMA_RANDR_H

#include <stdio.h>
#include <stdint.h>

#include <xcb/xcb.h>
#include <xcb/randr.h>

#include "redshift.h"


typedef struct {
	xcb_randr_crtc_t crtc;
	unsigned int ramp_size;
	uint16_t *saved_ramps;
} randr_crtc_state_t;

typedef struct {
	xcb_connection_t *conn;
	xcb_screen_t *screen;
	int preferred_screen;
	int preserve;
	int screen_num;
	int crtc_num;
	unsigned int crtc_count;
	randr_crtc_state_t *crtcs;
} randr_state_t;


int randr_init(randr_state_t *state);
int randr_start(randr_state_t *state);
void randr_free(randr_state_t *state);

void randr_print_help(FILE *f);
int randr_set_option(randr_state_t *state, const char *key, const char *value);

void randr_restore(randr_state_t *state);
int randr_set_temperature(randr_state_t *state,
			  const color_setting_t *setting);


#endif /* ! REDSHIFT_GAMMA_RANDR_H */
