clear
cc -Wall -Wextra -Werror -D BUFFER_SIZE=$1 ../*.c test.c -o testing
./testing $2
rm -rf testing
