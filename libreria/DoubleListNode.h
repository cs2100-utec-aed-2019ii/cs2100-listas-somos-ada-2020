#ifndef DOUBLELISTNODE
#define DOUBLELISTNODE
#include "./Node.h"

template <typename T>
class DoubleListNode : public Node<T>
{
public:
  DoubleListNode<T> * next;
  DoubleListNode<T> * prev;
  DoubleListNode(void){}
  ~DoubleListNode(void){}
};

#endif
