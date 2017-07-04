#!/bin/bash

gcc -O3 -ansi -pedantic-errors -fno-builtin -fno-stack-protector -Wall -Wextra -Wshadow -Werror -Wfatal-errors -Wno-unused-result -Wno-unused-parameter source/aesalon.c -o Aesalon -lGLEW -lglfw -lGL -lopenal -lvulkan -lpthread
