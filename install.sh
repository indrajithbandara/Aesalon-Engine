#!/bin/bash

if [ -f build/game ]; then
    echo "Copying Executable to /usr/games/bin..."
    sudo cp ./build/game /usr/games/bin/falcon
    echo "Copying Config..."
    cp ./falcon.cfg ~/falcon.cfg
    echo "Installing .desktop File..."
    sudo cp ./falcon.desktop /usr/share/applications/falcon.desktop
    echo "Copying Icons..."
    sudo cp ./icons/256x256/apps/falcon.png /usr/share/pixmaps
    echo "Falcon has been Successfully Installed"
else
    echo "Project not built, building..."
    ./build.sh
    ./install.sh
fi
