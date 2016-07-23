#!/bin/bash

./cleanup.sh

if [ ! -d build ]; then
    mkdir build
fi

if [ ! -d debug ]; then
    mkdir debug
fi

echo "Compiler:"
echo "1. GCC"
echo "2. LLVM Clang"
read compiler

echo "Building Debug Version..."
if [ $compiler == '2' ]; then
    clang -ggdb -ansi -pedantic-errors -Weverything -lglfw -lGL game.c -o ./debug/game
    echo "Building..."
    clang -O3 -lglfw -lGL game.c -o ./build/game
else
    gcc -ggdb -ansi -lglfw -lGL game.c -o ./debug/game
    echo "Building..."
    gcc -O3 -lglfw -lGL game.c -o ./build/game
fi
echo "Done"
