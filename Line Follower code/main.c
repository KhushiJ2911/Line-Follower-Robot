/*
 * LINE.c
 *
 * Created: 22-10-2024 08:36:44
 * Author : Khushi
 */ 

#include <avr/io.h>
#include "Init.h"
#define NUM_SENSORS 8
#include "motor.h"
uint16_t threshold[NUM_SENSORS];
void set_threshold(void)
{
	uint16_t low_value[NUM_SENSORS];
	uint16_t high_value[NUM_SENSORS];
	
	// Assume low_value is when the sensor is over the black line (low reflection)
	// and high_value is when the sensor is over the white surface (high reflection).

	// Step 1: Measure low voltage (sensor over the black line)
	for (uint8_t i = 0; i < NUM_SENSORS; i++)
	{
		low_value[i] = read_adc(i);  // Read low voltage (black line)
		_delay_ms(2000);  // Short delay for stability
		if(i%2 == 0)
		{
			PORTC |= 0xFF;
			PORTD |= 0xFF;
		}
		else
		{
			PORTC &= 0x00;
			PORTD &= 0x00;
		}
	}
	
	PORTC |= 0xFF;
	PORTD |= 0xFF;
	_delay_ms(3000);

	// Step 2: Measure high voltage (sensor over the white surface)
	for (uint8_t i = 0; i < NUM_SENSORS; i++)
	{
		high_value[i] = read_adc(i);  // Read high voltage (white surface)
		_delay_ms(2000);  // Short delay for stability
		if(i%2 == 0)
		{
			PORTC |= 0xFF;
			PORTD |= 0xFF;
		}
		else
		{
			PORTC &= 0x00;
			PORTD &= 0x00;
		}
	}
	
	PORTC |= 0xFF;
	PORTD |= 0xFF;
	_delay_ms(3000);

	// Step 3: Calculate the threshold (mean of low and high values)
	for (uint8_t i = 0; i < NUM_SENSORS; i++)
	{
		threshold[i] = (low_value[i] + high_value[i]) / 2;  // Set threshold
		if(i%2 == 0)
		{
			PORTC |= 0xFF;
			PORTD |= 0xFF;
		}
		else
		{
			PORTC &= 0x00;
			PORTD &= 0x00;
		}
	}
}
	
int ir[8];

int convert()
{
	if(read_adc(0) > threshold[0])
	{
		ir[0] = 0;
	}
	else
	{
		ir[0] = 1;
	}
	
	if(read_adc(1) > threshold[1])
	{
		ir[1] = 0;
	}
	else
	{
		ir[1] = 1;
	}
	
	if(read_adc(2) > threshold[2])
	{
		ir[2] = 0;
	}
	else
	{
		ir[2] = 1;
	}
	
	if(read_adc(3) > threshold[3])
	{
		ir[3] = 0;
	}
	else
	{
		ir[3] = 1;
	}
	
	if(read_adc(4) > threshold[4])
	{
		ir[4] = 0;
	}
	else
	{
		ir[4] = 1;
	}
	
	if(read_adc(5) > threshold[5])
	{
		ir[5] = 0;
	}
	else
	{
		ir[5] = 1;
	}
	
	if(read_adc(6) > threshold[6])
	{
		ir[6] = 0;
	}
	else
	{
		ir[6] = 1;
	}
	
	if(read_adc(7) > threshold[7])
	{
		ir[7] = 0;
	}
	else
	{
		ir[7] = 1;
	}
	
	int reading = 10000000*ir[7] + 1000000*ir[6] + 100000*ir[5] + 10000*ir[4] + 1000*ir[3] + 100*ir[2] + 10*ir[1] + ir[0];
	
	return reading;
	
	
}

void glow_leds_based_on_sensor(void)
{
	uint8_t led_data = 0x00;
	
	// Loop through the sensor values and assign LEDs to glow
	for (uint8_t i = 0; i < NUM_SENSORS; i++)
	{
		if (ir[i] == 1)  // If the sensor detects black
		{
			led_data |= (1 << i);  // Set corresponding bit to turn on the LED
		}
	}
	
	PORTB = led_data;  // Send the LED data to PORTB (connected to LEDs)
}

	
int main(void)
{
	Init();
  // set_threshold();
	while(1){
		forward(125,125);
	
// 	{if(read_adc(3)>threshold[3]){
// 		PORTC|=0xFF;
// 		PORTD|=0xFF;
// 	}else{
// 		PORTC&=0X00;
// 		PORTD&=0x00;
// 		
// 	}
// 		if(convert() == 00000111 || convert() == 10000111)
// 		{
// 			sharpleft
// 		
// 		}
// 		
// 		if(convert() == 11000111)
// 		{
// 			left
// 		}
// 		
// 		if(convert() == 11100111 || convert() == 11000011)
// 		{
// 			forward
// 		}
// 		
// 		if(convert() == 11000111 || convert() == 11100111)
// 		{
// 
// 			backward
// 		}
// 		
// 		if(convert() == 11100000 || convert() == 11100001)
// 		{
// 			sharpRight
// 		}
// 		
// 		if(convert() == 11100011 )
// 		{
// 			right
// 		}
// 		
// 		if(convert() == 01111110 || convert() == 11111111)
// 		{
// 			stop
// 		}
//  		
	}
	
	return 1;
	
	
}
