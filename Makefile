UNAME=$(shell uname)

CCFLAGS=-Wall -O3 -std=gnu99
CC=gcc
LIBS = -lm

all: tst

tst: main.o slider.o physics_model.o buttons.o fifo.o ctest.h unit_tests.o
	$(CC) $(LDFLAGS) main.o slider.o physics_model.o buttons.o fifo.o unit_tests.o -o unittest $(LIBS)

remake: clean all

%.o: %.c ctest.h
	$(CC) $(CCFLAGS) -c -o $@ $<

clean:
	rm -f unittest *.o
