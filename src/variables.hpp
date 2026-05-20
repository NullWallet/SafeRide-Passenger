#pragma once
#include <esp_now.h>
#include <Arduino.h>

typedef unsigned char uint8_t;
uint8_t receiverMacAddress[] = {0x14, 0x33, 0x5C, 0x04, 0x20, 0x70};

enum HelmetTypes
{
    Driver,
    Passenger
};

struct PassengerData
{
    HelmetTypes helmetType;
    bool helmetOn;
};
