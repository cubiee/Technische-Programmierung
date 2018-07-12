#ifndef PI_H
#define PI_H

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>

/*Startadressen*/
#define ARM_ADDRESS 0x3F000000
#define GPIO_OFFSET 0x200000
#define GPIO_ADDRESS (ARM_ADDRESS + GPIO_OFFSET)

struct BCM2837 {
    unsigned long address;
    int memory_fd;
    void *mmap;
    volatile unsigned int *virtualAdd;
};

#endif
