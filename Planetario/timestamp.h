#ifndef TIMESTAMP_H
#define TIMESTAMP_H

const double DAYTIME_PER_DAY = 1.0;

class TimeStamp
{
private:
    int _day;
    double _dayTime;
public:
    int day();
    double dayTime();
    double dayTimeTotal();
    TimeStamp *timeSince(TimeStamp *anchorStamp);
    TimeStamp(int day, double dayTime);
};

#endif // TIMESTAMP_H
