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

void LEDArray::init_randbow(){
	CHSV current=CHSV(random(255),255,255);
	CHSV prev=CHSV(random(255),255,255);
	CHSV first=prev;
	int width=20;
	int i;
	for(i=0; i<num_leds-width; i+=width){
		fill_gradient(leds,i,prev,i+width,current,SHORTEST_HUES);		
		prev=current;
		current=CHSV(random(255),255,255);
	}
	
	fill_gradient(leds,i,prev,num_leds,first,SHORTEST_HUES);		
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

void LEDArray::rotate_hue(){
	for(int i=0; i<num_leds; i++){
			CHSV hsv=rgb2hsv_approximate(leds[i]);
			hsv.hue=(( (int) hsv.hue)+10) % 256;
			//hsv.hue=3;
			leds[i] = hsv;
		}
		
	
}


void LEDArray::blur(){
	CHSV prev=CHSV(random(255),255,255);
	CHSV current=rgb2hsv_approximate(leds[0]);
	CHSV next;
	int i;
	for(i=0; i<num_leds-1; i++){
		CHSV next=rgb2hsv_approximate(leds[i+1]);
		leds[i]=CHSV(0.3*prev.hue+0.4*current.hue+0.3*prev.hue,255,255);
		prev=current;
		current=next;
	}
	
	next=CHSV(random(255),255,255);
	leds[i]=CHSV(0.3*prev.hue+0.4*current.hue+0.3*prev.hue,255,255);
}

