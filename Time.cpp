#include "Time.h"

std::string Time::toString() const {
        std::stringstream ss;
        ss << (hour < 10 ? "0" : "") << hour << ":"
           << (minute < 10 ? "0" : "") << minute << ":"
           << (second < 10 ? "0" : "") << second;
        return ss.str();
    }

Time::Time(int h, int m, int s) {
    if(h < 0 || h > 23)
        throw std::invalid_argument("Hour must be between 0 and 23");
    if(m < 0 || m > 59)
        throw std::invalid_argument("Minute must be between 0 and 59");
    if(s < 0 || s > 59)
        throw std::invalid_argument("Second must be between 0 and 59");
    this->hour = h;
    this->minute = m;
    this->second = s;
}

bool Time::operator==(const Time &other) const {
    return this->hour == other.hour &&
              this->minute == other.minute &&
              this->second == other.second;
}

bool Time::operator!=(const Time &other) const {
    return !(*this == other);
}

bool Time::operator<(const Time &other) const {
    if(this->hour < other.hour)
        return true;
    else if(this->hour == other.hour){
        if(this->minute < other.minute)
            return true;
        else if(this->minute == other.minute){
            if(this->second < other.second)
                return true;
        }
    }
    return false;
}

void Time::setHour(int h) {
    if(h < 0 || h > 23)
        throw std::invalid_argument("Hour must be between 0 and 23");
    this->hour = h;
}

void Time::setMinute(int m) {
    if(m < 0 || m > 59)
        throw std::invalid_argument("Minute must be between 0 and 59");
    this->minute = m;
}

void Time::setSecond(int s) {
    if(s < 0 || s > 59)
        throw std::invalid_argument("Second must be between 0 and 59");
    this->second = s;
}

bool Time::operator>(const Time &other) const {
    if(this->hour > other.hour)
        return true;
    else if(this->hour == other.hour){
        if(this->minute > other.minute)
            return true;
        else if(this->minute == other.minute){
            if(this->second > other.second)
                return true;
        }
    }
    return false;
}
