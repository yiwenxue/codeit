CC=clang

PROJECT=main

SSL_LIBS=-L/usr/local/lib -lssl -lcrypto
SSL_FLAGS=-I/usr/local/include

CFLAGS=
LIBS=

SRC=main.c\
	add.c\
	utils.c

OBJS=${SRC:.c=.o}

all : main
	@echo "Done!"

main : ${OBJS}
	${CC} ${OBJS} ${LIBS} -o main 

%.o : %.c
	$(CC) ${CFLAGS} -c $< -o $@

main.o : main.c 
add.o : add.c add.h
utils.o : utils.c utils.h 

.PHONY: clean

clean:
	rm -rf main ${OBJS}
