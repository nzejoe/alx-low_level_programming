#!/bin/bash

# Compile all .c files in the current directory into object files
gcc -c -fPIC *.c
# Create the dynamic library liball.so from the object files
gcc -shared -o liball.so *.o
# Clean up dir by removing the object files
rm *.o
