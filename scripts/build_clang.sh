#!/bin/bash

if [ ! -d ./build ]; then
    mkdir ./build
fi

if [ ! -d ./debug ]; then
    mkdir ./debug
fi

echo "Building Debug..."
clang -ggdb -ansi -pedantic-errors -Weverything ./aesalon.c -o ./build/aesalon -lGLEW -lglfw -lGL -lopenal
echo "Building Release..."
clang -O3 -ansi ./aesalon.c -o ./build/aesalon -lGLEW -lglfw -lGL -lopenal
