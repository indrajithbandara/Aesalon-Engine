#!/bin/bash

if [ ! -d ./build ]; then
    mkdir ./build
fi

if [ ! -d ./debug ]; then
    mkdir ./debug
fi

echo "Building Debug..."
gcc -ggdb -ansi -pedantic-errors -Weverything ./game.c -o ./build/game -lGLEW -lglfw -lGL -lopenal
echo "Building Release..."
gcc -O3 -ansi ./game.c -o ./build/game -lGLEW -lglfw -lGL -lopenal
