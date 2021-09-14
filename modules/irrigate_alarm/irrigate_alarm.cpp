//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"

#include "irrigate_alarm.h"
#include "humidity_sensor.h"
#include "motor.h"

//=====[Declaration of private defines]======================================

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

DigitalIn irrigateAlarmTestButton(BUTTON1);
Timeout motorTask;
Timeout humidityChange;
int MIN_HUMIDITY_LEVEL = 50;

//=====[Declaration and initialization of private global variables]============

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

static bool humidityBelowDetected        = OFF;
static bool humidityBelowDetectorState   = OFF;
static bool taskMotorRunning             = OFF;
static bool humidityChanged              = OFF;

//=====[Declarations (prototypes) of private functions]========================

static void motorTaskFinish();
static void humidityAlreadyChanged();

//=====[Implementations of public functions]===================================

void updateMinHumLevel( float humidity )
{
    MIN_HUMIDITY_LEVEL = humidity;
}

void irrigateAlarmInit()
{
    humiditySensorInit();
    motorInit();
    irrigateAlarmTestButton.mode(PullDown); 
}

void irrigateAlarmUpdate()
{
    humiditySensorUpdate();

    humidityBelowDetectorState = humiditySensorRead() < 
                                   MIN_HUMIDITY_LEVEL;

    if ( humidityBelowDetectorState && !taskMotorRunning
        && !humidityChanged ) {
        activateMotor();
        humidityChanged = ON;
        motorTask.attach(&motorTaskFinish, 10.0);
        taskMotorRunning = ON;
        humidityBelowDetected = ON;
    }

    if( irrigateAlarmTestButton && !taskMotorRunning
       && !humidityChanged ) {
        activateMotor();
        humidityChanged = ON;
        motorTask.attach(&motorTaskFinish, 10.0);
        taskMotorRunning = ON;
        humidityBelowDetected = ON;
    }
}

bool humidityBelowDetectorStateRead()
{
    return humidityBelowDetectorState;
}

bool humidityBelowDetectedRead()
{
    return humidityBelowDetected;
}

void irrigateAlarmDeactivate()
{
    humidityBelowDetected = OFF;   
}

//=====[Implementations of private functions]==================================

static void motorTaskFinish()
{
    taskMotorRunning = OFF;
    humidityChange.attach(&humidityAlreadyChanged, 20);
    deactivateMotor();
}

static void humidityAlreadyChanged()
{
    humidityChanged = OFF;
}