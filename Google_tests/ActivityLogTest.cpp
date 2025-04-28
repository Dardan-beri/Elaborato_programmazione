#include "gtest/gtest.h"
#include "../ActivityLog.h"
#include "../Activity.h"
#include "../Time.h"

TEST(ActivityLogTest, NumberOfActivities) {
    ActivityLog log;
    EXPECT_EQ(log.getNumberOfActivities(), 0);
}

TEST(ActivityLogTest, AddActivityValid) {
    ActivityLog log;
    Time s(21, 30);
    Time e(22, 30);
    Activity a("Test", "Test activity", s, e);
    EXPECT_TRUE(log.addActivity(a));
    EXPECT_EQ(log.getNumberOfActivities(), 1);
}

TEST(ActivityLogTest, AddActivityInvalid) {
    ActivityLog log;
    Time s(21, 30);
    Time e(22, 30);
    Activity a("Test", "Test activity", s, e);
    log.addActivity(a);
    EXPECT_FALSE(log.addActivity(a));
    EXPECT_EQ(log.getNumberOfActivities(), 1);
}

TEST(ActivityLogTest, DeleteActivityValid) {
    ActivityLog log;
    Time s(21, 30);
    Time e(22, 30);
    Activity a("Test", "Test activity", s, e);
    log.addActivity(a);
    EXPECT_TRUE(log.deleteActivity(a));
    EXPECT_EQ(log.getNumberOfActivities(), 0);
}

TEST(ActivityLogTest, DeleteActivityInvalid) {
    ActivityLog log;
    Time s(21, 30);
    Time e(22, 30);
    Activity a("Test", "Test activity", s, e);
    log.addActivity(a);
    Activity b("Test2", "Test activity", s, e);
    EXPECT_FALSE(log.deleteActivity(b));
    EXPECT_EQ(log.getNumberOfActivities(), 1);
}

TEST(ActivityLogTest, DeleteActivityByTitleValid) {
    ActivityLog log;
    Time s(21, 30);
    Time e(22, 30);
    Activity a("Test", "Test activity", s, e);
    log.addActivity(a);
    std::string title = "Test";
    EXPECT_TRUE(log.deleteActivity(title));
    EXPECT_EQ(log.getNumberOfActivities(), 0);
}

TEST(ActivityLogTest, DeleteActivityByTitleInvalid) {
    ActivityLog log;
    Time s(21, 30);
    Time e(22, 30);
    Activity a("Test", "Test activity", s, e);
    log.addActivity(a);
    std::string title = "Test2";
    EXPECT_FALSE(log.deleteActivity(title));
    EXPECT_EQ(log.getNumberOfActivities(), 1);
}

TEST(ActivityLogTest, GetActivities) {
    ActivityLog log;
    Time s(21, 30);
    Time e(22, 30);
    Activity a("Test", "Test activity", s, e);
    log.addActivity(a);
    std::vector<Activity> activities = log.getActivities();
    EXPECT_EQ(activities.size(), 1);
    EXPECT_EQ(activities[0].getTitle(), "Test");
}

TEST(ActivityLogTest, GetActivitiesByType) {
    ActivityLog log;
    Time s(21, 30);
    Time e(22, 30);
    Activity a("Test", "Test activity", s, e);
    Activity b("Other", "Other type", s, e);
    Activity c("Test 2", "Second test activity", s, e);
    log.addActivity(a);
    log.addActivity(b);
    log.addActivity(c);
    std::vector<Activity> activities = log.getActivitiesByType("Test");
    EXPECT_EQ(activities.size(), 2);
    EXPECT_EQ(activities[0].getTitle(), "Test");
    EXPECT_EQ(activities[1].getTitle(), "Test 2");
}

TEST(ActivityLogTest, GetActivitiesByTypeEmpty) {
    ActivityLog log;
    Time s(21, 30);
    Time e(22, 30);
    Activity a("Test", "Test activity", s, e);
    log.addActivity(a);
    std::vector<Activity> activities = log.getActivitiesByType("Other");
    EXPECT_EQ(activities.size(), 0);
}

TEST(ActivityLogTest, OperatorIndex) {
    ActivityLog log;
    Time s(21, 30);
    Time e(22, 30);
    Activity a("Test", "Test activity", s, e);
    log.addActivity(a);
    EXPECT_EQ(log[0].getTitle(), "Test");
}