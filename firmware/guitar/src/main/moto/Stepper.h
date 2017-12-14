/*
 * Stepper.h
 *
 *  Created on: 2017年12月13日
 *      Author: richard.zhao
 */

#ifndef SRC_MAIN_MOTO_STEPPER_H_
#define SRC_MAIN_MOTO_STEPPER_H_

class Stepper {
public:
    Stepper(int stepPin, int dirPin);
    void step(long steps);

	virtual ~Stepper();

private:
    int stepPin;	    // pin to controll step
    int dirPin;     // pin to controll direction
    int speed = 120;      // speed of RPM
    int steps = 200;      //steps per round
    int micros = 32;      //细分数
    unsigned long pulseTime = 0;      // = (long) 60000 * (long) 1000 / speed / steps / micros; // pulse time in microsecond
    void setSpeed(int speed);
    void setSteps(int steps);
    void calcPulseTime();
};

#endif /* SRC_MAIN_MOTO_STEPPER_H_ */
