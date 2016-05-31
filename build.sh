echo "Building..."
clang -ggdb -ansi -Wall -Werror -O2 -lglfw -lGL game.c -o game
echo "Done"
