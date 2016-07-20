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
ListNode<T> *build_list(T arr[], unsigned int size)
{
    ListNode<T> *head = NULL;
    ListNode<T> *tail = NULL;
    for (int ndx=0; ndx<size; ++ndx)
    {
        ListNode<T> *item = new ListNode<T>(arr[ndx]);

        if (head == NULL)
        {
            head = item;
            tail = item;
        }
        else
        {
            tail->next = item;
            tail = item;
        }
    }

    return head;
}

template <class T>
void clear(ListNode<T> *head)
{
    while (head != NULL)
    {
        ListNode<T> *item = head;
        head = head->next;
        delete item;
    }
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
ListNode<T>* find_middle(ListNode<T> *head)
{
    ListNode<T> *pRunner = head;
    ListNode<T> *pHalfRunner = head;
    bool isEven = true; // to control slow moving
    while (pRunner != NULL)
    {
        if (!isEven)
            pHalfRunner = pHalfRunner->next;

        pRunner = pRunner->next;
        isEven = !isEven;
    }

    return pHalfRunner;
}

template <class T>
T find_kth_first(ListNode<T> *head, unsigned int k)
{

    if (head == NULL)
        return T();

    unsigned int ndxCurr = 0;
    ListNode<T> *runner = head;

    while (runner != NULL)
    {
        if (ndxCurr == k)
            break;

        runner = runner->next;
        // increment ndx only if next item is available
        if (runner != NULL)
            ++ndxCurr;
    }

    if (ndxCurr == k)
        return runner->value;
    else
        return T();
}

template <class T>
T find_kth_last(ListNode<T>* head, unsigned int k)
{
    if (head == NULL)
        return T();

    unsigned int ndxCurr = k;
    ListNode<T> *runCurr = head;
    ListNode<T> *runKth = head;

    while (runCurr->next != NULL)
    {
        // delay runKth so it points to Kth item
        if (ndxCurr > 0)
        {
            --ndxCurr;
        }
        else
        {
            runKth = runKth->next;
        }

        runCurr = runCurr->next;
    }

    if (ndxCurr == 0)
        return runKth->value;
    else
        return T();

}

template <class T>
T find_max(ListNode<T> *head)
{
    ListNode<int> *maxNode = head;
    ListNode<int> *runner = head;

    while (runner != NULL)
    {
        if (maxNode->value < runner->value)
            maxNode = runner;

        runner = runner->next;
    }

    if (maxNode != NULL)
        return maxNode->value;
    else
        return T();
}

template <class T>
T find_min(ListNode<T> *head)
{
    ListNode<int> *minNode = head;
    ListNode<int> *runner = head;

    while (runner != NULL)
    {
        if (minNode->value > runner->value)
            minNode = runner;

        runner = runner->next;
    }

    if (minNode != NULL)
        return minNode->value;
    else
        return T();
}

template <class T>
ListNode<T>* erase(ListNode<T> *head, unsigned int pos)
{
    if (head == NULL)
        return NULL;

    unsigned int currPos = 0;
    ListNode<T> **pRunner = &(head);
    while ( (*pRunner) != NULL)
    {
        if (currPos == pos)
        {
            ListNode<T> *item = (*pRunner);
            (*pRunner) = (*pRunner)->next;
            delete item;

            if (pos == 0)
                head = (*pRunner);

            break;
        }

        ++currPos;
        pRunner = &((*pRunner)->next);
    }

    return head;
}

template <class T>
bool is_palindrome(ListNode<T> *head)
{
    if (head == NULL)
        return false;

    if (head->next == NULL)
        return true;

    ListNode<T> *midItem = find_middle<T>(head);
    ListNode<T> *pRevRunner = reverse<T>(midItem);
    ListNode<T> *pFwdRunner = head;

    bool isPalindrome = true;
    while (pFwdRunner != NULL && pRevRunner != NULL)
    {
        if (pFwdRunner->value != pRevRunner->value)
        {
            isPalindrome = false;
            break;
        }
        pFwdRunner = pFwdRunner->next;
        pRevRunner = pRevRunner->next;
    }

    return isPalindrome;
}

template <class T>
ListNode<T> *merge(ListNode<T> *head1, ListNode<T> *head2)
{
    // check if any empty
    if (head1 == NULL)
        return head2;

    if (head2 == NULL)
        return head1;

    ListNode<T> *pRunner1 = head1;
    ListNode<T> *pRunner2 = head2;

    ListNode<T> *newHead = NULL;
    ListNode<T> *newTail = NULL;

    while (pRunner1 != NULL && pRunner2 != NULL)
    {
        ListNode<T> *newItem = NULL;
        if (pRunner1->value < pRunner2->value)
        {
            newItem = pRunner1;
            pRunner1 = pRunner1->next;
        }
        else
        {
            newItem = pRunner2;
            pRunner2 = pRunner2->next;
        }
        newItem->next = NULL;

        if (newHead == NULL)
        {
            newHead = newItem;
            newTail = newItem;
        }
        else
        {
            newTail->next = newItem;
            newTail = newItem;
        }
    }

    // check for tails
    if (pRunner1 != NULL)
    {
        newTail->next = pRunner1;
    }

    if (pRunner2 != NULL)
    {
        newTail->next = pRunner2;
    }

    return newHead;
}

template <class T>
ListNode<T> *find_intersection(ListNode<T> *head1, ListNode<T> *head2)
{
    unsigned int size1 = size<T>(head1);
    unsigned int size2 = size<T>(head2);

    ListNode<int> *pRunner1 = head1;
    ListNode<int> *pRunner2 = head2;

    // align size
    while (size1 > size2)
    {
        pRunner1 = pRunner1->next;
        --size1;
    }

    while (size2 > size1)
    {
        pRunner2 = pRunner2->next;
        --size2;
    }

    // compare nodes
    ListNode<int> *intrNode = NULL;
    while (pRunner1 != NULL)
    {
        if (pRunner1 == pRunner2)
        {
            intrNode = pRunner1;
            break;
        }

        pRunner1 = pRunner1->next;
        pRunner2 = pRunner2->next;
    }

    return intrNode;
}

template <class T>
ListNode<T> *merge_odd_even(ListNode<T> *head1, ListNode<T> *head2)
{
    // TODO
}

template <class T>
ListNode<T>* find_cycle_head(ListNode<T> *head)
{
    // TODO
}
