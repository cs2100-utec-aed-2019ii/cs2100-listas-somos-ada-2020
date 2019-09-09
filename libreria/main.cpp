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
  return 0;
}
