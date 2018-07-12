#ifndef GPIO_H
#define GPIO_H

#include "PI.h"

#define HIGH 1
#define LOW  0

void setAsInput(struct BCM2837 *gpio, int pin);
void setAsOutput(struct BCM2837 *gpio, int pin);

int setPinLevel(struct BCM2837 *gpio, int pin, int state);

int readPin(struct BCM2837 *gpio, int pin);

#endif