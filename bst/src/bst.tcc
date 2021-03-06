#ifndef BST_H_
#error Please inlcude .h instead of .tcc
#endif

#include <list>
#include <sstream>
template <class T>
std::string trace(TreeNode<T> *head)
{
    std::stringstream strm;
    std::stringstream strmLine;
    strm << '[';
    bool isFirst = true;

    std::list<TreeNode<T> *> levelEven;
    levelEven.push_back(head);
    std::list<TreeNode<T> *> levelOdd;

    bool isEven = true;
    bool emptyLine = true;

    while (levelEven.empty() == false || levelOdd.empty() == false)
    {
        if (isEven)
        {
            TreeNode<T> *item = levelEven.front();
            levelEven.pop_front();
            if (item != NULL)
            {
                // this section repeats. can be moved to out function;
                if (isFirst)
                    isFirst = false;
                else
                    strmLine << ',';
                strmLine << item->value;

                emptyLine = false;
                levelOdd.push_back(item->left);
                levelOdd.push_back(item->right);
            }
            else
            {
                // this section repeats. can be moved to out function;
                if (isFirst)
                    isFirst = false;
                else
                    strmLine << ',';
                strmLine << 'X';

                // even if item is null - push nulls as childs
                levelOdd.push_back(NULL);
                levelOdd.push_back(NULL);
            }
        }
        else
        {
            TreeNode<T> *item = levelOdd.front();
            levelOdd.pop_front();
            if (item != NULL)
            {
                // this section repeats. can be moved to out function;
                if (isFirst)
                    isFirst = false;
                else
                    strmLine << ',';
                strmLine << item->value;

                emptyLine = false;
                levelEven.push_back(item->left);
                levelEven.push_back(item->right);
            }
            else
            {
                // this section repeats. can be moved to out function;
                if (isFirst)
                    isFirst = false;
                else
                    strmLine << ',';
                strmLine << 'X';

                levelEven.push_back(NULL);
                levelEven.push_back(NULL);
            }
        }

        // check if its the end of a level
        if (    (isEven && levelEven.empty())
             || (!isEven && levelOdd.empty()))
        {
            // if its end of the tree
            if (emptyLine)
                break;

            // dump line stream into main stream
            strm << strmLine.str();
            strmLine.str("");
            strmLine.clear();

            emptyLine = true;
            isEven = !isEven;
        }
    }

    strm << ']';

    return strm.str();
}

TreeNode<int>* build_list_rcr(int arr[], unsigned int size)
{
    // here we simply will go ove the ndxs and build level by level
    // take middle and make it head, device the array and build the subtree by passing the ndxs

    if (size == 0)
        return NULL;

    // verify the size. always expect the odd number
    if (size % 2 == 0)
        return NULL;

    return build_list_rcr_sub(arr, 0, size-1);
}

TreeNode<int>* build_list_rcr_sub(int arr[], unsigned int ndxStart, unsigned int ndxEnd)
{
    // if its a single element
    if (ndxStart == ndxEnd)
    {
        // if its not 0 (0 stands for NULL)
        if (arr[ndxStart] == 0)
            return NULL;

        return new TreeNode<int>(arr[ndxStart]);
    }
    else
    {
        unsigned int ndxMiddle = (ndxEnd - ndxStart)/2 + ndxStart;
        // we should get always odd numbers

        // check if root is not null
        if (arr[ndxMiddle] == 0)
            return NULL;

        TreeNode<int> *head = new TreeNode<int>(arr[ndxMiddle]);
        head->left = build_list_rcr_sub(arr, ndxStart, ndxMiddle-1);
        head->right = build_list_rcr_sub(arr, ndxMiddle+1, ndxEnd);
        return head;
    }
}

template <class T>
void clear_rcr(TreeNode<T> *head)
{
    if (head != NULL)
    {
        clear_rcr<T>(head->left);
        clear_rcr<T>(head->right);
        delete head;
    }
}

