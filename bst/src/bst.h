#ifndef BST_H_
#define BST_H_

/**
 * The common BST functions will be implemented here as a template to avoid
 * tighting to any data structure as BST is just a container.
 */

// just to allow easy tracing and building
#include <string>

template <class T>
class TreeNode
{
  public:
    TreeNode<T>()
        : left(NULL), right(NULL) {}
    TreeNode<T>(const T &val, TreeNode<T> *leftNode = NULL, TreeNode<T> *rightNode = NULL)
        : value(val), left(leftNode), right(rightNode) {}
    T value;
    TreeNode *left;
    TreeNode *right;
};

// Helper function
// Builds a string as a printed elements level by level (including nulls)like [root,left1,right1,left1.1,right1.2...]"
template <class T>
std::string trace(TreeNode<T> *head);

// Helper function
// Builds a Tree based on array of items. int only for now. -1 is taken as a null
// NOTE: arr has to contain items in in-order sequence. left_child, root, right_child
TreeNode<int>* build_list_rcr(int arr[], unsigned int size);
// This is a helper function for build_list_rcr.
TreeNode<int>* build_list_rcr_sub(int arr[], unsigned int ndxStart, unsigned int ndxEnd);

// Deletes all the items from the list. Uses recursive method
template <class T>
void clear_rcr(TreeNode<T> *head);

// Deletes all the items from the list. Uses iterative method
template <class T>
void clear_itr(TreeNode<T> *head);

// Traverse Binary Tree by level. Similar to BFS method
// returns in format like v0,v1,...,vn
template <class T>
std::string levelTraverse(TreeNode<T> *head);

// Traverse Binary Tree by depth, Similar to DFS method
// returns in format like v0,v1,...,vn
template <class T>
std::string depthTraverse(TreeNode<T> *head);

// Pre-order binary tree traversing
template <class T>
std::string pre_order_traverse(TreeNode<T> *head);

// In-order binary tree traversing
template <class T>
std::string in_order_traverse(TreeNode<T> *head);

// Post-order binary tree traversing
template <class T>
std::string post_order_traverse_1(TreeNode<T> *head);

template <class T>
std::string post_order_traverse_2(TreeNode<T> *head);

#include "bst.tcc"

#endif // SBT_H_
