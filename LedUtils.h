#pragma once
#include <Arduino.h>
#define FASTLED_INTERNAL // Disable FastLED messages
#include <FastLED.h>

class LedUtils {
    public:
        // Not thread safe
        static char* CRGBToString(CRGB color) {
            static char buffer[21];
            sprintf(buffer, "r: %3d g: %3d b: %3d", color.r, color.g, color.b);
            return buffer;
        }
};