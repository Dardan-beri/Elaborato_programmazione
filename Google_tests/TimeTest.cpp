#include "gtest/gtest.h"
#include "../Time.h"

TEST(TimeTest, ConstructorValid) {
    Time t(12, 30, 45);
    EXPECT_EQ(t.getHour(), 12);
    EXPECT_EQ(t.getMinute(), 30);
    EXPECT_EQ(t.getSecond(), 45);
}

TEST(TimeTest, ConstructorInvalid) {
    EXPECT_THROW(Time t(25, 30, 45), std::invalid_argument); //ore sbagliate
    EXPECT_THROW(Time t(12, 60, 45), std::invalid_argument); //minuti sbagliati
    EXPECT_THROW(Time t(12, 30, 61), std::invalid_argument); //secondi sbagliati

    EXPECT_THROW(Time t(-1, 30, 45), std::invalid_argument); //ore sbagliate
    EXPECT_THROW(Time t(12, -5, 45), std::invalid_argument); //minuti sbagliati
    EXPECT_THROW(Time t(12, 30, -10), std::invalid_argument); //secondi sbagliati
}

TEST(TimeTest, SettersValid) {
    Time t(12, 30, 45);
    t.setHour(10);
    t.setMinute(20);
    t.setSecond(50);

    EXPECT_EQ(t.getHour(), 10);
    EXPECT_EQ(t.getMinute(), 20);
    EXPECT_EQ(t.getSecond(), 50);
}

TEST(TimeTest, SettersInvalid) {
    Time t(12, 30, 45);

    EXPECT_THROW(t.setHour(25), std::invalid_argument); //ore sbagliate
    EXPECT_THROW(t.setMinute(60), std::invalid_argument); //minuti sbagliati
    EXPECT_THROW(t.setSecond(61), std::invalid_argument); //secondi sbagliati

    EXPECT_THROW(t.setHour(-1), std::invalid_argument); //ore sbagliate
    EXPECT_THROW(t.setMinute(-5), std::invalid_argument); //minuti sbagliati
    EXPECT_THROW(t.setSecond(-10), std::invalid_argument); //secondi sbagliati
}

TEST(TimeTest, toStringValid) {
    Time t(12, 30, 45);
    EXPECT_EQ(t.toString(), "12:30:45");
}

TEST(TimeTest, EqualOperator) {
    Time t1(12, 30, 45);
    Time t2(12, 30, 45);
    Time t3(10, 20, 50);

    EXPECT_TRUE(t1 == t2);
    EXPECT_FALSE(t1 == t3);
}

TEST(TimeTest, NotEqualOperator) {
    Time t1(12, 30, 45);
    Time t2(12, 30, 45);
    Time t3(10, 20, 50);

    EXPECT_FALSE(t1 != t2);
    EXPECT_TRUE(t1 != t3);
}

TEST(TimeTest, LessThanOperator) {
    Time t1(12, 30, 45);
    Time t2(12, 30, 50);
    Time t3(12, 31, 0);

    EXPECT_TRUE(t1 < t2);
    EXPECT_TRUE(t1 < t3);
    EXPECT_FALSE(t2 < t1);
    EXPECT_FALSE(t3 < t1);
}