#!/bin/bash

if [ ! -d ./build ]; then
    mkdir ./build
fi

if [ ! -d ./debug ]; then
    mkdir ./debug
fi

echo "Building Debug..."
clang -ggdb -ansi -pedantic-errors -Weverything -lGLEW -lglfw -lGL -lopenal -lalut ./game.c -o ./debug/game
echo "Building Release..."
clang -O3 -ansi -lGLEW -lglfw -lGL -lopenal -lalut ./game.c -o ./build/game
