#include <Arduino.h>
#include <FastLED.h>

#define numberOfLEDs 61
#define controlPin 5

CRGB leds[numberOfLEDs];
bool up;
int blue;

void showLED(int *rgb) {
  for (int thisLED = 0; thisLED < numberOfLEDs; thisLED++) {
    leds[thisLED].r = rgb[0];
    leds[thisLED].g = rgb[1];
    leds[thisLED].b = rgb[2];    
  }
  FastLED.show();
}

void setup() {
  FastLED.addLeds<WS2812B, controlPin, GRB>(leds, numberOfLEDs);
  FastLED.setBrightness(200);  // 光度を設定（最大255）
  Serial.begin(9600);
  up = true;
  blue = 50;
}

void loop() {
  if(up) {
    if (blue <= 240) {
      blue += 10;
    } else {
      up = false;
    }
  } else {
    if (blue > 50) {
      blue -= 10;
    } else {
      up = true;
    }
  }
  
  int rgb[3] = {255, 0, blue};
  showLED(rgb);  
  delay(60);    
}
