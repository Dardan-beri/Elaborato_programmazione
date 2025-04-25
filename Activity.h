#ifndef ELABORATO_PROGRAMMAZIONE_ACTIVITY_H
#define ELABORATO_PROGRAMMAZIONE_ACTIVITY_H


#include <string>
#include "Time.h"

class Activity {

public:
    explicit Activity(std::string title, std::string description, Time start, Time end);
    bool operator==(const Activity &other) const;
    bool operator==(const std::string &title) const;
    bool operator!=(const Activity &other) const;
    bool operator<(const Activity &other) const;
    std::string toString() const;

    std::string getTitle() const {return title;};
    std::string getDescription() const {return description;};
    Time getStartTime() const {return start;};
    Time getEndTime() const {return end;};

private:
    std::string title;
    std::string description;
    Time start;
    Time end;

};

#endif //ELABORATO_PROGRAMMAZIONE_ACTIVITY_H
