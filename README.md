Bridge serial ports and TCP sockets
===================================

It is often necessary to bridge a serial port and a TCP socket. Every
modern language includes an easy way of opening TCP sockets, while they
do not all come with advanced facilities to deal with serial ports.
See [this blog post](https://www.rfc1149.net/blog/2011/12/01/accessing-serial-ports-the-easy-way/)
for reasons to do so.

Common methods to bridge a serial port and a TCP socket include:

- `pyserial`: this Python module lets you easily configure and access
  serial ports;
- `socat`: this program lets you build many kind of briges, including
  serial port to TCP socket ones.

However, those do not let you configure an arbitrary baud rate that works
with every kind of serial port. Configuring an arbitrary baud rate may be
needed when dealing with some devices, such as an [XBee module](http://www.digi.com/xbee/),
whose clock divisor only allows for speeds such as the non-standard
111,111 bps.

`serialbridge` and `setspeed` take advantage of `ioctl` calls introduced
in 2009 in the Linux kernel named `TCGETS2` and `TCSETS2`. Those allow
to set a serial port at an arbitrary speed, such as 111,111 bps.

Before the introduction of those new `ioctl` calls, it was possible to use
an arbitrary speed by setting the port to 38400 bps and configuring a custom
divisor. However, it does not work on all the devices. In particular, the
`ttyACM` driver does not support this way of setting a custom speed and
conveying the information to the device over USB.

License
=======

This software is made available under the GNU General Public License. See the
source files and the `LICENSE` file for more information.

Programs composing this package
===============================

`serialbridge`
--------------

`serialbridge` allows you to build a bridge between a serial port and an incoming TCP socket:

```bash
serialbridge [-v] device speed port
```

For example, the command

```bash
% serialbridge /dev/ttyACM0 111111 4161
```

will open a TCP socket listening on local port 4161 which will be a bridge to `/dev/ttyACM0` at a
111,111 bps speed. You can add `-v` if you want to dump all the information going through the
serial port, for debugging or reverse engineering purpose.

`serialbridge` configures the serial port in raw mode. The bridge is totally transparent.

`setspeed`
----------

`setspeed` allows you to configure the speed of a serial port, much like `stty` allows you to do that,
but using the new `ioctl` calls:

```bash
setspeed device speed
```

For example, the command

```bash
% setspeed /dev/ttyACM0 111111
```

will configure the `/dev/ttyACM0` serial port with a 111,111 bps
speed. You can then read from and write to this device from the shell
or any program.
