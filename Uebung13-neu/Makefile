PROGRAM = led
OBJECTS = main.o HTW-Uebung-13.o GPIO.o mapping.o
#--------- ab hier nicht mehr �ndern
DEPENDFILE = .depend
CC=gcc
CFLAGS=-Wall -pedantic 

.PHONY: all
all: dep $(PROGRAM)

$(PROGRAM) : $(OBJECTS)
	$(CC) $(OBJECTS) -o $(PROGRAM)

%.o : %.c
	$(CC) -c $(CFLAGS) $< -o $@

.PHONY: dep
dep: *.c
	gcc -MM *.c > $(DEPENDFILE)

-include $(DEPENDFILE)

.PHONY: clean
clean:
	rm  -rf *.o