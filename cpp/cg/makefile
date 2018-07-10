IDIR= ../include
ODIR=obj
LDIR=../lib

CC=g++
CFLAGS=-c -g -Wall -std=c++14 -I$(IDIR)
LDFLAGS=

LIBS=

SRC=main.cpp
_OBJ=$(SRC:.cpp=.o)
OBJ=$(patsubst %,$(ODIR)/%,$(_OBJ))
EXE=hello

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) $(CXXFLAGS) $@ $<

hello: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
	rm -f hello
