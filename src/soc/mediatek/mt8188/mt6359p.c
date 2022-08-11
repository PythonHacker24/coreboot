/* SPDX-License-Identifier: GPL-2.0-only OR MIT */

#include <soc/mt6359p.h>

/*
 * These values are used by MediaTek internally.
 * We can find these registers in "MT6315 datasheet v1.3.pdf".
 * The setting values are provided by MeidaTek designers.
 */

static const struct pmic_setting init_setting[] = {
	{0x20, 0xA, 0xA, 0},
	{0x24, 0x1F00, 0x1F00, 0},
	{0x30, 0x1, 0x1, 0},
	{0x32, 0x1, 0x1, 0},
	{0x94, 0x0, 0xFFFF, 0},
	{0x10C, 0x10, 0x10, 0},
	{0x112, 0x4, 0x4, 0},
	{0x118, 0x8, 0x8, 0},
	{0x14A, 0x20, 0x20, 0},
	{0x198, 0x0, 0x1FF, 0},
	{0x1B2, 0x3, 0x3, 0},
	{0x3B0, 0x0, 0x300, 0},
	{0x790, 0x3, 0x3, 0},
	{0x796, 0x1750, 0x3FFF, 0},
	{0x798, 0x1750, 0x3FFF, 0},
	{0x7A6, 0xF800, 0xFC00, 0},
	{0x7A8, 0x80, 0x280, 0},
	{0x98A, 0x80, 0x80, 0},
	{0x992, 0xF00, 0xF00, 0},
	{0xA08, 0x1, 0x1, 0},
	{0xA0C, 0x300, 0x300, 0},
	{0xA10, 0x0, 0x4000, 0},
	{0xA12, 0x1E0, 0x1E0, 0},
	{0xA24, 0xFFFF, 0xFFFF, 0},
	{0xA26, 0xFFE0, 0xFFE0, 0},
	{0xA2C, 0xC0DF, 0xC0DF, 0},
	{0xA2E, 0xEBE0, 0xEBE0, 0},
	{0xA34, 0x8000, 0x8000, 0},
	{0xA3C, 0x1600, 0x1F00, 0},
	{0xA3E, 0x3A61, 0x7FFF, 0},
	{0xA40, 0x4042, 0x7FFF, 0},
	{0xA42, 0xED0, 0x7FFF, 0},
	{0xA44, 0x1CC4, 0x7FFF, 0},
	{0xA46, 0x21AD, 0x7FFF, 0},
	{0xA48, 0x4409, 0x7FFF, 0},
	{0xA4A, 0x46AA, 0x7FFF, 0},
	{0xA4C, 0x3E8E, 0x7FFF, 0},
	{0xA4E, 0x5253, 0x7FFF, 0},
	{0xA50, 0xA0, 0x7FFF, 0},
	{0xA9C, 0x4000, 0x4000, 0},
	{0xA9E, 0x2E11, 0xFF11, 0},
	{0xF8C, 0x115, 0x115, 0},
	{0x1188, 0x0, 0x8000, 0},
	{0x1198, 0x13, 0x3FF, 0},
	{0x119E, 0x6000, 0x7000, 0},
	{0x11D4, 0x0, 0x2, 0},
	{0x1212, 0x0, 0x2, 0},
	{0x1224, 0x0, 0x2, 0},
	{0x1238, 0x0, 0x2, 0},
	{0x124A, 0x0, 0x2, 0},
	{0x125C, 0x0, 0x2, 0},
	{0x125E, 0x0, 0x8000, 0},
	{0x1260, 0x1, 0xFFF, 0},
	{0x1262, 0x4, 0x4, 0},
	{0x1412, 0x8, 0x8, 0},
	{0x148E, 0x38, 0x7F, 0},
	{0x1492, 0xF1F, 0x7F7F, 0},
	{0x150E, 0x18, 0x7F, 0},
	{0x1512, 0xC1F, 0x7F7F, 0},
	{0x158E, 0x18, 0x7F, 0},
	{0x1592, 0xF00, 0x7F00, 0},
	{0x160E, 0x18, 0x7F, 0},
	{0x168E, 0x18, 0x7F, 0},
	{0x1692, 0xF1F, 0x7F7F, 0},
	{0x170E, 0x18, 0x7F, 0},
	{0x1712, 0xF1F, 0x7F7F, 0},
	{0x178E, 0x18, 0x7F, 0},
	{0x1792, 0xF0F, 0x7F7F, 0},
	{0x1918, 0x0, 0x3F3F, 0},
	{0x191A, 0x0, 0x3F00, 0},
	{0x198A, 0x5004, 0x502C, 0},
	{0x198C, 0x3E, 0x3F, 0},
	{0x198E, 0x1E0, 0x1E0, 0},
	{0x1990, 0xFD, 0xFF, 0},
	{0x1994, 0x10, 0x38, 0},
	{0x1996, 0x2004, 0xA02C, 0},
	{0x1998, 0x3E, 0x3F, 0},
	{0x199A, 0xFB78, 0xFF78, 0},
	{0x199E, 0x2, 0x7, 0},
	{0x19A0, 0x1050, 0x10F1, 0},
	{0x19A2, 0x3E, 0x3F, 0},
	{0x19A4, 0xFD0F, 0xFF0F, 0},
	{0x19A6, 0x20, 0xFF, 0},
	{0x19AC, 0x4208, 0x4698, 0},
	{0x19AE, 0x6E, 0x7E, 0},
	{0x19B0, 0x3C00, 0x3C00, 0},
	{0x19B4, 0x20FD, 0xFFFF, 0},
	{0x1A08, 0x4208, 0x4698, 0},
	{0x1A0A, 0x6E, 0x7E, 0},
	{0x1A0C, 0x3C00, 0x3C00, 0},
	{0x1A10, 0x20FD, 0xFFFF, 0},
	{0x1A14, 0x4208, 0x4698, 0},
	{0x1A16, 0x6E, 0x7E, 0},
	{0x1A18, 0x3C00, 0x3C00, 0},
	{0x1A1C, 0x20FD, 0xFFFF, 0},
	{0x1A1E, 0x0, 0x200, 0},
	{0x1A20, 0x4208, 0x4698, 0},
	{0x1A22, 0x4A, 0x7E, 0},
	{0x1A24, 0x3C00, 0x3C00, 0},
	{0x1A28, 0x20FD, 0xFF00, 0},
	{0x1A2C, 0x20, 0x74, 0},
	{0x1A2E, 0x1E, 0x1E, 0},
	{0x1A30, 0x42, 0xFF, 0},
	{0x1A32, 0x480, 0x7E0, 0},
	{0x1A34, 0x20, 0x74, 0},
	{0x1A36, 0x1E, 0x1E, 0},
	{0x1A38, 0x42, 0xFF, 0},
	{0x1A3A, 0x480, 0x7E0, 0},
	{0x1A3C, 0x14C, 0x3CC, 0},
	{0x1A3E, 0x23C, 0x3FC, 0},
	{0x1A40, 0xC400, 0xFF00, 0},
	{0x1A42, 0x80, 0xFF, 0},
	{0x1A44, 0x702C, 0xFF2C, 0},
	{0x1B0E, 0xF, 0xF, 0},
	{0x1B10, 0x1, 0x1, 0},
	{0x1B14, 0xFFFF, 0xFFFF, 0},
	{0x1B1A, 0x3FFF, 0x3FFF, 0},
	{0x1B32, 0x8, 0x8, 0},
	{0x1B8A, 0x30, 0x8030, 0},
	{0x1B9C, 0x10, 0x8010, 0},
	{0x1BA0, 0x4000, 0x4000, 0},
	{0x1BAE, 0x1410, 0x9C10, 0},
	{0x1BB2, 0x2, 0x2, 0},
	{0x1BC0, 0x10, 0x8010, 0},
	{0x1BD2, 0x13, 0x8013, 0},
	{0x1BE4, 0x10, 0x8010, 0},
	{0x1C0A, 0x10, 0x8010, 0},
	{0x1C1E, 0x10, 0x8010, 0},
	{0x1C30, 0x10, 0x8010, 0},
	{0x1C42, 0x10, 0x8010, 0},
	{0x1C54, 0x32, 0x8033, 0},
	{0x1C66, 0x10, 0x8010, 0},
	{0x1C8A, 0x10, 0x8010, 0},
	{0x1C8E, 0x4000, 0x4000, 0},
	{0x1C9C, 0x10, 0x8010, 0},
	{0x1CAE, 0x10, 0x8010, 0},
	{0x1CC0, 0x10, 0x8010, 0},
	{0x1CD2, 0x33, 0x8033, 0},
	{0x1CE4, 0x33, 0x8033, 0},
	{0x1D0A, 0x10, 0x8010, 0},
	{0x1D1E, 0x10, 0x8010, 0},
	{0x1D22, 0x4000, 0x4000, 0},
	{0x1D30, 0x10, 0x8010, 0},
	{0x1D34, 0x4000, 0x4000, 0},
	{0x1D42, 0x30, 0x8030, 0},
	{0x1D46, 0x4000, 0x4000, 0},
	{0x1D54, 0x30, 0x8030, 0},
	{0x1D66, 0x32, 0x8033, 0},
	{0x1D8A, 0x10, 0x8010, 0},
	{0x1D9C, 0x10, 0x8010, 0},
	{0x1E8A, 0x10, 0x8010, 0},
	{0x1E8E, 0x10, 0x7F, 0},
	{0x1E92, 0xF1F, 0x7F7F, 0},
	{0x1EAA, 0x10, 0x8010, 0},
	{0x1EAE, 0x10, 0x7F, 0},
	{0x1EB2, 0xF1F, 0x7F7F, 0},
	{0x1F0A, 0x10, 0x8010, 0},
	{0x1F0E, 0x8, 0x7F, 0},
	{0x1F12, 0xF1F, 0x7F7F, 0},
	{0x1F30, 0x10, 0x8010, 0},
	{0x1F34, 0x8, 0x7F, 0},
	{0x1F38, 0xF1F, 0x7F7F, 0},
	{0x200A, 0x8, 0xC, 0},
	{0x202C, 0x8, 0xC, 0},
	{0x208C, 0x100, 0xF00, 0},
	{0x209C, 0x80, 0x1E0, 0},
};

