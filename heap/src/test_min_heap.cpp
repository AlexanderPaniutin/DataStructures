#include <gtest/gtest.h>
#include "min_heap.h"


// NOTE: These test might be tight to implementation
//
TEST(MinHeap, Add)
{
    MinHeap<int> heap;
    EXPECT_EQ("", heap.trace());
    EXPECT_EQ(true, heap.isValid());

    heap.add(10);
    EXPECT_EQ("3", heap.trace());
    EXPECT_EQ(true, heap.isValid());

    heap.add(5);
    EXPECT_EQ("5,10", heap.trace());
    EXPECT_EQ(true, heap.isValid());

    heap.add(3);
    EXPECT_EQ("3,10,5", heap.trace());
    EXPECT_EQ(true, heap.isValid());

    heap.add(1);
    EXPECT_EQ("1,3,5,10", heap.trace());
    EXPECT_EQ(true, heap.isValid());

    heap.add(2);
    EXPECT_EQ("1,2,5,10,3", heap.trace());
    EXPECT_EQ(true, heap.isValid());
}

TEST(MinHeap, Remove)
{
    MinHeap<int> heap;
    heap.add(10);
    heap.add(5);
    heap.add(3);
    heap.add(1);
    heap.add(2);

    EXPECT_EQ(1, heap.remove());
    EXPECT_EQ(2, heap.remove());
    EXPECT_EQ(3,  heap.remove());
    EXPECT_EQ(5,  heap.remove());
    EXPECT_EQ(10,  heap.remove());
}