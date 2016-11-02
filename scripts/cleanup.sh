#!/bin/bash

if [ -d ../build ]; then
    rm -rf ../build
fi

if [ -d ../debug ]; then
    rm -rf ../debug
fi

if [ -f ../aesalon.log ]; then
    rm ../aesalon.log
fi
