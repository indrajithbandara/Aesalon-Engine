echo "Building Debug Version..."
gcc -ggdb -ansi -lglfw -lGL game.c -o ./debug/game
echo "Building..."
gcc -O3 -lglfw -lGL game.c -o ./build/game
