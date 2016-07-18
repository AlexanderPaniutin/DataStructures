#ifndef ALEXP_LIST_H
#error Please include .h instead of .tcc
#endif

/*
 this is the implementation of a template class list
 */
namespace alexp
{
    template <class T>
    list<T>::list()
    {
        nodes_count = 0;
        head = nullptr;
        tail = nullptr;
    }

    template <class T>
    list<T>::~list()
    {
        // remove all the items here or call erase/clear
    }
    template <class T>
    bool list<T>::empty() const
    {
        // should we rely here on node_count?
        // no. node_count is just to simplify size function
        return (head == nullptr);
    }

    template <class T>
    unsigned int list<T>::size() const
    {
        return nodes_count;
    }

    template <class T>
    T& list<T>::front()
    {
        assert(head != nullptr);

        return head->value;
    }

    template <class T>
    const T& list<T>::front() const
    {
        assert(head != nullptr);

        return head->value;
    }

    template <class T>
    T& list<T>::back()
    {
        assert(tail != nullptr);

        return tail->value;
    }

    template <class T>
    const T& list<T>::back() const
    {
        assert(tail != nullptr);

        return tail->value;
    }

    template <class T>
    void list<T>::push_front(const T& value)
    {
        list_node<T> *new_node = new list_node<T>(value, head);

        // update tail only if it was empty
        if (head == nullptr)
        {
            tail = new_node;
        }

        // always update head
        head = new_node;

        ++nodes_count;
    }

    template <class T>
    void list<T>::pop_front()
    {
        if (head != nullptr)
        {
            list_node<T> *tmp = head;
            head = head->next;
            delete tmp;

            --nodes_count;
        }

        // if list became empty - update tail
        if (head == nullptr)
        {
            tail = nullptr;
        }
    }

    template <class T>
    void list<T>::push_back(const T& value)
    {
        list_node<T> *new_node = new list_node<T>(value, nullptr, tail);

        // update head only if it was empty
        if (tail == nullptr)
        {
            head = new_node;
        }

        // always update tail
        tail = new_node;

        ++nodes_count;
    }

    template <class T>
    void list<T>::pop_back()
    {
        if (tail != nullptr)
        {
            list_node<T> *tmp = tail;
            tail = tail->prev;
            delete tmp;

            --nodes_count;
        }

        // if list became empty - update head
        if (tail == nullptr)
        {
            head = nullptr;
        }
    }

//    template <class C>
//    list_node<C>::list_node<C>(const C &val, list_node<C> *next=nullptr, list_node<C> *prev=nullptr)
//    {
//        this->value = val;
//        this->next = next;
//        this->prev = prev;
//    }

}
