#!/bin/bash

if [ ! -d ./debug ]; then
    mkdir ./debug
fi

echo "Building Debug Version with GCC..."
gcc -ggdb -ansi -pedantic-errors ./aesalon.c -o ./debug/aesalon -lGLEW -lglfw -lGL -lopenal
