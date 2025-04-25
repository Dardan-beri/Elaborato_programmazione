//
// Created by Dardan Matias Berisha on 21/06/23.
//

#ifndef ELABORATO_PROGRAMMAZIONE_ACTIVITYLOG_H
#define ELABORATO_PROGRAMMAZIONE_ACTIVITYLOG_H
#include <string>
#include <sstream>
#include <vector>
#include "Activity.h"

class ActivityLog{
public:
    bool addActivity(const Activity &a);
    std::vector<Activity> getActivities() const;
    bool deleteActivity(Activity &a);
    bool deleteActivity(std::string &title);
    Activity operator[](int pos) const;

    //attività di un certo tipo (che nel titolo o descrizione contengono la stringa type)
    std::vector<Activity> getActivitiesByType(const std::string &type) const;

    //numero di attività
    int getNumberOfActivities() const {
        return activities.size();
    }

private:
    std::vector<Activity> activities;
};


#endif //ELABORATO_PROGRAMMAZIONE_ACTIVITYLOG_H
