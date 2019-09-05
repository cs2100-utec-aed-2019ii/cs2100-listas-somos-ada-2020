#ifndef NODO
#define NODO

template <typename T>
class Node {
protected:
  T value;
public:
  Node<T>* next;
  Node(void){}
  ~Node(void){}
  void set_value(T valor)
  {
    value = valor;
  }

  T get_value()
  {
    return Node<T>::value;
  }

};

#endif
