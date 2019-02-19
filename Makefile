all: createdir
	$(MAKE) -f Makefile_color
	$(MAKE) -f Makefile_crgb_array

.PHONY: clean createdir

createdir:
	mkdir -p $(BUILDDIR)

clean:
	-rm -dr $(BUILDROOT)