#!/bin/bash

./cleanup.sh

if [ ! -d build ]; then
    mkdir build
fi

if [ ! -d debug ]; then
    mkdir debug
fi

echo "Building Debug Version..."
clang -ggdb -ansi -pedantic-errors -Weverything -lglfw -lGL game.c -o ./debug/game
echo "Building..."
clang -O3 -lglfw -lGL game.c -o ./build/game
echo "Done"
