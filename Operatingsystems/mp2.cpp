#include <iostream>
#include <cstdlib>
using namespace std;

int r1pc; //reader 1 program counter
int r2pc; //reader 2 program counter
int r3pc; //reader 3 program counter
int w1pc; //writer 1 program counter
int w2pc; //writer 2 program counter
//wait reader
void p(int &s)
{
    while (s <= 0)
        ; //do nothing
    s--;
}
int reader_count = 0;
//signal reader
void v(int &s)
{
    s++;
}

//wait writer
void x(int &mutex)
{
    if (mutex = 0)
        ; //do nothing
    else
        mutex = 0;
}
//signal writer
void y(int &mutex)
{
    mutex = 1;
}
int writer_count = 0;
// reader semaphore
int s = 2;
// writer semaphore
int mutex = 1;
//bounded buffer

int my_grade = 1;

//TestAndSet Function
bool testandset(bool *target)
{
    bool rv = *target;
    *target = true;
    return rv;
}
void reset(int s)
{
    s = 2;
    cout << "set to 2" << endl;
}
void panic()
{
    cout << "Panic!!!!" << endl;
}
int pr1 = 0;
int pr2 = 0;
int pr3 = 0;
int pw1 = 0;
int pw2 = 0;

//reader 1
void r1()
{
    switch (r1pc)
    {
    case 0:
    {
        cout << "im reader 1 and in the NCS" << endl;
        r1pc++;
        break;
    }
    case 1:
    {
        cout << " Im reader 1 and im trying to enter the CS" << endl;
        if (s > 0) // checks writing semaphore limit
        {
            p(s);
            r1pc++;
            break;
        }
        else
            break;
    }
    case 2:
    {
        if (mutex == 1) //checks the writer semaphore if its locked or unlocked  lock = 1 , unlock = 0
            break;
        else
        { //calls the function to lock the semaphore
            x(mutex);
            r1pc++;
            break;
        }
    }
    case 3:
    {
        if (reader_count < 2 && writer_count <= 0)
        {
            reader_count++;
            cout << "     there are " << reader_count << " readers and " << writer_count << " writers in the critical section. My Grade is " << my_grade << endl; //gives reader and writer count      cout<<"reader 1 im in the critical section and see my grade as "<<my_grade<<endl;

            r1pc++;
            break;
        }
        else
            break;
    }
    case 4:
    {
        y(mutex);
        v(s);
        reader_count--;
        cout << "im reader 1 and im out of the critical section" << endl;
        r1pc++;
        break;
    }
    case 5:
    {

        if (pr1 < 100) //loop to help slow down each process after it has finished and resets it for the next call
        {
            pr1++;
            break;
        }
        else
            pr1 = 0;
        r1pc = 0;
        cout << "r1 im done" << endl;
        break;
    }
    }
}

//reader 2
void r2()
{
    switch (r2pc)
    {
    case 0:
    {
        cout << "im reader 2 and in the ncs" << endl;
        r2pc++;
        break;
    }
    case 1:
    {
        cout << " Im reader 2 and im trying to enter the CS" << endl;

        if (s > 0) // checks writing semaphore limit
        {
            p(s);
            r2pc++;
            break;
        }
        else
            break;
    }
    case 2:
    {
        if (mutex == 1) //checks the writer semaphore if its locked or unlocked  lock = 1 , unlock = 0
            break;
        else
            x(mutex); //calls the function to lock the semaphore
        r2pc++;
        break;
    }
    case 3:
    {
        if (reader_count < 2 && writer_count <= 0)
        {
            reader_count++;
            cout << "     there are " << reader_count << " readers and " << writer_count << " writers in the critical section. My Grade is " << my_grade << endl; //gives reader and writer count      cout<<"reader 1 im in the critical section and see my grade as "<<my_grade<<endl;

            r2pc++;
            break;
        }
        else
            break;
    }
    case 4:
    {
        y(mutex);
        v(s);
        reader_count--;
        cout << "im reader 2 and im out of the critical section" << endl;
        r2pc++;
        break;
    }
    case 5:
    {

        if (pr2 < 100) //loop to help slow down each process after it has finished and resets it for the next call
        {
            pr2++;
            break;
        }
        else
            pr2 = 0;
        r2pc = 0;
        cout << "r2 im done" << endl;
        break;
    }
    }
}

