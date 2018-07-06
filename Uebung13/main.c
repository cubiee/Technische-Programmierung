#include "mapping.h"
#include "LED.h"

int main(int argc, char *argv[]) {
	struct BCM2837 gpio;
	mappingPeripheral(&gpio);

	setAllLedAsOutput(&gpio);
	
	int i = 0;

	for (i = 0; i < 20; i++){
		lauflicht(&gpio, MICRO(1), ClOCKWISE);
	}

	for (i = 0; i < 5; i++){
		blinkAllLED(&gpio, MICRO(0.5));
	}
	
	unmappingPeripheral(&gpio);
	return 0;
}


