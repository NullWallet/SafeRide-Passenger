#pragma once
#include <Arduino.h>
#include <esp_now.h>
#include "variables.hpp"

inline void OnDataSent(const uint8_t *mac, esp_now_send_status_t status) {
    Serial.printf("[ESP-NOW] send to %02X:%02X:%02X:%02X:%02X:%02X -> %s\n",
        mac[0], mac[1], mac[2], mac[3], mac[4], mac[5],
        status == ESP_NOW_SEND_SUCCESS ? "OK" : "FAIL");
}