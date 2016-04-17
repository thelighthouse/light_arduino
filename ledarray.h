#ifndef LEDARRAY_H
#define LEDARRAY_H

class LEDArray
{
	public:
		LEDArray(struct CRGB *_leds, long _NUM_LEDS);
		
	// initialization utilities	
		void init_noise();
		void init_rainbow();
		void init_single();
	// animation utilities
		void rotate();
		
	//private:
		long num_leds;
		struct CRGB *leds;

};

#endif