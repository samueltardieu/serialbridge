/*
 serialbridge - build bridges between serial ports and TCP sockets
 Copyright (c) 2013 Samuel Tardieu <sam@rfc1149.net>

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

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
