#include "GPIO.h"


void setAsInput(struct BCM2837 *gpio, int button){
	unsigned int bitmask = ~(7U << ((button % 10) * 3));
	unsigned int offset = button / 10;
	*(gpio->virtualAdd + offset) &= bitmask;
}

void setAsOutput(struct BCM2837 *gpio, int led){
	unsigned int bitmask = 1U << ((led % 10) * 3);
	unsigned int offset = led / 10;
	*(gpio->virtualAdd + offset) |= bitmask;
}

int setPinLevel(struct BCM2837 *gpio, int pin, int state){
	if (state == HIGH){
		unsigned int bitmask = 1U << (pin % 32);
		unsigned int registeroffset = (pin / 32);
		*(gpio->virtualAdd + 7 + registeroffset) = bitmask;
		state = HIGH;
	}
	else if (state == LOW){
		unsigned int bitmask = 1U << (pin % 32);
		unsigned int registeroffset = (pin / 32);
		*(gpio->virtualAdd + 10 + registeroffset) = bitmask;
		state = LOW;
	}
	else{
		state = -1;
	}
	return state;
}

int readPin(struct BCM2837 *gpio, int pin){
	unsigned int bitmask = 1U << (pin % 32);
	unsigned int registeroffset = (pin / 32);
	unsigned int state = (*(gpio->virtualAdd + 13 + registeroffset) & bitmask);
	if (state == 0){
		state = LOW;
	}
	else{
		state = HIGH;
	}
	return state;
}

