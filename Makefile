CFLAGS=

LOCAL_CFLAGS=$(CFLAGS)
ifdef ATHEROS
LOCAL_CFLAGS += -DATHEROS

ATHEROS_DEPS += \
	ar5416.ini		\
	ar5416_howl.ini		\
	ar5416_sowl.ini		\
	ar9280.ini		\
	ar9280_merlin2.ini	\
	ar9285.ini		\
	ar9285_v1_2.ini		\
	ar9287.ini		\
	ar9287_1_1.ini		\
	ar9271.ini		\
	ar9300_osprey22.ini	\
	ar9330_11.ini		\
	ar9330_12.ini		\
	ar9485.ini		\
	ar9580.ini		\
	ar9300_jupiter20.ini
endif

ATH9K_HEADERS = \
	ar5008:ar5008_initvals.h		\
	ar9001:ar9001_initvals.h		\
	ar9002:ar9002_initvals.h		\
	ar9003-2p2:ar9003_2p2_initvals.h	\
	ar9330-1p1:ar9330_1p1_initvals.h	\
	ar9330-1p2:ar9330_1p2_initvals.h	\
	ar9485:ar9485_initvals.h		\
	ar9580-1p0:ar9580_1p0_initvals.h \
	ar9462-2p0:ar9462_2p0_initvals.h

ATH9K_DEPS := $(foreach header,$(ATH9K_HEADERS),$(word 2,$(subst :, ,$(header))))

SOURCES:=initvals.c sha1.c

initvals: $(ATH9K_DEPS) $(ATHEROS_DEPS) $(SOURCES)
	gcc $(LOCAL_CFLAGS) -o $@ $(SOURCES)

define refresh_command
	./initvals -w -f $(word 1,$(subst :, ,$(1))) > $(word 2,$(subst :, ,$(1)))

endef

refresh: initvals
	$(foreach header,$(ATH9K_HEADERS),$(call refresh_command,$(header)))
	./initvals > checksums.txt

all: initvals

clean:
	rm -f initvals
