#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next, *prev;
};

class linkedlist 
{
    private:
    node *head, *tail;
    public:
    linkedlist(){           //constructor for setting everything to NULL
        head = tail = NULL;
    }
     ~linkedlist()   //destructor
    {
        for (node *tmp = head; tmp!=NULL;)
        {
            tmp= head->next; //goes to next
            delete head;//deletes prev which is head
            head=tmp;//next is head
        }
    }
    void addnode(int d)     //creates the new node to add to the list
    {
        node *tmp = new node;
        tmp-> data = d;
        tmp-> next = NULL;
            if (head==NULL)
            {
                head = tmp;
                tail = tmp;
                tmp = NULL;
            }
        else
        {
            tail->next = tmp;
            tail = tmp;
        }
        
        
    }
    void addnodetohead(int d)     //creates the new node to add to the list
    {
        node *tmp = new node;
        tmp-> data = d;
        tmp-> next = NULL;
            if (head == NULL)
            {
                head = tmp;
                tail = tmp;
                tmp = NULL;
            }
    }
    void addnodetotail(int d)
    {   
        if (head == NULL)           //in case list is empty and user tries to add to an empty list
        listempty();
        
        else
        {
            node *tmp = new node; // for(node *tmp = head; tmp!=NULL;) ||  tmp=tmp->next;
            tmp->data= d;
            tail->next=tmp;
            tmp=tail;
        }

    }
    void deletenode(int d)
    {
        if (head == NULL)           //in case list is empty and user tries to add to an empty list
        listempty();
        else if (head == tail)
        {
            delete head;
        }
        
    }
    void deletetail(int d)
    {
        if (head == NULL)           //in case list is empty and user tries to add to an empty list
        listempty();
        else
        {
            node *tmp = head;
         if (tmp->next!=tail)
                tmp ->next;
         if (tmp->next =tail)
            {
                delete tail;
                tmp = tail;
            }
        }
    }
    int count()// counts the nodes in the list
    {   
        if(head==NULL)
        {
            listempty(); //cout<<"List empty, add some values"<<endl; //why you try to break :(
        }
        else
        {
            node *tmp = head; //starts at the head 
            int length = 0; // the varible that holds the length value
            while(tmp!=NULL)
            {
                length++;
                tmp= tmp->next;
            }
            return(length);
        }
    }
    void size()
    {   int size = 0;
        size = count();
        cout<<"size of list is "<<size<<endl;
    }    
    void printlist()
    {
        node *tmp = head;
        while(tmp != NULL)
        {
            cout<<tmp->data<<endl;
            tmp=tmp->next;
        }
    }
    void ascendingsort()
    {  for (int list = count(); list>0; list--)
      {
        node *tmp = head;
        node *tmp2 = tmp->next;
       
       while (tmp2!=NULL)
       {    
           if(tmp->data>=tmp2->data)
           {
               swap(tmp->data, tmp2->data);
           //    tmp= tmp->next;
             //  tmp2=tmp2->next;
           }
          // else
          // {
              
              tmp=tmp->next;
              tmp2=tmp2->next;
           //}
           
       }
    }
    }
    void descendingsort()
    {  for (int list = count(); list>0; list--)
      {
        node *tmp = head;
        node *tmp2 = tmp->next;
       
       while (tmp2!=NULL)
       {    
           if(tmp->data<=tmp2->data)
           {
               swap(tmp->data, tmp2->data);
               //tmp= tmp->next; 
               //tmp2=tmp2->next;
           }
          // else
           //{
              
              tmp=tmp->next;
              tmp2=tmp2->next;
           //}
           
       }
    }
    }
    void insertinbetween(int d)
    {   
        if(head==NULL)
        {
            cout<<"error"<<endl;
        }
        else
        {
            node*tmp= head;
            node*tmp2=tmp->next;
            node*tmp3=new node;
            tmp3->data = d;
            int position = 0;
            int listlength = count();
            cout<<"What position would you like to insert the node at?"<<endl;
            cin>>position;
            cout<<"====================================================="<<endl;
                if(position>listlength)
                {
                    error();
                }
                else
                {
                        for (position<=listlength; position!=2 ; position--)
                        {   
                                tmp = tmp->next;
                                tmp2 = tmp2->next;
                                //position--;
                            
                        }
                   tmp->next =tmp3;
                   tmp3->next = tmp2;
            
        }
            
        }
    }
    void search(int d)
    {   
        pos(d);
        instances(d);
        
    }

