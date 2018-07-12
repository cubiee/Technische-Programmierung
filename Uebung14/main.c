#include "mapping.h"
#include "HTW-Uebung-14.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
	struct BCM2837 gpio;
	mappingPeripheral(&gpio);

	setAllButtonAsInput(&gpio);
	
	
	

	unmappingPeripheral(&gpio);
	return 0;
}


