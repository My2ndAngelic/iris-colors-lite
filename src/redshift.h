////////////////////////////////////////////////////////////
#ifndef IRIS_COLORS_LITE_H
#define IRIS_COLORS_LITE_H
////////////////////////////////////////////////////////////
/* redshift.h -- Main program header */

////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>


////////////////////////////////////////////////////////////
/* Location */
typedef struct
{
	float lat;
	float lon;
} location_t;

////////////////////////////////////////////////////////////
/* Periods of day. */
typedef enum
{
	PERIOD_NONE = 0,
	PERIOD_DAYTIME,
	PERIOD_NIGHT,
	PERIOD_TRANSITION
} period_t;

////////////////////////////////////////////////////////////
/* Color setting */
typedef struct
{
	int temperature;
	float gamma[3];
	float brightness;
} color_setting_t;


////////////////////////////////////////////////////////////
/* Gamma adjustment method */
typedef int gamma_method_init_func(void *state);
typedef int gamma_method_start_func(void *state);
typedef void gamma_method_free_func(void *state);
typedef void gamma_method_print_help_func(FILE *f);
typedef int gamma_method_set_option_func(void *state, const char *key, const char *value);
typedef void gamma_method_restore_func(void *state);
typedef int gamma_method_set_temperature_func(void *state, const color_setting_t *setting);

////////////////////////////////////////////////////////////
typedef struct
{
	char *name;

	/* If true, this method will be tried if none is explicitly chosen. */
	int autostart;

	/* Initialize state. Options can be set between init and start. */
	gamma_method_init_func *init;
	/* Allocate storage and make connections that depend on options. */
	gamma_method_start_func *start;
	/* Free all allocated storage and close connections. */
	gamma_method_free_func *free;

	/* Print help on options for this adjustment method. */
	gamma_method_print_help_func *print_help;
	/* Set an option key, value-pair */
	gamma_method_set_option_func *set_option;

	/* Restore the adjustment to the state before start was called. */
	gamma_method_restore_func *restore;
	/* Set a specific color temperature. */
	gamma_method_set_temperature_func *set_temperature;
} gamma_method_t;


////////////////////////////////////////////////////////////
/* Location provider */
typedef int location_provider_init_func(void *state);
typedef int location_provider_start_func(void *state);
typedef void location_provider_free_func(void *state);
typedef void location_provider_print_help_func(FILE *f);
typedef int location_provider_set_option_func(void *state, const char *key, const char *value);
typedef int location_provider_get_location_func(void *state, location_t *loc);

////////////////////////////////////////////////////////////
typedef struct
{
	char *name;

	/* Initialize state. Options can be set between init and start. */
	location_provider_init_func *init;
	/* Allocate storage and make connections that depend on options. */
	location_provider_start_func *start;
	/* Free all allocated storage and close connections. */
	location_provider_free_func *free;

	/* Print help on options for this location provider. */
	location_provider_print_help_func *print_help;
	/* Set an option key, value-pair. */
	location_provider_set_option_func *set_option;

	/* Get current location. */
	location_provider_get_location_func *get_location;
} location_provider_t;


////////////////////////////////////////////////////////////
#endif /* ! IRIS_COLORS_LITE_H */
////////////////////////////////////////////////////////////
