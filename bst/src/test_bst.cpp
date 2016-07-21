#include <gtest/gtest.h>
#include "bst.h"

TEST(BinaryTree, TraceEmpty)
{
    TreeNode<int> *head = NULL;
    EXPECT_EQ("[]", trace<int>(head));
}

TEST(BinaryTree, TraceSimpleNode)
{
    TreeNode<int> *head = new TreeNode<int>(1);
    EXPECT_EQ("[1]", trace<int>(head));
    clear_rcr<int>(head);
}

TEST(BinaryTree, TraceRandom1)
{
    TreeNode<int> *head = new TreeNode<int>(1);
    head->left = new TreeNode<int>(11);
    head->left->right = new TreeNode<int>(112);
    EXPECT_EQ("[1,11,X,X,112,X,X]", trace<int>(head));
    clear_rcr<int>(head);
}

TEST(BinaryTree, TracePerfectTree)
{
    TreeNode<int> *head = new TreeNode<int>(1);
    head->left = new TreeNode<int>(11);
    head->right = new TreeNode<int>(12);
    head->left->left = new TreeNode<int>(111);
    head->left->right = new TreeNode<int>(112);
    head->right->left = new TreeNode<int>(121);
    head->right->right = new TreeNode<int>(122);
    EXPECT_EQ("[1,11,12,111,112,121,122]", trace<int>(head));
    clear_rcr<int>(head);
}

TEST(BinaryTree, BuildRcrEmpty)
{
    EXPECT_EQ(NULL, build_list_rcr(NULL, 0));
}

TEST(BinaryTree, BuildRcrSingleEmpty)
{
    int arr[] = {0};
    EXPECT_EQ(NULL, build_list_rcr(arr, 1));
}

TEST(BinaryTree, BuildRcrSingle)
{
    int arr[] = {1};
    TreeNode<int> *head = build_list_rcr(arr, 1);
    ASSERT_TRUE(head != NULL);
    EXPECT_EQ(1, head->value);
    EXPECT_EQ(NULL, head->left);
    EXPECT_EQ(NULL, head->right);
    clear_rcr<int>(head);
}

TEST(BinaryTree, BuildWithEmptyRoot)
{
    int arr[] = {11,1,12, 0, 21,2,0};
    EXPECT_EQ(NULL, build_list_rcr(arr, 7));
}

TEST(BinaryTree, BuildListKindLeft)
{
    int arr[] = {1111,111,0, 11, 0,0,0,  1,  0,0,0, 0, 0,0,0};
    TreeNode<int> *head = build_list_rcr(arr, 15);
    ASSERT_TRUE(head != NULL);
    // here is the level taversal
    EXPECT_EQ("[1,11,X,111,X,X,X,1111,X,X,X,X,X,X,X]", trace<int>(head));
    clear_rcr<int>(head);
}

TEST(BinaryTree, BuildListKindRight)
{
    int arr[] = {0,0,0, 0, 0,0,0,  1,  0,0,0, 12, 0,122,1222};
    TreeNode<int> *head = build_list_rcr(arr, 15);
    ASSERT_TRUE(head != NULL);
    // here is the level taversal
    EXPECT_EQ("[1,X,12,X,X,X,122,X,X,X,X,X,X,X,1222]", trace<int>(head));
    clear_rcr<int>(head);
}

TEST(BinaryTree, LevelTraverseEmpty)
{
    EXPECT_EQ("", levelTraverse<int>(NULL));
}

TEST(BinaryTree, LevelTraverseSingleItem)
{
    TreeNode<int> *head = new TreeNode<int>(1);
    EXPECT_EQ("1", levelTraverse<int>(head));
    clear_itr<int>(head);
}

TEST(BinaryTree, LevelTraverseRandom)
{
    // level                                         0
    // level                     1                                      1
    // level           2                  2                   2                  2
    // level      3        3         3        3          3        3         3        3
    int arr[] = { 0   ,0  ,0   , 11, 0,   112,1122,  1,  0,   0,  0,    0,  0,   0,  0};
    TreeNode<int> *head = build_list_rcr(arr, 15);
    EXPECT_EQ("1,11,112,1122", levelTraverse<int>(head));
    clear_rcr<int>(head);
}

