#ifndef NODO
#define NODO

template <typename T>
class Node {
protected:
  T value;
  Node<T> * next;
public:
  Node(void);
  ~Node(void);
  void set_value(T valor);
  T get_value();  
};

#endif
