#include <iostream>           
#include <pthread.h>
#include <cstdlib> //This is POSIX based multithreading
using namespace std;
int BUFFER_SIZE;
int in, out;
#define threadnum 10 //Numver of threads being used

void *consumerthread(void *threadn)
{   
    int *a  = (int *)threadn;
    int i;
   for(i=0; i<in; i++)
    {
        while (in==out) sched_yield();
       cout<<"Consuming "<<a[out]<<endl;
        //a[out]=0;
        out = (out + 1) % BUFFER_SIZE;
    
    }
    pthread_exit(NULL); //terminates the threads
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
    int *a = new int [BUFFER_SIZE];
    pthread_t threads[threadnum]; //names the threads and uses earlier defintion for number of usable threads
    int i;
    int th; 
    for (i = 0; i<BUFFER_SIZE; i++)
    {   
        a[i] = rand() % 100+1;
       while((i+1) %BUFFER_SIZE == out) sched_yield();
       cout<<"Producing Thread: "<<i<<" "<<a[i]<<endl;
        in = (in +1)%BUFFER_SIZE;
        
        th = pthread_create(&threads[i], NULL, consumerthread, (void *)a); //passes threads for num of threads,  NULL for default value, name of pointer argument and its arugment type along with the iterator for the for loop
    //long because it i is an int but the argument asks for a long, so i is passed as a long parameter
        //error catch
        if(th!=0)
        {
            cout<<"error, threads cannot be created "<<th<<endl;
            exit(-1);

        }
        
    }
    pthread_exit(NULL); //kills all the threads 
}