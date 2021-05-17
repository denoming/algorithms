#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "List.hpp"

#include <list>
#include <iostream>

using namespace testing;
using namespace algorithms;

struct Data {
    explicit Data(bool throwException = false)
    {
        if (throwException) {
            throw std::runtime_error{"Dummy exception"};
        }
        std::cout << "ctor" << std::endl;
    }

    ~Data()
    {
        std::cout << "dtor" << std::endl;
    }
};

class ListTest : public Test {
public:
    List<int> list;
};

TEST_F(ListTest, Iterate)
{
    ASSERT_THAT(list, IsEmpty());

    list.pushBack(1);
    list.pushBack(2);
    list.pushBack(3);

    unsigned expected{1};
    for (auto value : list) {
        ASSERT_EQ(value, expected);
        expected++;
    }

    expected = 1;
    for (auto it = list.begin(); it != list.end(); ++it) { // NOLINT(modernize-loop-convert)
        auto value = *it;
        ASSERT_EQ(value, expected);
        expected++;
    }
}

TEST_F(ListTest, Emplace)
{
    ASSERT_THAT(list, IsEmpty());

    ASSERT_EQ(list.emplaceBack(1), 1);
    ASSERT_EQ(list.emplaceBack(2), 2);
    ASSERT_EQ(list.emplaceBack(3), 3);

    ASSERT_THAT(list, Not(IsEmpty()));
    ASSERT_THAT(list, SizeIs(3));

    ASSERT_EQ(list.front(), 1);
    list.popFront();
    ASSERT_EQ(list.front(), 2);
    list.popFront();
    ASSERT_EQ(list.front(), 3);
    list.popFront();

    ASSERT_THAT(list, IsEmpty());
    ASSERT_THAT(list, SizeIs(0));

    ASSERT_EQ(list.emplaceFront(1), 1);
    ASSERT_EQ(list.emplaceFront(2), 2);
    ASSERT_EQ(list.emplaceFront(3), 3);

    ASSERT_THAT(list, Not(IsEmpty()));
    ASSERT_THAT(list, SizeIs(3));

    EXPECT_EQ(list.back(), 1);
    list.popBack();
    EXPECT_EQ(list.back(), 2);
    list.popBack();
    EXPECT_EQ(list.back(), 3);
    list.popBack();

    EXPECT_THAT(list, IsEmpty());
    EXPECT_THAT(list, SizeIs(0));
}

TEST_F(ListTest, Push)
{
    ASSERT_THAT(list, IsEmpty());

    list.pushBack(1);
    list.pushBack(2);
    list.pushBack(3);

    ASSERT_THAT(list, Not(IsEmpty()));
    ASSERT_THAT(list, SizeIs(3));

    EXPECT_EQ(list.front(), 1);
    list.popFront();
    EXPECT_EQ(list.front(), 2);
    list.popFront();
    EXPECT_EQ(list.front(), 3);
    list.popFront();

    ASSERT_THAT(list, IsEmpty());
    ASSERT_THAT(list, SizeIs(0));

    list.pushFront(1);
    list.pushFront(2);
    list.pushFront(3);

    ASSERT_THAT(list, Not(IsEmpty()));
    ASSERT_THAT(list, SizeIs(3));

    EXPECT_EQ(list.back(), 1);
    list.popBack();
    EXPECT_EQ(list.back(), 2);
    list.popBack();
    EXPECT_EQ(list.back(), 3);
    list.popBack();

    EXPECT_THAT(list, IsEmpty());
    EXPECT_THAT(list, SizeIs(0));
}

TEST_F(ListTest, Assign)
{
    std::list<int> values;
    values.push_back(1);
    values.push_back(2);
    values.push_back(3);

    ASSERT_THAT(list, IsEmpty());
    list.pushBack(0);
    ASSERT_THAT(list, Not(IsEmpty()));

    list.assign(values.begin(), values.end());
    ASSERT_THAT(list, SizeIs(3));

    EXPECT_EQ(list.front(), 1);
    list.popFront();
    EXPECT_EQ(list.front(), 2);
    list.popFront();
    EXPECT_EQ(list.front(), 3);
    list.popFront();

    EXPECT_THAT(list, IsEmpty());
    EXPECT_THAT(list, SizeIs(0));
}

