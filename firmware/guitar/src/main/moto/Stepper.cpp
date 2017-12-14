/*
 * Stepper.cpp
 *
 *  Created on: 2017年12月13日
 *      Author: richard.zhao
 */

#include <Arduino.h>
#include "Stepper.h"

Stepper::Stepper(int stepPin, int dirPin) {
	this->stepPin = stepPin;
    this->dirPin = dirPin;
    this->calcPulseTime();
    pinMode(this->stepPin, OUTPUT);
    pinMode(this->dirPin, OUTPUT);
}

Stepper::~Stepper() {
}

void Stepper::setSpeed(int speed) {
    this->speed = speed;
    this->calcPulseTime();
}

void Stepper::setSteps(int steps) {
    this->steps = steps;
    this->calcPulseTime();
}

void Stepper::step(long steps) {
    pinMode(this->dirPin, steps > 0 ? HIGH : LOW);
    steps = steps > 0 ? steps : -steps;
    while (steps > 0) {
        digitalWrite(this->stepPin, HIGH);
        delayMicroseconds(this->pulseTime);
        digitalWrite(this->stepPin, LOW);
        delayMicroseconds(this->pulseTime);
    }
}

void Stepper::calcPulseTime() {
    this->pulseTime = (long) 60000 * (long) 1000 / speed / steps / micros;
}
