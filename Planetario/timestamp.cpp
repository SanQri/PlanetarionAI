#include "timestamp.h"

TimeStamp::TimeStamp(int day, double dayTime) {
    _day = day;
    _dayTime = dayTime;
    if (dayTime < 0) {
        _day--;
        _dayTime += DAYTIME_PER_DAY;
    }
}

int TimeStamp::day() {
    return _day;
}

double TimeStamp::dayTime() {
    return _dayTime;
}

double TimeStamp::dayTimeTotal() {
    return _day * DAYTIME_PER_DAY + _dayTime;
}

TimeStamp *TimeStamp::timeSince(TimeStamp *anchorStamp) {
    return new TimeStamp(_day - anchorStamp->day(), _dayTime - anchorStamp->dayTime());
}
