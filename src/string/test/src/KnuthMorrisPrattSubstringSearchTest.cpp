#include <gtest/gtest.h>

#include "KnuthMorrisPrattSubstringSearch.hpp"

using namespace algorithms;
using namespace testing;

using CharSubstringSearch = KnuthMorrisPrattSubstringSearch<char>;

TEST(TrioSubstringSearchTest, Find)
{
    static const std::string_view text{"Peter Piper picked a peck of pickled peppers\n"
                                       "A peck of pickled peppers Peter Piper picked\n"
                                       "If Peter Piper picked a peck of pickled peppers\n"
                                       "Where’s the peck of pickled peppers Peter Piper picked?"};

    static const std::string_view pattern{"pepper"};

    const auto p1 = CharSubstringSearch::search(text, pattern);
    const auto p2 = text.find(pattern);
    EXPECT_EQ(p1, p2);
}