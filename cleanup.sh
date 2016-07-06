#!/bin/bash

if [ -d build ]; then
    rm -rf build
fi

if [ -d debug ]; then
    rm -rf debug
fi

if [ -f flcn.log ]; then
    rm flcn.log
fi
