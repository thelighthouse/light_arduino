#ifndef LEDARRAY_H
#define LEDARRAY_H

class LEDArray
{
	public:
		LEDArray(struct CRGB *_leds, long _NUM_LEDS);
		
	// initialization utilities	
		void init_noise();
		void init_rainbow();
		void init_randbow();
		void init_single();
	// animation utilities
		void rotate();
		void rotate_hue();
		void blur();
		void rand_swap();
		void rand_swapn();
		void rand_hue();
		void rand_huen();
	//private:
		long num_leds;
		struct CRGB *leds;

};

#endif