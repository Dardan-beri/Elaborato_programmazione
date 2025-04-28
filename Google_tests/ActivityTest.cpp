#include "gtest/gtest.h"
#include "../Activity.h"

TEST(ActivityTest, ConstructorValid) {
    Time start(12, 30, 45);
    Time end(13, 30, 45);
    Activity a("Title", "Description", start, end);
    EXPECT_EQ(a.getTitle(), "Title");
    EXPECT_EQ(a.getDescription(), "Description");
    EXPECT_EQ(a.getStartTime().getHour(), 12);
    EXPECT_EQ(a.getStartTime().getMinute(), 30);
    EXPECT_EQ(a.getStartTime().getSecond(), 45);
    EXPECT_EQ(a.getEndTime().getHour(), 13);
    EXPECT_EQ(a.getEndTime().getMinute(), 30);
    EXPECT_EQ(a.getEndTime().getSecond(), 45);
}

TEST(ActivityTest, ConstructorInvalid) {
    Time start(12, 30, 45);
    Time end(11, 30, 45);
    EXPECT_THROW(Activity a("Title", "Description", start, end), std::invalid_argument);
}

TEST(ActivityTest, EqualValid){
    Time start(12, 30, 45);
    Time end(13, 30, 45);
    Activity a("Title", "Description", start, end);
    Activity b("Title", "Description", start, end);
    Activity c("Different", "Description", start, end);
    EXPECT_TRUE(a == b);
    EXPECT_FALSE(a == c);
}

TEST(ActivityTest, NotEqualValid){
    Time start(12, 30, 45);
    Time end(13, 30, 45);
    Activity a("Title", "Description", start, end);
    Activity b("Title", "Description", start, end);
    Activity c("Different", "Description", start, end);
    EXPECT_FALSE(a != b);
    EXPECT_TRUE(a != c);
}

TEST(ActivityTest, LessThanValid){
    Time start1(12, 30, 45);
    Time end1(13, 30, 45);
    Activity a("Title", "Description", start1, end1);

    Time start2(14, 30, 45);
    Time end2(15, 30, 45);
    Activity b("Title", "Description", start2, end2);

    EXPECT_TRUE(a < b);
}

TEST(ActivityTest, ToStringValid) {
    Time start(12, 30, 45);
    Time end(13, 30, 45);
    Activity a("Title", "Description", start, end);
    EXPECT_EQ(a.toString(), "Title: Title\nDescription: Description\nStart: 12:30:45\nEnd: 13:30:45");
}

TEST(ActivityTest, EqualOperatorString) {
    Time start(12, 30, 45);
    Time end(13, 30, 45);
    Activity a("Title", "Description", start, end);
    std::string b("Title");
    std::string c("Different");

    EXPECT_TRUE(a == b);
    EXPECT_FALSE(a == c);
}