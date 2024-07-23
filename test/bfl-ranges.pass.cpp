#include <gtest/gtest.h>
#include <bfl-ranges.hpp>

#include <vector>
#include <deque>
#include <list>
#include <string>
#include <stack>
#include <queue>

// ---------------------------------------------------------------------------------------------------------------------
TEST(PushBackRangeTest, VectorPushBack)
{
    std::vector<int> vec;
    bfl::ranges::push_back_range(vec, 1, 2, 3, 4);
    ASSERT_EQ(vec.size(), 4);
    EXPECT_EQ(vec[0], 1);
    EXPECT_EQ(vec[1], 2);
    EXPECT_EQ(vec[2], 3);
    EXPECT_EQ(vec[3], 4);
}

// ---------------------------------------------------------------------------------------------------------------------
TEST(PushBackRangeTest, DequePushBack)
{
    std::deque<int> deq;
    bfl::ranges::push_back_range(deq, 5, 6, 7);
    ASSERT_EQ(deq.size(), 3);
    EXPECT_EQ(deq[0], 5);
    EXPECT_EQ(deq[1], 6);
    EXPECT_EQ(deq[2], 7);
}

// ---------------------------------------------------------------------------------------------------------------------
TEST(PushBackRangeTest, ListPushBack)
{
    std::list<int> lst;
    bfl::ranges::push_back_range(lst, 8, 9);
    ASSERT_EQ(lst.size(), 2);
    auto it = lst.begin();
    EXPECT_EQ(*it++, 8);
    EXPECT_EQ(*it, 9);
}

// ---------------------------------------------------------------------------------------------------------------------
TEST(PushBackRangeTest, MixedValues)
{
    using namespace std::string_literals;
    std::vector<std::string> vec;
    bfl::ranges::push_back_range(vec, "hello"s, "world"s, "test"s);
    ASSERT_EQ(vec.size(), 3);
    EXPECT_EQ(vec[0], "hello");
    EXPECT_EQ(vec[1], "world");
    EXPECT_EQ(vec[2], "test");
}

// ---------------------------------------------------------------------------------------------------------------------
TEST(PushFrontRangeTest, DequePushFront)
{
    std::deque<int> deq;
    bfl::ranges::push_front_range(deq, 1, 2, 3, 4);
    ASSERT_EQ(deq.size(), 4);
    EXPECT_EQ(deq[0], 4);
    EXPECT_EQ(deq[1], 3);
    EXPECT_EQ(deq[2], 2);
    EXPECT_EQ(deq[3], 1);
}

// ---------------------------------------------------------------------------------------------------------------------
TEST(PushFrontRangeTest, ListPushFront)
{
    std::list<int> lst;
    bfl::ranges::push_front_range(lst, 5, 6, 7, 8);
    ASSERT_EQ(lst.size(), 4);
    auto it = lst.begin();
    EXPECT_EQ(*it++, 8);
    EXPECT_EQ(*it++, 7);
    EXPECT_EQ(*it++, 6);
    EXPECT_EQ(*it, 5);
}

// ---------------------------------------------------------------------------------------------------------------------
TEST(PushFrontRangeTest, MixedValues)
{
    using namespace std::string_literals;
    std::deque<std::string> deq;
    bfl::ranges::push_front_range(deq, "hello"s, "world"s, "test"s);
    ASSERT_EQ(deq.size(), 3);
    EXPECT_EQ(deq[0], "test");
    EXPECT_EQ(deq[1], "world");
    EXPECT_EQ(deq[2], "hello");
}

// ---------------------------------------------------------------------------------------------------------------------
TEST(PushRangeTest, StackPush)
{
    std::stack<int> stk;
    bfl::ranges::push_range(stk, 1, 2, 3, 4);
    ASSERT_EQ(stk.size(), 4);
    EXPECT_EQ(stk.top(), 4);
    stk.pop();
    EXPECT_EQ(stk.top(), 3);
    stk.pop();
    EXPECT_EQ(stk.top(), 2);
    stk.pop();
    EXPECT_EQ(stk.top(), 1);
}

