#ifndef SIMPLE_LIST_H_
#define SIMPLE_LIST_H_

/**
 * NOTE: Just to make the functions name similar to STL, the underscore was taken as a
 *       word separator in names of functions. Internal implementation sticks to camelStyleNaming
 */
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

// Helper function
// Builds a string as a printed elements like "[item1,item2,...,itemN]"
template <class T>
std::string trace(ListNode<T> *head);

// Helper function
// Builds a linked list out of array of items.
template <class T>
ListNode<T>* build_list(T arr[], unsigned int size);

// Helper function
// Deletes all the items from the list
template <class T>
void clear(ListNode<T> *head);

// Checks if list is not empty
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

// Returns an item which points to the middle of the list
template <class T>
ListNode<T>* find_middle(ListNode<T> *head);

// Returns K-th item from the beginning. Returns default value if not available
template <class T>
T find_kth_first(ListNode<T> *head, unsigned int k);

// Returns K-th item from the end. Returns default value if not available
template <class T>
T find_kth_last(ListNode<T>* head, unsigned int k);

// Returns a maximum item value. Returns default value if not available
template <class T>
T find_max(ListNode<T> *head);

// Returns a minimum item value. Returns default value if not available
template <class T>
T find_min(ListNode<T> *head);

// Delete node at position pos. Has no effect if out of range
template <class T>
ListNode<T>* erase(ListNode<T> *head, unsigned int pos);

// Checks if given list is a palindrome kind
// NOTE: uses find_middle and reverse
template <class T>
bool is_palindrome(ListNode<T> *head);

// Merges 2 sorter lists into a single. Returns a new head
template <class T>
ListNode<T>* merge(ListNode<T> *head1, ListNode<T> *head2);

// Finds an element where 2 lists are intersected.
template <class T>
ListNode<T>* find_intersection(ListNode<T> *head1, ListNode<T> *head2);

// Builds an Odd-Even mix of 2 linked lists
template <class T>
ListNode<T>* merge_odd_even(ListNode<T> *head1, ListNode<T> *head2);

// Finds whether a list is cycled
template <class T>
ListNode<T>* is_cycled(ListNode<T> *head);

// Finds an element where cycle starts
template <class T>
ListNode<T>* find_cycle_head(ListNode<T> *head);

#include "simple_list.tcc"

#endif // SIMPLE_LIST_H
