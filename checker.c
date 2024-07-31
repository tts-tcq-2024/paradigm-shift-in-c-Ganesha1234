#include <stdio.h>
#include <assert.h>
#include <string.h>

#define TOLERANCE_PERCENTAGE 0.05


#define TEMP_MIN  0
#define TEMP_MAX  45
#define SOC_MIN  20
#define SOC_MAX  80
#define CHARGE_RATE_MAX  0.8

typedef enum {
    ENGLISH,
    GERMAN
} Language;

Language currentLanguage = ENGLISH;

const char* TemperatureMessages[2][3] = {
    {"Temperature out of range!", "Warning: Approaching low temperature", "Warning: Approaching high temperature"},
    {"Temperatur außerhalb des Bereichs!", "Warnung: Annäherung an niedrige Temperatur", "Warnung: Annäherung an hohe Temperatur"}
};

const char* SoCMessages[2][3] = {
    {"State of Charge out of range!", "Warning: Approaching discharge", "Warning: Approaching charge-peak"},
    {"Ladezustand außerhalb des Bereichs!", "Warnung: Annäherung an Entladung", "Warnung: Annäherung an Ladungsspitze"}
};

const char* ChargeRateMessages[2][1] = {
    {"Charge Rate out of range!"},
    {"Laderate außerhalb des Bereichs!"}
};

const char*  printMessage(const char* message) {
    printf("%s\n", message);
}

float calculateTolerance(float upperLimit) {
    return upperLimit * TOLERANCE_PERCENTAGE;
}

int checkTemperature(float temperature) {
    float lowerWarningLimit = TEMP_MIN + calculateTolerance(TEMP_MAX);
    float upperWarningLimit = TEMP_MAX - calculateTolerance(TEMP_MAX);
    
    if (temperature < TEMP_MIN || temperature > TEMP_MAX) {
        printMessage(TemperatureMessages[currentLanguage][0]);
        return 0;
    }
    if (temperature <= lowerWarningLimit) {
        printMessage(TemperatureMessages[currentLanguage][1]);
    }
    if (temperature >= upperWarningLimit) {
        printMessage(TemperatureMessages[currentLanguage][2]);
    }
    return 1;
}

int checkSoC(float soc) {
    float lowerWarningLimit = SOC_MIN + calculateTolerance(SOC_MAX);
    float upperWarningLimit = SOC_MAX - calculateTolerance(SOC_MAX);

    if (soc < SOC_MIN || soc > SOC_MAX) {
        printMessage(SoCMessages[currentLanguage][0]);
        return 0;
    }
    if (soc <= lowerWarningLimit) {
        printMessage(SoCMessages[currentLanguage][1]);
    }
    if (soc >= upperWarningLimit) {
        printMessage(SoCMessages[currentLanguage][2]);
    }
    return 1;
}

int checkChargeRate(float chargeRate) {
    if (chargeRate > CHARGE_RATE_MAX) {
        printMessage(ChargeRateMessages[currentLanguage][0]);
        return 0;
    }
    return 1;
}

int checkBatteryIsOk(float temperature, float soc, float chargeRate) {
    int tempIsOk = checkTemperature(temperature);
    int socIsOk = checkSoC(soc);
    int crIsOk = checkChargeRate(chargeRate);
    return tempIsOk && socIsOk && crIsOk;
}

int main() {
    currentLanguage = ENGLISH;  // Change to GERMAN for German messages
    
    assert(checkBatteryIsOk(25, 70, 0.7));
    assert(!checkBatteryIsOk(50, 85, 0));
    
    
    currentLanguage = GERMAN;  // Switch to German
    assert(checkBatteryIsOk(25, 70, 0.7));
    assert(!checkBatteryIsOk(50, 85, 0));

    return 0;
}
