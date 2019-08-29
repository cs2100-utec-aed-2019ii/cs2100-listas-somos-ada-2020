#include "node.h"

template <typename T>
void Node<T>::set_value(T valor){
  Node<T>::value = valor;
}

template <typename T>
T Node<T>::get_value(){
  return Node<T>::value;
}  
