#include <FastLED.h>
#include <PacketSerial.h>
#define LED_TYPE    NEOPIXEL
#define COLOR_ORDER RGB
#define framerate   500
//#define COLOR_CORRECTION CRGB(255,172,240)
#define BRIGHTNESS  125
#define NUM_STRIPS 5
#define NUM_LEDS_PER_STRIP 240
#define NUM_LEDS 1118
CRGB leds[NUM_LEDS];

#include "ledarray.h"
#include "animation.h"
#include "noise.h"

#define NUM_ANIMATIONS 1
Animation * current_animation;
Animation *(*list[NUM_ANIMATIONS])(LEDArray * ledarray);
LEDArray *ledarray;

void setup() {
  
   // power-up sanity delay
  pinMode(12, INPUT); 
  
  //delay( 3000 );
  
  // tell FastLED about the LEDs
  FastLED.addLeds<NEOPIXEL, 2>(leds, 0*NUM_LEDS_PER_STRIP, NUM_LEDS_PER_STRIP);
  FastLED.addLeds<NEOPIXEL, 3>(leds, 1*NUM_LEDS_PER_STRIP, NUM_LEDS_PER_STRIP);
  FastLED.addLeds<NEOPIXEL, 6>(leds, 2*NUM_LEDS_PER_STRIP, NUM_LEDS_PER_STRIP);
  FastLED.addLeds<NEOPIXEL, 4>(leds, 3*NUM_LEDS_PER_STRIP, NUM_LEDS_PER_STRIP);
  FastLED.addLeds<NEOPIXEL, 5>(leds, 4*NUM_LEDS_PER_STRIP, 158);
  
  
  //FastLED.addLeds<NEOPIXEL, 4>(leds, 0*NUM_LEDS_PER_STRIP, NUM_LEDS_PER_STRIP);
  
  // set master brightness control
  FastLED.setBrightness(BRIGHTNESS);
  //fill_solid(leds,NUM_LEDS,CHSV(128,255,128));
  FastLED.show();
  ledarray=new LEDArray(leds,NUM_LEDS);
  
  list[0] = &noise_factory;
  //list[1] = &foobar_factory;
  
  current_animation = list[0](ledarray);
  
}

// loop is called repeatedly forever
void loop()
{
  current_animation->step(ledarray); 
  /*if(digitalRead(12)==HIGH){
     fill_solid(leds,NUM_LEDS,CHSV(64,255,128));

  } else {
    fill_solid(leds,NUM_LEDS,CHSV(192,255,128));    
  }
  
  FastLED.show();   */
}
