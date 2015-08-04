SOURCE=../../Wire.cpp simple_read.c
PROGRAM=a.out
INCLUDES=../../

LIBRARIES=
CC=g++

all: $(PROGRAM)
$(PROGRAM): $(SOURCE)
	$(CC) -I$(INCLUDES) $(SOURCE) -o$(PROGRAM)
clean:
	rm -f $(PROGRAM)

