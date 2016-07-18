
#include <gtest/gtest.h>
#include "list.h"
#include <string>

TEST(List, Empty)
{

    alexp::list<int> mylist;
    EXPECT_EQ(0, mylist.size());

    mylist.pop_back();
    EXPECT_EQ(0, mylist.size());

    mylist.pop_front();
    EXPECT_EQ(0, mylist.size());

}

TEST(List, Push)
{
    alexp::list<std::string> mylist;
    EXPECT_EQ(0, mylist.size());

    mylist.push_back("test1");
    EXPECT_EQ(1, mylist.size());
    EXPECT_EQ("test1", mylist.back());
    EXPECT_EQ("test1", mylist.front());

    mylist.push_back("test2");
    EXPECT_EQ(2, mylist.size());
    EXPECT_EQ("test2", mylist.back());
    EXPECT_EQ("test1", mylist.front());
}