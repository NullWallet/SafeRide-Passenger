#pragma once
#include <Arduino.h>
#include <esp_now.h>

// ====== Pin map (ESP32-C3 Super Mini) ======
#define FSR_PIN 3   // GPIO3 = ADC1_CH3 — any ADC1 pin (GPIO0..4) works

// ====== Motor ESP MAC ======
const uint8_t receiverMacAddress[] = {0x14, 0x33, 0x5C, 0x04, 0x20, 0x70};

// ====== Wire packet — MUST match motor's DriverData byte-for-byte ======
// Motor's OnDataRecv checks `len == sizeof(DriverData)`, so passenger
// must send the same 3-field struct. `isSober` is unused for passenger
// but kept so the size matches.
enum HelmetTypes { Driver, Passenger };

struct HelmetData {
    HelmetTypes helmetType;
    bool helmetOn;
    bool isSober;   // unused for passenger; kept for size parity
};

// ====== FSR thresholds (raw analogRead, 0..4095) ======
// Tune by printing analogRead while pressing/releasing the FSR.
const int WEAR_THRESHOLD = 1500;
const int HYSTERESIS     = 150;

// ====== Timing ======
const unsigned long HEARTBEAT_MS            = 5UL * 1000UL;
const unsigned long HELMET_OFF_DEEPSLEEP_MS = 5UL * 60UL * 1000UL;