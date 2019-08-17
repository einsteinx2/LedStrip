#include "RgbLed.h"

RgbLed::RgbLed(uint8_t redPin, uint8_t greenPin, uint8_t bluePin) {
    _redPin = redPin;
    _greenPin = greenPin;
    _bluePin = bluePin;
}

void RgbLed::setColor(CRGB color) {
    analogWrite(_redPin, color.r); 
    analogWrite(_greenPin, color.g); 
    analogWrite(_bluePin, color.b);
}