#ifndef DOUBLECIRCULARLIST
#define DOUBLECIRCULARLIST
#include <iostream>
#define HEAD (List<T>::head)
#define DHEAD ((DoubleListNode<T>*)HEAD)
#define N(a) ((Node<T> *)a)
#define D(a) ((DoubleListNode<T> *)a)
#include "./DoubleListNode.h"
#include "./List.h"

template <typename T>
class DoubleCircularList : public List<T>{
protected:
    DoubleListNode<T> *tail;
public:
  DoubleCircularList(DoubleCircularList &copia) : List<T>(copia)
  {

  }
  DoubleCircularList(T* arreglo, int size) : List<T>(arreglo, size)
  {

  }
  DoubleCircularList(Node<T>* copia) : List<T>(copia)
  {

  }
  DoubleCircularList(int numero_elementos) : List<T>(numero_elementos)
  {

  } 
  DoubleCircularList()
  {
    HEAD = NULL;
    tail = NULL;
  } 
  T front(void)
  {
    if(HEAD)
    {
      return HEAD->get_value();
    }
  }
  T back(void)
  {
    if(HEAD)
    {
      return DHEAD->prev->get_value();
    }
  }
  
  void push_back(const T& element)
  {
    if(HEAD)
    {
      DoubleListNode<T> *temp = DHEAD->prev;
      temp->next = NULL;
      temp->next = new DoubleListNode<T>;
      temp->next->set_value(element);
      temp->next->next = DHEAD;
      temp->next->prev = temp;
      DHEAD->prev = temp->next;
      return;
    }
    HEAD = new DoubleListNode<T>;
    DHEAD->set_value(element);
    DHEAD->next = DHEAD;
    DHEAD->prev = DHEAD;
  }
  void push_front(const T& element)
  {
    if(HEAD)
    {
      DoubleListNode<T> *temp = new DoubleListNode<T>;
      temp->set_value(element);
      temp->next = DHEAD;
      temp->prev = DHEAD->prev;
      DHEAD->prev->next = temp;
      DHEAD->prev = temp;
      HEAD = N(temp);
      return;
    }
    HEAD = new DoubleListNode<T>;
    DHEAD->set_value(element);
    DHEAD->next = DHEAD;
    DHEAD->prev = DHEAD;
  }

  Node<T>* pop_back(void)
  {
    if(HEAD && DHEAD != DHEAD->prev)
    {
      DoubleListNode<T> *temp = DHEAD->prev;
      temp->prev->next = DHEAD;
      DHEAD->prev = temp->prev;
      return temp;
    }
    if(HEAD)
    {
      DoubleListNode<T> *temp = DHEAD;
      HEAD = NULL;
      return temp;
    }
    return NULL;
  }
  Node<T>* pop_front(void)
  {
    if(HEAD && DHEAD != DHEAD->prev)
    {
      DoubleListNode<T> *temp = DHEAD;
      DHEAD->next->prev = DHEAD->prev;
      DHEAD->prev->next = DHEAD->next;
      HEAD = N(DHEAD->next);
      return temp;
    }
    if(HEAD)
    {
      DoubleListNode<T> *temp = DHEAD;
      HEAD = NULL;
      return temp;
    }
    return NULL;
  }

  T& operator[] (const int& posicion)
  {
    int answer = 0;
    DoubleListNode<T> *temp = DHEAD;
    for(int i = 0; i < posicion; i++)
    {
      temp = temp->next;
    }
    answer = temp->get_value();
    return answer;
  }
  
  bool empty(void)
  {
    if(HEAD)
    {
      return false;
    }
    return true;
  }
  unsigned int size(void)
  {
    if(!HEAD){return 0;}
    unsigned int contador = 0;
    DoubleListNode<T> *temp = DHEAD;
    do
    {
      contador++;
      temp = temp->next;
    }
    while(temp != HEAD);
    return contador;
  }
  void clear(void)
  {
    Node<T> *temp;
    while(HEAD)
    {
      temp = pop_back();
      delete temp;
    }
  }

  void erase(Node<T>* element)
  {
    if(element == HEAD)
    {
      HEAD = DHEAD->next;
      DoubleListNode<T> *temp = D(element)->next;
      DoubleListNode<T> *temp2 = D(element)->prev;
      delete element;
      temp2->next = temp;
      temp->prev = temp2;
      return;
    }
    DoubleListNode<T> *temp = D(element)->next;
    DoubleListNode<T> *temp2 = D(element)->prev;
    delete element;
    temp2->next = temp;
    temp->prev = temp2;
  }
  void insert(Node<T>* element, const T& position)
  {

  }
  void drop(const T& item)
  {
    if(!HEAD){return;}
    int posicion = 0;
    DoubleListNode<T> *temp = DHEAD;
    DoubleListNode<T> **temp2[size()];
    do
    {
      if(temp->get_value() == item)
      {
        temp2[posicion++] = &temp;
        std::cout << "VALOR " << temp->get_value() << std::endl;
      }
      temp = temp->next;
    }
    while(temp != HEAD);
    while(posicion >= 0)
    {
      erase(*temp2[posicion--]);
    }
  }

  List<T>& sort(void)
  {

  }
  List<T>& reverse(void)
  {

  }
};


#endif
