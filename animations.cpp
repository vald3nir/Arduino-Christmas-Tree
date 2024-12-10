#include "animations.h"

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayTime = 100;

void setupAnimations()
{
    strip.begin();
    strip.show();
}

void colorWipe(uint32_t color, int wait)
{
    for (int i = 0; i < strip.numPixels(); i++)
    {
        strip.setPixelColor(i, color);
        strip.show();
        delay(wait);
    }
}

void theaterChase(uint32_t color, int wait)
{
    for (int j = 0; j < 10; j++)
    {
        for (int q = 0; q < 3; q++)
        {
            for (int i = 0; i < strip.numPixels(); i += 3)
            {
                strip.setPixelColor(i + q, color);
            }
            strip.show();
            delay(wait);
            for (int i = 0; i < strip.numPixels(); i += 3)
            {
                strip.setPixelColor(i + q, 0);
            }
        }
    }
}

void rainbow(int wait)
{
    for (long firstPixelHue = 0; firstPixelHue < 5 * 65536; firstPixelHue += 256)
    {
        for (int i = 0; i < strip.numPixels(); i++)
        {
            int pixelHue = firstPixelHue + (i * 65536L / strip.numPixels());
            strip.setPixelColor(i, strip.gamma32(strip.ColorHSV(pixelHue)));
        }
        strip.show();
        delay(wait);
    }
}

void loopAnimations()
{
    // Effect: Flashes all colors
    colorWipe(strip.Color(255, 0, 0), delayTime); // RED
    colorWipe(strip.Color(0, 255, 0), delayTime); // GREEN
    colorWipe(strip.Color(0, 0, 255), delayTime); // BLUE

    // Effect: Theater
    theaterChase(strip.Color(127, 127, 127), 50); // WRITE
    theaterChase(strip.Color(127, 0, 0), 50);     // RED
    theaterChase(strip.Color(0, 0, 127), 50);     // BLUE

    // Effect: Rainbow
    rainbow(20);
}