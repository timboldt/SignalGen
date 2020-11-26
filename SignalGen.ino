#include <Arduino.h>

void setup() {
    pinMode(13, OUTPUT);
    analogWriteResolution(12);
}

float theta = 0;
bool on = false;

void loop() {
    float x = sin(theta);
    float y = cos(theta);
    analogWrite(A0, (uint32_t)round(x*2047 + 2048));
    analogWrite(A1, (uint32_t)round(y*2047 + 2048));
    theta += 0.1;
}