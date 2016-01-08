CC=clang
CFLAGS=-lncurses
DEPS = include.h artoo.h R2Window.h
OBJ = artoo.o R2Window.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

artoo: $(OBJ)
	clang -o $@ $^ $(CFLAGS)


