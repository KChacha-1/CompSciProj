#include <iostream>
#include <thread>
#include <cstdlib>
using namespace std;


int BUFFER_SIZE;
int in, out;

void producer (int a[])
{
  while(true)
  {   
      int i= rand()%100+1;
      while((i+1) %BUFFER_SIZE == out) sched_yield();
      a[in] = i;
      in = (in +1)%BUFFER_SIZE;

  }
}
void consumer (int a[])
{
    while (true)
    {
       while (in == out) sched_yield();
    int i = a [out];
    out = (out + 1) % BUFFER_SIZE;
    cout<<"Consuming "<<a[out]<<endl;
    }
    
}

int main()
{
  start:
    cout<<"Insert a buffer size"<<endl;
    cin>>BUFFER_SIZE;
    if (BUFFER_SIZE <0)
    {
        cout<<"Invalid BUFFER_SIZE, Try again"<<endl;
        goto start;
    }
    int a[BUFFER_SIZE];
    thread prod(producer, a[BUFFER_SIZE]);
    thread cons(consumer, a[BUFFER_SIZE]);

}
//Producer:
//
//while (true) {
//  /*produce item v */
//  b [in] = v;
//  in++;
//}
//Consumer:
//
//while (true) {
//  while (in <= out) /* do nothing */;
//  w = b [out];
//  out++;
//  /*consume item w */
//}