// ---------------------------------------------------------------------------------------------------------------------
TEST(PushRangeTest, QueuePush)
{
    std::queue<int> que;
    bfl::ranges::push_range(que, 5, 6, 7, 8);
    ASSERT_EQ(que.size(), 4);
    EXPECT_EQ(que.front(), 5);
    que.pop();
    EXPECT_EQ(que.front(), 6);
    que.pop();
    EXPECT_EQ(que.front(), 7);
    que.pop();
    EXPECT_EQ(que.front(), 8);
}

// ---------------------------------------------------------------------------------------------------------------------
TEST(PushRangeTest, MixedValues)
{
    using namespace std::string_literals;
    std::stack<std::string> stk;
    bfl::ranges::push_range(stk, "hello"s, "world"s, "test"s);
    ASSERT_EQ(stk.size(), 3);
    EXPECT_EQ(stk.top(), "test");
    stk.pop();
    EXPECT_EQ(stk.top(), "world");
    stk.pop();
    EXPECT_EQ(stk.top(), "hello");
}

// ---------------------------------------------------------------------------------------------------------------------
TEST(ContainsAllTest, VectorContainsAll)
{
    std::vector<int> vec = {1, 2, 3, 4, 5};
    EXPECT_TRUE(bfl::ranges::contains_all(vec, 1, 2, 3));
    EXPECT_TRUE(bfl::ranges::contains_all(vec, 5));
    EXPECT_FALSE(bfl::ranges::contains_all(vec, 0));
    EXPECT_FALSE(bfl::ranges::contains_all(vec, 6, 7));
}

// ---------------------------------------------------------------------------------------------------------------------
TEST(ContainsAllTest, DequeContainsAll)
{
    std::deque<int> deq = {6, 7, 8, 9, 10};
    EXPECT_TRUE(bfl::ranges::contains_all(deq, 6, 7, 8));
    EXPECT_TRUE(bfl::ranges::contains_all(deq, 10));
    EXPECT_FALSE(bfl::ranges::contains_all(deq, 1));
    EXPECT_FALSE(bfl::ranges::contains_all(deq, 11, 12));
}

// ---------------------------------------------------------------------------------------------------------------------
TEST(ContainsAllTest, ListContainsAll)
{
    std::list<int> lst = {11, 12, 13, 14, 15};
    EXPECT_TRUE(bfl::ranges::contains_all(lst, 11, 12, 13));
    EXPECT_TRUE(bfl::ranges::contains_all(lst, 15));
    EXPECT_FALSE(bfl::ranges::contains_all(lst, 16));
    EXPECT_FALSE(bfl::ranges::contains_all(lst, 17, 18));
}

// ---------------------------------------------------------------------------------------------------------------------
TEST(ContainsAllTest, MixedValues)
{
    std::vector<std::string> vec = {"hello", "world", "test"};
    EXPECT_TRUE(bfl::ranges::contains_all(vec, "hello", "world"));
    EXPECT_TRUE(bfl::ranges::contains_all(vec, "test"));
    EXPECT_FALSE(bfl::ranges::contains_all(vec, "goodbye"));
    EXPECT_FALSE(bfl::ranges::contains_all(vec, "hello", "universe"));
}

// ---------------------------------------------------------------------------------------------------------------------
TEST(ContainsAnyTest, VectorContainsAny)
{
    std::vector<int> vec = {1, 2, 3, 4, 5};
    EXPECT_TRUE(bfl::ranges::contains_any(vec, 1, 6, 7));
    EXPECT_TRUE(bfl::ranges::contains_any(vec, 5));
    EXPECT_FALSE(bfl::ranges::contains_any(vec, 0));
    EXPECT_FALSE(bfl::ranges::contains_any(vec, 6, 7));
}