TEST_F(ListTest, Insert)
{
    std::list<int> values;
    values.push_back(1);
    values.push_back(2);
    values.push_back(3);

    ASSERT_THAT(list, IsEmpty());
    list.pushBack(4);
    ASSERT_THAT(list, Not(IsEmpty()));

    list.insert(list.begin(), values.begin(), values.end());
    ASSERT_THAT(list, SizeIs(4));

    EXPECT_EQ(list.front(), 1);
    list.popFront();
    EXPECT_EQ(list.front(), 2);
    list.popFront();
    EXPECT_EQ(list.front(), 3);
    list.popFront();
    EXPECT_EQ(list.front(), 4);
    list.popFront();

    EXPECT_THAT(list, IsEmpty());
    EXPECT_THAT(list, SizeIs(0));
}

TEST_F(ListTest, Clear)
{
    ASSERT_THAT(list, IsEmpty());

    list.pushBack(1);

    ASSERT_THAT(list, Not(IsEmpty()));
    ASSERT_THAT(list, SizeIs(1));

    list.clear();

    EXPECT_THAT(list, IsEmpty());
    EXPECT_THAT(list, SizeIs(0));
}

TEST_F(ListTest, Copy)
{
    ASSERT_THAT(list, IsEmpty());

    list.pushBack(1);
    list.pushBack(2);
    list.pushBack(3);

    std::array<std::byte, 1024> buffer = {};
    std::pmr::monotonic_buffer_resource resource{buffer.data(), buffer.size()};
    decltype(list) copyOfList(list, std::pmr::polymorphic_allocator(&resource));

    EXPECT_THAT(copyOfList, Not(IsEmpty()));
    EXPECT_THAT(copyOfList, SizeIs(3));
}

TEST_F(ListTest, CopyByAsign)
{
    ASSERT_THAT(list, IsEmpty());

    list.pushBack(1);
    list.pushBack(2);
    list.pushBack(3);

    decltype(list) copyOfList;
    copyOfList = list;

    EXPECT_THAT(copyOfList, Not(IsEmpty()));
    EXPECT_THAT(copyOfList, SizeIs(3));
}

TEST_F(ListTest, Move)
{
    list.pushBack(1);
    list.pushBack(2);
    list.pushBack(3);

    decltype(list) otherList1(std::move(list));

    ASSERT_THAT(otherList1, Not(IsEmpty()));
    EXPECT_THAT(otherList1, SizeIs(3));

    ASSERT_THAT(list, IsEmpty());
    EXPECT_THAT(list, SizeIs(0));
}

TEST_F(ListTest, MoveWithDifferentMemoryResource)
{
    list.pushBack(1);
    list.pushBack(2);
    list.pushBack(3);

    std::array<std::byte, 1024> buffer = {};
    std::pmr::monotonic_buffer_resource resource{buffer.data(), buffer.size()};
    decltype(list) otherList(std::move(list), std::pmr::polymorphic_allocator(&resource));

    ASSERT_THAT(otherList, Not(IsEmpty()));
    EXPECT_THAT(otherList, SizeIs(3));

    ASSERT_THAT(list, Not(IsEmpty()));
    EXPECT_THAT(list, SizeIs(3));
}

TEST_F(ListTest, MoveByAsign)
{
    list.pushBack(1);
    list.pushBack(2);
    list.pushBack(3);

    decltype(list) otherList;
    otherList = std::move(list);

    ASSERT_THAT(otherList, Not(IsEmpty()));
    EXPECT_THAT(otherList, SizeIs(3));
    ASSERT_THAT(list, IsEmpty());
    EXPECT_THAT(list, SizeIs(0));
}

TEST_F(ListTest, ExceptionSafety)
{
    List<Data> dataList;
    EXPECT_NO_THROW(dataList.emplaceBack());
    EXPECT_ANY_THROW(dataList.emplaceBack(true));
}
