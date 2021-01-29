#include <Adafruit_NeoPixel.h>
#include <Adafruit_CircuitPlayground.h>

//define is for constants
#define LED_PIN    A9
#define ANALOG_INPUT  A10
#define LED_COUNT 5
#define VALUE_MIN     5
#define VALUE_MAX     1000

//variables are for things that might change
byte stepVal = (VALUE_MAX-VALUE_MIN)/LED_COUNT;
byte red = 60;
byte green = 87;
byte blue = 174;
uint8_t pixeln = 0;

Adafruit_CPlay_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
    Serial.begin(9600); //confirm this setting

    CircuitPlayground.begin();

    strip.begin();           
    strip.show();            
    strip.setBrightness(100); //255 is maximum
}

void loop() {
  // put your main code here, to run repeatedly:
  uint16_t value = analogRead(ANALOG_INPUT);
  Serial.println(value, DEC);
  //Serial.println(stepVal);

    if (value < (VALUE_MAX/1.75)) {
    CircuitPlayground.speaker.enable(false);
  } else {
    CircuitPlayground.speaker.enable(true);
    CircuitPlayground.playTone(500 + pixeln * 500, 50);
    if (value > (VALUE_MAX/1.25)) {
      CircuitPlayground.playTone(600 + pixeln * 500, 200);
    }
    if (value > (VALUE_MAX/1.1)) {
      CircuitPlayground.playTone(400 + pixeln * 500, 300);
    }
  }
  delay(10);

  if (value < VALUE_MIN) {
    strip.begin();
    strip.setPixelColor(0, 255,   0,   255);         //  Set pixel's color (in RAM)
    strip.show();
    delay(100); 
  }
  for(int i=0; i<5; i++) {
    if (value> stepVal*i) {
      strip.setPixelColor(i,  0,  255,   255);         //  Set pixel's color (in RAM)
      if (i == 1) {
        strip.setPixelColor(i,  34,  139,   34);
      }
      if (i == 2) {
        strip.setPixelColor(i,  0, 255,   0);
      }
      if (i == 3) {
        strip.setPixelColor(i,  255, 69,   0);
      }
      if (i == 4) {
        strip.setPixelColor(i,  139, 0,   0);
      }
    strip.show();
  }}
      delay(5);  
      strip.clear(); 
}
