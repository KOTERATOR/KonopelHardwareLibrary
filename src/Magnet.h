#ifndef MAGNET_H
#define MAGNET_H

#define DEFAULT_PWM_FREQ 48

#include "Adafruit_PWMServoDriver.h"

Adafruit_PWMServoDriver pwmDriver = Adafruit_PWMServoDriver();

class Magnet 
{
    private:
    int _pin = 0;
    int _value = 0;
    int _freq = DEFAULT_PWM_FREQ;
    

    public:
    Magnet(int pin);

    void begin();
    void write(int value);
    int read();
    void setFrequency(int freq);
};

Magnet::Magnet(int pin = 0)
{
    _pin = pin;
}

void Magnet::begin()
{
    pwmDriver.begin();
    pwmDriver.setPWMFreq(_freq);
}

void Magnet::setFrequency(int freq)
{
    pwmDriver.setPWMFreq(freq);
}

void Magnet::write(int value)
{
    _value = value;
    pwmDriver.setPin(_pin, value);
}

int Magnet::read()
{
    return _value;
}

#endif