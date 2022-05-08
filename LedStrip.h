#pragma once
#include <Arduino.h>
#define FASTLED_INTERNAL // Disable FastLED messages
#include <FastLED.h>

/*
 * Represents a strip of individually addressible RGB LEDs (currently only NEOPIXELs)
 */
class LedStrip {
    public:
        LedStrip(uint16_t numLeds, uint8_t dataPin, uint8_t defaultBrightness, uint8_t startHue);
        ~LedStrip();
        void turnOff();
        void setColorAll(CRGB color);
        void setColors(CRGB *colors, uint8_t length);
        void flashAllLeds(CRGB color, uint16_t delay);
        CRGB rainbowEffect(bool reset);
    private:
        CRGB *leds;
        uint16_t _numLeds;
        uint8_t _dataPin;
        uint8_t _defaultBrightness;
        uint8_t _startHue;

};