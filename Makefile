CC = gcc
CFLAGS = -std=c99 -O3 -Wall -Wextra
LD = gcc
LDFLAGS = -O
RM = rm -f

PROGS = serialbridge setspeed

.PHONY: all clean

all: $(PROGS)

clean:
	$(RM) *.o $(PROGS)

setspeed: setspeed.o speed.o

serialbridge: serialbridge.o speed.o

serialbridge.o: serialbridge.c check.h speed.h

speed.o: speed.c check.h speed.h

setspeed.o: setspeed.c speed.h
