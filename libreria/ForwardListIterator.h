#ifndef FORWARDLISTITERATOR_H
#define FORWARDLISTITERATOR_H
#include "./ForwardListNode.h"
#include "List.h"
#include "IteratorForward.h"

template <typename T>
class ForwardListIterator:public List<T> {


protected:
  ForwardListNode<T> *tail;
  public:
  ForwardListIterator(ForwardListIterator &copia) : List<T>(copia)
  {

  }
  ForwardListIterator(T* arreglo, int size) : List<T>(arreglo, size)
  {

  }
  ForwardListIterator(Node<T>* copia) : List<T>(copia)
  {

  }
  ForwardListIterator(int numero_elementos) : List<T>(numero_elementos)
  {

  }

  ForwardListIterator()
  {
    List<T>::head = NULL;
    tail = NULL;
  }

    IteratorForward<T> begin(){
        return IteratorForward<T>(List<T>::head) ;
    }
    IteratorForward<T> end (){
        return IteratorForward<T>(tail);
    }

  T front(void)
  {
    if(List<T>::head)
    {
      return List<T>::head->get_value();
    }
    return 0;
  }
  T back(void)
  {
    ForwardListNode<T> *temp = (ForwardListNode<T>*)List<T>::head;
    if(temp)
    {
      while(temp->next)
      {
        temp = temp->next;
      }
      return temp->get_value();
    }
    return 0;
  }
  
  void push_back(const T& element)
  {
    if(List<T>::head)
    {
      ForwardListNode<T> *temp = (ForwardListNode<T>*)List<T>::head;
      while(temp->next)
      {
        temp = temp->next;
      }
      temp->next = new ForwardListNode<T>;
      temp->next->set_value(element);
      tail = temp->next;
      return;
    }
    List<T>::head = new ForwardListNode<T>;
    List<T>::head->set_value(element);
    tail = (ForwardListNode<T>*)List<T>::head;
  }
  void push_front(const T& element)
  {
    if(List<T>::head)
    {
      ForwardListNode<T> *temp = new ForwardListNode<T>;
      temp->set_value(element);
      ForwardListNode<T> *temp2 = (ForwardListNode<T>*)List<T>::head;
      List<T>::head = temp;
      ((ForwardListNode<T>*)List<T>::head)->next = temp2;
      return;
    }
    List<T>::head = new ForwardListNode<T>;
    List<T>::head->set_value(element);
  }

  ForwardListNode<T>* pop_back(void)
  {
    if(List<T>::head==NULL) {
      return NULL;
    }
    else if(((ForwardListNode<T>*)List<T>::head)->next==NULL){
      ForwardListNode<T> temp2 = *((ForwardListNode<T>*)List<T>::head);
      delete List<T>::head;
      List<T>::head = NULL;
      tail = NULL;
      return &temp2;
    }
    ForwardListNode<T> *temp1 = (ForwardListNode<T>*)List<T>::head;
    ForwardListNode<T> temp2;
    while (temp1->next->next) {
      temp1 = temp1->next;
    }
    temp2 = *temp1->next;
    delete temp1->next;
    temp1->next=NULL; 
    tail = temp1;
    return &temp2; 
  }
  ForwardListNode<T>* pop_front(void)
  {
    if(List<T>::head != NULL){
      ForwardListNode<T> temp;
      temp=*((ForwardListNode<T>*)List<T>::head);
      ForwardListNode<T> *aux_borrar;
      aux_borrar=(ForwardListNode<T>*)List<T>::head;
      
      List<T>::head=((ForwardListNode<T>*)List<T>::head)->next;
      delete aux_borrar;
      return &temp;
    }else{
      return NULL;
    }
  }

  T& operator[] (const int& posicion)
  {
    if(List<T>::head)
    {
      T temp2;
      ForwardListNode<T> *temp = (ForwardListNode<T>*)List<T>::head;
      for(int i = 0; i < posicion; i++)
      {
        temp = temp->next;
      }
      temp2 = temp->get_value();
      return temp2;
    }
  }
  
  bool empty(void)
  {
    if(List<T>::head!=NULL){
      return true;
    }else{
      return false;
    }
  }
  unsigned int size(void)
  {
    unsigned int size=0;
    ForwardListNode<T> *temp=(ForwardListNode<T>*)List<T>::head;
    while(temp!=NULL){
      size++;
      temp=temp->next;
    }
    return size;
  }
  void clear(void)
  {
    ForwardListNode<T> *aux=(ForwardListNode<T>*)List<T>::head;
    while(List<T>::head!=NULL) {
      List<T>::head = ((ForwardListNode<T>*)List<T>::head)->next;
      delete aux;
      aux=(ForwardListNode<T>*)List<T>::head;
    }
    List<T>::head = NULL;
    tail = NULL;
  }

  void erase(Node<T>* element)
  {

  }
  void insert(Node<T>* element, const T& position)
  {

  }
  void drop(const T& item)
  {

  }

  List<T>& sort(void)
  {

  }
  List<T>& reverse(void)
  {
    ForwardListNode<T> *aux1 = (ForwardListNode<T>*)List<T>::head;
    while(((ForwardListNode<T>*)List<T>::head)->next!=NULL){
      List<T>::head = ((ForwardListNode<T>*)List<T>::head)->next;
    }
  
    ForwardListNode<T> *aux2;
    ForwardListNode<T> *aux3;
    aux2 = aux1->next;
    ((ForwardListNode<T>*)List<T>::head)->next = aux1;
    aux1->next=NULL;
  
    while(aux2!=List<T>::head){
      aux3=aux2;
      aux2=aux2->next;
      ((ForwardListNode<T>*)List<T>::head)->next=aux3;
      aux3->next=aux1;
      aux1=aux3;
    }
    return *this;
  }
     
         
};

#endif