#include "LedStrip.h"

LedStrip::LedStrip(int numLeds, int dataPin, int defaultBrightness, uint8_t startHue) {
    _numLeds = numLeds;
    _dataPin = dataPin;
    _defaultBrightness = defaultBrightness;
    _startHue = startHue;

    leds = new CRGB[numLeds];

    // Get around C++ template limits to allow dynamically setting the data pin
    switch (dataPin) {
        #if MAX_PIN >= 0
        case  0: FastLED.addLeds<NEOPIXEL,  0>(leds, numLeds); break;
        #endif
        #if MAX_PIN >= 1
        case  1: FastLED.addLeds<NEOPIXEL,  1>(leds, numLeds); break;
        #endif
        #if MAX_PIN >= 2
        case  2: FastLED.addLeds<NEOPIXEL,  2>(leds, numLeds); break;
        #endif
        #if MAX_PIN >= 3
        case  3: FastLED.addLeds<NEOPIXEL,  3>(leds, numLeds); break;
        #endif
        #if MAX_PIN >= 4
        case  4: FastLED.addLeds<NEOPIXEL,  4>(leds, numLeds); break;
        #endif
        #if MAX_PIN >= 5
        case  5: FastLED.addLeds<NEOPIXEL,  5>(leds, numLeds); break;
        #endif
        #if MAX_PIN >= 6
        case  6: FastLED.addLeds<NEOPIXEL,  6>(leds, numLeds); break;
        #endif
        #if MAX_PIN >= 7
        case  7: FastLED.addLeds<NEOPIXEL,  7>(leds, numLeds); break;
        #endif
        #if MAX_PIN >= 8
        case  8: FastLED.addLeds<NEOPIXEL,  8>(leds, numLeds); break;
        #endif
        #if MAX_PIN >= 9
        case  9: FastLED.addLeds<NEOPIXEL,  9>(leds, numLeds); break;
        #endif
        #if MAX_PIN >= 10
        case 10: FastLED.addLeds<NEOPIXEL, 10>(leds, numLeds); break;
        #endif
        #if MAX_PIN >= 11
        case 11: FastLED.addLeds<NEOPIXEL, 11>(leds, numLeds); break;
        #endif
        #if MAX_PIN >= 12
        case 12: FastLED.addLeds<NEOPIXEL, 12>(leds, numLeds); break;
        #endif
        #if MAX_PIN >= 13
        case 13: FastLED.addLeds<NEOPIXEL, 13>(leds, numLeds); break;
        #endif
        #if MAX_PIN >= 14
        case 14: FastLED.addLeds<NEOPIXEL, 14>(leds, numLeds); break;
        #endif
        #if MAX_PIN >= 15
        case 15: FastLED.addLeds<NEOPIXEL, 15>(leds, numLeds); break;
        #endif
        #if MAX_PIN >= 16
        case 16: FastLED.addLeds<NEOPIXEL, 16>(leds, numLeds); break;
        #endif
        #if MAX_PIN >= 17
        case 17: FastLED.addLeds<NEOPIXEL, 17>(leds, numLeds); break;
        #endif
        #if MAX_PIN >= 18
        case 18: FastLED.addLeds<NEOPIXEL, 18>(leds, numLeds); break;
        #endif
        #if MAX_PIN >= 19
        case 19: FastLED.addLeds<NEOPIXEL, 19>(leds, numLeds); break;
        #endif
        #if MAX_PIN >= 20
        case 20: FastLED.addLeds<NEOPIXEL, 20>(leds, numLeds); break;
        #endif
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

CRGB LedStrip::rainbowEffect() {
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

    return currentColor;
}