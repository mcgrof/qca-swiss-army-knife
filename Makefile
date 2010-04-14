initvals: ar5008_initvals.h ar9001_initvals.h ar9002_initvals.h ar9003_initvals.h initvals.c
	gcc -o $@ $@.c

all: initvals

clean:
	rm -f initvals
