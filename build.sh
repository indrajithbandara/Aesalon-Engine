echo "Compile With:"
echo "1. Clang"
echo "2. GCC"
echo ""
read choice
echo "Building..."
if [ "$choice" = '1' ]; then
    clang -ggdb -ansi -Wall -Werror -O2 -lglfw game.c -o game
else
    gcc -g -ansi -Wall -Werror -O2 -lglfw game.c -o game
fi
echo "Done"
