
#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>

int bubble_count = 0;

void stateChange( int state ) {
    if(state) {
        ++bubble_count;
        printf("Seen %d bubbles\n", bubble_count);
    }
}

void waitForBubble(int pin) {
    static int wait_forever = -1;
    int success = waitForInterrupt(pin, wait_forever);
    if(success <= 0) {
        printf("success = %d\n", success);
        exit(1);
    }
}

int main() {
    int pin = 18, bubble_length_ms = 10;
    printf("Raspberry Pi bubble counter\n");

    if( wiringPiSetupSys() == -1 )
        exit(1);

    pinMode(pin, INPUT);

    int prev_state, state;
    prev_state = state = digitalRead(pin);
    for(;;) {
        waitForBubble(pin);
        state = digitalRead(pin);
        delay(bubble_length_ms);
        if( state != prev_state ) stateChange( state );
        prev_state = state;
    }

    return 0;
}
