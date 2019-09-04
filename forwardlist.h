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
  T& operator[] (const int& posicion);
  
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
  if(head)
  {
    Node<T> *temp = head;
    while(temp->next)
    {
      temp = temp->next;
    }
    temp->next = new Node<T>;
    temp->next->set_value(element);
    return;
  }
  head = new Node<T>;
  head->set_value(element);
}
template<typename T>
void ForwardList<T>::push_front(const T& element)
{
    if(head)
    {
        Node<T> *temp = new Node<T>;
        temp->set_value(element);
        Node<T> *temp2 = head;
        head = temp;
        head->next = temp2;
        return;
    }
    head = new Node<T>;
    head->set_value(element);
}
template<typename T>
Node<T>* ForwardList<T>::pop_back(void)
{
   if(head==NULL) {
    return NULL;
  }
  else if(head->next==NULL){
    delete head;
    return NULL;
  }
  Node<T> *temp1 = head;
  Node<T> temp2;
  while (temp1->next->next) {
    temp1 = temp1->next;
  }
  temp2 = *temp1->next;
  delete temp1->next;
  temp1->next=NULL; 
  return &temp2; 
}

template<typename T>
Node<T>* ForwardList<T>::pop_front(void)
{
  if(head !=NULL){
    Node<T> temp;
    temp=*head;
    Node<T> *aux_borrar;
    aux_borrar=head;
    
    head=head->next;
    delete aux_borrar;
    return &temp;
  }else{
    return NULL;
  }    
}
template<typename T>
T& ForwardList<T>::operator[] (const int& posicion)
{
  if(head)
  {
    int temp2;
    Node<T> *temp = head;
    for(int i = 0; i < posicion; i++)
    {
      temp = temp->next;
    }
    temp2 = temp->get_value();
    return temp2;
  }
}
template<typename T>
bool ForwardList<T>::empty(void)
{
  if(head!=NULL){
    return true;
  }else{
    return false;
  }
}
template<typename T>
unsigned int ForwardList<T>::size(void)
{
  unsigned int size=0;
  Node<T> *temp=head;
  while(temp!=NULL){
    size++;
    temp=temp->next;
  }
  return size;
}
template<typename T>
void ForwardList<T>::clear(void)
{
  Node<T> *aux=head;
  while(head!=NULL) {
    head = head->next;
    delete aux;
    aux=head;
  }
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
