#include <FastLED.h>
#include "ledarray.h"

LEDArray::LEDArray(struct CRGB *_leds, long _NUM_LEDS){
	leds=_leds;
	num_leds=_NUM_LEDS;
}

void LEDArray::init_noise(){
	for(int i=0; i<num_leds; i++){
			leds[i] = CHSV(random(255),255,255);
		}
}

void LEDArray::init_rainbow(){
	fill_gradient(leds,num_leds,CHSV(0,255,255),CHSV(1,255,255),LONGEST_HUES);
}

void LEDArray::init_single(){
	fill_solid(leds,num_leds,CHSV(0,0,0));
	leds[1]=CRGB(255,255,255);
}

void LEDArray::rotate(){
	CRGB led0=leds[0];
	for(int i=0; i<num_leds-1; i++){
			leds[i] = leds[i+1];
		}
		
	leds[num_leds-1]=led0;
}