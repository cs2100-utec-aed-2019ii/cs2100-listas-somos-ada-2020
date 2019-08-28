#include "node.h"

template <typename T>
void node<T>::set_value(T valor){
  node<T>::value = valor;
}

template <typename T>
T node<T>::get_value(){
  return node<T>::value;
}  