#include <iostream>
using namespace std;
 struct node
 {
     int data;
     node *next;
     node *pre;

 };

 class dllist
 {
     private:
     node *head, *tail, *pre; //private member funtions, *side note: unsure why previous must be included but not next
     public:
     dllist() //initiates the list 
     {
         head = tail = pre = NULL;
     }
     ~dllist()
     {
         for (node *tmp = head; tmp!=NULL;)
        {
            tmp= head->next; //goes to next
            delete head;//deletes pre which is head
            head=tmp;//next is head
        }
     }
     void addnode(int d)
     {  
         if(head == NULL) // creates the start of the list when theres no head
        {
         node *tmp = new node;
         tmp->data = d;
         tmp->next = NULL;
         tmp->pre = NULL;
         head = tmp;
         tail = tmp;          
        }
        else //when there is already a head
        {
        node *tmp = new node;
        tmp->data = d;
        tmp->pre = tail;
        tail->next = tmp;
        tail = tmp;
        }
        
     }
     void addtohead(int d)
     {
         if (head==NULL)
         {
             listisempty();
         }
         else
         {
             node *tmp = new node;
             tmp->data = d;
             head->pre = tmp;
             tmp->next = head;
             head = tmp;
         }
         
     }
     void addtotail(int d)
     {
         if (head==NULL)
         {
             listisempty();
            
         }
         else
         {
             node *tmp = new node;
             tmp->data = d;
             tmp->pre = tail;
             tail->next = tmp;
             tail = tmp;
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
    void deletetail()   //Returns 0 instead of removing completely
    {
        if (head==NULL)
        {
            listisempty();

        }
        else
        {
            node *tmp = tail;
            tail = tail->pre;
            delete tail->next;
            tail->next = NULL;
           

            
            
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
    void size()  //uses the count function in order to get the size
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
     void error()
    {
        cout<<"error"<<endl;
    }
    void listisempty()
    {
       cout<<"List is empty "<<endl;
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
 };
 int main()
 {
     dllist a;
     a.addnode(3);
     a.addnode(6);
     a.addnode(2);
     a.addnode(43);
     a.addnode(54);
     a.addnode(88);
     a.addtohead(55);
     //a.insertinbetween(34);
    
     a.printlist();
      cout<<"=================="<<endl;
     a.deletetail();
     a.printlist();
 }