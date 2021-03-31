PREFIX  = /usr/local
LIBDIR  = $(PREFIX)/lib/berry/packages

CFLAGS  = -fPIC -I/usr/include/
LIBS    = -lintl

intl.so: be-intl.o
	$(CC) -shared $(CFLAGS) -o $@ be-intl.o $(LIBS)

install:
	mkdir -p $(DESTDIR)$(LIBDIR)
	cp intl.so $(DESTDIR)$(LIBDIR)

docs: intl.so docs/config.ld
	ldoc -c docs/config.ld -d html -a .

clean:
	rm -rf *.o *.so

.PHONY: intl.so
