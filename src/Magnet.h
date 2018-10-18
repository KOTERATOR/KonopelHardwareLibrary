#ifndef MAGNET_H
#define MAGNET_H

#define DEFAULT_PWM_FREQ 48

#include "Adafruit_PWMServoDriver.h"

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

class Magnet 
{
    private:
    int _offValue = 0;
    int _pin = 0;
    int _value = 0;
    int _freq = DEFAULT_PWM_FREQ;

    bool _on = true;

    public:
    Magnet(int pin);

    void begin();
    void write(int value);
    int read();
    void setFrequency(int freq);

    void on();
    void off();
};

Magnet::Magnet(int pin = 0)
{
    _pin = pin;
}

void Magnet::begin()
{
    pwm.begin();
    pwm.setPWMFreq(_freq);
}

void Magnet::setFrequency(int freq)
{
    pwm.setPWMFreq(freq);
}

void Magnet::write(int value)
{
    _value = value;
    if(_on)
    {
        pwm.setPin(_pin, value);
    }
    else
    {
        _offValue = value;
    }
}

int Magnet::read()
{
    return _value;
}

void Magnet::on()
{
    _on = true;
    write(_offValue);
}

void Magnet::off()
{
    write(0);
    _on = false;
}

#endif