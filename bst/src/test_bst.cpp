#include <gtest/gtest.h>
#include "bst.h"

TEST(BST, TraceEmpty)
{
    TreeNode<int> *head = NULL;
    EXPECT_EQ("[]", trace<int>(head));
}

TEST(BST, TraceSimpleNode)
{
    TreeNode<int> *head = new TreeNode<int>(1);
    EXPECT_EQ("[1]", trace<int>(head));
    clear_rcr<int>(head);
}

TEST(BST, TraceRandom1)
{
    TreeNode<int> *head = new TreeNode<int>(1);
    head->left = new TreeNode<int>(11);
    head->left->right = new TreeNode<int>(112);
    EXPECT_EQ("[1,11,X,X,112,X,X]", trace<int>(head));
    clear_rcr<int>(head);
}

TEST(BST, TracePerfectTree)
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

TEST(BST, BuildRcrEmpty)
{
    EXPECT_EQ(NULL, build_list_rcr(NULL, 0));
}

TEST(BST, BuildRcrSingleEmpty)
{
    int arr[] = {0};
    EXPECT_EQ(NULL, build_list_rcr(arr, 1));
}

TEST(BST, BuildRcrSingle)
{
    int arr[] = {1};
    TreeNode<int> *head = build_list_rcr(arr, 1);
    ASSERT_TRUE(head != NULL);
    EXPECT_EQ(1, head->value);
    EXPECT_EQ(NULL, head->left);
    EXPECT_EQ(NULL, head->right);
    clear_rcr<int>(head);
}

TEST(BST, BuildWithEmptyRoot)
{
    int arr[] = {11,1,12, 0, 21,2,0};
    EXPECT_EQ(NULL, build_list_rcr(arr, 7));
}

TEST(BST, BuildListKindLeft)
{
    int arr[] = {1111,111,0, 11, 0,0,0,  1,  0,0,0, 0, 0,0,0};
    TreeNode<int> *head = build_list_rcr(arr, 15);
    ASSERT_TRUE(head != NULL);
    // here is the level taversal
    EXPECT_EQ("[1,11,X,111,X,X,X,1111,X,X,X,X,X,X,X]", trace<int>(head));
    clear_rcr<int>(head);
}

TEST(BST, BuildListKindRight)
{
    int arr[] = {0,0,0, 0, 0,0,0,  1,  0,0,0, 12, 0,122,1222};
    TreeNode<int> *head = build_list_rcr(arr, 15);
    ASSERT_TRUE(head != NULL);
    // here is the level taversal
    EXPECT_EQ("[1,X,12,X,X,X,122,X,X,X,X,X,X,X,1222]", trace<int>(head));
    clear_rcr<int>(head);
}

TEST(BST, LevelTraverseEmpty)
{
    EXPECT_EQ("", levelTraverse<int>(NULL));
}

TEST(BST, LevelTraverseSingleItem)
{
    TreeNode<int> *head = new TreeNode<int>(1);
    EXPECT_EQ("1", levelTraverse<int>(head));
    clear_itr<int>(head);
}

TEST(BST, LevelTraversePerfect)
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


TEST(BST, DepthTraverseEmpty)
{
    EXPECT_EQ("", depthTraverse<int>(NULL));
}

TEST(BST, DepthTraverseSingle)
{
    TreeNode<int> *head = new TreeNode<int>(1);
    EXPECT_EQ("1", depthTraverse<int>(head));
    clear_rcr<int>(head);
}

TEST(BST, DepthTraversePerfect)
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

TEST(BST, PreOrderTraverseEmpty)
{
    TreeNode<int> *head = new TreeNode<int>(1);
    EXPECT_EQ("1", pre_order_traverse<int>(head));
    clear_rcr<int>(head);
}

TEST(BST, PreOrderTraverseSingle)
{
    TreeNode<int> *head = new TreeNode<int>(1);
    EXPECT_EQ("1", pre_order_traverse<int>(head));
    clear_rcr<int>(head);
}

TEST(BST, PreOrderTraversePerfect)
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

TEST(BST, InOrderTraverseEmpty)
{
    EXPECT_EQ("", in_order_traverse<int>(NULL));
}

TEST(BST, InOrderTraverseSingle)
{
    TreeNode<int> *head = new TreeNode<int>(1);
    EXPECT_EQ("1", in_order_traverse<int>(head));
    clear_rcr<int>(head);
}

TEST(BST, InOrderTraversePerfect)
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

TEST(BST, DISABLED_PostOrderTraverseEmpty)
{
    EXPECT_EQ("", post_order_traverse_1<int>(NULL));
}

TEST(BST, DISABLED_PostOrderTraverseSingle)
{
    TreeNode<int> *head = new TreeNode<int>(1);
    EXPECT_EQ("1", post_order_traverse_1<int>(head));
    clear_rcr<int>(head);
}


TEST(BST, DISABLED_PostOrderTraverseRandom)
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

TEST(BST, DISABLED_PostOrderTraversePerfect)
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

TEST(BST, PostOrderTraverse2Empty)
{
    EXPECT_EQ("", post_order_traverse_2<int>(NULL));
}

TEST(BST, PostOrderTraverse2Single)
{
    TreeNode<int> *head = new TreeNode<int>(1);
    EXPECT_EQ("1", post_order_traverse_2<int>(head));
    clear_rcr<int>(head);
}


TEST(BST, PostOrderTraverse2Random)
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

TEST(BST, PostOrderTraverse2Perfect)
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