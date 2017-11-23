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
MAIN := obj/Source.o
OUT ?= a
OBJ := $(SRC:.cpp=.o)
LIBO := $(LIB:.cpp=.o)
#dir/file
OBJPATH := $(patsubst %.o,obj/%.o,$(OBJ))
LIBPATH := $(patsubst %.o,lib/%.o,$(LIBO))
FINAL := $(OBJPATH) $(LIBPATH)
#flags
CFLAG := -c
LFLAG :=
STANDARD := -std=c++11

#build everything including dependencies
all: dep src

#build only the source code
src: $(OBJPATH)
	$(CC) $(LFLAG) $(FINAL) -o $(BINDIR)/$(OUT)

#compile the object file for the source code
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) $(CFLAG) $(STANDARD) -I$(INCDIR) -I$(LIBDIR) $< -o $@

#compile all the dependencies
dep: $(LIBPATH)

#compile the object file for the dependency
$(LIBDIR)/%.o: $(LIBDIR)/%.cpp
	$(CC) $(CFLAG) $(STANDARD) -I$(LIBDIR) $< -o $@

#build the program with debug symbols
debug: clean
CFLAG += -g
debug: all

#build everything and create the unit test executable
test: $(OBJPATH) dep test/test.o
	$(CC) $(LFLAG) $(filter-out $(MAIN),$(FINAL)) test/test.o -o $(BINDIR)/$(OUT)

#this will compile the unit test source code
test/test.o: test/test.cpp
	$(CC) $(CFLAG) -std=gnu++11 -I$(INCDIR) -I$(LIBDIR) $< -o $@

prod: 
	LFLAG += -static-libgcc -static-libstdc++
prod: all

.PHONY: clean all src dep debug test testsrc

clean:
	rm -f obj/*.o
	rm -f lib/*.o
