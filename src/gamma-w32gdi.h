#ifndef REDSHIFT_GAMMA_W32GDI_H
#define REDSHIFT_GAMMA_W32GDI_H

#include <windows.h>
#include <wingdi.h>

#include "redshift.h"


typedef struct {
	WORD *saved_ramps;
	int preserve;
} w32gdi_state_t;


int w32gdi_init(w32gdi_state_t *state);
int w32gdi_start(w32gdi_state_t *state);
void w32gdi_free(w32gdi_state_t *state);

void w32gdi_print_help(FILE *f);
int w32gdi_set_option(w32gdi_state_t *state, const char *key,
		      const char *value);

void w32gdi_restore(w32gdi_state_t *state);
int w32gdi_set_temperature(w32gdi_state_t *state,
			   const color_setting_t *color);


#endif /* ! REDSHIFT_GAMMA_W32GDI_H */
