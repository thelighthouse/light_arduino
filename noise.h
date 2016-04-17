#ifndef NOISE_H
#define NOISE_H

#include "animation.h"

class Noise : public Animation {
public:
	Noise(LEDArray *ledarray)
	{
		ledarray->init_single();
		FastLED.show();

	}
	
	void step(LEDArray *ledarray)
	{
		ledarray->rotate();
		FastLED.show();
	}
};

Animation * noise_factory(LEDArray *ledarray) {
  return new Noise(ledarray);  
} 

#endif