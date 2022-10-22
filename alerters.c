#include "alerters.h"

int emailAlertCallCount;
int ledAlertCallCount;

void emailAlerter()
{
 emailAlertCallCount = 1;
}

void ledAlerter()
{
 ledAlertCallCount = 1;
}

