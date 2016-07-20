# Falcon Engine
The Falcon Game Engine project.

INSTALLING:
Run build.sh to compile the project.
Then run install.sh to install it.

Dependencies:
Falcon currently depends on OpenGL and GLFW.

NOTE:
Some larger 3D models and other files will fail to load because they have
too long lines in the file resulting in a segfault. A common example is
complex obj models with faces that have a huge number of points. If you
want to load these files you can change the max line length setting in
globals.h, this will adjust the buffer sizes in all files to which this
issue applies such as the obj loader.

FALCON OBJ LOADER
The Falcon Engine loads 3D models in the Wavefront .obj format.
The built in parser for this format however is not a compelete
implmentation of the spec, as my parsers tend to never be. It is
built to load what I need and certain .obj files will fail to load
with it. This is not a concern for me, it will load the .obj files
I use, I aimed to keep the loader simple rather than bulletproof.
It is my belief that formats should adjust to the parsers rather
than the other way around, I like to keep parsers simple and
enforce limits on the ways in which the format is used rather than
create huge, complex parsers for the sake of having less strict
formats.

KNOWN BUGS:
Config cannot be read when running from Steam, could be some sort of
sandboxing or something, will look into it some other time.
