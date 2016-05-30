/*
 * GTests for: BinaryIndexTree
 *     Author: Alex Paniutin
 *    Created: May 30, 2016
 *
 */

#include <gtest/gtest.h>
#include "BinaryIndexTree.h"
#include <iostream>

using namespace std;

TEST(BinaryIndexTree, Empty)
{
    BinaryIndexTree bit;
    cout << "printing of an empty binary index tree: ";
    bit.print();

    //EXPECT_EQ(0, paths.size());
}
