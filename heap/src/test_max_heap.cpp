#include <gtest/gtest.h>
#include "max_heap.h"


// NOTE: These test might be tight to implementation
//
TEST(MaxHeap, Add)
{
    MaxHeap<int> heap;
    EXPECT_EQ("", heap.trace());
    EXPECT_EQ(true, heap.isValid());

    heap.add(3);
    EXPECT_EQ("3", heap.trace());
    EXPECT_EQ(true, heap.isValid());

    heap.add(5);
    EXPECT_EQ("5,3", heap.trace());
    EXPECT_EQ(true, heap.isValid());

    heap.add(10);
    EXPECT_EQ("10,3,5", heap.trace());
    EXPECT_EQ(true, heap.isValid());

    heap.add(1);
    EXPECT_EQ("10,3,5,1", heap.trace());
    EXPECT_EQ(true, heap.isValid());

    heap.add(15);
    EXPECT_EQ("15,10,5,1,3", heap.trace());
    EXPECT_EQ(true, heap.isValid());
}

TEST(MaxHeap, Remove)
{
    MaxHeap<int> heap;
    heap.add(3);
    heap.add(5);
    heap.add(10);
    heap.add(1);
    heap.add(15);

    EXPECT_EQ(15, heap.remove());
    EXPECT_EQ(10, heap.remove());
    EXPECT_EQ(5,  heap.remove());
    EXPECT_EQ(3,  heap.remove());
    EXPECT_EQ(1,  heap.remove());
}