#!/bin/bash

gcc -O3 -ansi -pedantic-errors -fno-builtin -Wall -Wextra -Wshadow -Werror -Wfatal-errors -Wno-unused-result -Wno-unused-parameter source/aesalon.c -o Aesalon -lGLEW -lglfw -lGL -lopenal -lvulkan
