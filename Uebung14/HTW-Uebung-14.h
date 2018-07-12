#ifndef HTW_UEBUNG_14_H
#define HTW_UEBUNG_14_H

#include "GPIO.h"
#include "Random.h"

/*Button Pins*/
#define BUTTON_1         4
#define BUTTON_2        17
#define BUTTON_3        22
#define BUTTON_4        27

/*LED Pins*/
#define RED_LED         23
#define BLUE_LED        24
#define GREEN_LED       18
#define YELLOW_LED      25

/*Drehrichtung*/
#define ClOCKWISE        1
#define ANTIClOCKWISE    0

/*Hilfsmakros*/
#define SEC_MICRO(seconds)  (seconds * 1000000)

/*set as output*/
void setAllLedAsOutput(struct BCM2837 *gpio);

/*set as input*/
void setAllButtonAsInput(struct BCM2837 *gpio);

/*set on led*/
void setOnAllLED(struct BCM2837 *gpio);

/*set off led*/
void setOffAllLED(struct BCM2837 *gpio);

/*blink*/
void blinkLED(struct BCM2837 *gpio, int led, int ontime, int offtime);
void blinkAllLED(struct BCM2837 *gpio, int ontime, int offtime);

/*Uebung 14*/


#endif