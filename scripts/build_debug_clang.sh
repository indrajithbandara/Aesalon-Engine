#!/bin/bash

if [ ! -d ./debug ]; then
    mkdir ./debug
fi

echo "Building Debug Version with LLVM Clang..."
clang -ggdb -ansi -pedantic-errors -Weverything ./aesalon.c -o ./build/aesalon -lGLEW -lglfw -lGL -lopenal