    void pos(int d)
    {
        int instances = getinstance(d);

        if (instances <= 0)
        {
            cout << "data not found in list" << endl;
        }
        else if (instances == 1)
        {
            node *tmp2 = head;
            int pos = 1;

            while (tmp2 != NULL && tmp2->data != d)
            {
                tmp2 = tmp2->next;
                pos++;
            }
            cout << "data found in list position " << pos << endl;
        }
        else
        {
            node *tmp2 = head;
            int pos = 1;

            while (tmp2 != NULL && instances != 0)
            {
                if (tmp2->data == d)
                {
                    instances--;
                    if (instances > 0)
                        cout << "Found in position "<<pos;
                    else
                        cout << " and " << pos << endl;
                }
                tmp2 = tmp2->next;
                pos++;
            }
        }
    }
    void instances(int d)
    {
        if(head==NULL)
        {
            listempty();
        }
        else
        {
            node *tmp = head;
            //int listsize = count();
            int itterator = 0;
            while (tmp!=NULL )//&& tmp->data !=d)
            {   if(tmp->data !=d)
                {
                tmp = tmp->next;
                }
                else
                {
                   itterator++;
                   tmp=tmp->next;
                }
                
            }
            //itterator = listsize-itterator;
            //while(tmp!=NULL && tmp->data = d)
            //{   
                 
                    
            //        tmp= tmp->next;
            //        itterator++;
                
            //}
            cout<<"The value occurs "<< itterator << " times "<<endl;
        }
    }
    int getinstance(int d)
    {
        
            node *tmp = head;
            //int listsize = count();
            int itterator = 0;
            while (tmp!=NULL )//&& tmp->data !=d)
            {   if(tmp->data !=d)
                {
                tmp = tmp->next;
                }
                else
                {
                   itterator++;
                   tmp=tmp->next;
                }
            }
        return (itterator);
    }
    void error()
    {
        cout<<"error"<<endl;
    }
    void listempty()
    {
       cout<<"List is empty "<<endl;
    }
    friend linkedlist operator+(const linkedlist& x , const linkedlist& y)
    {
       
    }
};
linkedlist operator+(const linkedlist& x , const linkedlist& y)
{
    return linkedlist(x + y);
}


class doublelinkedlist
{   
    private:
    node *head, *tail, *prev;
    public:
    doublelinkedlist(){     //constructor for setting everything to NULL
        head = tail = prev = NULL;
    }
    void addnodetohead(int d)     //creates the new node to add to the list
    {
        node *tmp = new node;
        tmp-> data = d;
        tmp-> next = NULL;
            if (head == NULL)
            {
                head = tmp;
                tail = tmp;
                prev = tmp;
                tmp = NULL;
            }
         
    }
    void addnodetotail(int d)
    {   
        if (tail == NULL)
        {
            cout<<"Error, List does not exist or is empty"<<endl;
        }
        node *tmp = new node;
        tmp -> next = NULL;
        tmp -> prev = tail;
        tail = tmp;
    }
};

class circularlinkedlist
{
    private:
    node *head;
    public:
    circularlinkedlist(){    //constructor for setting everything to NULL
    head = NULL;
    }
    void addnode(int d)     //creates the new node to add to the list
    {
        node *tmp = new node;
        tmp-> data = d;
        tmp-> next = NULL;
    }
};

class stack
{ 
    private:
    node *head, *tail;
    public:
    stack(){
        head = tail = NULL;     //constructor for setting everything to NULL
    }
    void addnode(int d)     //creates the new node to add to the list
    {
        node *tmp = new node;
        tmp-> data = d;
        tmp-> next = NULL;
    }
};

class queue
{
    private:
    node *head, *tail;
    public:
    queue(){    //constructor for setting everything to NULL
        head = tail = NULL;
    }
    void addnode(int d)     //creates the new node to add to the list
    {
        node *tmp = new node;
        tmp-> data = d;
        tmp-> next = NULL;
    }
};


int main()
{
    linkedlist a;
    a.addnode(100);
    a.addnode(45);
    a.addnode(123);
    a.addnode(99);
    a.addnode(77);
    a.addnode(123);
    a.addnode(2);
    a.count();
    a.printlist();
    a.size();
    //a.insertinbetween(34);
    //a.count();
    //a.printlist();
    //a.size();
    a.pos(123);
    a.ascendingsort();
    a.printlist();
    //a.instances(123);
    linkedlist b;
    b.addnode(33);
    b.addnode(45);
    b.addnode(65);
    b.addnode(87);
    linkedlist c;
    c= a+b;
    c.printlist();
}