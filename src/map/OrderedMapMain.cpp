#include <gtest/gtest.h>

#include "Data.hpp"
#include "OrderedMap.hpp"

using namespace algorithms;

class OrderedMapTest : public ::testing::Test {
protected:
    void SetUp() override
    {
        map.put("S", Data{"S"});
        map.put("E", Data{"E"});
        map.put("A", Data{"A"});
        map.put("C", Data{"C"});
        map.put("X", Data{"X"});
        map.put("R", Data{"R"});
        map.put("H", Data{"H"});
        map.put("M", Data{"M"});
    }

    void TearDown() override
    {
    }

protected:
    OrderedMap<std::string, Data> map;
};

TEST_F(OrderedMapTest, EmptyTest)
{
    EXPECT_FALSE(map.empty());
}

TEST_F(OrderedMapTest, SizeTest)
{
    EXPECT_EQ(map.size(), 8);
}

TEST_F(OrderedMapTest, ContainsTest)
{
    EXPECT_TRUE(map.contains("E"));
}

TEST_F(OrderedMapTest, ValidGetTest)
{
    EXPECT_TRUE(map.get("S").name == "S");
}

TEST_F(OrderedMapTest, InvalidGetTest)
{
    EXPECT_THROW(map.get("O"), std::runtime_error);
}

TEST_F(OrderedMapTest, ValidPickTest)
{
    auto value = map.pick("S");
    ASSERT_TRUE(value.has_value());
    EXPECT_EQ(value.value().name, "S");
}

TEST_F(OrderedMapTest, InvalidPickTest)
{
    auto value = map.pick("O");
    EXPECT_FALSE(value.has_value());
}

TEST_F(OrderedMapTest, MinMaxTest)
{
    auto minKey = map.min();
    ASSERT_TRUE(minKey.has_value());
    EXPECT_EQ(map.get(minKey.value()).name, "A");
    map.eraseMin();
    EXPECT_FALSE(map.contains("A"));

    auto maxKey = map.max();
    ASSERT_TRUE(maxKey.has_value());
    EXPECT_EQ(map.get(maxKey.value()).name, "X");
    map.eraseMax();
    ASSERT_FALSE(map.contains("X"));
}

TEST_F(OrderedMapTest, EraseTest)
{
    map.erase("C");
    EXPECT_FALSE(map.contains("C"));
}

TEST_F(OrderedMapTest, RankTest)
{
    EXPECT_EQ(map.rank("M"), 4);
}

TEST_F(OrderedMapTest, FloorTest)
{
    auto floorKey = map.floor("F");
    ASSERT_TRUE(floorKey.has_value());
    EXPECT_EQ(map.get(floorKey.value()).name, "E");
}

TEST_F(OrderedMapTest, CeilingTest)
{
    auto ceilingKey = map.ceiling("B");
    ASSERT_TRUE(ceilingKey.has_value());
    EXPECT_EQ(map.get(ceilingKey.value()).name, "C");
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
