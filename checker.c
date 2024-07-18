/*
#include <stdio.h>
#include <assert.h>
int TemperaureIsOk(float temperature)
{
     if (temperature < 0 || temperature > 45) 
     {
        printf("Temperature out of range\n");
        return 0;
     }
     return 1;
}
int socIsOk(float soc)
{
    if (soc < 20 || soc > 80) 
    {
        printf("State of Charge out of range!\n");
        return 0;
    }
    return 1;
}
int chargeRateIsOk(float chargeRate)
{
    if (chargeRate > 0.8) 
    {
        printf("Charge Rate out of range!\n");
        return 0;
    }
    return 1;
}
 
 
 
int batteryIsOk(float temperature, float soc, float chargeRate) 
{
    int tempIsOk = TemperaureIsOk(temperature);
    int stcIsOk = socIsOk(soc);
    int crIsOk = chargeRateIsOk(chargeRate);
    int result = tempIsOk&stcIsOk&crIsOk;
    return result;
}
int main() 
{
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
}
*/

#include <stdio.h>
#include <assert.h>
int TemperaureIsOk(float temperature)
{
     if (temperature < 0 || temperature > 45) 
     {
        printf("Temperature out of range\n");
        return 0;
     }
     return 1;
}
int socIsOk(float soc)
{
    if (soc < 20 || soc > 80) 
    {
        printf("State of Charge out of range!\n");
        return 0;
    }
    return 1;
}
int chargeRateIsOk(float chargeRate)
{
    if (chargeRate > 0.8) 
    {
        printf("Charge Rate out of range!\n");
        return 0;
    }
    return 1;
}
 
 
 
int batteryIsOk(float temperature, float soc, float chargeRate) 
{
    
    //int tempIsOk = TemperaureIsOk(temperature);
   // int stcIsOk = socIsOk(soc);
    //int crIsOk = chargeRateIsOk(chargeRate);
    //int result = tempIsOk&stcIsOk&crIsOk;
    //return result;
     result 0;
}
int main() 
{
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
}
