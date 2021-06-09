#MAKE?=mingw32-make
AR?=ar
ARFLAGS?=rcs
PATHSEP?=/
CC=gcc
BUILDROOT?=build

ifeq ($(CLANG),1)
	export CC=clang
endif

BUILDDIR?=$(BUILDROOT)$(PATHSEP)$(CC)
BUILDPATH?=$(BUILDDIR)$(PATHSEP)

all: createdir
	$(MAKE) -f Makefile_color
	$(MAKE) -f Makefile_crgb_array

install:
	$(MAKE) -f Makefile_color install
	$(MAKE) -f Makefile_crgb_array install

.PHONY: clean install createdir

createdir:
	mkdir -p $(BUILDDIR)

clean:
	-rm -dr $(BUILDROOT)