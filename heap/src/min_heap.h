#ifndef MIN_HEAP_H_
#define MIN_HEAP_H_

/**
 * The HEAP implementation
 */

#include <vector>
#include <string>

template <class T>
class MinHeap
{
  public:
    MinHeap();
    void add(const T &item);
    T remove(void);
    std::string trace(void);
    bool isValid();

  private:
    std::vector<T> data;
};

#include "min_heap.tcc"

#endif // MIN_HEAP_H_
