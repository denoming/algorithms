#include "CircularBuffer.hpp"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace testing;
using namespace algorithms;

template<std::size_t N>
using IntCircularBuffer = CircularBuffer<int, N>;

TEST(CircularBufferTest, Put)
{
    IntCircularBuffer<6> buffer;
    EXPECT_EQ(buffer.capacity(), 6);

    EXPECT_TRUE(buffer.empty());
    buffer.put(1);
    buffer.put(2);
    buffer.put(3);
    EXPECT_THAT(buffer, SizeIs(3));
    EXPECT_THAT(buffer.full(), IsFalse());

    EXPECT_FALSE(buffer.empty());
    buffer.put(4);
    buffer.put(5);
    buffer.put(6);
    EXPECT_THAT(buffer, SizeIs(6));
    EXPECT_THAT(buffer.full(), IsTrue());
}

TEST(CircularBufferTest, Get)
{
    IntCircularBuffer<3> buffer;
    EXPECT_EQ(buffer.capacity(), 3);

    EXPECT_TRUE(buffer.empty());
    buffer.put(1);
    EXPECT_FALSE(buffer.empty());
    EXPECT_THAT(buffer.get(), Optional(Eq(1)));
    EXPECT_TRUE(buffer.empty());
    buffer.put(2);
    EXPECT_FALSE(buffer.empty());
    EXPECT_THAT(buffer.get(), Optional(Eq(2)));
    EXPECT_TRUE(buffer.empty());
}

TEST(CircularBufferTest, GetFromEmpty)
{
    IntCircularBuffer<3> buffer;
    EXPECT_EQ(buffer.capacity(), 3);

    EXPECT_TRUE(buffer.empty());
    EXPECT_THAT(buffer.get(), std::nullopt);
}

TEST(CircularBufferTest, Reset)
{
    IntCircularBuffer<3> buffer;
    EXPECT_EQ(buffer.capacity(), 3);

    buffer.put(1);
    buffer.put(2);
    buffer.put(3);

    EXPECT_FALSE(buffer.empty());
    EXPECT_THAT(buffer, SizeIs(3));
    buffer.reset();
    EXPECT_TRUE(buffer.empty());
    EXPECT_THAT(buffer, SizeIs(0));
}