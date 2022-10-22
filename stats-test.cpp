#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "catch.hpp"
#include "stats.h"

#include <stdlib.h>
#include <math.h>
#include "alerters.h"

TEST_CASE("reports average, minimum and maximum") {
   float numberset[] = {1.5, 8.9, 3.2, 4.5};
   int setlength = sizeof(numberset) / sizeof(numberset[0]);
   Stats_t computedStats = compute_statistics(numberset, setlength);
   float epsilon = 0.001;

   REQUIRE(abs(computedStats.average - 4.525) < epsilon);
   REQUIRE(abs(computedStats.max - 8.9) < epsilon);
   REQUIRE(abs(computedStats.min - 1.5) < epsilon);
}

TEST_CASE("average is NaN for empty array") {
   float  numberset[] = {};
   Stats_t computedStats = compute_statistics(numberset, 0);

   REQUIRE(isnan(computedStats.average));
   REQUIRE(isnan(computedStats.max));
   REQUIRE(isnan(computedStats.min));

}

TEST_CASE("raises alerts when max is greater than threshold") {
     alerter_funcptr alerters[] = {emailAlerter, ledAlerter};
     float numberset[] = {99.8, 34.2, 4.5};
     int setlength = sizeof(numberset) / sizeof(numberset[0]);
     Stats_t computedStats = compute_statistics(numberset, setlength);

    const float maxThreshold = 10.2;
    check_and_alert(maxThreshold, alerters, computedStats);

    REQUIRE(emailAlertCallCount == 1);
    REQUIRE(ledAlertCallCount == 1);
}
