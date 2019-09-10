#ifndef FORWARDLISTNODE
#define FORWARDLISTNODE
#include "Node.h"

template <typename T>
class ForwardListNode : public Node<T>
{
  public:
    ForwardListNode<T>* next;
    ForwardListNode (){}
    virtual ~ForwardListNode (){}
};

#endif
