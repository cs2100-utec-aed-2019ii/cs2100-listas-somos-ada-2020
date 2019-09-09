#ifndef FORWARDLISTNODE
#define FORWARDLISTNODE
#include "Node.h"

template <typename T>
class ForwardListNode : public Node<T>
{
  protected:
    ForwardListNode<T>* next;
  public:
    ForwardListNode (){}
    virtual ~ForwardListNode (){}
};

#endif