static const struct pmic_setting lp_setting[] = {
	/* Suspend */
	{0x1594, 0x1, 0x1, 0x0},
	{0x159a, 0x1, 0x1, 0x0},
	{0x1d22, 0x1, 0x1, 0xe},
	{0x1d28, 0x0, 0x1, 0xe},
	{0x1c6a, 0x1, 0x1, 0x0},
	{0x1c70, 0x1, 0x1, 0x0},
	{0x1d34, 0x1, 0x1, 0xe},
	{0x1d3a, 0x0, 0x1, 0xe},
	{0x1d46, 0x1, 0x1, 0xe},
	{0x1d4c, 0x0, 0x1, 0xe},
	{0x1c8e, 0x1, 0x1, 0x0},
	{0x1c94, 0x1, 0x1, 0x0},
	{0x1ba0, 0x1, 0x1, 0x0},
	{0x1ba6, 0x1, 0x1, 0x0},
	{0x1d0e, 0x1, 0x1, 0x0},
	{0x1d14, 0x1, 0x1, 0x0},

	/* Deep idle */
	{0x1594, 0x1, 0x1, 0x2},
	{0x159a, 0x1, 0x1, 0x2},
	{0x1c6a, 0x1, 0x1, 0x2},
	{0x1c70, 0x1, 0x1, 0x2},
	{0x1c8e, 0x1, 0x1, 0x2},
	{0x1c94, 0x1, 0x1, 0x2},
	{0x1ba0, 0x1, 0x1, 0x2},
	{0x1ba6, 0x1, 0x1, 0x2},
	{0x1d0e, 0x1, 0x1, 0x2},
	{0x1d14, 0x1, 0x1, 0x2},
};

void pmic_init_setting(void)
{
	for (int i = 0; i < ARRAY_SIZE(init_setting); i++)
		mt6359p_write_field(init_setting[i].addr, init_setting[i].val,
			init_setting[i].mask, init_setting[i].shift);
}

void pmic_lp_setting(void)
{
	for (int i = 0; i < ARRAY_SIZE(lp_setting); i++)
		mt6359p_write_field(lp_setting[i].addr, lp_setting[i].val,
			lp_setting[i].mask, lp_setting[i].shift);
}
