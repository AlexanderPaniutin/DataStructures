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

TEST(SimpleList, BuildList)
{
    EXPECT_EQ(NULL, build_list<int>(NULL, 0));

    int arr1[] = {1};
    ListNode<int> *head = build_list<int>(arr1, 1);
    ASSERT_TRUE(head != NULL);
    EXPECT_EQ(1, head->value);
    EXPECT_EQ(NULL, head->next);
    delete head;

    int arr2[] = {1, 2};
    head = build_list<int>(arr2, 2);
    ASSERT_TRUE(head != NULL);
    EXPECT_EQ(1, head->value);
    ASSERT_TRUE(head->next != NULL);
    EXPECT_EQ(2, head->next->value);
    EXPECT_EQ(NULL, head->next->next);
    delete head->next;
    delete head;

    int arr3[] = {31, 54, 32, 1, 934, 332, 0, 0, -1, 2};
    head = build_list<int>(arr3, 10);
    EXPECT_EQ("[31,54,32,1,934,332,0,0,-1,2]", trace<int>(head));
    clear<int>(head);
}

TEST(SimpleList, Clean)
{
    // you cant really test clear. every system might behave differently
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

TEST(SimpleList, FindKthFirst)
{
    ListNode<int> *myList = NULL;
    EXPECT_EQ(0, find_kth_first<int>(myList, 0));
    EXPECT_EQ(0, find_kth_first<int>(myList, 1));

    myList = new ListNode<int>(1);
    EXPECT_EQ(1, find_kth_first<int>(myList, 0));
    EXPECT_EQ(0, find_kth_first<int>(myList, 1));

    myList->next = new ListNode<int>(5);
    myList->next->next = new ListNode<int>(3);
    EXPECT_EQ(3, find_kth_first<int>(myList, 2));
    EXPECT_EQ(5, find_kth_first<int>(myList, 1));
    EXPECT_EQ(0, find_kth_first<int>(myList, 3));

    delete myList->next->next;
    delete myList->next;
    delete myList;
}

TEST(SimpleList, FindKthLast)
{
    ListNode<int> *myList = NULL;
    EXPECT_EQ(0, find_kth_last<int>(myList, 0));
    EXPECT_EQ(0, find_kth_last<int>(myList, 1));

    myList = new ListNode<int>(1);
    EXPECT_EQ(1, find_kth_last<int>(myList, 0));
    EXPECT_EQ(0, find_kth_last<int>(myList, 1));

    myList->next = new ListNode<int>(5);
    myList->next->next = new ListNode<int>(3);
    EXPECT_EQ(3, find_kth_last<int>(myList, 0));
    EXPECT_EQ(1, find_kth_last<int>(myList, 2));
    EXPECT_EQ(5, find_kth_last<int>(myList, 1));
    EXPECT_EQ(0, find_kth_last<int>(myList, 3));

    delete myList->next->next;
    delete myList->next;
    delete myList;
}

TEST(SimpleList, FindMax)
{
    ListNode<int> *myList = NULL;
    EXPECT_EQ(0, find_max<int>(myList));

    myList = new ListNode<int>(1);
    EXPECT_EQ(1, find_max<int>(myList));

    myList->next = new ListNode<int>(5);
    myList->next->next = new ListNode<int>(3);
    EXPECT_EQ(5, find_max<int>(myList));

    // make 8 5 3
    myList->value = 8;
    EXPECT_EQ(8, find_max<int>(myList));

    // make 8 5 9
    myList->next->next->value = 9;
    EXPECT_EQ(9, find_max<int>(myList));

    delete myList->next->next;
    delete myList->next;
    delete myList;
}

TEST(SimpleList, FindMin)
{
    ListNode<int> *myList = NULL;
    EXPECT_EQ(0, find_min<int>(myList));

    myList = new ListNode<int>(1);
    EXPECT_EQ(1, find_min<int>(myList));

    myList->next = new ListNode<int>(5);
    myList->next->next = new ListNode<int>(3);
    EXPECT_EQ(1, find_min<int>(myList));

    // make 8 5 3
    myList->value = 8;
    EXPECT_EQ(3, find_min<int>(myList));

    // make 8 5 9
    myList->next->next->value = 9;
    EXPECT_EQ(5, find_min<int>(myList));

    delete myList->next->next;
    delete myList->next;
    delete myList;
}

TEST(SimpleList, EraseEmpty)
{
    ListNode<int> *myList = NULL;
    EXPECT_EQ(NULL, erase<int>(myList, 0));
}

TEST(SimpleList, EraseSingleItem)
{
    ListNode<int> *myList = new ListNode<int>(1);
    ListNode<int> *newHead = erase<int>(myList, 1);
    ASSERT_TRUE(newHead != NULL);
    EXPECT_EQ(1, newHead->value);
    EXPECT_EQ(NULL, newHead->next);

    newHead = erase<int>(myList, 0);
    EXPECT_EQ(NULL, newHead);
}

TEST(SimpleList, EraseFirst)
{
    int arr1[] = {1, 2};
    ListNode<int> *myList = build_list(arr1, 2);
    ListNode<int> *newHead = erase<int>(myList, 0);
    ASSERT_TRUE(newHead != NULL);
    EXPECT_EQ(2, newHead->value);
    EXPECT_EQ(NULL, newHead->next);

    newHead = erase<int>(newHead, 0);
    EXPECT_EQ(NULL, newHead);

    int arr2[] = {1, 2, 3, 4, 5, 6, 7};
    myList = build_list(arr2, 7);
    newHead = erase<int>(myList, 0);
    EXPECT_EQ("[2,3,4,5,6,7]", trace<int>(newHead));
    clear<int>(newHead);
}

TEST(SimpleList, EraseLast)
{
    int arr1[] = {1, 2};
    ListNode<int> *myList = build_list(arr1, 2);
    ListNode<int> *newHead = erase<int>(myList, 1);
    ASSERT_TRUE(newHead != NULL);
    EXPECT_EQ(1, newHead->value);
    EXPECT_EQ(NULL, newHead->next);

    newHead = erase<int>(newHead, 0);
    EXPECT_EQ(NULL, newHead);

    int arr2[] = {1, 2, 3, 4, 5, 6, 7};
    myList = build_list(arr2, 7);
    newHead = erase<int>(myList, 6);
    EXPECT_EQ("[1,2,3,4,5,6]", trace<int>(newHead));
    clear<int>(newHead);
}

TEST(SimpleList, IsPalindrome)
{

}

TEST(SimpleList, Merge)
{

}

TEST(SimpleList, FindIntersection)
{

}

TEST(SimpleList, MergeOddEven)
{

}