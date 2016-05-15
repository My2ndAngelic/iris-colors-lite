#include <stdio.h>
#include <stdlib.h>

#ifdef ENABLE_NLS
# include <libintl.h>
# define _(s) gettext(s)
#else
# define _(s) s
#endif

#include "redshift.h"


int
gamma_dummy_init(void *state)
{
	return 0;
}

int
gamma_dummy_start(void *state)
{
	fputs(_("WARNING: Using dummy gamma method! Display will not be affected by this gamma method.\n"), stderr);
	return 0;
}

void
gamma_dummy_restore(void *state)
{
}

void
gamma_dummy_free(void *state)
{
}

void
gamma_dummy_print_help(FILE *f)
{
	fputs(_("Does not affect the display but prints the color temperature to the terminal.\n"), f);
	fputs("\n", f);
}

int
gamma_dummy_set_option(void *state, const char *key, const char *value)
{
	fprintf(stderr, _("Unknown method parameter: `%s'.\n"), key);
	return -1;
}

int
gamma_dummy_set_temperature(void *state, const color_setting_t *setting)
{
	printf(_("Temperature: %i\n"), setting->temperature);
	return 0;
}
