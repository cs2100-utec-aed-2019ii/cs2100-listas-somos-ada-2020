#ifndef DOUBLELIST
#define DOUBLELIST
#include "./DoubleListNode.h"
#include "./List.h"

template <typename T>
class DoubleList : public List<T>{
  protected:
    DoubleListNode<T> *tail;
  public:
    DoubleList(DoubleList &copia) : List<T>(copia)
    {

    }
    DoubleList(T* arreglo, int size) : List<T>(arreglo, size)
    {

    }
    DoubleList(Node<T>* copia) : List<T>(copia)
    {

    }
    DoubleList(int numero_elementos) : List<T>(numero_elementos)
    {

    } 
    DoubleList()
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