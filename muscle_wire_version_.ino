
//Analog pin 1 for reading in the analog voltage from the MaxSonar device.
//This variable is a constant because the pin will not change throughout execution of this code.


//variables needed to store values
long anVolt, inches, cm;
int sum = 0; //Create sum variable so it can be averaged
int avgrange = 60; //Quantity of values to average (sample size)

int tissues = 0;

#include <Adafruit_NeoPixel.h>

#define PIN 6
#define NUM_LEDS 2
Adafruit_NeoPixel strip = Adafruit_NeoPixel(2, PIN, NEO_GRB + NEO_KHZ800);

void setup()
{
  //This opens up a serial connection to shoot the results back to the PC console
  Serial.begin(9600);

  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  strip.setBrightness(155);
}

void loop()
{
  //MaxSonar Analog reads are known to be very sensitive. See the Arduino forum for more information.
  //A simple fix is to average out a sample of n readings to get a more consistent reading.
  //Even with averaging I still find it to be less accurate than the PW method.
  //This loop gets 60 reads and averages them

  for (int i = 0; i < avgrange ; i++)
  {
    //Used to read in the analog voltage output that is being sent by the MaxSonar device.
    //Scale factor is (Vcc/512) per inch. A 5V supply yields ~9.8mV/in
    //Arduino analog pin goes from 0 to 1024, so the value has to be divided by 2 to get the actual inches
    anVolt = analogRead(A10);
    sum += anVolt;
    delay(10);
  }


  inches = sum / avgrange;
  cm = inches * 2.54;

  //reset sample total
  sum = 0;
  Serial.println(anVolt);
  delay(500);
  if (anVolt < 30) {
    digitalWrite (9, HIGH);
    digitalWrite (12, LOW);
    tissues = tissues + 1;
    delay(3000);
  } else {
    digitalWrite (9, LOW);
    digitalWrite (12, HIGH);
  }
  if (tissues == 0) {
    for (uint16_t i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, 255, 255, 255);
      strip.show();
    }
  }

  if (tissues == 1) {
    for (uint16_t i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, 255, 198, 207);
      strip.show();
    }
  }

  if (tissues == 2) {
    for (uint16_t i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, 255, 173, 185);
      strip.show();
    }
  }

  if (tissues == 3) {
    for (uint16_t i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, 255, 240, 240);
      strip.show();
    }
  }

  if (tissues == 4) {
    for (uint16_t i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(1, 255, 147, 163);
      strip.show();
    }
  }

  if (tissues == 5) {
    for (uint16_t i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, 255, 117, 137);
      strip.show();
    }
  }

  if (tissues == 6) {
    for (uint16_t i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, 255, 91, 116);
      strip.show();
    }
  }

  if (tissues == 7) {
    for (uint16_t i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, 255, 66, 94);
      strip.show();
    }
  }

  if (tissues == 8) {
    for (uint16_t i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, 255, 47, 77);
      strip.show();
    }
  }

  if (tissues == 9) {
    for (uint16_t i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, 225, 28, 62);
      strip.show();
    }
  }

  if (tissues == 10) {
    for (uint16_t i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, 255, 0, 0);
      strip.show();
    }
  }

}

