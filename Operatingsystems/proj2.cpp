#include <iostream>
#include <cstdlib>
using namespace std;

int r1pc = 0, r2pc = 0, r3pc = 0, w1pc = 0, w2pc = 0;
int i = 0;

//wait reader
void p(int s)
{
    while (s <= 0)
        ; //do nothing
    s--;
}
int reader_count = 0;
//signal reader
void v(int s)
{
    s++;
}

//wait writer
void x(bool &mutex)
{
    while (mutex == 0)
        ; //do nothing
    mutex == 0;
}
//signal writer
void y(bool &mutex)
{
    mutex == 1;
}
int writer_count = 0;
// reader semaphore
int s = 2;
// writer semaphore
bool mutex = 1;
//bounded buffer

int my_grade = 0;

//TestAndSet Function
void testandset(int s)
{

    s = 0;
    cout << "set to 0" << endl;
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
        if (writer_count >= 1)
            break;
        else
            x(mutex);
        r1pc++;
        break;
    }
    case 3:
    {
        if (reader_count >= 2)
        {
            break;
        }
        else
            p(s);
        r1pc++;
        break;
    }
    case 4:
    {

        if (reader_count <= 2 || writer_count <= 0)
        {
            reader_count++;
            cout << "       Im reader 1 and there are " << reader_count << " readers and " << writer_count << " writers in the critical section. My Grade is " << my_grade << endl; //gives reader and writer count      cout<<"reader 1 im in the critical section and see my grade as "<<my_grade<<endl;

            r1pc++;
            break;
        }
    }
    case 5:
    {
        y(mutex);
        reader_count--;
        cout << "im reader 1 and im out of the critical section" << endl;
        r1pc++;
        break;
    }
    case 6:
    {
        p(s);
        ;
        cout << "r1 im done" << endl;
        for (int p = 0; p < 100; p++)
            ;
        r1pc = 0;
        break;
    }
    }
}
void r2()
{
    switch (r2pc)
    {
    case 0:
    {
        cout << "Im reader 2 and im in the non critical section" << endl;
        r2pc++;
        break;
    }
    case 1:
    {
        cout << "Im reader 2 trying to enter critical section" << endl;
        r2pc++;
        break;
    }
    case 2:
    {
        if (writer_count >= 1)
            break;
        else
            x(mutex);
        r2pc++;
        break;
    } //locks out all writers
    case 3:
    {
        if (reader_count >= 2)
            break;
        else
        {
            p(s);
            r2pc++;
            break;
        }
    } //void wait for reader, decrements the amount of readers able to go into the critical section
    case 4:
    {

        if (reader_count <= 2 || writer_count <= 0)
        {
            reader_count++;
            cout << "     Im reader 2 and there are " << reader_count << " readers and " << writer_count << " writers in the critical section" << endl; //gives reader and writer count
            cout << "reader 2 im in the critical section and see my grade as " << my_grade << endl;
            r2pc++;
            break;
        }
        else
        {
            break;
        }
    }
    case 5:
    {
        y(mutex);
        cout << "im reader 1 and im out of the critical section" << endl;
        r2pc++;
        break;
    }
    case 6:
    {
        p(s);
        cout << "r2 im done" << endl;
        reader_count--;
        for (int p = 0; p < 100; p++)
            ;
        r2pc = 0;
        break;
    }
    }
}
void r3()
{
    switch (r3pc)
    {
    case 0:
    {
        cout << "Im reader 3 and im in the non critical section" << endl;
        r3pc++;
        break;
    }
    case 1:
    {
        cout << "Im reader 3 trying to enter critical section" << endl;
        r3pc++;
        break;
    }
    case 2:
    {
        if (writer_count > 0)
            break;
        else
        {
            x(mutex);
            r3pc++;
            break;
        }
    } //locks out all writers
    case 3:
    {
        if (reader_count >= 2)
            break;
        else
        {
            p(s);
            r3pc++;
            break;
        }
    } //void wait for reader, decrements the amount of readers able to go into the critical section
    case 4:
    {

        if (reader_count <= 2 || writer_count <= 0)
        {
            reader_count++;
            cout << "     Im reader 3 and there are " << reader_count << " readers and " << writer_count << " writers in the critical section" << endl; //gives reader and writer count
            cout << "reader 3 im in the critical section and see my grade as " << my_grade << endl;
            r3pc++;
            break;
        }
        else
            break;
    }
    case 5:
    {
        y(mutex);
        cout << "im reader 3 and im out of the critical section" << endl;
        r3pc++;
        break;
    }
    case 6:
    {
        p(s);
        cout << "r3 im done" << endl;
        reader_count--;
        for (int p = 0; p < 100; p++)
            ;
        r3pc = 0;
        break;
    }
    }
}
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
        if (reader_count > 0)
            break;
        else
            w1pc++;
        break;
    }

    case 3:
    {
        while (reader_count > 0)
            break;
        testandset(s);

        w1pc++;
        break;
    }
    case 4:
    {
        if (writer_count >= 1)
        {
            break;
        }
        else
        {
            x(mutex);
            w1pc++;
            break;
        }
    }
    case 5:
    {
        if (writer_count <= 0 || reader_count <= 0)
        {
            writer_count++;
            cout << "im Writer 1      there are " << reader_count << " readers and " << writer_count << " writers in the critical section" << endl;
            my_grade = my_grade * 2;
            cout << "writer 1 in the critical section and changed grade to " << my_grade << endl;
            w1pc++;
            break;
        }
        else
            break;
    }
    case 6:
    {
        writer_count--;
        y(mutex);
        reset(s);
        cout << "wrtier 1 out of the critical section" << endl;
        w1pc++;
        break;
    }
    case 7:
    {
        cout << "w1 done" << endl;
        for (int p = 0; p < 100; p++)
            ;
        w1pc = 0;
        break;
    }
    }
}
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
        if (reader_count > 0)
            break;
        else
            w2pc = 4;
        break;
    }
    case 3:
    {
    case 4:
    {
        if (reader_count > 0)
            break;
        else
            testandset(s);
        w2pc++;
        break;
    }
    case 5:
    {
        if (writer_count >= 1)
        {
            break;
        }
        else
        {
            x(mutex);
            w2pc++;
            break;
        }
    }
    case 6:
    {

        if (writer_count <= 0 || reader_count <= 0)
        {
            writer_count++;
            cout << "Im writer 2     there are " << reader_count << " readers and " << writer_count << " writers in the critical section" << endl;
            my_grade = rand() % 100;
            cout << "writer 2 in the critical section and changed grade to " << my_grade << endl;
            w2pc++;
            break;
        }
        else
            break;
    }
    case 7:
    {
        writer_count--;
        y(mutex);
        reset(s);
        cout << "Writer 2 out of the critcial section" << endl;
        w2pc++;
        break;
    }
    case 8:
    {
        cout << "w2 done" << endl;
        for (int p = 0; p < 100; p++)
            ;
        w2pc = 0;
        break;
    }
    }
    }
}

int main()
{

    for (int i = 0; i <= 1000; i++)
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
