#ifndef LIST_BASE
#define LIST_BASE
#include "./Node.h"

template <typename T>
class List {
  protected:
    Node<T> *head;
  public:
    List(List &copia) // Constructor copia
    {
    
    }
    
    List(T* arreglo, int size) //Constructor  parametro, llena una lista a partir de un array
    {

    }

    List(Node<T>* copia) //Constructor por parametro, retorna una lista con un nodo
    {

    }

    List(int numero_elementos) //Constructor por parametro, retorna un lista de randoms de tamaño n
    {

    }

    List(void) // Constructor por defecto
    {

    }

    ~List(void)
    {
        
    }

    virtual T front(void) = 0; // Retorna una referencia al primer elemento
    virtual T back(void) = 0; // Retorna una referencia al ultimo elemento
    
    virtual void push_back(const T& element) = 0; // Inserta un elemento al final
    virtual void push_front(const T& element) = 0; // Inserta un elemento al inicio

    virtual Node<T>* pop_back(void) = 0; // Quita el ultimo elemento de la lista y retorna una referencia 
    virtual Node<T>* pop_front(void) = 0; // Quita el primer elemento de la lista y retorna una referencia 

    virtual T& operator[] (const int& posicion) = 0; // devuelve el valor de un nodo en una posicion determinada
    
    virtual bool empty(void) = 0; // la lista esta vacia?
    virtual unsigned int size(void) = 0; // retorna el tamaño de la lista
    virtual void clear(void) = 0; // Elimina toda la lista

    virtual void erase(Node<T>* element) = 0; // Elimina un elemento de la lista en base a un puntero
    virtual void insert(Node<T>* element, const T& position) = 0; // Inserta un elemento en la lista en base a un puntero
    virtual void drop(const T& item) = 0; // Elimina todos los elementos de la lista que tienen el valor igual al parametro

    virtual List<T>& sort(void) = 0; // ordena la lista
    virtual List<T>& reverse(void) = 0; // invierte la lista
};

#endif
