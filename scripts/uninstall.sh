#!/bin/bash

echo "Removing Executable..."
sudo rm /usr/games/bin/aesalon
echo "Removing Config..."
rm ~/aesalon.cfg
echo "Removing .desktop File..."
sudo rm /usr/share/applications/Aesalon.desktop
echo "Removing Icons..."
sudo rm /usr/share/pixmaps/aesalon.png
echo "Aesalon has been Successfully Uninstalled"
