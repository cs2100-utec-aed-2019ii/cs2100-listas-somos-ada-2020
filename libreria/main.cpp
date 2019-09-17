#include <iostream>
#include "./ForwardList.h"
#include "./DoubleList.h"
#include "./CircularList.h"
/*#include "./DoubleCircularList.h"*/
using namespace std;

int main()
{ int a_[] = {1,2,3,4};
  ForwardList<int> *a = new ForwardList<int>;
  DoubleList<int> *b = new DoubleList<int>;
  CircularList<int> *c = new CircularList<int>(a_,4);
  
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
  cout<<"Circularlist:\n";
  cout<< c->back()<<endl;
  cout<< c->front()<<endl;
  c->push_back(19);c->push_front(20);
  cout<< c->back()<<endl;
  cout<< c->front()<<endl;
  *c<<21;*c>>22;
cout<< c->back()<<endl;
  cout<< c->front()<<endl;
  c->clear();
  cout<< c->back()<<endl;
  cout<< c->front()<<endl;
  delete a;
  delete b;
  delete c;
  return 0;
}