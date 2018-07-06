#include "LED.h"

//Define as output
void setAllLedAsOutput(struct BCM2837 *gpio){
	setRedLedAsOutput(gpio);
	setBlueLedAsOutput(gpio);
	setYellowLedAsOutput(gpio);
	setGreenLedAsOutput(gpio);
}

void setRedLedAsOutput(struct BCM2837 *gpio) {
	*(gpio->virtualAdd + 2) |= (1 << 9);
}

void setBlueLedAsOutput(struct BCM2837 *gpio) {
	*(gpio->virtualAdd + 2) |= (1 << 12);
}

void setYellowLedAsOutput(struct BCM2837 *gpio) {
	*(gpio->virtualAdd + 2) |= (1 << 15);
}

void setGreenLedAsOutput(struct BCM2837 *gpio) {
	*(gpio->virtualAdd + 1) |= (1 << 24);
}

//Set on or off
void setOnLED(struct BCM2837 *gpio, int led) {
	unsigned int bitmask = 1U << (led % 32);
	unsigned int registeroffset = (led / 32);
	*(gpio->virtualAdd + 7 + registeroffset) = bitmask;
}

void setOnAllLED(struct BCM2837 *gpio) {
	setOnLED(gpio, RED_LED);
	setOnLED(gpio, BLUE_LED);
	setOnLED(gpio, YELLOW_LED);
	setOnLED(gpio, GREEN_LED);
}

void setOffLED(struct BCM2837 *gpio, int led) {
	unsigned int bitmask = 1U << (led % 32);
	unsigned int registeroffset = (led / 32);
	*(gpio->virtualAdd + 10 + registeroffset) = bitmask;
}

void setOffAllLED(struct BCM2837 *gpio) {
	setOffLED(gpio, RED_LED);
	setOffLED(gpio, BLUE_LED);
	setOffLED(gpio, YELLOW_LED);
	setOffLED(gpio, GREEN_LED);
}

//blink
void blinkLED(struct BCM2837 *gpio, int led, int useconds){
	setOnLED(gpio, led);
	usleep(useconds);
	setOffLED(gpio, led);
}

void blinkAllLED(struct BCM2837 *gpio, int useconds){
	setOnAllLED(gpio);
	usleep(useconds/2);
	setOffAllLED(gpio);
	usleep(useconds/2);
}

//lauflicht
void lauflicht(struct BCM2837 *gpio, int useconds, int direction){
	if (direction){
		blinkLED(gpio, RED_LED, useconds / 4);
		blinkLED(gpio, BLUE_LED, useconds / 4);
		blinkLED(gpio, YELLOW_LED, useconds / 4);
		blinkLED(gpio, GREEN_LED, useconds / 4);
	}
	else{
		blinkLED(gpio, GREEN_LED, useconds / 4);
		blinkLED(gpio, YELLOW_LED, useconds / 4);
		blinkLED(gpio, BLUE_LED, useconds / 4);
		blinkLED(gpio, RED_LED, useconds / 4);
	}
	
}