// ---------------------------------------------------------------------------------------------------------------------
TEST(ContainsAnyTest, DequeContainsAny)
{
    std::deque<int> deq = {6, 7, 8, 9, 10};
    EXPECT_TRUE(bfl::ranges::contains_any(deq, 6, 11, 12));
    EXPECT_TRUE(bfl::ranges::contains_any(deq, 10));
    EXPECT_FALSE(bfl::ranges::contains_any(deq, 1));
    EXPECT_FALSE(bfl::ranges::contains_any(deq, 11, 12));
}

// ---------------------------------------------------------------------------------------------------------------------
TEST(ContainsAnyTest, ListContainsAny)
{
    std::list<int> lst = {11, 12, 13, 14, 15};
    EXPECT_TRUE(bfl::ranges::contains_any(lst, 11, 16, 17));
    EXPECT_TRUE(bfl::ranges::contains_any(lst, 15));
    EXPECT_FALSE(bfl::ranges::contains_any(lst, 18));
    EXPECT_FALSE(bfl::ranges::contains_any(lst, 16, 17));
}

// ---------------------------------------------------------------------------------------------------------------------
TEST(ContainsAnyTest, MixedValues)
{
    std::vector<std::string> vec = {"hello", "world", "test"};
    EXPECT_TRUE(bfl::ranges::contains_any(vec, "hello", "universe"));
    EXPECT_TRUE(bfl::ranges::contains_any(vec, "test"));
    EXPECT_FALSE(bfl::ranges::contains_any(vec, "goodbye"));
    EXPECT_FALSE(bfl::ranges::contains_any(vec, "universe", "galaxy"));
}

// ---------------------------------------------------------------------------------------------------------------------
TEST(ContainsNoneTest, VectorContainsNone)
{
    std::vector<int> vec = {1, 2, 3, 4, 5};
    EXPECT_TRUE(bfl::ranges::contains_none(vec, 6, 7, 8));
    EXPECT_TRUE(bfl::ranges::contains_none(vec, 0));
    EXPECT_FALSE(bfl::ranges::contains_none(vec, 1, 5));
    EXPECT_FALSE(bfl::ranges::contains_none(vec, 2, 6));
}

// ---------------------------------------------------------------------------------------------------------------------
TEST(ContainsNoneTest, DequeContainsNone)
{
    std::deque<int> deq = {6, 7, 8, 9, 10};
    EXPECT_TRUE(bfl::ranges::contains_none(deq, 1, 2, 3));
    EXPECT_TRUE(bfl::ranges::contains_none(deq, 11, 12));
    EXPECT_FALSE(bfl::ranges::contains_none(deq, 7, 8));
    EXPECT_FALSE(bfl::ranges::contains_none(deq, 6, 9));
}

// ---------------------------------------------------------------------------------------------------------------------
TEST(ContainsNoneTest, ListContainsNone)
{
    std::list<int> lst = {11, 12, 13, 14, 15};
    EXPECT_TRUE(bfl::ranges::contains_none(lst, 1, 2, 3));
    EXPECT_TRUE(bfl::ranges::contains_none(lst, 16, 17));
    EXPECT_FALSE(bfl::ranges::contains_none(lst, 11, 12));
    EXPECT_FALSE(bfl::ranges::contains_none(lst, 13, 14));
}

// ---------------------------------------------------------------------------------------------------------------------
TEST(ContainsNoneTest, MixedValues)
{
    std::vector<std::string> vec = {"hello", "world", "test"};
    EXPECT_TRUE(bfl::ranges::contains_none(vec, "universe", "galaxy"));
    EXPECT_TRUE(bfl::ranges::contains_none(vec, "goodbye"));
    EXPECT_FALSE(bfl::ranges::contains_none(vec, "hello", "world"));
    EXPECT_FALSE(bfl::ranges::contains_none(vec, "test", "universe"));
}

