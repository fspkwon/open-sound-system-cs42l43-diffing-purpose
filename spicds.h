/*-
 * SPDX-License-Identifier: BSD-2-Clause
 *
 * Copyright (c) 2025 davidjo <https://github.com/davidjo>
 * Copyright (c) 2025 Cirrus Logic <https://cirrus.com>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHERIN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THEPOSSIBILITY OF
 * SUCH DAMAGE.
 */

/* supported CODECs */
#define SPICDS_TYPE_CS42L43 0

/* CS42L43 control registers */
#define CS42L43_POWER 0x00
#define   CS42L43_POWER_PWDA 0x01
#define   CS42L43_POWER_PWAD 0x02
#define   CS42L43_POWER_PWVR 0x04
#define CS42L43_RESET 0x01
#define   CS42L43_RESET_RSDA 0x01
#define   CS42L43_RESET_RSAD 0x02
#define CS42L43_FORMAT 0x02
#define   CS42L43_FORMAT_1X       0x00
#define   CS42L43_FORMAT_2X       0x01
#define   CS42L43_FORMAT_4X1      0x02
#define   CS42L43_FORMAT_4X2      0x03
#define   CS42L43_FORMAT_256FSN   0x00
#define   CS42L43_FORMAT_512FSN   0x04
#define   CS42L43_FORMAT_1024FSN  0x08
#define   CS42L43_FORMAT_384FSN   0x10
#define   CS42L43_FORMAT_768FSN   0x14
#define   CS42L43_FORMAT_OM24IL16 0x00
#define   CS42L43_FORMAT_OM24IL20 0x20
#define   CS42L43_FORMAT_OM24IM24 0x40
#define   CS42L43_FORMAT_I2S      0x60
#define   CS42L43_FORMAT_OM24IL24 0x80
#define CS42L43_DVC 0x03
#define   CS42L43_DVC_DEM441  0x00
#define   CS42L43_DVC_DEMOFF  0x01
#define   CS42L43_DVC_DEM48   0x02
#define   CS42L43_DVC_DEM32   0x03
#define   CS42L43_DVC_ZTM256  0x00
#define   CS42L43_DVC_ZTM512  0x04
#define   CS42L43_DVC_ZTM1024 0x08
#define   CS42L43_DVC_ZTM2048 0x0c
#define   CS42L43_DVC_ZCE     0x10
#define   CS42L43_DVC_HPFL    0x04
#define   CS42L43_DVC_HPFR    0x08
#define   CS42L43_DVC_SMUTE   0x80
#define CS42L43_LIPGA 0x04
#define CS42L43_RIPGA 0x05
#define CS42L43_LOATT 0x06
#define CS42L43_ROATT 0x07

struct spicds_info;

typedef void (*spicds_ctrl)(void *, unsigned int, unsigned int, unsigned int);

struct spicds_info *spicds_create(device_t dev, void *devinfo, int num, spicds_ctrl);
void spicds_destroy(struct spicds_info *codec);
void spicds_settype(struct spicds_info *codec, unsigned int type);
void spicds_setcif(struct spicds_info *codec, unsigned int cif);
void spicds_setformat(struct spicds_info *codec, unsigned int format);
void spicds_setdvc(struct spicds_info *codec, unsigned int dvc);
void spicds_init(struct spicds_info *codec);
void spicds_reinit(struct spicds_info *codec);
void spicds_set(struct spicds_info *codec, int dir, unsigned int left, unsigned int right);
