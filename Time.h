//
// Created by Dardan Matias Berisha on 24/04/25.
//

#ifndef ELABORATO_PROGRAMMAZIONE_TIME_H
#define ELABORATO_PROGRAMMAZIONE_TIME_H


#include <string>
#include <sstream>

class Time {
public:
    Time(int h, int m, int s = 0);
    std::string toString() const;
    bool operator==(const Time &other) const;
    bool operator!=(const Time &other) const;
    bool operator<(const Time &other) const;

    int getHour() const { return hour; }
    int getMinute() const { return minute; }
    int getSecond() const { return second; }

    void setHour(int h);
    void setMinute(int m);
    void setSecond(int s);

private:
    int hour;
    int minute;
    int second;
};


#endif //ELABORATO_PROGRAMMAZIONE_TIME_H
