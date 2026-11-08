all:
	mkdir -p build
	gcc -Wall -Werror -Wextra classic_pong/pong.c -o build/pong

clean:
	rm -rf build