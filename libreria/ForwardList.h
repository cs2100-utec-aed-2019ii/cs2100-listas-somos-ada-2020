#ifndef FORWARDLIST
#define FORWARDLIST
#include "./ForwardListNode.h"
#include "./List.h"

template <typename T>
class ForwardList : public List<T>{
  protected:
    ForwardListNode<T> *tail;
  public:
    ForwardList(ForwardList &copia) : List<T>(copia)
    {

    }
    ForwardList(T* arreglo, int size) : List<T>(arreglo, size)
    {

    }
    ForwardList(Node<T>* copia) : List<T>(copia)
    {

    }
    ForwardList(int numero_elementos) : List<T>(numero_elementos)
    {

    } 
    ForwardList()
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
