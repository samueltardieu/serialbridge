#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <stropts.h>
#include <linux/termios.h>

#include "speed.h"

int main(int argc, char *argv[]) {
  if (argc != 3)
    goto error;
  int speed = atoi(argv[2]);
  if (speed == 0)
    goto error;
  int fd = open(argv[1], O_RDWR);
  if (fd < 0) {
    perror("open");
    exit(1);
  }
  setspeed(fd, speed);
  exit(0);
 error:
  fprintf(stderr, "Usage: %s port speed\n", argv[0]);
  exit(1);
}