template <class T>
void clear_itr(TreeNode<T> *head)
{
    // pull all the items using BFS traversing
    std::list<TreeNode<T> *> itemsToDelete;

    // collect all the items into itemsToDelete
    std::list<TreeNode<T> *> itemsToVisit;
    if (head != NULL)
        itemsToVisit.push_back(head);

    while (itemsToVisit.empty() == false)
    {
        TreeNode<T> *item = itemsToVisit.front();
        itemsToVisit.pop_front();

        // item visiting...
        itemsToDelete.push_back(item);

        if (item->left != NULL)
            itemsToVisit.push_back(item->left);

        if (item->right != NULL)
            itemsToVisit.push_back(item->right);
    }

    // now delete all the collected items
    while (itemsToDelete.empty() == false)
    {
        TreeNode<T> *item = itemsToDelete.back();
        itemsToDelete.pop_back();
        delete item;
    }
}

template <class T>
std::string levelTraverse(TreeNode<T> *head)
{
    std::stringstream strm;
    bool isFirst = true;

    std::list<TreeNode<T> *> itemsToVisit;
    if (head != NULL)
        itemsToVisit.push_back(head);

    while (itemsToVisit.empty() == false)
    {
        TreeNode<T> *item = itemsToVisit.front();
        itemsToVisit.pop_front();

        // visiting the item...
        if (isFirst)
            isFirst = false;
        else
            strm << ',';
        strm << item->value;

        if (item->left != NULL)
            itemsToVisit.push_back(item->left);

        if (item->right != NULL)
            itemsToVisit.push_back(item->right);
    }

    return strm.str();
}

template <class T>
std::string depthTraverse(TreeNode<T> *head)
{
    std::stringstream strm;
    bool isFirst = true;

    std::list<TreeNode<T> *> itemsToVisit;
    if (head != NULL)
        itemsToVisit.push_back(head);

    while (itemsToVisit.empty() == false)
    {
        TreeNode<T> *item = itemsToVisit.back();
        itemsToVisit.pop_back();

        // visiting the item...
        if (isFirst)
            isFirst = false;
        else
            strm << ',';
        strm << item->value;

        // since we are using stack, push right node first so left node will be on the top
        if (item->right != NULL)
            itemsToVisit.push_back(item->right);

        if (item->left != NULL)
            itemsToVisit.push_back(item->left);
    }

    return strm.str();
}

template <class T>
std::string pre_order_traverse(TreeNode<T> *head)
{
    std::stringstream strm;
    bool isFirst = true;
    // Preorder traversal looks exactly like DFS style traversing
    std::list<TreeNode<T> *> itemsToVisit;

    if (head != NULL)
        itemsToVisit.push_back(head);

    while (itemsToVisit.empty() == false)
    {
        TreeNode<T> *item = itemsToVisit.back();
        itemsToVisit.pop_back();

        if (isFirst)
            isFirst = false;
        else
            strm << ',';
        strm << item->value;

        // push right item first so left node is getting visited first
        if (item->right != NULL)
            itemsToVisit.push_back(item->right);

        if (item->left != NULL)
            itemsToVisit.push_back(item->left);
    }

    return strm.str();
}

template <class T>
std::string in_order_traverse(TreeNode<T> *head)
{
    std::stringstream strm;
    bool isFirst = true;

    std::list<TreeNode<T> *> itemsToVisit;
    TreeNode<T> *item = head;

    while (item != NULL || itemsToVisit.empty() == false)
    {
        if (item != NULL)
        {
            itemsToVisit.push_back(item);
            item = item->left;
        }
        else
        {
            item = itemsToVisit.back();
            itemsToVisit.pop_back();

            // item visiting
            if (isFirst)
                isFirst = false;
            else
                strm <<  ',';
            strm << item->value;

            item = item->right;
        }
    }

    return strm.str();
}

