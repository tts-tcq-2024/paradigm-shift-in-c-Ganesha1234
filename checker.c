#include <stdio.h>
#include <assert.h>
 
int isTemperatureOk(float temperature) {
  if(temperature < 0 || temperature > 45) {
    printf("Temperature out of range!\n");
    return 0;
  }
  return 1;
}
 
int isSocOk(float soc) {
  if(soc < 20 || soc > 80) {
    printf("State of Charge out of range!\n");
    return 0;
  }
  return 1;
}
 
int isChargeRateOk(float chargeRate) {
  if(chargeRate > 0.8) {
    printf("Charge Rate out of range!\n");
    return 0;
  }
  return 1;
}



int batteryIsOk(float temperature, float soc, float chargeRate) { 
 
 int temperatureOk = isTemperatureOk(temperature);   
 int socOk = isSocOk(soc);   
 int chargeRateOk = isChargeRateOk(chargeRate); 
 return (temperatureOk && socOk && chargeRateOk);

}




int main() {
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
}
