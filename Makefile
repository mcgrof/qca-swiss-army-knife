initvals: initvals.h initvals.c
	gcc -o $@ $@.c

all: initvals

clean:
	rm -f initvals
