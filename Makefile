all: victim

CFLAGS = -fno-stack-protector -Wl,-no_pie

%: %.c Makefile
	clang $(CFLAGS) -o $@ $<

sled:
	python -c "print 'A' * 1000"

.PHONY: sled
