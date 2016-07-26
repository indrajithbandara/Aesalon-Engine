# Aesalon Engine
Welcome to the Aesalon (formerly Falcon) Game Engine project, an effort to build a lightweight, fast and powerful 3D game engine in C using the GLFW library & the Sandford C Library.

Dependencies
============
 - OpenGL
 - GLEW
 - GLFW3

Building
========
Ensure you have GCC or LLVM Clang installed on Linux
OR
Ensure you have GCC installed on Windows, you can do this through MinGW,
make sure you add it to your system path or the buildscript won't be able to
invoke it.

**Linux**
Run build.sh and select the compiler you wish to use to compile the project.

**Windows**
Run build.bat to compile the project.

Installing & Running
====================

**Linux**
Run install.sh to install the project on your system.

**Windows**
Install MinGW and run install.bat to install the project on your system.

**Please Note:**
To actually be able to play a game you will need the game assets. These are not
included here in order to make the download smaller for people who only want the
engine code itself. In order to be able to play anything please download the
Aesalon-Assets repo and place its contents into the 'res' folder in this
directory. These assets are loaded by the engine from the folder, there is no
need to rebuild the project if you put them in the folder after building.

Notes
=====
 - Some larger 3D models and other files will fail to load because they have too long lines in the file resulting in a segfault. A common example is complex obj models with faces that have a huge number of points. If you want to load these files you can change the max line length setting in globals.h, this will adjust the buffer sizes in all files to which this issue applies such as the obj loader.

 - Aesalon loads 3D models in the Wavefront .obj format. The built in parser for this format however is not a compelete implmentation of the spec, as my parsers tend to never be. It is built to load what I need and certain .obj files will fail to load with it. This is not a concern for me, it will load the .obj files I use, I aimed to keep the loader simple rather than bulletproof. It is my belief that formats should adjust to the parsers rather than the other way around, I like to keep parsers simple and enforce limits on the ways in which the format is used rather than create huge, complex parsers for the sake of having less strict formats.

Known Bugs
==========
 - Config cannot be read when running from Steam, could be some sort of sandboxing or something, will look into it some other time.
