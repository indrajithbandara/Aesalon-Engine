#!/bin/bash

echo "Removing Executable..."
sudo rm /usr/games/bin/falcon
echo "Removing Config..."
rm ~/falcon.cfg
echo "Removing .desktop File..."
sudo rm /usr/share/applications/falcon.desktop
echo "Removing Icons..."
sudo rm /usr/share/pixmaps/falcon.png
echo "Aesalon has been Successfully Uninstalled"
