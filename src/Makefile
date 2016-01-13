CC=clang
CFLAGS=-lncurses
DEPS = include.h R2Window.h R2WindowManager.h
OBJ = R2Window.o R2WindowManager.o artoo.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

artoo: $(OBJ)
	clang -o $@ $^ $(CFLAGS)


