#ifndef DOUBLELISTNODE
#define DOUBLELISTNODE
#include "./Node.h"

template <typename T>
class DoubleListNode : public Node<T>
{
  public:
    Node<T> * next;
    Node<T> * prev;
    DoubleListNode(void){}
    ~DoubleListNode(void){}
};

#endif
