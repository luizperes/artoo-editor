CC=clang
CFLAGS=-lncurses

DEPS = include.h R2Settings.h R2Window.h R2WindowManager.h
OBJ = R2Settings.o R2Window.o R2WindowManager.o artoo.o

%.o: %.c $(DEPS)
	$(CC) $(DEBUG) -c -o $@ $< $(CFLAGS)

artoo: $(OBJ)
	$(CC) $(DEBUG) -o $@ $^ $(CFLAGS)

clean:
	rm $(OBJ) *.h.gch

debug: DEBUG = -g
debug: artoo

