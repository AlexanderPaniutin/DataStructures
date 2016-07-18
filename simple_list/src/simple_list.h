#ifndef SIMPLE_LIST_H_
#define SIMPLE_LIST_H_

#include <string>

template <class T>
class ListNode
{
  public:
    ListNode<T>()
        : next(NULL) {}
    ListNode<T>(const T &val, ListNode<T> *nextItem = NULL)
        : value(val), next(nextItem) {}
    T value;
    ListNode *next;
};

// builds a string as a printed elements like "[item1,item2,...,itemN]"
template <class T>
std::string trace(ListNode<T> *head); 

// checks if list is not empty
template <class T>
bool empty(ListNode<T> *head);

// Returns amount of elements in a list
template <class T>
unsigned int size(ListNode<T> *head);

// Adds item to the end of the list. Returns new head
template <class T>
ListNode<T>* push_back(ListNode<T> *head, const T &value);

// Returns a value of the last item. Returns default value if empty
template <class T>
T back(ListNode<T> *head);

// Removes an item from the end of the list. Returns new head
template <class T>
ListNode<T>* pop_back(ListNode<T> *head);

// Adds item to the fron of the list. Returns new head
template <class T>
ListNode<T>* push_front(ListNode<T> *head, const T &value);

// Returns a value of the first item. Returns default value if empty
template <class T>
T front(ListNode<T> *head);

// Removes an itrm from the beginning of the list. Returns new head
template <class T>
ListNode<T>* pop_front(ListNode<T> *head);

// Reverses items. Returns new head
template <class T>
ListNode<T>* reverse(ListNode<T>* head);

// Returns K-th item from the beginning. Returns default value if not available
template <class T>
T findKthFirst(ListNode<T> *head, unsigned int k);

// Returns K-th item from the end. Returns default value if not available
template <class T>
T findKthLast(ListNode<T>* head, unsigned int k);

// Returns a maximum item value. Returns default value if not available
template <class T>
T findMax(ListNode<T> *head);

// Returns a minimum item value. Returns default value if not available
template <class T>
T findMin(ListNode<T> *head);

#include "simple_list.tcc"

#endif // SIMPLE_LIST_H
