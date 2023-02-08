#ifndef SPEKPALETTE_H
#define SPEKPALETTE_H

#include <stdint.h>

typedef enum palette {
    PALETTE_SPECTRUM,
    PALETTE_SPECTROGRAM,
    PALETTE_SOX,
    PALETTE_MONO,
    PALETTE_COUNT,
    PALETTE_DEFAULT = PALETTE_SPECTROGRAM,
}Palette;

uint32_t spek_palette(Palette palette, double level);

#endif
