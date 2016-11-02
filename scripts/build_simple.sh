#!/bin/bash

if [ ! -d ../build ]; then
    mkdir ../build
fi

if [ ! -d ../debug ]; then
    mkdir ../debug
fi

gcc -O3 -lglfw -lGLEW -lGL ../game.c -o ../build/game
