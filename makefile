.PHONY: test
.PHONY: clean
.PHONY: all
CC = gcc
CFLAGS = -Wall #-Wextra -Werror -Wshadow
DEPFLAGS = -MP -MMD 
DEPDIR = dep/
OBJDIR = build/
BINDIR = bin/
SRCDIR = src/
LIBS = -lSDL2
SRC_FILES := $(wildcard $(SRCDIR)*.c)
OBJ_FILES := $(patsubst $(SRCDIR)%.c,$(OBJDIR)%.o,$(SRC_FILES))
EXECUTABLE = $(BINDIR)main
 
all: dirs $(EXECUTABLE)
 
$(EXECUTABLE): $(OBJ_FILES)
	$(CC) $(CFLAGS) $< $(LIBS) -o $@
 
$(OBJDIR)%.o : $(SRCDIR)%.c
	$(CC) $(CFLAGS) $(DEPFLAGS) $(LIBS) -c -o $@ $< 
 
dirs:
	mkdir -p bin
	mkdir -p build
 
clean:
	rm -f $(BINDIR)* $(OBJDIR)*