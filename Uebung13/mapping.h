#ifndef MAPPING_H
#define MAPPING_H

#include "PI.h"


/*Mapping Konstante*/
#define BLOCK_SIZE (4*1024)

int mappingPeripheral(struct BCM2837 *bcm);
void unmappingPeripheral(struct BCM2837 *bcm);


#endif
