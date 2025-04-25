//
// Created by Dardan Matias Berisha on 24/04/25.
//

#include "Activity.h"

Activity::Activity(std::string title, std::string description, Time start, Time end)
        : title(std::move(title)), description(std::move(description)), start(std::move(start)), end(std::move(end)) {
}

bool Activity::operator==(const Activity &other) const {
    return this->title == other.title;
}

bool Activity::operator!=(const Activity &other) const {
    return this->title != other.title;
}

bool Activity::operator<(const Activity &other) const {
    return this->start < other.start;
}

std::string Activity::toString() const {
    return "Title: " + title +
    "\nDescription: " + description +
    "\nStart: " + start.toString() +
    "\nEnd: " + end.toString();
}

bool Activity::operator==(const std::string &title) const {
    return this->title == title;
}
