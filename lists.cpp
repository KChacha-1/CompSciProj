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
        cout<<"List is empty is empty"<<endl;
        
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
        cout<<"List is empty is empty"<<endl;
        else if (head == tail)
        {
            delete head;
        }
        
    }
    void deletetail(int d)
    {
        if (head == NULL)           //in case list is empty and user tries to add to an empty list
        cout<<"List is empty is empty"<<endl;
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
            //cout<<"List empty, add some values"<<endl; //why you try to break :(
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
               tmp= tmp->next;
               tmp2=tmp2->next;
           }
           else
           {
              
              tmp=tmp->next;
              tmp2=tmp2->next;
           }
           
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
               tmp= tmp->next;
               tmp2=tmp2->next;
           }
           else
           {
              
              tmp=tmp->next;
              tmp2=tmp2->next;
           }
           
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
                    cout<<"error"<<endl;
                }
                else
                {
                        while(position!=0 && tmp2!=NULL)//for (position<=listlength; position>0 ; position--)
                        {   
                            
                                tmp2= tmp2->next;
                                position--;
                            
                        }
                   // tmp=tmp2;
                    tmp2->next= tmp3;
                    tmp3->next=tmp;
            
        }
            
        }
    }
};

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
    a.insertinbetween(34);
    a.count();
    a.printlist();
    a.size();
    
    
    
   
    
}