TEST(BinaryTree, LevelTraversePerfect)
{
    // level                                         0
    // level                     1                                      1
    // level           2                  2                   2                  2
    // level      3        3         3        3          3        3         3        3
    int arr[] = { 1111,111,1112, 11, 1121,112,1122,  1,  1211,121,1212, 12, 1221,122,1222};
    TreeNode<int> *head = build_list_rcr(arr, 15);
    EXPECT_EQ("1,11,12,111,112,121,122,1111,1112,1121,1122,1211,1212,1221,1222", levelTraverse<int>(head));
    clear_rcr<int>(head);
}


TEST(BinaryTree, DepthTraverseEmpty)
{
    EXPECT_EQ("", depthTraverse<int>(NULL));
}

TEST(BinaryTree, DepthTraverseSingle)
{
    TreeNode<int> *head = new TreeNode<int>(1);
    EXPECT_EQ("1", depthTraverse<int>(head));
    clear_rcr<int>(head);
}

TEST(BinaryTree, DepthTraverseRandom)
{
    // level                                         0
    // level                     1                                      1
    // level           2                  2                   2                  2
    // level      3        3         3        3          3        3         3        3
    int arr[] = { 0   ,0  ,0   , 11, 0,   112,1122,  1,  0,   0,  0,    0,  0,   0,  0};
    TreeNode<int> *head = build_list_rcr(arr, 15);
    EXPECT_EQ("1,11,112,1122", depthTraverse<int>(head));
    clear_rcr<int>(head);
}

TEST(BinaryTree, DepthTraversePerfect)
{
    // level                                         0
    // level                     1                                      1
    // level           2                  2                   2                  2
    // level      3        3         3        3          3        3         3        3
    int arr[] = { 1111,111,1112, 11, 1121,112,1122,  1,  1211,121,1212, 12, 1221,122,1222};
    TreeNode<int> *head = build_list_rcr(arr, 15);
    EXPECT_EQ("1,11,111,1111,1112,112,1121,1122,12,121,1211,1212,122,1221,1222", depthTraverse<int>(head));
    clear_rcr<int>(head);
}

TEST(BinaryTree, PreOrderTraverseEmpty)
{
    EXPECT_EQ("", pre_order_traverse<int>(NULL));
}

TEST(BinaryTree, PreOrderTraverseSingle)
{
    TreeNode<int> *head = new TreeNode<int>(1);
    EXPECT_EQ("1", pre_order_traverse<int>(head));
    clear_rcr<int>(head);
}

TEST(BinaryTree, PreOrderTraverseRandom)
{
    // level                                         0
    // level                     1                                      1
    // level           2                  2                   2                  2
    // level      3        3         3        3          3        3         3        3
    int arr[] = { 0   ,0  ,0   , 11, 0,   112,1122,  1,  0,   0,  0,    0,  0,   0,  0};
    TreeNode<int> *head = build_list_rcr(arr, 15);
    EXPECT_EQ("1,11,112,1122", pre_order_traverse<int>(head));
    clear_rcr<int>(head);
}

TEST(BinaryTree, PreOrderTraversePerfect)
{
    // level                                         0
    // level                     1                                      1
    // level           2                  2                   2                  2
    // level      3        3         3        3          3        3         3        3
    int arr[] = { 1111,111,1112, 11, 1121,112,1122,  1,  1211,121,1212, 12, 1221,122,1222};
    TreeNode<int> *head = build_list_rcr(arr, 15);
    EXPECT_EQ("1,11,111,1111,1112,112,1121,1122,12,121,1211,1212,122,1221,1222", pre_order_traverse<int>(head));
    clear_rcr<int>(head);
}

TEST(BinaryTree, InOrderTraverseEmpty)
{
    EXPECT_EQ("", in_order_traverse<int>(NULL));
}

