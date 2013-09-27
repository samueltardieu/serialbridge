CC = gcc
CFLAGS = -std=c99 -O3 -Wall -Wextra
RM = rm -f

PROGS = serialbridge setspeed

.PHONY: all clean

all: $(PROGS)

clean:
	$(RM) $(PROGS)

setspeed: setspeed.c
	$(CC) $(CFLAGS) -o setspeed setspeed.c

serialbridge: serialbridge.c
	$(CC) $(CFLAGS) -o serialbridge serialbridge.c
