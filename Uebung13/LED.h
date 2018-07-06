#ifndef LED_H
#define LED_H

#include "PI.h"

/*LED Pins*/
#define RED_LED         23
#define BLUE_LED        24
#define GREEN_LED       18
#define YELLOW_LED      25

/*Drehrichtung*/
#define ClOCKWISE        1
#define ANTIClOCKWISE    0

#define MICRO(seconds)  (seconds * 1000000)


void setAllLedAsOutput(struct BCM2837 *gpio);
void setRedLedAsOutput(struct BCM2837 *gpio);
void setBlueLedAsOutput(struct BCM2837 *gpio);
void setGreenLedAsOutput(struct BCM2837 *gpio);
void setYellowLedAsOutput(struct BCM2837 *gpio);

void setOnLED(struct BCM2837 *gpio, int led);
void setOnAllLED(struct BCM2837 *gpio);
void setOffLED(struct BCM2837 *gpio, int led);
void setOffAllLED(struct BCM2837 *gpio);

void blinkLED(struct BCM2837 *gpio, int led, int useconds);
void blinkAllLED(struct BCM2837 *gpio, int useconds);

void lauflicht(struct BCM2837 *gpio, int useconds, int direction);
#endif
