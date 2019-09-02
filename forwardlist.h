#ifndef FLIST
#define FLIST
#include "node.h"
#include <iostream>

template <typename T>
class ForwardList {
protected:
  Node<T> *head;
public:
  ForwardList(void);
  ~ForwardList(void);
  T front(void);
  T back(void);
  
  void push_back(const T& element);
  void push_front(const T& element);
  Node<T>* pop_back(void);
  Node<T>* pop_front(void);
  T& operator[] (const int&);
  
  bool empty(void);
  unsigned int size(void);
  void clear(void);
  ForwardList<T>& sort(void);
  ForwardList<T>& reverse(void);
  friend std::ostream& operator<<(std::ostream& exit, const ForwardList<T>& element);
};

template<typename T>
ForwardList<T>::ForwardList(void)
{
  head = NULL;
}

template<typename T>
ForwardList<T>::~ForwardList(void)
{

}

template <typename T>
T ForwardList<T>::front(void)
{
  if(head)
  {
    return head->get_value();
  }
  return NULL;
}

template <typename T>
T ForwardList<T>::back(void)
{
  Node<T> *temp = head;
  if(temp)
  {
    while(temp->next)
    {
      temp = temp->next;
    }
    return temp->get_value();
  }
  return NULL;
}

template <typename T>
void ForwardList<T>::push_back(const T& element)
{
  
}
template<typename T>
void ForwardList<T>::push_front(const T& element)
{
  
}
template<typename T>
Node<T>* ForwardList<T>::pop_back(void)
{
  
}
template<typename T>
Node<T>* ForwardList<T>::pop_front(void)
{
   
}
template<typename T>
T& ForwardList<T>::operator[] (const int&)
{

}
template<typename T>
bool ForwardList<T>::empty(void)
{

}
template<typename T>
unsigned int ForwardList<T>::size(void)
{

}
template<typename T>
void ForwardList<T>::clear(void)
{

}
template<typename T>
ForwardList<T>& ForwardList<T>::sort(void)
{

}
template<typename T>
ForwardList<T>& ForwardList<T>::reverse(void)
{
    
}

template<typename T>
std::ostream& operator<<(std::ostream& exit, const ForwardList<T>& element)
{

}

#endif
