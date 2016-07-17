
#include <gtest/gtest.h>
#include "aslist.h"

TEST(AsList, Add)
{
    EXPECT_EQ(0,   add(0, 0));
    EXPECT_EQ(-1,  add(0, -1));
    EXPECT_EQ(-1,  add(-1, 0));
    EXPECT_EQ(100, add(50, 50));
}
