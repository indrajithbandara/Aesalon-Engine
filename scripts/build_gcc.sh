#!/bin/bash

if [ ! -d ./build ]; then
    mkdir ./build
fi

echo "Building with GCC..."
gcc -w -O3 -ansi ./aesalon.c -o ./build/aesalon -lGLEW -lglfw -lGL -lopenal
