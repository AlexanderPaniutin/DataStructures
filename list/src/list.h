#ifndef ALEXP_LIST_H
#define ALEXP_LIST_H

/**
 * aslist is a class that provides a similar functionality as std::list
 * but with certain limitations. Created for knowledge review only
 */

namespace alexp
{
    template <class T>
    class list
    {
     public:
        /* Member functions */
        list();
        ~list();
        //list<T> & operator = (const list<T> &);

        /* Iterators */
        //begin
        //end
        //rbegin
        //rend

        /* Capacity */
        bool empty() const;
        unsigned int size() const;
        //unsigned int max_size() const;

        /* Element access */
        T& front();
        const T& front() const;
        T& back();
        const T& back() const;

        /* Modifiers */
        //assign
        //emplace_front
        void push_front(const T& value);
        void pop_front();
        //emplace_back
        void push_back(const T& value);
        void pop_back();
        //emplace
        //insert
        //erase
        //swap
        //resize
        //clear

        /* Operations */
        //splice
        //remove
        //remove_if
        //unique
        //merge
        //sort
        //reverse

     private:
        unsigned int nodes_count;

        template <class C>
        class list_node
        {
         public:
            list_node<C>(const C &val, list_node *next_node=nullptr, list_node *prev_node=nullptr)
                : value(val)
                , next(next_node)
                , prev(prev_node) {}

            C value;
            list_node *next;
            list_node *prev;
        };

        list_node<T> *head;
        list_node<T> *tail;

    };
}

// include template implementation
#include "list.tcc"

#endif // ALEXP_LIST_H