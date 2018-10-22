#ifndef KONOPEL_H
#define KONOPEL_H

#include "Button.h"
#include "Magnet.h"
#include "Potentiometer.h"

Button Pedal(PEDAL_PIN);
Button Switch(SWITCH_PIN, true);
Potentiometer Pot(A15);

Magnet magnet(15);

#endif
