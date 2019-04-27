.PHONY: test
.PHONY: clean
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Wshadow
DEPFLAGS = -MMD -MP
DEPDIR = dep/
OBJDIR = build/
BINDIR = bin/
SRCDIR = src/
LIBS=-lSDL2
SRC_FILES := $(wildcard $(SRCDIR)*.c)
OBJ_FILES := $(patsubst $(SRCDIR)%.c,$(OBJDIR)%.o,$(SRC_FILES))
DEP_FILES := $(wildcard $(DEPDIR)*.d)
EXECUTABLE = $(BINDIR)main
 
 
.PHONY: all
all: dirs $(EXECUTABLE)
 
$(EXECUTABLE): $(OBJ_FILES)
	$(CC) $(CFLAGS) $(LIBS) -o $@ $^
 
$(OBJDIR)%.o : $(SRCDIR)%.c
	$(CC) $(CCFLAGS) $(DEPFLAGS) $(DEPFLAGS) $(LIBS) -c -o $@ $<
	mv -f $(OBJDIR)$*.d $(DEPDIR)$*.d
 
dirs:
	mkdir -p $(OBJDIR) $(BINDIR) $(DEPDIR)
 
clean:
	rm -f $(BINDIR)* $(OBJDIR)* $(DEPDIR)*
   
include $(DEP_FILES)