TEST(BinaryTree, InOrderTraverseSingle)
{
    TreeNode<int> *head = new TreeNode<int>(1);
    EXPECT_EQ("1", in_order_traverse<int>(head));
    clear_rcr<int>(head);
}

TEST(BinaryTree, InOrderTraverseRandom)
{
    // level                                         0
    // level                     1                                      1
    // level           2                  2                   2                  2
    // level      3        3         3        3          3        3         3        3
    int arr[] = { 0   ,0  ,0   , 11, 0,   112,1122,  1,  0,   0,  0,    0,  0,   0,  0};
    TreeNode<int> *head = build_list_rcr(arr, 15);
    EXPECT_EQ("11,112,1122,1", in_order_traverse<int>(head));
    clear_rcr<int>(head);
}

TEST(BinaryTree, InOrderTraversePerfect)
{
    // level                                         0
    // level                     1                                      1
    // level           2                  2                   2                  2
    // level      3        3         3        3          3        3         3        3
    int arr[] = { 1111,111,1112, 11, 1121,112,1122,  1,  1211,121,1212, 12, 1221,122,1222};
    TreeNode<int> *head = build_list_rcr(arr, 15);
    EXPECT_EQ("1111,111,1112,11,1121,112,1122,1,1211,121,1212,12,1221,122,1222", in_order_traverse<int>(head));
    clear_rcr<int>(head);
}

TEST(BinaryTree, PostOrderTraverseEmpty)
{
    EXPECT_EQ("", post_order_traverse_1<int>(NULL));
}

TEST(BinaryTree, DISABLED_PostOrderTraverse1Single)
{
    TreeNode<int> *head = new TreeNode<int>(1);
    EXPECT_EQ("1", post_order_traverse_1<int>(head));
    clear_rcr<int>(head);
}


TEST(BinaryTree, PostOrderTraverse1Random)
{
    // level                                         0
    // level                     1                                      1
    // level           2                  2                   2                  2
    // level      3        3         3        3          3        3         3        3
    int arr[] = { 0   ,0  ,0   , 11, 0,   112,1122,  1,  0,   0,  0,    0,  0,   0,  0};
    TreeNode<int> *head = build_list_rcr(arr, 15);
    EXPECT_EQ("1122,112,11,1", post_order_traverse_1<int>(head));
    clear_rcr<int>(head);
}

TEST(BinaryTree, PostOrderTraverse1Perfect)
{
    // level                                         0
    // level                     1                                      1
    // level           2                  2                   2                  2
    // level      3        3         3        3          3        3         3        3
    int arr[] = { 1111,111,1112, 11, 1121,112,1122,  1,  1211,121,1212, 12, 1221,122,1222};
    TreeNode<int> *head = build_list_rcr(arr, 15);
    EXPECT_EQ("1111,1112,111,1121,1122,112,11,1211,1212,121,1221,1222,122,12,1", post_order_traverse_1<int>(head));
    clear_rcr<int>(head);
}

TEST(BinaryTree, PostOrderTraverse2Empty)
{
    EXPECT_EQ("", post_order_traverse_2<int>(NULL));
}

TEST(BinaryTree, PostOrderTraverse2Single)
{
    TreeNode<int> *head = new TreeNode<int>(1);
    EXPECT_EQ("1", post_order_traverse_2<int>(head));
    clear_rcr<int>(head);
}


TEST(BinaryTree, PostOrderTraverse2Random)
{
    // level                                         0
    // level                     1                                      1
    // level           2                  2                   2                  2
    // level      3        3         3        3          3        3         3        3
    int arr[] = { 0   ,0  ,0   , 11, 0,   112,1122,  1,  0,   0,  0,    0,  0,   0,  0};
    TreeNode<int> *head = build_list_rcr(arr, 15);
    EXPECT_EQ("1122,112,11,1", post_order_traverse_2<int>(head));
    clear_rcr<int>(head);
}

