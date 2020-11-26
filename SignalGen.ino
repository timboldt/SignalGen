#include <Arduino.h>
#include <arm_math.h>

void setup() {
    pinMode(13, OUTPUT);
    analogWriteResolution(12);
}

// If theta advances by this much per loop cycle on a Feather M4, with default
// arduino-cli compilation settings, it will generate a 1Hz output.
const q31_t one_hz = 20548;

q31_t theta = 0;

void loop() {
    q31_t x, y;
    arm_sin_cos_q31(theta, &x, &y);
    analogWrite(A0, x / 1024 / 1024 + 2048);
    analogWrite(A1, y / 1024 / 1024 + 2048);
    theta += one_hz * 440;
}