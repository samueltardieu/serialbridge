#ifndef _CHECK_H
#define _CHECK_H

#include <stdio.h>
#include <stdlib.h>

#define check(test, msg) \
  do {			 \
    if (test) {		 \
      perror(msg);	 \
      exit(1);		 \
    }			 \
  } while(0)

#endif // _CHECK_H
