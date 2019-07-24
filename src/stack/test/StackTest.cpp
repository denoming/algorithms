#include <gtest/gtest.h>

#include <memory>

#include "FixedArrayStack.hpp"
#include "ResizableArrayStack.hpp"
#include "LinkedStack.hpp"

using namespace algorithms;

static constexpr int MIN = 0;
static constexpr int MAX = 10;

using IntStack = Stack<int>;

using IntStackPtr = std::unique_ptr<IntStack>;

using CreateStackFunctionPtr = IntStackPtr (*)();

class StackTest : public ::testing::TestWithParam<CreateStackFunctionPtr> {
public:
    void SetUp() override;

    void TearDown() override;

protected:
    IntStackPtr _stack;
};

void StackTest::SetUp()
{
    CreateStackFunctionPtr f = *GetParam();
    _stack = f();
}

void StackTest::TearDown()
{
    _stack.reset();
}

TEST_P(StackTest, Empty)
{
    ASSERT_TRUE(_stack->empty());
}

TEST_P(StackTest, Order)
{
    for (int n = MIN; n <= MAX; ++n) {
        _stack->push(n);
    }

    for (int n = MAX; n >= MIN; --n) {
        ASSERT_EQ(_stack->pop(), n);
    }
}

IntStackPtr createFixedArrayStack()
{
    using IntFixedArrayStack = FixedArrayStack<int>;
    return std::make_unique<IntFixedArrayStack>(MAX - MIN + 1 /* Specify size of stack */);
}

IntStackPtr createLinkedStack()
{
    using IntLinkedStack = LinkedStack<int>;
    return std::make_unique<IntLinkedStack>();
}

IntStackPtr createResizableArrayStack()
{
    using IntResizableArrayStack = ResizableArrayStack<int>;
    return std::make_unique<IntResizableArrayStack>();
}

INSTANTIATE_TEST_SUITE_P(StackTestSuite, StackTest,
                         ::testing::Values(&createFixedArrayStack, &createLinkedStack, &createResizableArrayStack));
