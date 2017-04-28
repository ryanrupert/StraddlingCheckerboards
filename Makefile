#compiler
CC := g++
#dirs
BINDIR := bin
INCDIR := inc
LIBDIR := lib
OBJDIR := obj
SRCDIR := src
#file lists
#LIB := $(shell find $(LIBDIR) -type f -name *.cpp)
LIB := pugixml.cpp
SRC := Decode.cpp Encode.cpp Maps.cpp Source.cpp
OBJ := $(SRC:.cpp=.o)
LIBO := $(LIB:.cpp=.o)
#dir/file
OBJPATH := $(patsubst %.o,obj/%.o,$(OBJ))
LIBPATH := $(patsubst %.o,lib/%.o,$(LIBO))
FINAL := $(OBJPATH) $(LIBPATH)
#flags
CFLAG := -c -std=c++11
LFLAG :=

all: $(OBJPATH)
	$(CC) $(LFLAG) $(FINAL) -o $(BINDIR)/a

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) $(CFLAG) -I$(INCDIR) -I$(LIBDIR) $< -o $@

buildwdep: $(LIBPATH)

$(LIBDIR)/%.o: $(LIBDIR)/%.cpp
	$(CC) $(CFLAG) -I$(LIBDIR) $< -o $@

buildwdep: all


debug: CFLAG += -g
debug: all

.PHONY: clean

clean:
	rm obj/*.o
