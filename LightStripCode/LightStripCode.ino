#include <Adafruit_NeoPixel.h>
#include <Wire.h>

#define PIN 3
int numOfPixels = 12; //update this based on the number of pixels we are using

Adafruit_NeoPixel strip = Adafruit_NeoPixel(numOfPixels, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.setBrightness(50);
  strip.show();
  Serial.begin(9600);
  Serial.println("Starting...");

}

void loop() {
    setStripYellow();
    delay(5000);
    setStripBlue();
    delay(5000);
    rainbow();
    turnOff();
    delay(5000);
}

void setStripYellow() {
  Serial.println("Setting color to yellow...");
  for (int i = 0; i <= numOfPixels; i++) {
    strip.setPixelColor(i, 255, 208, 0);
  }
  strip.show();
}

void setStripBlue() {
  Serial.println("Setting color to blue...");
  for (int i = 0; i <= numOfPixels; i++) {
    strip.setPixelColor(i, 15, 8, 56);
  }
  strip.show();
}

void rainbow() {
  Serial.println("Setting strip to rainbow...");
  for (int i = 0; i < numOfPixels; i++) {
    strip.setPixelColor(i, 255, 0, 0);
  }
  strip.show();
  delay(1000);
  for (int i = 0; i < numOfPixels; i++) {
    strip.setPixelColor(i, 255, 165, 0);
  }
  strip.show();
  delay(1000);
  for (int i = 0; i < numOfPixels; i++) {
    strip.setPixelColor(i, 255, 255, 0);
  }
  strip.show();
  delay(1000);
  for (int i = 0; i < numOfPixels; i++) {
    strip.setPixelColor(i, 0, 255, 0);
  }
  strip.show();
  delay(1000);
  for (int i = 0; i < numOfPixels; i++) {
    strip.setPixelColor(i, 0, 0, 255);
  }
  strip.show();
  delay(1000);
}

void turnOff() {
  for (int i = 0; i <= numOfPixels; i++) {
    strip.setPixelColor(i, 0, 0, 0);
  }
  strip.show();
}
