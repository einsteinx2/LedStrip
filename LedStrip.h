#pragma once
#include <Arduino.h>
#define FASTLED_INTERNAL // Disable FastLED messages
#include <FastLED.h>

class LedStrip {
    public:
        LedStrip(int numLeds, int dataPin, int defaultBrightness, uint8_t startHue);
        ~LedStrip();
        void turnOff();
        void colorAllLeds(CRGB color);
        void flashAllLeds(CRGB color, int delay);
        CRGB rainbowEffect();
    private:
        CRGB *leds;
        int _numLeds;
        int _dataPin;
        int _defaultBrightness;
        uint8_t _startHue;

};
