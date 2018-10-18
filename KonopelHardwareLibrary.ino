#include "src/Konopel.h"

int counter = 0;

bool magnetOn = false;

void onPedalClick()
{
    Serial.println("PEDAL");
    if(Switch.isUp())
    {
        if(magnet.isOn)
        {
            magnet.off();
        }
        else
        {
            magnet.on();
        }
    }
    
}

void onSwitchClick()
{
    magnet.off();
}

void setup()
{
    Serial.begin(115200);
    Serial.println("STARTED");

    Switch.onClick(onSwitchClick);
    Pedal.onClick(onPedalClick);
    magnet.begin();
}

void loop()
{
    Pedal.check();
    Switch.check();

    int val = Pot.read();
    magnet.write(map(val, 0, 1023, 0, 4095));

    /*for (int j = 30; j < 100; j++)
    {
        for (int i = 0; i < 4096; i += 8)
        {
            Serial.println(i);
            m.write(i);
            delay(10);
        }
    }*/
}