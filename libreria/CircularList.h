#ifndef CIRCULARLIST
#define CIRCULARLIST
#include "./ForwardListNode.h"
#include "./List.h"

template <typename T>
class CircularList : public List<T>{
  public:
    CircularList(CircularList &copia) : List<T>(copia)
    {

    }
    CircularList(T* arreglo, int size) : List<T>(arreglo, size)
    {

    }
    CircularList(Node<T>* copia) : List<T>(copia)
    {

    }
    CircularList(int numero_elementos) : List<T>(numero_elementos)
    {

    } 
    CircularList()
    {

    } 
    T& front(void)
    {

    }
    T& back(void)
    {

    }
    
    void push_back(const T& element)
    {

    }
    void push_front(const T& element)
    {

    }

    Node<T>* pop_back(void)
    {

    }
    Node<T>* pop_front(void)
    {

    }

    T& operator[] (const int& posicion)
    {

    }
    
    bool empty(void)
    {

    }
    unsigned int size(void)
    {

    }
    void clear(void)
    {

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

    }
};

#endif
