#compiler
CC := g++
#dirs
BINDIR := bin
INCDIR := inc
LIBDIR := lib
OBJDIR := obj
SRCDIR := src
#file lists
LIB := $(shell find $(LIBDIR) -type f -name *.cpp)
#LIB := #list library files here
SRC := Source.cpp Maps.cpp
OBJ := $(SRC:.cpp=.o)
#dir/file
OBJPATH := $(patsubst %.o,obj/%.o,$(OBJ))
LIBPATH := $(patsubst %.o,obj/%.o,$(LIB))
FINAL += $(LIBPATH)
#flags
CFLAG := -c -std=c++11
LFLAG :=

all: $(OBJPATH)
	$(CC) $(LFLAG) $(OBJPATH) -o $(BINDIR)/a

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) $(CFLAG) -I$(INCDIR) -I$(LIBDIR) $< -o $@

$(LIBDIR)/%.o: $(LIBDIR)/%.cpp
	$(CC) $(CFLAG) -I$(LIBDIR) $< -o $@

.PHONY: clean

clean:
	rm obj/*.o
