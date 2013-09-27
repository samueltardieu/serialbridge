#include <sys/types.h>
#include <fcntl.h>
#include <poll.h>
#include <stropts.h>
#include <linux/termios.h>

#include "check.h"
#include "speed.h"

void setspeed(int fd, int speed) {
  struct termios2 t;
  check(ioctl(fd, TCGETS2, &t), "TCGETS2");
  t.c_cflag = (t.c_cflag & ~CBAUD) | BOTHER;
  t.c_ispeed = t.c_ospeed = speed;
  check(ioctl(fd, TCSETS2, &t), "TCSETS2");
}
