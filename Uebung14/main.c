#include "mapping.h"
#include "HTW-Uebung-13.h"

int main(int argc, char *argv[]) {
	struct BCM2837 gpio;
	mappingPeripheral(&gpio);

	setAllLedAsOutput(&gpio);
	
	int i = 0;

	for (i = 0; i < 10; i++){
		lauflicht(&gpio, SEC_MICRO(0.9), SEC_MICRO(0.1), ClOCKWISE);
	}

	for (i = 0; i < 5; i++){
		blinkAllLED(&gpio, SEC_MICRO(0.5), SEC_MICRO(0.5));
	}
	
	unmappingPeripheral(&gpio);
	return 0;
}


