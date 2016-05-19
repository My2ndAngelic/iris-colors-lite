////////////////////////////////////////////////////////////
#ifndef REDSHIFT_GAMMA_DRM_H
#define REDSHIFT_GAMMA_DRM_H
////////////////////////////////////////////////////////////
/* gamma-drm.h -- DRM gamma adjustment header */

////////////////////////////////////////////////////////////
#include <stdint.h>

#include <xf86drm.h>
#include <xf86drmMode.h>

#include "redshift.h"


////////////////////////////////////////////////////////////
typedef struct {
	int crtc_num;
	int crtc_id;
	int gamma_size;
	uint16_t* r_gamma;
	uint16_t* g_gamma;
	uint16_t* b_gamma;
} drm_crtc_state_t;

////////////////////////////////////////////////////////////
typedef struct {
	int card_num;
	int crtc_num;
	int fd;
	drmModeRes* res;
	drm_crtc_state_t* crtcs;
} drm_state_t;


////////////////////////////////////////////////////////////
int drm_init(drm_state_t *state);
int drm_start(drm_state_t *state);
void drm_free(drm_state_t *state);

void drm_print_help(FILE *f);
int drm_set_option(drm_state_t *state, const char *key, const char *value);

void drm_restore(drm_state_t *state);
int drm_set_temperature(drm_state_t *state, const color_setting_t *setting);


////////////////////////////////////////////////////////////
#endif /* ! REDSHIFT_GAMMA_DRM_H */
////////////////////////////////////////////////////////////
