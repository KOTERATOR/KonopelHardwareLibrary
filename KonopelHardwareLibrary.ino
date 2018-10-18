#include "src/Magnet.h"
//#include "Adafruit_PWMServoDriver.h"

Magnet m(15);

void setup()
{
    Serial.begin(9600);
    delay(5000);
    Serial.println("STARTED");
    m.begin();
}

void loop()
{
    
    for (int j = 30; j < 100; j++)
    {
        for (int i = 0; i < 4096; i += 8)
        {
            Serial.println(i);
            m.write(i);
            delay(10);
        }
    }
}