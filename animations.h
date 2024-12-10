#ifndef ANIMATIONS_H
#define ANIMATIONS_H

#include <Adafruit_NeoPixel.h>

// NeoPixel Settings
#define PIN 6        // Pin connected to the LED ring
#define NUMPIXELS 24 // Number of LEDs in the ring

void setupAnimations();
void colorWipe(uint32_t color, int wait);
void theaterChase(uint32_t color, int wait);
void rainbow(int wait);
void loopAnimations();

#endif