#ifndef NODO_BASE
#define NODO_BASE

template <typename T>
class Node
{
  protected:
    T value;
  public:
    Node(void){}
    virtual ~Node (void){}
};

#endif
