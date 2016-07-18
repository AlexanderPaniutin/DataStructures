#include <gtest/gtest.h>
#include "simple_list.h"

TEST(SimpleList, Trace)
{
    ListNode<int> *myList = NULL;
    EXPECT_EQ("[]", trace<int>(myList));

    myList = new ListNode<int>(1);
    EXPECT_EQ("[1]", trace<int>(myList));

    myList->next = new ListNode<int>(2);
    EXPECT_EQ("[1,2]", trace<int>(myList));

    myList->next->next = new ListNode<int>(3);
    EXPECT_EQ("[1,2,3]", trace<int>(myList));

    delete myList->next->next;
    delete myList->next;
    delete myList;
}

TEST(SimpleList, Empty)
{
    ListNode<int> *myList = NULL;
    EXPECT_TRUE(empty(myList));

    myList = new ListNode<int>(1);
    EXPECT_FALSE(empty(myList));
    delete myList;
}

TEST(SimpleList, Size)
{
    ListNode<int> *myList = NULL;
    EXPECT_EQ(0, size(myList));

    myList = new ListNode<int>(1);
    EXPECT_EQ(1, size(myList));
    delete myList;
}

TEST(SimpleList, PushBack)
{
    ListNode<int> *myList = NULL;
    myList = push_back<int>(myList, 0);
    ASSERT_TRUE(myList != NULL);
    EXPECT_EQ(0, myList->value);
    EXPECT_EQ(NULL, myList->next);
    EXPECT_EQ("[0]", trace<int>(myList));

    myList = push_back<int>(myList, 1);
    EXPECT_EQ(0, myList->value);
    ASSERT_TRUE(myList->next != NULL);
    EXPECT_EQ(1, myList->next->value);
    EXPECT_EQ(NULL, myList->next->next);
    EXPECT_EQ("[0,1]", trace<int>(myList));


    delete myList->next;
    delete myList;
}

TEST(SimpleList, Back)
{
    ListNode<int> *myList = NULL;
    EXPECT_EQ(0, back<int>(myList));

    myList = new ListNode<int>(10);
    EXPECT_EQ(10, back<int>(myList));
    
    myList->next = new ListNode<int>(20);
    EXPECT_EQ(20, back<int>(myList));

    delete myList->next;
    delete myList;
}

TEST(SimpleList, PopBack)
{
    ListNode<int> *myList = NULL;
    EXPECT_EQ(NULL, pop_back<int>(myList));

    myList = new ListNode<int>(1);
    myList = pop_back<int>(myList);
    EXPECT_EQ(NULL, myList);
    EXPECT_EQ("[]", trace<int>(myList));


    myList = new ListNode<int>(2);
    myList->next = new ListNode<int>(3);
    ListNode<int> *newHead = pop_back<int>(myList);
    EXPECT_EQ(myList, newHead);
    EXPECT_EQ(NULL, myList->next);
    EXPECT_EQ("[2]", trace<int>(newHead));

    newHead = pop_back<int>(myList);
    EXPECT_EQ(NULL, newHead);
    EXPECT_EQ("[]", trace<int>(newHead));
}

TEST(SimpleList, PushFront)
{
    ListNode<int> *myList = NULL;

    myList = push_front<int>(myList, 1);
    ASSERT_TRUE(myList != NULL);
    EXPECT_EQ(1, myList->value);
    EXPECT_EQ(NULL, myList->next);
    EXPECT_EQ("[1]", trace<int>(myList));

    myList = push_front<int>(myList, 2);
    ASSERT_TRUE(myList != NULL);
    EXPECT_EQ(2, myList->value);
    ASSERT_TRUE(myList->next != NULL);
    EXPECT_EQ(1, myList->next->value);
    EXPECT_EQ(NULL, myList->next->next);
    EXPECT_EQ("[2,1]", trace<int>(myList));

    delete myList->next;
    delete myList;
}

TEST(SimpleList, Front)
{
    ListNode<int> *myList = NULL;
    EXPECT_EQ(0, front<int>(myList));

    myList = new ListNode<int>(1);
    EXPECT_EQ(1, front<int>(myList));

    myList->next = new ListNode<int>(2);
    EXPECT_EQ(1, front<int>(myList));

    delete myList->next;
    delete myList;
}

TEST(SimpleList, PopFront)
{
    ListNode<int> *myList = NULL;
    EXPECT_EQ(NULL, pop_front<int>(myList));

    myList = new ListNode<int>(1);
    ListNode<int> *newHead = pop_front<int>(myList);
    EXPECT_EQ(NULL, newHead);
    EXPECT_EQ("[]", trace<int>(newHead));


    myList = new ListNode<int>(1);
    myList->next = new ListNode<int>(2);
    newHead = pop_front<int>(myList);
    ASSERT_TRUE(newHead != NULL);
    EXPECT_EQ(2, newHead->value);
    EXPECT_EQ(NULL, newHead->next);
    EXPECT_EQ("[2]", trace<int>(newHead));
    delete newHead;

    myList = new ListNode<int>(1);
    myList->next = new ListNode<int>(2);
    myList->next->next = new ListNode<int>(3);
    newHead = pop_front<int>(myList);
    ASSERT_TRUE(newHead != NULL);
    EXPECT_EQ(2, newHead->value);
    ASSERT_TRUE(newHead->next != NULL);
    EXPECT_EQ(3, newHead->next->value);
    EXPECT_EQ(NULL, newHead->next->next);
    EXPECT_EQ("[2,3]", trace<int>(newHead));
    delete newHead->next;
    delete newHead;
}

// TODO: separate tests
TEST(SimpleList, Reverse)
{
    ListNode<int> *myList = NULL;
    ListNode<int> *newHead = reverse<int>(myList);
    EXPECT_EQ(NULL, newHead);

    myList = new ListNode<int>(1);
    newHead = reverse<int>(myList);
    ASSERT_TRUE(newHead != NULL);
    EXPECT_EQ(1, newHead->value);
    EXPECT_EQ(NULL, newHead->next);
    delete newHead;

    myList = new ListNode<int>(134);
    myList->next = new ListNode<int>(43);
    myList->next->next = new ListNode<int>(54);
    newHead = reverse<int>(myList);
    ASSERT_TRUE(newHead != NULL);
    EXPECT_EQ(54, newHead->value);
    ASSERT_TRUE(newHead->next != NULL);
    EXPECT_EQ(43, newHead->next->value);
    ASSERT_TRUE(newHead->next->next !=NULL);
    EXPECT_EQ(134, newHead->next->next->value);
    EXPECT_EQ(NULL, newHead->next->next->next);
    EXPECT_EQ("[54,43,134]", trace<int>(newHead));
    delete newHead->next->next;
    delete newHead->next;
    delete newHead;
}

TEST(SimpleList, DISABLED_FindKthFirst)
{
}

TEST(SimpleList, DISABLED_FindKthLast)
{
}

TEST(SimpleList, DISABLED_FindMax)
{
}

TEST(SimpleList, DISABLED_FindMin)
{
}
