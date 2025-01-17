/* SPDX-License-Identifier: GPL-2.0-only */

#ifndef __MAINBOARD_GOOGLE_GERALT_PANEL_H__
#define __MAINBOARD_GOOGLE_GERALT_PANEL_H__

#include <soc/display.h>

void configure_mipi_pwm_backlight(void);
void fill_lp_backlight_gpios(struct lb_gpios *gpios);
uint32_t panel_id(void);
struct panel_description *get_panel_description(uint32_t panel_id);

#endif