TEST(BinaryTree, PostOrderTraverse2Perfect)
{
    // level                                         0
    // level                     1                                      1
    // level           2                  2                   2                  2
    // level      3        3         3        3          3        3         3        3
    int arr[] = { 1111,111,1112, 11, 1121,112,1122,  1,  1211,121,1212, 12, 1221,122,1222};
    TreeNode<int> *head = build_list_rcr(arr, 15);
    EXPECT_EQ("1111,1112,111,1121,1122,112,11,1211,1212,121,1221,1222,122,12,1", post_order_traverse_2<int>(head));
    clear_rcr<int>(head);
}

// My custom algorithm that uses self managed stack
TEST(BinaryTree, MyPreOrderTraverseEmpty)
{
    EXPECT_EQ("", my_pre_order_traverse<int>(NULL));
}

TEST(BinaryTree, MyPreOrderTraverseSingle)
{
    TreeNode<int> *head = new TreeNode<int>(1);
    EXPECT_EQ("1", my_pre_order_traverse<int>(head));
    clear_rcr<int>(head);
}

TEST(BinaryTree, MyPreOrderTraversePerfect)
{
    // level                                         0
    // level                     1                                      1
    // level           2                  2                   2                  2
    // level      3        3         3        3          3        3         3        3
    int arr[] = { 1111,111,1112, 11, 1121,112,1122,  1,  1211,121,1212, 12, 1221,122,1222};
    TreeNode<int> *head = build_list_rcr(arr, 15);
    EXPECT_EQ("1,11,111,1111,1112,112,1121,1122,12,121,1211,1212,122,1221,1222", my_pre_order_traverse<int>(head));
    clear_rcr<int>(head);
}

TEST(BinaryTree, MyInOrderTraverseEmpty)
{
EXPECT_EQ("", my_in_order_traverse<int>(NULL));
}

TEST(BinaryTree, MYInOrderTraverseSingle)
{
    TreeNode<int> *head = new TreeNode<int>(1);
    EXPECT_EQ("1", my_in_order_traverse<int>(head));
    clear_rcr<int>(head);
}

TEST(BinaryTree, MyInOrderTraversePerfect)
{
    // level                                         0
    // level                     1                                      1
    // level           2                  2                   2                  2
    // level      3        3         3        3          3        3         3        3
    int arr[] = { 1111,111,1112, 11, 1121,112,1122,  1,  1211,121,1212, 12, 1221,122,1222};
    TreeNode<int> *head = build_list_rcr(arr, 15);
    EXPECT_EQ("1111,111,1112,11,1121,112,1122,1,1211,121,1212,12,1221,122,1222", my_in_order_traverse<int>(head));
    clear_rcr<int>(head);
}

TEST(BinaryTree, MyPostOrderTraverse2Empty)
{
    EXPECT_EQ("", my_post_order_traverse<int>(NULL));
}

TEST(BinaryTree, MyPostOrderTraverse2Single)
{
    TreeNode<int> *head = new TreeNode<int>(1);
    EXPECT_EQ("1", my_post_order_traverse<int>(head));
    clear_rcr<int>(head);
}


TEST(BinaryTree, MyPostOrderTraverse2Random)
{
    // level                                         0
    // level                     1                                      1
    // level           2                  2                   2                  2
    // level      3        3         3        3          3        3         3        3
    int arr[] = { 0   ,0  ,0   , 11, 0,   112,1122,  1,  0,   0,  0,    0,  0,   0,  0};
    TreeNode<int> *head = build_list_rcr(arr, 15);
    EXPECT_EQ("1122,112,11,1", my_post_order_traverse<int>(head));
    clear_rcr<int>(head);
}

TEST(BinaryTree, MyPostOrderTraverse2Perfect)
{
    // level                                         0
    // level                     1                                      1
    // level           2                  2                   2                  2
    // level      3        3         3        3          3        3         3        3
    int arr[] = { 1111,111,1112, 11, 1121,112,1122,  1,  1211,121,1212, 12, 1221,122,1222};
    TreeNode<int> *head = build_list_rcr(arr, 15);
    EXPECT_EQ("1111,1112,111,1121,1122,112,11,1211,1212,121,1221,1222,122,12,1", my_post_order_traverse<int>(head));
    clear_rcr<int>(head);
}