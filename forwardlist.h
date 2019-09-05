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
  friend std::ostream& operator<<(std::ostream& exit, ForwardList<T>* element)
  {
    for(int i = 0; i < element->size(); i++)
    {
      exit << (*element)[i] << " ";
    }
    return exit;
  }
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
  return 0;
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
  return 0;
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
  if(head != NULL){
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
  unsigned int contador=0;
  Node<T> *temp = head;
  Node<T> *temp_1 = head;
  Node<T> *temp_2 = head;
  while (temp!= NULL)
  {
    contador++;
    temp = temp->next;
  }
  delete temp;
  T a[contador];

  for(int i = 0;i<contador;i++){
    a[i]=temp_1->get_value();
    temp_1 = temp_1->next;
  }
  delete temp_1;
  
  for(int i = 0;i<contador;i++){  
    for (size_t j = 0; j <contador-1; j++)
          {
              if (a[j]>a[j+1])
              {
                  int temp1 = a[j+1];
                  a[j+1]=a[j];
                  a[j]=temp1;
              }
          }
  }
  
  for(int i = 0;i<contador;i++){
      temp_2->set_value(a[i]);
      temp_2 = temp_2->next;
    }
  delete temp_2;
  return *this;
}
template<typename T>
ForwardList<T>& ForwardList<T>::reverse(void)
{
  Node<T> *aux1=head;
  while(head->next!=NULL){
    head=head->next;
  }
  
  Node<T> *aux2;
  Node<T> *aux3;
  aux2 = aux1->next;
  head->next = aux1;
  aux1->next=NULL;
  
  while(aux2!=head){
    aux3=aux2;
    aux2=aux2->next;
    head->next=aux3;
    aux3->next=aux1;
    aux1=aux3;
  }
  return *this;
}



#endif
