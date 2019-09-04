#include <iostream>
#include "./node.h"
#include "./forwardlist.h"
using namespace std;

int main()
{
  ForwardList<int> *owo = new ForwardList<int>;
  owo->push_back(4);
  owo->push_back(5);
  owo->push_front(7);
  owo->push_front(8);
  owo->pop_front();
  cout << (*owo)[2] << endl;
  cout << owo->front() << endl;
  delete owo;
  return 0;
}
