#ifndef SIMPLE_LIST_H_
#error Please inlcude .h instead of .tcc
#endif

#include <sstream>

template <class T>
std::string trace(ListNode<T> *head)
{
    std::stringstream strm;
    bool isFirst = true;
    ListNode<T> *runner = head;

    strm << '[';
    while (runner != NULL)
    {
        if (isFirst)
            isFirst = false;
        else
            strm << ',';
        
        strm << runner->value;
        runner = runner->next;
    }
    strm << ']';
    
    return strm.str();
}

template <class T>
bool empty(ListNode<T> *head)
{
    return (head == NULL);
}

template <class T>
unsigned int size(ListNode<T> *head)
{
    ListNode<T> *runner = head;
    unsigned int count = 0;
    while (runner != NULL)
    {
        ++count;
        runner = runner->next;
    }

    return count;
}

template <class T>
ListNode<T>* push_back(ListNode<T> *head, const T &value)
{
    if (head == NULL)
        return new ListNode<T>(value);

    // go until you find last item
    ListNode<T> *runner = head;
    while (runner->next != NULL)
        runner = runner->next;

    // attach a new item to the end
    runner->next = new ListNode<T>(value); 
    
    return head;
}

template <class T>
T back(ListNode<T> *head)
{
    if (head == NULL)
        return T();

    ListNode<T> *runner = head;
    while (runner->next != NULL)
        runner = runner->next;

    return runner->value;
}

template <class T>
ListNode<T>* pop_back(ListNode<T> *head)
{
    if (head == NULL)
        return NULL;

    // if 1 item only
    if (head->next == NULL)
    {
        delete head;
        return NULL;
    }

    // get the last item
    // in this case (*runner) will be same as prev->next
    ListNode<T> **runner = &head;
    while ((*runner)->next != NULL)
        runner = &((*runner)->next);

    delete (*runner);
    (*runner) = NULL;

    return head;
}

template <class T>
ListNode<T>* push_front(ListNode<T> *head, const T &value)
{
    ListNode<T> *newHead = new ListNode<T>(value, head);
    return newHead;
}

template <class T>
T front(ListNode<T> *head)
{
    if (head == NULL)
    	return T();

    return head->value;
}

template <class T>
ListNode<T>* pop_front(ListNode<T> *head)
{
    if (head == NULL)
        return NULL;

    ListNode<int> *newHead = head->next;
    delete head;

    return newHead;
}

template <class T>
ListNode<T>* reverse(ListNode<T>* head)
{
    ListNode<T> *newHead = NULL;
    while (head != NULL)
    {
        // remove item from old list
        ListNode<T> *item = head;
        head = head->next;

        // attach item to the beginning of a new list
        item->next = newHead;
        newHead = item;
    }

    return newHead;
}

template <class T>
T findKthFirst(ListNode<T> *head, int k)
{
    return T();
}

template <class T>
T findKthLast(ListNode<T>* head)
{
    return T();
}

template <class T>
T findMax(ListNode<T> *head)
{
    return T();
}

template <class T>
T findMin(ListNode<T> *head)
{
    return T();
}
