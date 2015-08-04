
// Yout will find ExternalEeprom here: https://github.com/dalmirdasilva/ArduinoMemoryDriver

#include <stdio.h>
#include <ExternalEeprom.h>
#include <External24cl256Eeprom.h>

int main() {
    int i;
    External24cl256Eeprom eeprom(0x00);

    for (i = 0; i < 16; i++) {
        printf("%d\n", eeprom.read(i));
    }

    return 0; 
}


