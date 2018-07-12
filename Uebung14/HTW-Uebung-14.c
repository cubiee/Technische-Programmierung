#include "HTW-Uebung-14.h"
#include "GPIO.h"

/*set as output*/
void setAllLedAsOutput(struct BCM2837 *gpio){
	setAsOutput(gpio, RED_LED);
	setAsOutput(gpio, BLUE_LED);
	setAsOutput(gpio, GREEN_LED);
	setAsOutput(gpio, YELLOW_LED);
}

/*set as input*/
void setAllButtonAsInput(struct BCM2837 *gpio){
	setAsInput(gpio, BUTTON_1);
	setAsInput(gpio, BUTTON_2);
	setAsInput(gpio, BUTTON_3);
	setAsInput(gpio, BUTTON_4);
}

/*set on led*/
void setOnAllLED(struct BCM2837 *gpio){
	setPinLevel(gpio, RED_LED, HIGH);
	setPinLevel(gpio, BLUE_LED, HIGH);
	setPinLevel(gpio, GREEN_LED, HIGH);
	setPinLevel(gpio, YELLOW_LED, HIGH);
}

/*set off led*/
void setOffAllLED(struct BCM2837 *gpio){
	setPinLevel(gpio, RED_LED, LOW);
	setPinLevel(gpio, BLUE_LED, LOW);
	setPinLevel(gpio, GREEN_LED, LOW);
	setPinLevel(gpio, YELLOW_LED, LOW);
}

/*blink*/
void blinkLED(struct BCM2837 *gpio, int led, int ontime, int offtime){
	setPinLevel(gpio, led, HIGH);
	usleep(ontime);
	setPinLevel(gpio, led, LOW);
	usleep(offtime);
}

void blinkAllLED(struct BCM2837 *gpio, int ontime, int offtime){
	setOnAllLED(gpio);
	usleep(ontime);
	setOffAllLED(gpio);
	usleep(offtime);
}

/*Uebung 14*/