
# Yout will find ExternalEeprom here: https://github.com/dalmirdasilva/ArduinoMemoryDriver

SOURCE=../../Wire.cpp \
	using_external_eeprom.c \
	../../../memory/ExternalEeprom/ExternalEeprom.cpp \
	../../../memory/External24cl256Eeprom/External24cl256Eeprom.cpp
PROGRAM=a.out
INCLUDES=-I../../ \
	-I./ \
	-I../../../memory/ExternalEeprom/ \
	-I../../../memory/External24cl256Eeprom/

LIBRARIES=
CC=g++

all: $(PROGRAM)
$(PROGRAM): $(SOURCE)
	$(CC) $(INCLUDES) $(SOURCE) -o$(PROGRAM)
clean:
	rm -f $(PROGRAM)

