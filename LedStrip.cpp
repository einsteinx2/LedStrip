#include "LedStrip.h"

LedStrip::LedStrip(int numLeds, int dataPin, int defaultBrightness, uint8_t startHue) {
    _numLeds = numLeds;
    _dataPin = dataPin;
    _defaultBrightness = defaultBrightness;
    _startHue = startHue;

    leds = new CRGB[numLeds];

    // Get around C++ template limits to allow dynamically setting the data pin
    switch (dataPin) {
        case  0: FastLED.addLeds<NEOPIXEL,  0>(leds, numLeds); break;
        case  1: FastLED.addLeds<NEOPIXEL,  1>(leds, numLeds); break;
        case  2: FastLED.addLeds<NEOPIXEL,  2>(leds, numLeds); break;
        case  3: FastLED.addLeds<NEOPIXEL,  3>(leds, numLeds); break;
        case  4: FastLED.addLeds<NEOPIXEL,  4>(leds, numLeds); break;
        case  5: FastLED.addLeds<NEOPIXEL,  5>(leds, numLeds); break;
        case  6: FastLED.addLeds<NEOPIXEL,  6>(leds, numLeds); break;
        case  7: FastLED.addLeds<NEOPIXEL,  7>(leds, numLeds); break;
        case  8: FastLED.addLeds<NEOPIXEL,  8>(leds, numLeds); break;
        case  9: FastLED.addLeds<NEOPIXEL,  9>(leds, numLeds); break;
        case 10: FastLED.addLeds<NEOPIXEL, 10>(leds, numLeds); break;
    }
    
    FastLED.setBrightness(defaultBrightness);
}

LedStrip::~LedStrip() {
    delete leds;
}

void LedStrip::colorAllLeds(CRGB color) {
    fill_solid(leds, _numLeds, color);
}

void LedStrip::flashAllLeds(CRGB color, int delayMillis) {
    colorAllLeds(color);
    FastLED.delay(delayMillis);
    colorAllLeds(CRGB::Black);
    FastLED.delay(delayMillis);
}

void LedStrip::rainbowEffect() {
    // Better color smoothing code from https://www.reddit.com/r/arduino/comments/5o552l/fastled_how_can_i_create_a_smoothnonchoppy_color/dcgnuje/
    static CRGB currentColor = CRGB(CHSV(_startHue, 255, 255));
    static CRGB lastColor = currentColor;
    static CRGB targetColor = currentColor;
    static uint8_t hue = _startHue;
    static uint8_t step = 0;

    currentColor = blend(lastColor, targetColor, 255 / 8 * step++);
    if(step > 8) {
        step = 0;
        lastColor = targetColor;
        hsv2rgb_rainbow(CHSV(hue++, 255, 255), targetColor);
    }
    colorAllLeds(currentColor);
}