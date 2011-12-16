ifdef ATHEROS
CFLAGS += -DATHEROS

ATHEROS_DEPS += \
	ar9280.ini		\
	ar9280_merlin2.ini	\
	ar9285.ini		\
	ar9285_v1_2.ini		\
	ar9287.ini		\
	ar9287_1_1.ini		\
	ar9271.ini		\
	ar9300_osprey22.ini
endif

ATH9K_DEPS += \
	ar5008_initvals.h 	\
	ar9001_initvals.h	\
	ar9002_initvals.h 	\
	ar9003_2p2_initvals.h	\
	ar9580_1p0_initvals.h

initvals: $(ATH9K_DEPS) $(ATHEROS_DEPS) initvals.c
	gcc $(CFLAGS) -o $@ $@.c

all: initvals

clean:
	rm -f initvals
