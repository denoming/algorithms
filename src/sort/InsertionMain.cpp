#include <gtest/gtest.h>

#include <Sequence.hpp>

#include "Insertion.hpp"

using namespace algorithms;

TEST(Insertion, Sort1K)
{
    Numbers numbers = Sequence::numbers(1000);

    Insertion::sort(numbers.begin(), numbers.end());

    ASSERT_TRUE(Sequence::isOrdered(numbers.begin(), numbers.end()));
}

TEST(Insertion, Sort10K)
{
    Numbers numbers = Sequence::numbers(10000);

    Insertion::sort(numbers.begin(), numbers.end());

    ASSERT_TRUE(Sequence::isOrdered(numbers.begin(), numbers.end()));
}

TEST(Insertion, DISABLED_Sort100K)
{
    Numbers numbers = Sequence::numbers(100000);

    Insertion::sort(numbers.begin(), numbers.end());

    ASSERT_TRUE(Sequence::isOrdered(numbers.begin(), numbers.end()));
}
