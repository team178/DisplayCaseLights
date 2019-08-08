#include <Adafruit_NeoPixel.h>
#include <Wire.h>

#define PIN 3
int numOfPixels = 59; //update this based on the number of pixels we are using

uint32_t YELLOW1;
uint32_t BLUE1;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(numOfPixels, PIN, NEO_GRB + NEO_KHZ800);
int frame = 0;

void setup() {
  YELLOW1 = strip.Color(255,208,0);
  BLUE1 = strip.Color(15,8,56);
  strip.begin();
  strip.setBrightness(50);
  strip.show();
  Serial.println("Starting...");

}

void loop() {
    setStripYellow();
    delay(5000);
    setStripBlue();
    delay(5000);
    turnOff();
    delay(100000);
}

void setStripYellow() {
  for (int i = 0; i <= numOfPixels; i++) {
    strip.setPixelColor(i, YELLOW1);
  }
  strip.show();
}

void setStripBlue() {
  for (int i = 0; i <= numOfPixels; i++) {
    strip.setPixelColor(i, BLUE1);
  }
  strip.show();
}

void turnOff() {
  for (int i = 0; i <= numOfPixels; i++) {
    strip.setPixelColor(i, 0, 0, 0);
  }
  strip.show();
}
}
