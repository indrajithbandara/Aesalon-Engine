# Aesalon Engine
Welcome to the Aesalon Game Engine project, an effort to build a lightweight, fast and powerful 3D game engine in ANSI C using OpenGL, OpenAL, the GLFW library, Sandford C Library and the Sandford Userspace Libraries. Aesalon is currently built for GNU/Linux systems only.

License
=======
The Aesalon Project is licensed under the 2-clause BSD license refered to as the
"Simplified BSD License" or the "FreeBSD License". This license is very
permissive and allows you to do almost anything with the code, it is also
compatable with the GNU General Public License.

Dependencies
============
 - OpenGL
 - OpenAL
 - GLEW
 - GLFW3

Building
========
Ensure you have GCC or LLVM Clang installed.
From the project folder run `./scripts/build_gcc.sh` or `./scripts/build_clang.sh` to build with whichever compiler you prefer, do not cd into the scripts folder to run them.

Running
=======
While still in the project folder and after building the project you can run it using `./build/aesalon`
