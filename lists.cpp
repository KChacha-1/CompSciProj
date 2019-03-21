#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next, *pre;
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
            delete head;//deletes pre which is head
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
        listisempty();
        
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
        listisempty();
        else if (head == tail)
        {
            delete head;
        }
        
    }
    void deletetail(int d)
    {
        if (head == NULL)           //in case list is empty and user tries to add to an empty list
        listisempty();
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
            listisempty(); //cout<<"List empty, add some values"<<endl; //why you try to break :(
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
            listisempty();
    
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
    void operator + (linkedlist &other)
    {
        node *tmp = this->tail;
       tmp->next = other.head;
       other.head = NULL;
        this->tail = other.tail;

    }
    void error()
    {
        cout<<"error"<<endl;
    }
    void listisempty()
    {
       cout<<"List is empty "<<endl;
    }
    
};


class doublelinkedlist
{   
    private:
    node *head, *tail;
    public:
    doublelinkedlist(){     //constructor for setting everything to NULL
        head = tail = NULL;
    }
    void addnodetohead(int d)     //creates the new node to add to the list
    {
        node *tmp = new node;
        tmp-> data = d;
        tmp-> next = NULL;
        tmp-> pre = NULL;
            if (head == NULL)
            {
                head = tmp;
                tail = tmp;
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
        tmp -> pre = tail;
        tail = tmp;
    }
    void addinbetween(int d)
    {
        if (head==NULL)
        {
            listisempty();
        }
        else
        {
            
        }
        
    }
    int count()// counts the nodes in the list
    {   
        if(head==NULL)
        {
            listisempty(); //cout<<"List empty, add some values"<<endl; //why you try to break :(
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
     void error()
    {
        cout<<"error"<<endl;
    }
    void listisempty()
    {
       cout<<"List is empty "<<endl;
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
    node *head, *tail, *pre;
    public:
    stack(){
        head = tail = pre= NULL;     //constructor for setting everything to NULL
    }
    void push(int d)     //creates the new node to add to the list
    {
        if(head=NULL)
        {
        node *tmp = new node;
        tmp-> data = d;
        tmp-> next = NULL;
        head= tmp;
        tail = tmp;
        pre = tmp;
        }
        else
       { 
        node *tmp = new node;
        tmp-> data = d;
        tmp-> next = NULL;
        tmp -> pre = tail;
        tail = tmp;
       }
    }
    void pop()
    {
        node *tmp = tail;
        tail->pre = tmp;
        delete tail;
        tmp = tail;
        
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
    a+b;
    cout<<"================================================="<<endl;
    a.printlist();
    stack x;
    x.push(3);
    x.push(4);
    x.push(6);
    x.push(8);

}
