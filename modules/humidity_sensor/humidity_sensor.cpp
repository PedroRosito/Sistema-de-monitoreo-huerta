//=====[Libraries]=============================================================

#include "mbed.h"

#include "humidity_sensor.h"
#include "DHT.h"

//=====[Declaration of private defines]======================================

#define DHT22 DHT22

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

DHT dht22(PG_1, DHT22);

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

//=====[Declarations (prototypes) of private functions]========================

//=====[Implementations of public functions]===================================

void humiditySensorInit()
{
    return;
}

void humiditySensorUpdate()
{
    return;
}

float humiditySensorRead()
{
    dht22.readData();
    return dht22.ReadHumidity();
}

//=====[Implementations of private functions]==================================
