#include "mapping.h"

int mappingPeripheral(struct BCM2837 *bcm) {
	if ((bcm -> memory_fd = open("/dev/mem", O_RDWR|O_SYNC) ) < 0) {
      		printf("Oeffnen von /dev/mem fehlgeschlagen. \n");
		printf("Fuehren Sie das Programm als root aus. \n");

		return -1;
	}

	/*Mapping: virtuelle Adresse -> Physikalische Adresse. */
   	bcm -> mmap = mmap(
      		NULL,
      		BLOCK_SIZE,
      		PROT_READ|PROT_WRITE,
      		MAP_SHARED,
      		bcm -> memory_fd,      /*File descriptor to physical memory virtual file '/dev/mem'*/
      		GPIO_ADDRESS       /*Address in physical map that we want this memory block to expose*/
   	);
 
   	if (bcm -> mmap == MAP_FAILED) {
        	printf("mmap ist fehlgeschlagen. \n");
        	return -1;
   	}
 
   	bcm->virtualAdd = (volatile unsigned int *)bcm -> mmap;

	return 0;
}


void unmappingPeripheral(struct BCM2837 *bcm) {
	munmap(bcm -> mmap, BLOCK_SIZE); 
	close(bcm -> memory_fd);


}