template <class T>
std::string post_order_traverse_1(TreeNode<T> *head)
{
    std::stringstream strm;
    bool isFirst = true;

    TreeNode<T> *item = head;
    std::list<TreeNode<T> *> itemsToVisit;
    TreeNode<T> *lastVisited = NULL;

    while (item != NULL || itemsToVisit.empty() == false)
    {
        if (item != NULL)
        {
            itemsToVisit.push_back(item);
            item = item->left;
        }
        else
        {
            item = itemsToVisit.back();

            if (item->right != NULL && lastVisited != item->right)
            {
                item = item->right;
            }
            else
            {
                //visit (item);
                if (isFirst)
                    isFirst = false;
                else
                    strm << ',';
                strm << item->value;

                lastVisited = item;
                item = NULL;
                itemsToVisit.pop_back();
            }
        }
    }

    return strm.str();
}

template <class T>
std::string post_order_traverse_2(TreeNode<T> *head)
{
    if (head == NULL)
        return "";

    std::stringstream strm;
    bool isFirst = true;

    TreeNode<T> *item = head;
    std::list<TreeNode<T> *> itemsToVisit;

    do
    {
        // go through to the most left node and remember right children
        while (item != NULL)
        {
            // push the right node first and then item itself
            if (item->right != NULL)
                itemsToVisit.push_back(item->right);
            itemsToVisit.push_back(item);

            item = item->left;
        }

        item = itemsToVisit.back();
        itemsToVisit.pop_back();

        // check if the right child is still in a stack (unprocessed)
        // in other words - postpone processing a root node.
        if (item->right && itemsToVisit.back() == item->right)
        {
            // swap item and right child
            itemsToVisit.pop_back();
            itemsToVisit.push_back(item);

            // process right item first
            item = item->right;
        }
        else
        {
            // item visiting...
            if (isFirst)
                isFirst = false;
            else
                strm << ',';
            strm << item->value;

            // set item as null so next will be picked from the stack
            item = NULL;
        }
    } while (itemsToVisit.empty() == false);

    return strm.str();
}

template <class T>
class MyBstStackFrame
{
 public:
    MyBstStackFrame(unsigned int point, TreeNode<T> *treeNode)
        : retPoint(point), node(treeNode) {};
    unsigned int retPoint;
    TreeNode<T> *node;
};

/*
 * Return stile traversing based on its own stack frames.
 * each time stack is involved in original recursive traversing, we need to use custom stack management
 * Stack has 1 local variable "node" and a return address/point where to continue
 */
template <class T>
std::string my_pre_order_traverse(TreeNode<T> *head)
{
    std::stringstream strm;
    bool isFirst = true;

    std::list<MyBstStackFrame<T> > myStack;

    if (head != NULL)
        myStack.push_back(MyBstStackFrame<T>(0, head));

    // retpoint is a place were we need to get back next iteration when current not is on the stack
    while (myStack.empty() == false)
    {
        MyBstStackFrame<T> &local = myStack.back();

        // Return Point 0. when entering a function - we have a new Call Stack
        if (local.retPoint == 0)
        {
            local.retPoint = 1;

            // item visiting...
            if (isFirst)
                isFirst = false;
            else
                strm << ',';
            strm << local.node->value;

            if (local.node->left != NULL)
            {
                // pretend like we are calling a function again.
                myStack.push_back(MyBstStackFrame<T>(0, local.node->left));
                continue;
            }
        }

        if (local.retPoint == 1)
        {
            local.retPoint = 2;
            if (local.node->right != NULL)
            {
                // pretend like we are calling a function again.
                myStack.push_back(MyBstStackFrame<T>(0, local.node->right));
                continue;
            }
        }

        if (local.retPoint == 2)
        {
            myStack.pop_back();
        }
    }

    return strm.str();
}

