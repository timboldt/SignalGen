#include <Arduino.h>

void setup() {
    pinMode(13, OUTPUT);
    analogWriteResolution(12);
}

double theta = 0;
bool on = false;

void loop() {
    double x = sin(theta);
    double y = cos(theta);
    analogWrite(A0, (uint32_t)round(x*2048 + 2048));
    analogWrite(A1, (uint32_t)round(y*2048 + 2048));
    theta += 0.001;  // 1 milliradian
    // if (v >= 1<<12) {
    //     v = 0;
    //     // LOW is red LED on.
    //     on = !on;
    //     digitalWrite(13, on ? LOW : HIGH);
    // }
    delayMicroseconds(1);
}