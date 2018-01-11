/* Start of Code */

#include "FastLED.h"

// How many leds are connected?
#define NUM_LEDS 64

// Define the Pins
#define DATA_PIN 6

// Define the array of leds
CRGB leds[NUM_LEDS];

// Put color values in arrays
long invader1a[] =
{
0x008000, 0x000000, 0x000000,0x000000,0x000000,0x000000,0x000000, 0x008000,
0x008000, 0xFFFF00, 0x0000FF, 0xFFFF00, 0xFFFF00, 0x0000FF, 0xFFFF00, 0x008000,
0x008000, 0x000000, 0xFFFF00, 0x800080, 0x800080, 0xFFFF00, 0x000000, 0x008000,
0x000000, 0x000000, 0x000000, 0xFF0000, 0xFF0000, 0x000000, 0x000000, 0x000000
};

long invader1b[] =
{
0x000000, 0x000000, 0x0000FF, 0xFFFF00, 0xFFFF00, 0x0000FF, 0x000000, 0x000000,
0x000000, 0x008000, 0xFFFF00, 0x800080, 0x800080, 0xFFFF00, 0x008000, 0x000000,
0x008000, 0x000000, 0x000000, 0xFFFF00, 0xFFFF00, 0x000000, 0x000000, 0x008000,
0x000000, 0x008000, 0x000000, 0xFF0000, 0xFF0000, 0x000000, 0x008000, 0x000000
};


void setup() { 
FastLED.addLeds<NEOPIXEL,DATA_PIN>(leds, NUM_LEDS);
}

void loop() { 

int val = 950;
if (val < 1000) {

// Map the pot values to 0 - Number of Leds
int numLedsToLight = map(val, 0, 950, 0, NUM_LEDS);

// Clear the existing led values
FastLED.clear();

// Change led colors
for(int led = 0; led < numLedsToLight; led++) { 
if(led < (NUM_LEDS/3) )leds[led] = CRGB::Green;
if(led >= (NUM_LEDS/3) & led < ((NUM_LEDS/3)*2) )leds[led] = CRGB::Orange;
if(led >= ((NUM_LEDS/3)*2) )leds[led] = CRGB::Red;
}

FastLED.setBrightness(50);
FastLED.show();
}
}

/* End of Code */
