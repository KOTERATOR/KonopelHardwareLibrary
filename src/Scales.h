#ifndef SCALES_H
#define SCALES_H

#include "HX711.h"

class Scales
{
    public:
    HX711 * hx711;
    Scales(int DOUT, int PD_SCK);
    ~Scales();

    long read(int times);
    long readKg(int times);
};

Scales::Scales(int DOUT, int PD_SCK)
{
    hx711 = new HX711(DOUT, PD_SCK);
}

Scales::~Scales()
{
    delete hx711;
}

long Scales::read(int times = 1)
{
    return hx711->read(times);
}

long Scales::readKg(int times = 1)
{
    return hx711->read(times);
}

#endif
