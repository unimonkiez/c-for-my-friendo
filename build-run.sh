gcc -c src/main.c
gcc -c src/niv.c

gcc -o executable main.o niv.o

./executable
rm ./executable
rm ./niv.o
rm ./main.o
echo "\n\nMain ended."
