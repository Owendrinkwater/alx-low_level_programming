#!/bin/bash
gcc -Wall -pendatic -Werror -Wextra
ar -rc liball.a *.o
ranlib liball.a 
