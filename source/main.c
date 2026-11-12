#include <3ds.h>
#include <stdio.h>
#include <string.h>
#include "bottom_bin.h"

int main(int argc, char* argv[]) {
    gfxInitDefault();
    gfxSetDoubleBuffering(GFX_BOTTOM, false);
    u8* fb = gfxGetFramebuffer(GFX_BOTTOM, GFX_LEFT, NULL, NULL);
    if (bottom_bin_size <= 320 * 240 * 3) {
        memcpy(fb, bottom_bin, bottom_bin_size);
    }
    gfxFlushBuffers();
    gfxSwapBuffers();
    gspWaitForVBlank();
    while (aptMainLoop()) {
        hidScanInput();
        if (hidKeysDown() & KEY_START) break;
        gspWaitForVBlank();
    }
    gfxExit();
    return 0;
}
