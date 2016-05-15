/* location-manual.c -- Manual location provider source */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <errno.h>

#include "location-manual.h"

#ifdef ENABLE_NLS
# include <libintl.h>
# define _(s) gettext(s)
#else
# define _(s) s
#endif


int
location_manual_init(location_manual_state_t *state)
{
	state->loc.lat = NAN;
	state->loc.lon = NAN;

	return 0;
}

int
location_manual_start(location_manual_state_t *state)
{
	/* Latitude and longitude must be set */
	if (isnan(state->loc.lat) || isnan(state->loc.lon)) {
		fputs(_("Latitude and longitude must be set.\n"), stderr);
		exit(EXIT_FAILURE);
	}

	return 0;
}

void
location_manual_free(location_manual_state_t *state)
{
}

void
location_manual_print_help(FILE *f)
{
	fputs(_("Specify location manually.\n"), f);
	fputs("\n", f);

	/* TRANSLATORS: Manual location help output
	   left column must not be translated */
	fputs(_("  lat=N\t\tLatitude\n"
		"  lon=N\t\tLongitude\n"), f);
	fputs("\n", f);
	fputs(_("Both values are expected to be floating point numbers,\n"
		"negative values representing west / south, respectively.\n"), f);
	fputs("\n", f);
}

int
location_manual_set_option(location_manual_state_t *state, const char *key,
			   const char *value)
{
	/* Parse float value */
	char *end;
	errno = 0;
	float v = strtof(value, &end);
	if (errno != 0 || *end != '\0') {
		fputs(_("Malformed argument.\n"), stderr);
		return -1;
	}

	if (strcasecmp(key, "lat") == 0) {
		state->loc.lat = v;
	} else if (strcasecmp(key, "lon") == 0) {
		state->loc.lon = v;
	} else {
		fprintf(stderr, _("Unknown method parameter: `%s'.\n"), key);
		return -1;
	}

	return 0;
}

int
location_manual_get_location(location_manual_state_t *state,
			     location_t *loc)
{
	*loc = state->loc;

	return 0;
}
