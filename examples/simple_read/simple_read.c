#include <Wire.h>
#include <stdio.h>

int main() {
    printf("Begining...");
    Wire.begin();
    
    Wire.beginTransmission(0x21);
    Wire.write(0x00);
    Wire.write(0x00);
    Wire.endTransmission();
    
    Wire.requestFrom(0x21, 16);
    while (Wire.available()) {
        printf("%d\n", Wire.read());
    }
    Wire.dumpStatus();
    Wire.stop();
    printf("Stop.");
}
