#ifndef FORWARDLISTITERATOR_H
#define FORWARDLISTITERATOR_H
#include "./ForwardListNode.h"
#include "ForwardList.h"

template<typename Node>
class Iterator_Base {
protected:
  Node **backup;
  Node **position;
public:
  Iterator_Base(Node **head)
  {
    backup = head;
    position = head;
  }
  int operator*()
  {
    return (*position)->value;
  }
  void operator++()
  {
    if((*position)->next)
    {
      backup = position;
      position = &((*position)->next);
    }
    else
    {
      position = nullptr;
    }
  }
};

template<typename Node>
class Iterator : public Iterator_Base<Node>
{
public:
  Iterator(Node **head) : Iterator_Base<Node>(head){}
  bool operator!=(Iterator<Node> comp)
  {
    if(Iterator_Base<Node>::position != comp.position)
    {
      return true;
    }
    else
    {
      return false;
    }
  }
};

template<>
class Iterator<DoubleListNode> : public Iterator_Base<DoubleListNode>
{
public:
  Iterator(DoubleListNode **head) : Iterator_Base<DoubleListNode>(head){}
  void operator--()
  {
    position = &((*position)->prev);
  }
  bool operator!=(Iterator<DoubleListNode> comp)
  {
    if(Iterator_Base<DoubleListNode>::position != comp.position)
    {
      return true;
    }
    else
    {
      return false;
    }
  }
};

#endif
