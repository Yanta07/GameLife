.PHONY: clean
.PHONY: test
CCFLAGS=-Wall -Wextra -Wshadow -Werror -std=gnu17 
CC=clang
OUT=build/
EXE=bin/
SRC=src/
LIBS=-lSDL

all: bin build $(EXE)main

$(EXE)main: $(SRC)main.c
	$(CC) $(CCFLAGS) $< ${LIBS} -o $@

bin: 
	mkdir -p bin 

build:
	mkdir -p build

%.o: $(SRC)%.c 
	$(CC) $(CCFLAGS) -MP -MMD -c -o $@ $<

clean:
	rm -rf bin build

#-----------------------------tests------------------------------

#$(OUT)maint.o: all
#	$(CC) $(CCFLAGS) test/main.c -c -o $(OUT)maint.o
#	
#$(OUT)board_test.o:
#	$(CC) $(CCFLAGS) test/board_test.c -c -o $(OUT)board_test.o
#	
#
#test: $(OUT)maint.o  $(OUT)board_test.o $(ALLOBJ) 
#	$(CC) $(CCFLAGS) $(OUT)maint.o $(OUT)board_test.o  $(ALLOBJT) -o bin/test
