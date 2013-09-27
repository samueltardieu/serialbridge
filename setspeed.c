#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <stropts.h>
#include <linux/termios.h>

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
  struct termios2 t;
  if (ioctl(fd, TCGETS2, &t)) {
    perror("TCGETS2");
    exit(1);
  }
  t.c_cflag = (t.c_cflag & ~CBAUD) | BOTHER;
  t.c_ispeed = t.c_ospeed = speed;
  if (ioctl(fd, TCSETS2, &t)) {
    perror("TCSETS2");
    exit(1);
  }
  exit(0);
 error:
  fprintf(stderr, "Usage: %s port speed\n", argv[0]);
  exit(1);
}
