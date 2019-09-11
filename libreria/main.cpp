#include <iostream>
#include "./ForwardList.h"
#include "./DoubleList.h"
#include "./CircularList.h"
#include "./DoubleCircularList.h"
using namespace std;

int main()
{
  ForwardList<int> *a = new ForwardList<int>;
  DoubleList<int> *b = new DoubleList<int>;
  CircularList<int> *c = new CircularList<int>;
  DoubleCircularList<int> *d = new DoubleCircularList<int>;
  a->push_back(1);
  a->push_back(2);
  a->push_back(3);
  cout << a->front() << endl;
  cout << a->back() << endl;
  cout << (*a)[1] << endl;
  return 0;
}
