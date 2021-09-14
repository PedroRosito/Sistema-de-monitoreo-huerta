//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"

#include "ultrasonic_sensor.h"
#include "pc_serial_com.h"
#include "HCSR04.h"

//=====[Declaration of private defines]======================================

#define TRIGGER PG_2
#define ECHO PG_3

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

HCSR04 ultrasonic(TRIGGER, ECHO);

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

//=====[Declarations (prototypes) of private functions]========================

//=====[Implementations of public functions]===================================

bool ultrasonicSensorRead()
{
    return ultrasonic.distance(1) > 5;
}

//=====[Implementations of private functions]==================================
