all: 
	$(MAKE) -f Makefile_color
	$(MAKE) -f Makefile_crgb_array

install:
	$(MAKE) -f Makefile_color install
	$(MAKE) -f Makefile_crgb_array install

test:
	$(MAKE) -f Makefile_color test
	$(MAKE) -f Makefile_crgb_array test

clean:
	$(MAKE) -f Makefile_color clean
	$(MAKE) -f Makefile_crgb_array clean

.PHONY: clean install test
