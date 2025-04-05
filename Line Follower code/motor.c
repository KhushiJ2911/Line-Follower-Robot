/*
 * motor.c
 *
 * Created: 22-10-2024 18:57:56
 *  Author: Khushi
 */ 
#include <avr/io.h>
#include "mohot.h"
#define setpin(pin,reg) (reg |= (1<<pin))
#define clearpin(pin,reg) (reg &= ~(1<<pin))void forward(int leftSpeed, int rightSpeed)
{
	setpin(0 ,PORTB);
	clearpin(1,PORTB);
	setpin(3,PORTB);
	clearpin(2,PORTB);
	OCR1A=rightSpeed;
	OCR1B=leftSpeed;
}void backward(int leftSpeed, int rightSpeed)
{
	setpin(1,PORTB);
	clearpin(0,PORTB);
	setpin(2,PORTB);
	clearpin(3,PORTB);
	OCR1A=rightSpeed;
	OCR1B=leftSpeed;
}

void sharpleft(int leftSpeed, int rightSpeed)
{
	setpin(2,PORTB);
	clearpin(3,PORTB);
	clearpin(1,PORTB);
	clearpin(0,PORTB);
	OCR1A=rightSpeed;
	OCR1B=leftSpeed;
} void left(int leftSpeed, int rightSpeed)
{
	setpin(2,PORTB);
	clearpin(3,PORTB);
	setpin(0,PORTB);
	clearpin(1,PORTB);
	OCR1A=rightSpeed;
	OCR1B=leftSpeed;
}

void sharpRight(int leftSpeed, int rightSpeed)
{
	setpin(1,PORTB);
	clearpin(0,PORTB);
	clearpin(2,PORTB);
	clearpin(3,PORTB);
	OCR1A=rightSpeed;
	OCR1B=leftSpeed;
}

void right(int leftSpeed, int rightSpeed)
{
	setpin(1,PORTB);
	clearpin(0,PORTB);
	setpin(3,PORTD);
	clearpin(2,PORTD);
	OCR1A=rightSpeed;
	OCR1B=leftSpeed;
}

void stop(int leftSpeed, int rightSpeed)
{
	clearpin(2,PORTD);
	clearpin(3,PORTD);
	clearpin(0,PORTD);
	clearpin(1,PORTD);
	OCR1A=rightSpeed;
	OCR1B=leftSpeed;
}

 