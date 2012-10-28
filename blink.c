
#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int pin = 17;
    printf("Raspberry Pi wiringPi blink test\n");

    if( wiringPiSetupGpio() == -1 )
        exit(1);

    pinMode(pin, OUTPUT);

    for(;;) {
        printf("LED On\n");
        digitalWrite(pin, 1);
        delay(250);
        printf("LED Off\n");
        digitalWrite(pin, 0);
        delay(250);
    }

    return 0;
}
