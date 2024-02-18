# Copyright 2022 Markus Knutsson (@TweetyDaBird)
# SPDX-License-Identifier: GPL-2.0-or-later

# Link Time Optimization
LTO_ENABLE = yes			# Optimize size at compile (takes longer time)

# Additional rules for VIAL
VIA_ENABLE = yes
VIAL_ENABLE = yes

ENCODER_MAP_ENABLE = yes

QMK_SETTINGS = yes
KEY_OVERRIDE_ENABLE = yes

CONVERT_TO=promicro_rp2040

