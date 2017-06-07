#!/bin/bash

gcc -g -fno-builtin source/aesalon.c -o Aesalon-Debug -lGLEW -lglfw -lGL -lvulkan -lopenal
