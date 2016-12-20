#!/bin/bash

if [ -f build/aesalon ]; then
    echo "Copying Executable to /usr/games/bin..."
    sudo cp ./build/aesalon /usr/games/bin/aesalon
    echo "Copying Config..."
    cp ./aesalon.cfg ~/aesalon.cfg
    echo "Installing .desktop File..."
    sudo cp ./Aesalon.desktop /usr/share/applications/Aesalon.desktop
    echo "Copying Icons..."
    sudo cp ./icons/256x256/apps/aesalon.png /usr/share/pixmaps
    echo "Aesalon has been Successfully Installed"
else
    echo "Project not built, building..."
    ./scripts/build.sh
    ./scripts/install.sh
fi