template <class T>
std::string my_in_order_traverse(TreeNode<T> *head)
{
    std::stringstream strm;
    bool isFirst = true;

    std::list<MyBstStackFrame<T> > myStack;

    if (head != NULL)
        myStack.push_back(MyBstStackFrame<T>(0, head));

    // retpoint is a place were we need to get back next iteration when current not is on the stack
    while (myStack.empty() == false)
    {
        MyBstStackFrame<T> &local = myStack.back();

        // Return Point 0. when entering a function - we have a new Call Stack
        if (local.retPoint == 0)
        {
            local.retPoint = 1;

            if (local.node->left != NULL)
            {
                // pretend like we are calling a function again.
                myStack.push_back(MyBstStackFrame<T>(0, local.node->left));
                continue;
            }
        }

        if (local.retPoint == 1)
        {
            local.retPoint = 2;

            // item visiting...
            if (isFirst)
                isFirst = false;
            else
                strm << ',';
            strm << local.node->value;

            if (local.node->right != NULL)
            {
                // pretend like we are calling a function again.
                myStack.push_back(MyBstStackFrame<T>(0, local.node->right));
                continue;
            }
        }

        if (local.retPoint == 2)
        {
            myStack.pop_back();
        }
    }

    return strm.str();
}

template <class T>
std::string my_post_order_traverse(TreeNode<T> *head)
{
    std::stringstream strm;
    bool isFirst = true;

    std::list<MyBstStackFrame<T> > myStack;

    if (head != NULL)
        myStack.push_back(MyBstStackFrame<T>(0, head));

    // retpoint is a place were we need to get back next iteration when current not is on the stack
    while (myStack.empty() == false)
    {
        MyBstStackFrame<T> &local = myStack.back();

        // Return Point 0. when entering a function - we have a new Call Stack
        if (local.retPoint == 0)
        {
            local.retPoint = 1;

            if (local.node->left != NULL)
            {
                // pretend like we are calling a function again.
                myStack.push_back(MyBstStackFrame<T>(0, local.node->left));
                continue;
            }
        }

        if (local.retPoint == 1)
        {
            local.retPoint = 2;

            if (local.node->right != NULL)
            {
                // pretend like we are calling a function again.
                myStack.push_back(MyBstStackFrame<T>(0, local.node->right));
                continue;
            }
        }

        if (local.retPoint == 2)
        {
            // item visiting...
            if (isFirst)
                isFirst = false;
            else
                strm << ',';
            strm << local.node->value;

            myStack.pop_back();
        }
    }

    return strm.str();
}

template <class T>
std::string serialize(TreeNode<T> *head)
{
    if (head == NULL)
        return "";

    std::stringstream strm;
    std::list<TreeNode<T> *> itemsToVisit;

    // process first item
    itemsToVisit.push_back(head);
    strm << head->value << ' ';

    while (itemsToVisit.empty() == false)
    {
        TreeNode<T> *item = itemsToVisit.front();
        itemsToVisit.pop_front();

        // serialize left item and if not NULL - push it to the queue
        if (item->left == NULL)
        {
            strm << "X ";
        }
        else
        {
            strm << item->left->value << ' ';
            itemsToVisit.push_back(item->left);
        }

        // same with right item
        if (item->right == NULL)
        {
            strm << "X ";
        }
        else
        {
            strm << item->right->value << ' ';
            itemsToVisit.push_back(item->right);
        }
    }

    return strm.str();
}

//template <class T>
TreeNode<int> *deserialize(const std::string &serialized)
{
    if (serialized.empty())
        return NULL;

    std::stringstream strm(serialized);
    std::list<TreeNode<int> *> itemsToVisit;

    // process a head
    TreeNode<int> *head = NULL;
    std::string str;
    strm >> str;

    if (str.empty() || str == "X")
    {
        return head;
    }
    else
    {
        head = new TreeNode<int>(std::stoi(str));
        itemsToVisit.push_back(head);
    }

    // process a queue
    while (itemsToVisit.empty() == false)
    {
        TreeNode<int> *item = itemsToVisit.front();
        itemsToVisit.pop_front();

        strm >> str;
        if (str != "X")
        {
            item->left = new TreeNode<int>(std::stoi(str));
            itemsToVisit.push_back(item->left);
        }

        strm >> str;
        if (str != "X")
        {
            item->right = new TreeNode<int>(std::stoi(str));
            itemsToVisit.push_back(item->right);
        }
    }

    return head;
}
