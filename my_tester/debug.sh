clear
cc -Wall -Wextra -Werror -ggdb3 -D BUFFER_SIZE=$1 ../*.c test.c -o debug
valgrind --leak-check=full -s ./debug
#rm -rf debug
