#include <iostream>
#include "./ForwardList.h"
#include "./DoubleList.h"
//#include "./CircularList.h"
#include "./DoubleCircularList.h"
using namespace std;

int main()
{
  ForwardList<int> *a = new ForwardList<int>;
  DoubleList<int> *b = new DoubleList<int>;
  //CircularList<int> *c = new CircularList<int>;
  DoubleCircularList<int> *d = new DoubleCircularList<int>;
  a->push_back(1);
  a->push_back(2);
  a->push_back(3);
  cout << a->front() << endl;
  cout << a->back() << endl;
  cout << (*a)[1] << endl;
  a->pop_back();
  cout << a->back() << endl;
  //a->pop_front();
  //cout << a->front<<endl;
  //a->reverse();
  //cout << a->back() << endl;
  cout<<"Double list:\n";
  b->push_back(1);
  b->push_back(2);
  b->push_back(3);
  b->push_back(4);
  cout << b->front() << endl;
  cout << b->back() << endl;
  cout << (*b)[2] << endl;
  b->pop_front();
  cout << b->front() << endl;
  //cout<<b->size();
  //b->clear();
  //cout << b->empty();
  //b->reverse();
  //cout << b->back() << endl;
  cout << "Double Circular" << endl;
  d->push_front(3);
  d->push_front(4);
  d->push_front(4);
  d->push_back(5);
  d->push_back(5);
  cout << d->back() << endl;
  cout << d->front() << endl;
  d->drop(4);
  cout << d->back() << endl;
  cout << d->front() << endl;
  return 0;
}
