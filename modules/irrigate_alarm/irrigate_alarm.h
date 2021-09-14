//=====[#include guards - begin]===============================================

#ifndef _IRRIGATE_ALARM_H_
#define _IRRIGATE_ALARM_H_

//=====[Libraries]=============================================================

//=====[Declaration of public defines]=======================================

//=====[Declaration of public data types]======================================

//=====[Declarations (prototypes) of public functions]=========================

void irrigateAlarmInit();
void irrigateAlarmUpdate();
void irrigateAlarmDeactivate();
void updateMinHumLevel( float humidity );
bool humidityBelowDetectorStateRead();
bool humidityBelowDetectedRead();

//=====[#include guards - end]=================================================

#endif // _IRRIGATE_ALARM_H_
