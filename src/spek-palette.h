#ifndef SPEKPALETTE_H
#define SPEKPALETTE_H

#include <stdint.h>

enum Palette {
    PALETTE_SPECTRUM,
    PALETTE_PERCEPTUAL,
    PALETTE_RAINBOW,
    PALETTE_SOX,
    PALETTE_MONO,
    PALETTE_COUNT,
    PALETTE_DEFAULT = PALETTE_PERCEPTUAL,
};

uint32_t spek_palette(Palette palette, double level);

#endif
