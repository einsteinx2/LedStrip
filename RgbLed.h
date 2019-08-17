#pragma once
#include <Arduino.h>
#define FASTLED_INTERNAL // Disable FastLED messages
#include <FastLED.h>

/*
 * Represents a single regular RGB LED (currently only common cathode)
 *
 * The FastLED libary is used to provide the same CRGB struct used for
 * controlling LedStrips (and eventually for other uses). 
 */
class RgbLed {
    public:
        RgbLed(uint8_t redPin, uint8_t greenPin, uint8_t bluePin);
        void setColor(CRGB color);
    private:
        uint8_t _redPin;
        uint8_t _greenPin;
        uint8_t _bluePin;
};