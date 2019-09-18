#ifndef NODO_BASE
#define NODO_BASE
#include<iostream>
using namespace std;
template <typename T>
class Node
{
  protected:
    T value;
  public:
    Node(void){}
    virtual ~Node (void){}

    void set_value(T valor)
    {
      value = valor;
    }

    T get_value()
    {
      return Node<T>::value;
    }
    T& operator*(void){
            return value;
        }

        template <typename _T>
        inline friend ostream& operator<< (ostream& _out, const Node<_T>& _node){
            _out << "Nodo: " <<  _node.value;
            return _out;
        }
    
};

#endif
