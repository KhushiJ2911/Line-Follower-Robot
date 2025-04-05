/*
 * motor.h
 *
 * Created: 22-10-2024 18:59:20
 *  Author: Khushi
 */ 


#ifndef MOTOR_H_
#define MOTOR_H_

#define F_CPU 8000000UL
#include <avr/io.h>
#include "motor.h"
#include <util/delay.h>
void forward(int leftspeed,int rightspeed);
void backward(int leftspeed,int rightspeed);
void left(int leftspeed,int rightspeed);
void sharpleft(int leftspeed,int rightspeed);
void right(int leftspeed,int rightspeed);
void sharpright(int leftspeed,int rightspeed);
void stop();




#endif /* MOTOR_H_ */