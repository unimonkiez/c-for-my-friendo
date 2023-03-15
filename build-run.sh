# gcc -c src/josephus-niv.c
gcc -c src/file-editor.c
# gcc -c src/niv.c

# gcc -o executable main.o niv.o
gcc -o executable file-editor.o

./executable ./src/1.c
rm ./executable
rm ./file-editor.o
# rm ./main.o
echo "\n\nMain ended."
