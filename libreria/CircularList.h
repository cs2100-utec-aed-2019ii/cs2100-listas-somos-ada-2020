#ifndef CIRCULARLIST
#define CIRCULARLIST
#include "./ForwardListNode.h"
#include "./List.h"
#include <iostream>
template <typename T>
class CircularList : public List<T>{
  public:
    CircularList(CircularList &copia) : List<T>(copia)
    {
      this = copia; 
    }
    CircularList(T* arreglo, int size) : List<T>(arreglo, size)
    {
        for (int i = 0; i < size; i++)
        {
          push_back(arreglo[i]);
        }
    }
    CircularList(Node<T>* copia) : List<T>(copia)
    { 
   
    }
    CircularList(int numero_elementos) : List<T>(numero_elementos)
    {
      for (int i = 0; i < numero_elementos; i++)
        {
          push_back(0);
        }
    } 
    CircularList()
    {         
      List<T>::head = NULL;
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
      ForwardListNode<T>* temp = (ForwardListNode<T>*)List<T>::head;
      if (temp)
      {
        while (temp->next != List<T>::head)
        {
          temp = (ForwardListNode<T>*)(temp->next);
       
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
        while(temp->next!=List<T>::head)
        {
          temp = (ForwardListNode<T>*)temp->next;
        }
        temp->next = new ForwardListNode<T>;
        temp->next->set_value(element);
        ((ForwardListNode<T>*)temp->next)->next = (ForwardListNode<T>*)List<T>::head;
        return;
      }
      
      List<T>::head = new ForwardListNode<T>;
      List<T>::head->set_value(element);
      ((ForwardListNode<T>*)List<T>::head)->next =(ForwardListNode<T>*)List<T>::head; 

    }

    void push_front(const T& element)
    {
      if(List<T>::head)
      {
        
        ForwardListNode<T> *temp1 = (ForwardListNode<T>*)List<T>::head;
        while(temp1->next!=List<T>::head)
        { 
          temp1 = (ForwardListNode<T>*)temp1->next;  
        }
        ForwardListNode<T> *temp = new ForwardListNode<T>;
        temp->set_value(element);
        temp1->next = temp;
        temp->next = (ForwardListNode<T>*)List<T>::head;
        List<T>::head = temp;

        ((ForwardListNode<T>*)temp1)->next = (ForwardListNode<T>*)List<T>::head;
        return;
      }
      List<T>::head = new ForwardListNode<T>;
      List<T>::head->set_value(element);
      ((ForwardListNode<T>*)List<T>::head)->next =(ForwardListNode<T>*)List<T>::head; 
    }

    ForwardListNode<T>* pop_back(void)
    {
        if(List<T>::head==nullptr) {
      return nullptr;
    }
    else if(((ForwardListNode<T>*)List<T>::head)->next==((ForwardListNode<T>*)List<T>::head)->next){
      ForwardListNode<T> temp2 = *((ForwardListNode<T>*)List<T>::head);
      delete List<T>::head;
      return &temp2;
    }
    ForwardListNode<T> *temp1 = (ForwardListNode<T>*)List<T>::head;
    ForwardListNode<T> temp2;
    while (((ForwardListNode<T> *)(temp1->next))->next) {
      temp1 = (ForwardListNode<T>*)temp1->next;
    }
    temp2 = *(ForwardListNode<T>*)temp1->next;
    delete temp1->next;
    temp1->next=(ForwardListNode<T>*)List<T>::head; 
    
    return &temp2; 
    }


    ForwardListNode<T>* pop_front(void)
    {
         if(List<T>::head){
      
      ForwardListNode<T> temp=*((ForwardListNode<T>*)List<T>::head);
      ForwardListNode<T> *aux_borrar=(ForwardListNode<T>*)List<T>::head;
      ForwardListNode<T> *temp1 = (ForwardListNode<T>*)List<T>::head;
        while(temp1->next!=List<T>::head)
        { 
          temp1 = (ForwardListNode<T>*)temp1->next;  
        }
      List<T>::head=((ForwardListNode<T>*)List<T>::head)->next;
        temp1->next = (ForwardListNode<T>*)List<T>::head; 
      delete aux_borrar;
      return &temp;
    }else{
      return nullptr;
      }
    }

    T& operator[] (const int& posicion)
    {
      if(List<T>::head)
        {
          T temp2;
          ForwardListNode<T> *temp = (ForwardListNode<T> *)List<T>::head;
          for(int i = 0; i < posicion; i++)
          {
            temp = (ForwardListNode<T> *)temp->next;
          }
          temp2 = temp->get_value();
          return temp2;
        }
    }
    
    bool empty(void)
    { 
      return List<T>::head ==nullptr;
    }
    unsigned int size(void)
    {
      unsigned int size=1;
      ForwardListNode<T> *temp=(ForwardListNode<T> *)List<T>::head;
        temp = (ForwardListNode<T>* )temp->next;
       while(temp!=(ForwardListNode<T> *)List<T>::head){
          size++;
          temp=(ForwardListNode<T>* )temp->next;
         }
      return size;
    }
    
    void clear(void)
    {   if(List<T>::head == nullptr)
        return;
    ForwardListNode<T> *traversePointer = (ForwardListNode<T>*)List<T>::head;
    ForwardListNode<T> *deletePointer;
    do{
        deletePointer = traversePointer;
        traversePointer = (ForwardListNode<T> *)traversePointer->next;
        delete deletePointer;
    }while(traversePointer != List<T>::head);
    List<T>::head = nullptr;
    }

    void erase(Node<T>* element)
    {        
      ForwardListNode<T> *temp = (ForwardListNode<T> *)List<T>::head;  
        while(temp->next!= element){
           temp = (ForwardListNode<T> *)temp->next;
        }
      ForwardListNode<T> *temp1 = temp;
      temp1->next=((ForwardListNode<T> *)temp->next)->next;
      delete temp->next;
    }
    void insert(Node<T>* element, const T& position)
    {
    }
    void drop(const T& item)
    { 
    }

    List<T>& sort(void)
    {
        ForwardListNode<T> *temp_1 = (ForwardListNode<T> *)List<T>::head;
        ForwardListNode<T> *temp_2 = (ForwardListNode<T> *)List<T>::head;
        unsigned int contador= this->size();

        T a[contador];

        for(int i = 0;i<contador;i++){
          a[i]=temp_1->get_value();
          temp_1 = (ForwardListNode<T> *)temp_1->next;

        }
  

      for(int i = 0;i<contador;i++){  
        for (int j = 0; j <contador-1; j++)
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
      temp_2 = (ForwardListNode<T> *)temp_2->next;
      }
      
        return *this;
    }


    List<T>& reverse(void)
    {     
        if (List<T>::head == NULL) 
        return *this; 
  
    
    ForwardListNode<T>* prev = NULL; 
    ForwardListNode<T>* current = (ForwardListNode<T>*)List<T>::head; 
    ForwardListNode<T>* next; 
    do { 
        next = (ForwardListNode<T>*)current->next; 
        current->next = prev; 
        prev = current; 
        current = next; 
    } while (current != List<T>::head); 
    ((ForwardListNode<T>*)(List<T>::head))->next = prev; 
    
      List<T>::head = prev; 
      return *this;
    }
                   
};

#endif
