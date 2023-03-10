#!/bin/bash
gcc -Wall -pedantic -Werror -Wextra -c *.c
ar -cr liball.a *.o
ranlib liball.a
