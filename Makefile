CC=clang
CFLAGS=-lncurses

SRC = src
DEPS = $(SRC)/include.h $(SRC)/R2Util.h $(SRC)/R2Settings.h $(SRC)/R2File.h $(SRC)/R2Window.h $(SRC)/R2Synchronizer.h $(SRC)/R2WindowManager.h
OBJ = $(SRC)/R2Util.o $(SRC)/R2Settings.o $(SRC)/R2File.o $(SRC)/R2Window.o $(SRC)/R2Synchronizer.o $(SRC)/R2WindowManager.o $(SRC)/artoo.o

%.o: %.c $(DEPS)
	$(CC) $(DEBUG) -c -o $@ $< $(CFLAGS)

artoo: $(OBJ)
	$(CC) $(DEBUG) -o $@ $^ $(CFLAGS)

clean:
	rm $(OBJ)

debug: DEBUG = -g -O0
debug: artoo

