#include "BtnKit.h"
#include "controller.h"

BtnKit::BtnKit(const uint8_t* ard_pins, const uint8_t* el, const uint8_t t_pins)
: pins(ard_pins), elements(el), total_pins(t_pins)
{
    pState = new uint16_t[t_pins]();
    cState = new uint16_t[t_pins]();
    lastdebouncetime = new uint32_t[t_pins]();
}


void BtnKit::read(void (*func)(uint8_t, State))
{

    for (uint8_t i = 0; i < total_pins; i++)
    {
        cState[i] = digitalRead(pins[i]);
    }

    for (uint8_t i = 0; i < total_pins; i++)
    {

        if ((millis() - lastdebouncetime[i]) > debouncedelay)
        {

            if (cState[i] != pState[i])
            {
                lastdebouncetime[i] = millis();

                if (cState[i] == LOW)
                {
                    func(elements[i], State::Triggered);
                }
                else
                {
                    func(elements[i], State::Idle);
                }

                pState[i] = cState[i];
            }
        }
    }
}
