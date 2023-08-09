#include <gtest/gtest.h>

#include <BubbleSort.hpp>
#include <Sequence.hpp>

using namespace testing;
using namespace algorithms;

class BubbleSortTest : public TestWithParam<std::size_t> {
public:
    BubbleSortTest()
        : numbers{Sequence::numbers<int>(GetParam())}
    {
    }

public:
    Numbers<int> numbers;
};

TEST_P(BubbleSortTest, AscendingSort)
{
    BubbleSort::sort(numbers.begin(), numbers.end());
    ASSERT_TRUE(Sequence::isAscending(numbers.begin(), numbers.end()));
}

TEST_P(BubbleSortTest, DescendingSort)
{
    BubbleSort::sort(numbers.begin(), numbers.end(), std::greater<int>{});
    ASSERT_TRUE(Sequence::isDescending(numbers.begin(), numbers.end()));
}

TEST_P(BubbleSortTest, InvalidIterators)
{
    EXPECT_NO_THROW(BubbleSort::sort(numbers.end(), numbers.begin()));
}

INSTANTIATE_TEST_SUITE_P(Sort, BubbleSortTest, Values(100, 1000, 10000));
