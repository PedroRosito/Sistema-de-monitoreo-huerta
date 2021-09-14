//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"

#include "motor.h"

//=====[Declaration of private defines]======================================

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

PwmOut motor(PC_8);

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

//=====[Declarations (prototypes) of private functions]========================

//=====[Implementations of public functions]===================================

void motorInit()
{
    motor.period_ms(20);
    motor.pulsewidth_ms(1);
}

void activateMotor()
{
    motor.pulsewidth_ms(2);
}

void deactivateMotor()
{
    motor.pulsewidth_ms(1);
}

//=====[Implementations of private functions]==================================