#ifndef BUTTON_H
#define BUTTON_H

#define PEDAL_PIN 9
#define SWITCH_PIN 10
#define RATTLING_INTERVAL 50

class Button
{
    private:
    int _pin,
        prevMillis = 0;
    bool _isDown = false, _invert = false;
    void (*onClickFunc)();

    public:

    Button(int pin, bool invert);
    void check();
    void onClick(void(*onClickFunc)());
    bool isDown();
    bool isUp();
};

Button::Button(int pin, bool invert = false)
{
    _pin = pin;
    _invert = invert;
    pinMode(_pin, INPUT_PULLUP);
}

void Button::onClick(void(*onClickFunc)())
{
    this->onClickFunc = onClickFunc;
}

void Button::check()
{
    int currentMillis = millis();
    if(currentMillis - prevMillis >= RATTLING_INTERVAL)
    {
        bool prev = _isDown;
        bool value = !digitalRead(_pin);
        _isDown = _invert ? !value : value;
        if(_isDown == true && prev == false)
        {
            onClickFunc();
        }
        prevMillis = currentMillis;
    }
}

bool Button::isDown()
{
    check();
    return _isDown;
}

bool Button::isUp()
{
    return !isDown();
}

#endif