//reader 3
void r3()
{
    switch (r3pc)
    {
    case 0:
    {
        cout << "im reader 3 and in the ncs" << endl;
        r3pc++;
        break;
    }
    case 1:
    {
        cout << " Im reader 3 and im trying to enter the CS" << endl;
        if (s > 0) // checks writing semaphore limit
        {
            p(s);
            r3pc++;
            break;
        }
        else
            break;
    }
    case 2:
    {

        if (mutex == 1) //checks the writer semaphore if its locked or unlocked  lock = 1 , unlock = 0
            break;
        else
            x(mutex); //calls the function to lock the semaphore
        r3pc++;
        break;
    }
    case 3:
    {
        if (reader_count < 2 && writer_count <= 0)
        {
            reader_count++;
            cout << "     there are " << reader_count << " readers and " << writer_count << " writers in the critical section. My Grade is " << my_grade << endl; //gives reader and writer count      cout<<"reader 1 im in the critical section and see my grade as "<<my_grade<<endl;

            r3pc++;
            break;
        }
        else
        {
            break;
        }
    }
    case 4:
    {

        y(mutex);
        v(s);
        reader_count--;
        cout << " Im reader 3 and im out of the critical section" << endl;
        r3pc++;
        break;
    }
    case 5:
    {

        if (pr3 < 100) //loop to help slow down each process after it has finished and resets it for the next call
        {
            pr3++;
            break;
        }
        else
            pr3 = 0;
        r3pc = 0;
        cout << "r3 im done" << endl;
        break;
    }
    }
}

//writer 1
void w1()
{
    switch (w1pc)
    {
    case 0:
    {
        cout << "Im writer 1 and im in the non critical section" << endl;
        w1pc++;
        break;
    }
    case 1:
    {
        cout << "Im writer 1 and im trying to enter the critcial section " << endl;
        w1pc++;
        break;
    }
    case 2:
    {
        if (mutex == 1) //checks if the semaphore is unlocked for writer
        {
            x(mutex);
            w1pc++;
            break;
        }
        else
        {
            break;
        }
    }
    case 3:
    {
        if (reader_count > 0)
            break; //do nothing
        else
        {
            s = 0; //locks readers
            w1pc++;
            break;
        }
    }
    case 4:
    { //checks reader and writer before entering the CS
        if (reader_count <= 0 && writer_count <= 0)
        {
            writer_count++;
            cout << "im Writer 1      there are " << reader_count << " readers and " << writer_count << " writers in the critical section" << endl;
            my_grade = rand() % 100;
            cout << "writer 1 in the critical section and changed grade to " << my_grade << endl;
            w1pc++;

            break;
        }
        else
            break;
    }
    case 5:
    { // ends the CS for the writer and unlocks the lock for semaphore for the reader and writer
        writer_count--;
        y(mutex);
        v(s);
        cout << "Writer 1 out of the critcial section" << endl;
        w1pc++;
        break;
    }
    case 6:
    {
        if (pw1 < 100) //loop to help slow down each process after it has finished and resets it for the next call
        {
            pw1++;
            break;
        }
        else
            pw1 = 0;
        w1pc = 0;
        cout << "w1 done" << endl;
        break;
    }
    }
}

//writer 2
void w2()
{
    switch (w2pc)
    {
    case 0:
    {
        cout << "Im writer 2 and im in the non critical section" << endl;
        w2pc++;
        break;
    }
    case 1:
    {
        cout << "Im writer 2 and im trying to enter the critcial section " << endl;
        w2pc++;
        break;
    }
    case 2:
    {
        if (mutex == 1) //checks if the semaphore is unlocked for writer
        {
            x(mutex);
            w2pc++;
            break;
        }
        else
        {
            break;
        }
    }
    case 3:
    {
        if (reader_count > 0)
            break; //do nothing
        else
        {
            s = 0; //locks readers
            w2pc++;
            break;
        }
    }
    case 4:
    { //  //checks reader and writer before entering the CS
        if (reader_count <= 0 && writer_count <= 0)
        {
            writer_count++;
            cout << "im Writer 2      there are " << reader_count << " readers and " << writer_count << " writers in the critical section" << endl;
            my_grade = my_grade * 2;
            cout << "writer 2 in the critical section and changed grade to " << my_grade << endl;
            w2pc++;

            break;
        }
        else
            break;
    }
    case 5:
    { // ends the CS for the writer and unlocks the lock for semaphore for the reader and writer
        writer_count--;
        y(mutex);
        v(s);
        cout << "Writer 2 out of the critcial section" << endl;
        w2pc++;
        break;
    }
    case 6:
    {
        if (pw1 < 100) //loop to help slow down each process after it has finished and resets it for the next call
        {
            pw2++;
            break;
        }
        else
            pw2 = 0;
        w2pc = 0;
        cout << "w2 done" << endl;
        break;
    }
    }
}

int main()
{

    for (int i = 0; i <= 10000; i++)
    {
        int pid = rand() % 5; //process id
        switch (pid)
        {
        case 0:
            r1();
            break;
        case 1:
            r2();
            break;
        case 2:
            r3();
            break;
        case 3:
            w1();
            break;
        case 4:
            w2();
            break;
        }
    }
}