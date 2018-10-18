#ifndef POTENTIOMETER_H
#define POTENTIOMETER_H

class Potentiometer
{
    private:
    int _pin;

    public:
    Potentiometer(int pin);
    int read();
};

Potentiometer::Potentiometer(int pin)
{
    _pin = pin;
    pinMode(_pin, INPUT);
}

int Potentiometer::read()
{
    return analogRead(_pin);
}

#endif