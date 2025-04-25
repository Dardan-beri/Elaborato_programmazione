#include "ActivityLog.h"
#include <algorithm>

bool ActivityLog::addActivity(const Activity &activity) {
    auto it = std::find(activities.begin(), activities.end(), activity);
    if (it == activities.end()) {
        activities.push_back(activity);
        std::sort(activities.begin(), activities.end()); //sorts by start time of activities
        return true;
    }else{
        return false;
    }
}

std::vector<Activity> ActivityLog::getActivities() const{
    return activities;
}

bool ActivityLog::deleteActivity(Activity &activity){
    auto it = std::find(activities.begin(), activities.end(), activity);
    if(it != activities.end()) {
        activities.erase(it);
        return true;
    }
    return false;
}

bool ActivityLog::deleteActivity(std::string &title){
    auto it = std::find(activities.begin(), activities.end(), title);
    if(it != activities.end()) {
        activities.erase(it);
        return true;
    }
    return false;
}

Activity ActivityLog::operator[](int pos) const{
    return activities[pos];
}

std::vector<Activity> ActivityLog::getActivitiesByType(const std::string &type) const {
    std::vector<Activity> filteredActivities;
    for (const auto& activity : activities) {
        if (activity.getDescription().find(type) != std::string::npos ||
            activity.getTitle().find(type) != std::string::npos) {
            filteredActivities.push_back(activity);
        }
    }
    return filteredActivities;
}
