# Falcon Engine
The Falcon Game Engine project.

NOTE:
Some larger 3D models and other files will fail to load because they have 
too long lines in the file resulting in a segfault. A common example is 
complex obj models with faces that have a huge number of points. If you 
want to load these files you can change the max line length setting in 
globals.h, this will adjust the buffer sizes in all files to which this 
issue applies such as the obj loader.
