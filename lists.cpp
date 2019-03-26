// Lists.cpp :So this is my project that i have complied originally on g++ however due to several issues, it works better using visual studio 2017. 
//If it does not properly work in g++ then please try using visual studio. 

#include "stdafx.h"
#include <iostream>
#include<fstream>
#include<ctime>
#include<string>
#include<fstream>
using namespace std;

struct node //used in every single data struct in this project
{
	int data;
	node *next, *pre;
};

struct deck //used for the deck function beacause the cards use string, probably should of changed the naming scheme, 
{
	string number;
	string suit;
	deck *next;
};

class linkedlist
{
private:
	node * head, *tail;
public:
	linkedlist() {           //constructor for setting everything to NULL
		head = tail = NULL;
	}
	~linkedlist()   //destructor
	{
		for (node *tmp = head; tmp != NULL;)
		{
			tmp = head->next; //goes to next
			delete head;//deletes pre which is head
			head = tmp;//next is head
		}
	}
	void addnode(int d)     //creates the new node to add to the list
	{
		node *tmp = new node;//creates new node
		tmp->data = d;
		tmp->next = NULL;
		if (head == NULL)
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
		node *tmp = new node;//creates new node
		tmp->data = d;
		tmp->next = NULL;
		if (head == NULL)//checks if the list has been initizalized
		{
			head = tmp;
			tail = tmp;
			tmp = NULL;
		}
	}
	void addnodetotail(int d)
	{
		if (head == NULL)//checks if the list has been initizalized           //in case list is empty and user tries to add to an empty list
			listisempty();

		else
		{
			node *tmp = new node;//creates new node // for(node *tmp = head; tmp!=NULL;) ||  tmp=tmp->next;
			tmp->data = d;
			tail->next = tmp;
			tail = tmp;
		}

	}
	void deletehead()//deletes head
	{
		if (head == NULL)//checks if the list has been initizalized           //in case list is empty and user tries to add to an empty list
			listisempty();
		else if (head == tail)
		{
			delete head;
			head = tail = NULL;
		}
		else {
			node *tmp = head->next;
			delete head;
			head = tmp;
		}

	}
	void deletetail()//deletes tail
	{
		if (head == NULL)//checks if the list has been initizalized           //in case list is empty and user tries to add to an empty list
			listisempty();
		else
		{
			node *tmp = head;
			while (tmp->next != tail)
			{
				tmp = tmp->next;
			}

			delete tail;
			tail = tmp;
			tmp->next = NULL;

		}
	}
	void deleteinbetween(int d) //deletes nodes based on a given value
	{
		if (head == NULL)//checks if the list has been initizalized
		{
			listisempty();
		}
		else
		{
			node *tmp = new node;//creates new node
			tmp->data = d;//passes the data from the function
			node *tmp2 = head;

			while (tmp2->next->data != tmp->data)
			{
				tmp2 = tmp2->next;
			}
			tmp = tmp2->next;


			tmp2->next = tmp->next;
			delete tmp;

		}
	}
	int count()// counts the nodes in the list
	{
		if (head == NULL)
		{
			listisempty(); //cout<<"List empty, add some values"<<endl; //why you try to break :(
		}
		else
		{
			node *tmp = head; //starts at the head 
			int length = 0; // the varible that holds the length value
			while (tmp != NULL)
			{
				length++;
				tmp = tmp->next;
			}
			return(length);
		}
	}
	void size() //shows the size and is called by other functions
	{
		int size = 0;
		size = count();
		cout << "size of list is " << size << endl;
	}
	void printlist() //prints list
	{
		if (head == NULL)
		{
			listisempty();
		}
		else
		{
			node *tmp = head;
			while (tmp != NULL)
			{
				cout << tmp->data << endl;
				tmp = tmp->next;
			}
		}
	}
	void ascendingsort()  //sorting algorithim least to greatest
	{
		for (int list = count(); list>0; list--)
		{
			node *tmp = head;
			node *tmp2 = tmp->next;

			while (tmp2 != NULL)
			{
				if (tmp->data >= tmp2->data)
				{
					swap(tmp->data, tmp2->data);
					//    tmp= tmp->next;
					//  tmp2=tmp2->next;
				}
				// else
				// {

				tmp = tmp->next;
				tmp2 = tmp2->next;
				//}

			}
		}
	}
	void descendingsort() //sorting algorithim greatest to least
	{
		for (int list = count(); list>0; list--)
		{
			node *tmp = head;
			node *tmp2 = tmp->next;

			while (tmp2 != NULL)
			{
				if (tmp->data <= tmp2->data)
				{
					swap(tmp->data, tmp2->data);
					//tmp= tmp->next; 
					//tmp2=tmp2->next;
				}
				// else
				//{

				tmp = tmp->next;
				tmp2 = tmp2->next;
				//}

			}
		}
	}
	void insertinbetween(int d) //inserting data in between the data based on position
	{
		if (head == NULL)
		{
			cout << "error" << endl;
		}
		else
		{
			node*tmp = head;
			node*tmp2 = tmp->next;
			node*tmp3 = new node;
			tmp3->data = d;
			int position = 0;
			int listlength = count();
			cout << "What position would you like to insert the node at?" << endl;
			cin >> position;
			cout << "=====================================================" << endl;
			if (position>listlength)
			{
				error();
			}
			else
			{
				for (position <= listlength; position != 2; position--)
				{
					tmp = tmp->next;
					tmp2 = tmp2->next;
					//position--;

				}
				tmp->next = tmp3;
				tmp3->next = tmp2;

			}

		}
	}
	void search(int d) //search function
	{
		pos(d);
		instances(d);

	}

	void pos(int d)  //position number
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
						cout << "Found in position " << pos;
					else
						cout << " and " << pos << endl;
				}
				tmp2 = tmp2->next;
				pos++;
			}
		}
	}
	void instances(int d) // function for printing instances the data appears 
	{
		if (head == NULL)
		{
			listisempty();
		}
		else
		{
			if (getinstance(d) == 1)
			{
				cout << "The value occurs once" << endl;
			}
			else
			{
				cout << "The value occurs " << getinstance(d) << " times " << endl;
			}
		}
	}
	int getinstance(int d) //number of instances
	{

		node *tmp = head;

		int itterator = 0;
		while (tmp != NULL)//&& tmp->data !=d)
		{
			if (tmp->data != d)
			{
				tmp = tmp->next;
			}
			else
			{
				itterator++;
				tmp = tmp->next;
			}
		}
		return (itterator);
	}
	void operator + (linkedlist &other) //combining 2 lists
	{
		node *tmp = this->tail;
		tmp->next = other.head;
		other.head = NULL;
		this->tail = other.tail;

	}
	void error() //error functiom  
	{
		cout << "error" << endl;
	}
	void listisempty() //lists empty funtion 
	{
		cout << "List is empty " << endl;
	}

	void emptylist()
	{
		node *tmp = head;
		while (tmp != NULL)
		{
			tmp = head->next; //goes to next
			delete head;//deletes pre which is head
			head = tmp;//next is head
		}

	}
	void randomizor()  //
	{
		//srand(time(NULL));
		for (int i = 0; i < 100; i++)
		{
			int random = rand() % 100;
			addnode(random);
		}
	}
};


class doublelinkedlist
{
private:
	node * head, *tail, *pre; //private member funtions, *side note: unsure why previous must be included but not next
public:
	doublelinkedlist() //initiates the list
	{
		head = tail = pre = NULL;
	}
	~doublelinkedlist()
	{
		for (node *tmp = head; tmp != NULL;)
		{
			tmp = head->next; //goes to next
			delete head;      //deletes pre which is head
			head = tmp;       //next is head
		}
	}
	void addnode(int d)
	{
		if (head == NULL)//checks if the list has been initizalized // creates the start of the list when theres no head
		{
			node *tmp = new node;//creates new node
			tmp->data = d;//passes the data from the function
			tmp->next = NULL;
			tmp->pre = NULL;
			head = tmp;
			tail = tmp;
		}
		else //when there is already a head
		{
			node *tmp = new node;//creates new node
			tmp->data = d;//passes the data from the function
			tmp->pre = tail;
			tail->next = tmp;
			tail = tmp;
			tmp->next = NULL;
		}
	}
	void addtohead(int d)
	{
		if (head == NULL)//checks if the list has been initizalized
		{
			listisempty();
		}
		else
		{
			node *tmp = new node;//creates new node
			tmp->data = d;//passes the data from the function
			head->pre = tmp;
			tmp->next = head;
			head = tmp;
		}
	}
	void addtotail(int d)
	{
		if (head == NULL)//checks if the list has been initizalized
		{
			listisempty();
		}
		else
		{
			node *tmp = new node;//creates new node
			tmp->data = d;//passes the data from the function
			tmp->pre = tail;
			tail->next = tmp;
			tail = tmp;
		}
	}

	void insertinbetween(int d)
	{
		if (head == NULL)//checks if the list has been initizalized
		{
			cout << "error" << endl;
		}
		else
		{
			node *tmp = head;
			node *tmp2 = tmp->next;
			node *tmp3 = new node;
			tmp3->data = d;
			int position = 0;
			int listlength = count();
			cout << "What position would you like to insert the node at?" << endl;
			cin >> position;
			cout << "=====================================================" << endl;
			if (position > listlength)
			{
				error();
			}
			else
			{
				for (position <= listlength; position != 2; position--)
				{
					tmp = tmp->next;
					tmp2 = tmp2->next;
					//position--;
				}
				tmp->next = tmp3;
				tmp3->next = tmp2;
			}
		}
	}
	void deletetail() //Returns 0 instead of removing completely
	{
		if (head == NULL)//checks if the list has been initizalized
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
	void deletehead()
	{
		if (head == NULL)//checks if the list has been initizalized
		{
			listisempty();
		}
		else
		{
			node *tmp = head;
			head = head->next;
			delete head->pre;
			head->pre = NULL;
		}
	}
	void ascendingsort()
	{
		for (int list = count(); list>0; list--)
		{
			node *tmp = head;
			node *tmp2 = tmp->next;

			while (tmp2 != NULL)
			{
				if (tmp->data >= tmp2->data)
				{
					swap(tmp->data, tmp2->data);
					//    tmp= tmp->next;
					//  tmp2=tmp2->next;
				}
				// else
				// {

				tmp = tmp->next;
				tmp2 = tmp2->next;
				//}

			}
		}
	}
	void descendingsort()
	{
		for (int list = count(); list>0; list--)
		{
			node *tmp = head;
			node *tmp2 = tmp->next;

			while (tmp2 != NULL)
			{
				if (tmp->data <= tmp2->data)
				{
					swap(tmp->data, tmp2->data);
					//tmp= tmp->next; 
					//tmp2=tmp2->next;
				}
				// else
				//{

				tmp = tmp->next;
				tmp2 = tmp2->next;
				//}

			}
		}
	}

	int count() // counts the nodes in the list
	{
		if (head == NULL)//checks if the list has been initizalized
		{
			listisempty(); //cout<<"List empty, add some values"<<endl; //why you try to break :(
		}
		else
		{
			node *tmp = head; //starts at the head
			int length = 0;   // the varible that holds the length value
			while (tmp != NULL)
			{
				length++;
				tmp = tmp->next;
			}
			return (length);
		}
	}
	void size() //uses the count function in order to get the size
	{
		int size = 0;
		size = count();
		cout << "size of list is " << size << endl;
	}
	void printlist()
	{
		if (head == NULL)
		{
			listisempty();
		}
		else {


			node *tmp = head;
			while (tmp->next != NULL)
			{
				cout << tmp->data << endl;
				tmp = tmp->next;
			}
		}
	}
	void error() // a base error used during early development of the project , probably the most used function.
	{
		cout << "error" << endl;
	}
	void listisempty() //list is empty 
	{
		cout << "List is empty " << endl;
	}
	void search(int d) //search using 2 functions. may be a bit bugged
	{
		pos(d);
		instances(d);
	}

	void pos(int d) //shows the positions that the data was found in
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
						cout << "Found in position " << pos;
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
		if (head == NULL)//checks if the list has been initizalized
		{
			listisempty();
		}
		else
		{
			node *tmp = head;
			//int listsize = count();
			int itterator = 0;
			while (tmp != NULL) //&& tmp->data !=d)
			{
				if (tmp->data != d)
				{
					tmp = tmp->next;
				}
				else
				{
					itterator++;
					tmp = tmp->next;
				}
			}
			//itterator = listsize-itterator;
			//while(tmp!=NULL && tmp->data = d)
			//{

			//        tmp= tmp->next;
			//        itterator++;

			//}
			cout << "The value occurs " << itterator << " times " << endl;
		}
	}
	int getinstance(int d)
	{

		node *tmp = head;

		int itterator = 0;
		while (tmp != NULL) //&& tmp->data !=d)
		{
			if (tmp->data != d)
			{
				tmp = tmp->next;
			}
			else
			{
				itterator++;
				tmp = tmp->next;
			}
		}
		return (itterator);
	}
	void emptylist()
	{
		node *tmp = head;
		while (tmp != NULL)
		{
			tmp = head->next; //goes to next
			delete head;//deletes pre which is head
			head = tmp;//next is head
		}

	}
	void randomizor() //create 100 random nodes 
	{
		//srand(time(0)+1); supposed to create a seed;
		for (int i = 0; i < 100; i++)
		{
			int random = rand() % 100;
			addnode(random);
		}
	}

};

class circularlinkedlist
{
private:
	node * tail;

public:
	circularlinkedlist()
	{ //constructor for setting everything to NULL
		tail = NULL;
	}
	~circularlinkedlist()
	{
		node *tmp = tail->next;
		while (tmp != tail)
		{
			//tmp = tail->next;



		}
		delete tail;

	}
	void addnode(int d) //creates the new node to add to the list and add to tail
	{
		if (tail == NULL)
		{
			node *tmp = new node;
			tmp->data = d;
			tail = tmp;

			tmp->next = tail;
		}
		else
		{
			node *tmp = new node;
			tmp->data = d;
			tmp->next = tail->next;
			tail->next = tmp;
			tail = tmp;
		}
	}
	void addtofront(int d)
	{
		if (tail == NULL)
		{
			listisempty();
		}
		else
		{
			node *tmp = new node;
			tmp->data = d;
			tmp->next = tail->next;
			tail->next = tmp;
		}
	}
	void addinbetween(int d)
	{
		if (tail == NULL)
		{
			listisempty();
		}
		else
		{
			node *tmp = tail->next;
			node *tmp2 = tmp->next;
			node *tmp3 = new node;
			tmp3->data = d;
			int position = 1;
			int listlength = count();
			cout << "What position would you like to insert the node at?" << endl;
			cin >> position;
			cout << "=====================================================" << endl;
			if (position > listlength)
			{
				error();
			}
			else
			{
				for (position <= listlength; position != 2; position--)
				{
					tmp = tmp->next;
					tmp2 = tmp2->next;
					//position--;
				}
				tmp->next = tmp3;
				tmp3->next = tmp2;
			}
		}

	}
	int count() // counts the nodes in the list
	{
		if (tail == NULL)//checks if the list has been initizalized
		{
			listisempty(); //cout<<"List empty, add some values"<<endl; //why you try to break :(
		}
		else
		{
			node *tmp = tail->next; //starts at the head
			int length = 1;   // the varible that holds the length value
			while (tmp != tail)
			{
				length++;
				tmp = tmp->next;
			}
			return (length);
		}
	}
	void size() //uses the count function in order to get the size
	{
		int size = 0;
		size = count();
		cout << "size of list is " << size << endl;
	}

	void deletetail(int d) //delete a specific known data value
	{
		if (tail == NULL)
		{
			listisempty();
		}
		else
		{
			node *tmp = new node;//creates new node
			tmp->data = d;//passes the data from the function
			node *tmp2 = tail->next;

			while (tmp2->next->data != tmp->data)
			{
				tmp2 = tmp2->next;
			}
			tmp = tmp2->next;


			tmp2->next = tmp->next;
			delete tmp;

		}
	}

	void printlist() //prints lists 
	{
		if (tail == NULL)
		{
			listisempty();
		}
		else
		{
			node *tmp = tail->next;
			while (tmp != tail && tmp!=NULL)
			{
				cout << tmp->data << endl;
				tmp = tmp->next;
			}
			
				cout << tmp->data << endl;
			
			
		}
	}

	void deletenode(int d) //deletes nodes based on data 
	{
		if (tail == NULL)
		{
			listisempty();
		}

		else
		{
			node *tmp = new node;
			tmp->data = d;
			node *tmp2 = tail->next;
			while (tmp2 != tail) //tmp2->data != tmp->data && tmp2->next !=tail)
			{
				if (tmp2->next->data = tmp->data)
				{
					tmp2->next = tmp->next;
					delete tmp;

				}
				tmp2 = tmp2->next;
			}
		}
	}
	void error()// base errors
	{
		cout << "error" << endl;
	}
	void listisempty() //list empty 
	{
		cout << "List is empty " << endl;
	}
	void randomizor()  //randomizes data for 100 nodes
	{
		srand(time(NULL));
		for (int i = 0; i < 100; i++)
		{
			int random = rand() % 100;
			addnode(random);
		}
	}
	void search(int d) //search function
	{
		pos(d);
		instances(d);

	}

	void pos(int d)  //position number
	{
		int instances = getinstance(d);

		if (instances <= 0)
		{
			cout << "data not found in list" << endl;
		}
		else if (instances == 1)
		{
			node *tmp2 = tail->next;
			int pos = 1;

			while (tmp2 != tail && tmp2->data != d)
			{
				tmp2 = tmp2->next;
				pos++;
			}
			cout << "data found in list position " << pos << endl;
		}
		else
		{
			node *tmp2 = tail->next;
			int pos = 1;

			while (tmp2 != tail && instances != 0)
			{
				if (tmp2->data == d)
				{
					instances--;
					if (instances > 0)
						cout << "Found in position " << pos;
					else
						cout << " and " << pos << endl;
				}
				tmp2 = tmp2->next;
				pos++;
			}
		}
	}
	void instances(int d) // function for printing instances the data appears 
	{
		if (tail == NULL)
		{
			listisempty();
		}
		else
		{
			if (getinstance(d) == 1)
			{
				cout << "The value occurs once" << endl;
			}
			else
			{
				cout << "The value occurs " << getinstance(d) << " times " << endl;
			}
		}
	}
	int getinstance(int d) //number of instances
	{

		node *tmp = tail->next;

		int itterator = 0;
		while (tmp != tail)//&& tmp->data !=d)
		{
			if (tmp->data != d)
			{
				tmp = tmp->next;
			}
			else
			{
				itterator++;
				tmp = tmp->next;
			}
		}
		return (itterator);
	}
	void descendingsort() //sorting algorithim greatest to least
	{
		for (int list = count(); list>0; list--)
		{
			node *tmp = tail->next;
			node *tmp2 = tmp->next;

			while (tmp2 != tail->next)
			{
				if (tmp->data <= tmp2->data)
				{
					swap(tmp->data, tmp2->data);
					//tmp= tmp->next; 
					//tmp2=tmp2->next;
				}
				// else
				//{

				tmp = tmp->next;
				tmp2 = tmp2->next;
				//}

			}
		}
	}
	void ascendingsort()  //sorting algorithim least to greatest
	{
		for (int list = count(); list>0; list--)
		{
			node *tmp = tail->next;
			node *tmp2 = tmp->next;

			while (tmp2 != tail->next)
			{
				if (tmp->data >= tmp2->data)
				{
					swap(tmp->data, tmp2->data);
					//    tmp= tmp->next;
					//  tmp2=tmp2->next;
				}
				// else
				// {

				tmp = tmp->next;
				tmp2 = tmp2->next;
				//}

			}
		}
	}
	void emptylist()
	{
		if (tail == NULL)
		{
			listisempty();

		}
		else
		{
			node *tmp = tail->next;
			while (tmp != tail)
			{
				tail->next = tmp->next;
				delete tmp;
				tmp = tail->next;
			}
			//tmp = tail;
			delete tmp;
			//tmp->next = NULL;


		}
	}
};

class stack
{
private:
	node * head, *tail;
public:
	stack() {
		head = tail = NULL;     //constructor for setting everything to NULL
	}
	void push(int d)     //creates the new node to add to the list
	{
		node *tmp = new node;//creates new node
		tmp->data = d;
		tmp->next = NULL;
		if (head == NULL)
		{
			head = tmp;
			tail = tmp;
			tmp->next = NULL;
		}
		else
		{
			tail->next = tmp;
			tail = tmp;
			tmp->next = NULL;
		}
	}
	void pop()
	{
		node *tmp = head;
		while (tmp->next != tail)
		{
			tmp = tmp->next;
		}

		delete tail;
		tail = tmp;
		tmp->next = NULL;

	}
	int count()// counts the nodes in the list
	{
		if (head == NULL)
		{
			listisempty(); //cout<<"List empty, add some values"<<endl; //why you try to break :(
		}
		else
		{
			node *tmp = head; //starts at the head 
			int length = 0; // the varible that holds the length value
			while (tmp != NULL)
			{
				length++;
				tmp = tmp->next;
			}
			return(length);
		}
	}
	void size()
	{
		int size = 0;
		size = count();
		cout << "size of list is " << size << endl;
	}
	void ascendingsort()
	{
		for (int list = count(); list>0; list--)
		{
			node *tmp = head;
			node *tmp2 = tmp->next;

			while (tmp2 != NULL)
			{
				if (tmp->data >= tmp2->data)
				{
					swap(tmp->data, tmp2->data);
					//    tmp= tmp->next;
					//  tmp2=tmp2->next;
				}
				// else
				// {

				tmp = tmp->next;
				tmp2 = tmp2->next;
				//}

			}
		}
	}
	void descendingsort()
	{
		for (int list = count(); list>0; list--)
		{
			node *tmp = head;
			node *tmp2 = tmp->next;

			while (tmp2 != NULL)
			{
				if (tmp->data <= tmp2->data)
				{
					swap(tmp->data, tmp2->data);
					//tmp= tmp->next; 
					//tmp2=tmp2->next;
				}
				// else
				//{

				tmp = tmp->next;
				tmp2 = tmp2->next;
				//}

			}
		}
	}
	void printlist()
	{
		node *tmp = head;
		while (tmp != NULL)
		{
			cout << tmp->data << endl;
			tmp = tmp->next;
		}
	}
	void error()
	{
		cout << "error" << endl;
	}
	void listisempty()
	{
		cout << "List is empty " << endl;
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
						cout << "Found in position " << pos;
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
		if (head == NULL)
		{
			listisempty();

		}
		else
		{
			if (getinstance(d) == 1)
			{
				cout << "The value occurs once" << endl;
			}
			else
			{
				cout << "The value occurs " << getinstance(d) << " times " << endl;
			}
		}
	}
	int getinstance(int d)
	{

		node *tmp = head;

		int itterator = 0;
		while (tmp != NULL)//&& tmp->data !=d)
		{
			if (tmp->data != d)
			{
				tmp = tmp->next;
			}
			else
			{
				itterator++;
				tmp = tmp->next;
			}
		}
		return (itterator);
	}
	// void addstring()
	// {
	//     string a = "diamond";
	//     node *tmp = new node;
	//     tmp->data = stoi(a);
	//      tail->next = tmp;
	//         tail = tmp;
	//         tmp->next=NULL;
	// }
	void randomizor()  //
	{
		//srand(time(NULL));
		for (int i = 0; i < 100; i++)
		{
			int random = rand() % 100;
			push(random);
		}
	}
	void top()
	{
		if (head == NULL)
		{
			listisempty();

		}
		else
		{
			node *tmp = new node;
			tmp = head;
			cout << tmp->data << " Is the head value. " << endl;
		}
	}

};
class cards // stack based deck 
{
private:
	deck * head, *tail;
public:
	cards()
	{
		head = tail = NULL;
	}

	void addcard()
	{
		string a[4] = { "Spades", "Clubs", "Diamonds", "Hearts" };
		string b[13] = { "Ace", "Two", "Three", "Four", "Five", "Six", "Seven",
			"Eight", "Nine", "Ten", "Jack", "Queen", "King" };

		for (int i = 1; i <= 1; i++)
		{
			for (int h = 0; h < 4; h++)
			{
				for (int j = 0; j < 13; j++)
				{
					deck *card = new deck;
					card->number = a[h];
					card->suit = b[j];
					if (head == NULL)
					{
						head = card;
						tail = card;
						card->next = NULL;
					}
					else
					{
						tail->next = card;
						tail = card;
						card->next = NULL;
					}
				}
			}
		}
	}
	void shuffle() //shuffles around the deck
	{
		string a[4] = { "Spades", "Clubs", "Diamonds", "Hearts" };
		string b[13] = { "Ace", "Two", "Three", "Four", "Five", "Six", "Seven",
			"Eight", "Nine", "Ten", "Jack", "Queen", "King" };

		for (int i = 0; i <= 52; i++)
		{
			int h = rand() % 4;
			int j = rand() % 13;

			deck *card = new deck;
			card->number = a[h];
			card->suit = b[j];
			if (head == NULL)
			{
				head = card;
				tail = card;
				card->next = NULL;
			}
			else
			{
				tail->next = card;
				tail = card;
				card->next = NULL;
			}


		}
	}

	void printlist()
	{
		deck *card = new deck;
		card = head;
		while (card != NULL)
		{
			cout << card->number << card->suit << endl;
			card = card->next;
		}
	}
};

class queue
{
private:
	node * head, *tail;

public:
	queue() {    //constructor for setting everything to NULL
		head = tail = NULL;
	}
	void enqueue(int d)     //creates the new node to add to the list
	{
		if (head == NULL)
		{
			node *tmp = new node;//creates new node
			tmp->data = d;
			head = tmp;
			tail = tmp;
			tmp->next = NULL;
		}
		else
		{
			node *tmp = new node; //creates new node
			tmp->data = d;
			tail->next = tmp;
			tail = tmp;
		}
	}
	void dequeue()
	{
		if (head == NULL)//checks if the list has been initizalized           //in case list is empty and user tries to add to an empty list
		{
			listisempty();
		}
		else if (head == tail)
		{
			delete head;
			head = tail = NULL;
		}
		else {
			node *tmp = head->next;
			delete head;
			head = tmp;
		}
	}
	void error() //base errors
	{
		cout << "error" << endl;
	}
	void listisempty() //list empty error
	{
		cout << "List is empty " << endl;
	}
	void search(int d) //unififed search function calling 2 other functions
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

					instances--;
				if (instances > 0)
					cout << "Found in position " << pos;
				else
					cout << " and " << pos << endl;
			}
			tmp2 = tmp2->next;
			pos++;
		}
	}

	void instances(int d)
	{
		if (head == NULL)
		{
			listisempty();

		}
		else
		{
			if (getinstance(d) == 1)
			{
				cout << "The value occurs once" << endl;
			}
			else
			{
				cout << "The value occurs " << getinstance(d) << " times " << endl;
			}
		}
	}
	int getinstance(int d)
	{

		node *tmp = head;

		int itterator = 0;
		while (tmp != NULL)//&& tmp->data !=d)
		{
			if (tmp->data != d)
			{
				tmp = tmp->next;
			}
			else
			{
				itterator++;
				tmp = tmp->next;
			}
		}
		return (itterator);
	}
	void printlist()
	{
		if (head == NULL)
		{
			listisempty();
		}
		else
		{
			node *tmp = head;
			while (tmp != NULL)
			{
				cout << tmp->data << endl;
				tmp = tmp->next;
			}
		}
	}
	void randomizor() //create 100 random nodes 
	{
		//srand(time(0)+1); supposed to create a seed;
		for (int i = 0; i < 100; i++)
		{
			int random = rand() % 100;
			enqueue(random);
		}
	}
	void front()
	{
		if (head == NULL)
		{
			listisempty();

		}
		else
		{
			node *tmp = new node;
			tmp = head;
			cout << tmp->data << " is the value of the front" << endl;
		}
	}
	void back()
	{
		if (head == NULL)
		{
			listisempty();

		}
		else
		{
			node*tmp = new node;
			tmp = tail;
			cout << tmp->data << " is the value of the back" << endl;
		}
	}

};

int main()
{


	//cout << "==============START=========================" << endl;
	//cards a;
	//a.addcard();
	//a.printlist();
	//cout << "=======================================" << endl;
	//a.shuffle();
	//a.printlist();
	//cout << "=================Cards END======================" << endl;
	//linkedlist k;
	//k.randomizor();
	//k.printlist();
	//cout << "=======================================" << endl;
	//k.ascendingsort();
	//k.printlist();
	//cout << "=======================================" << endl;
	//k.emptylist();
	//k.printlist();
	//cout << "=================Linked List END======================" << endl;
	//
	//doublelinkedlist c;
	//c.randomizor();
	//c.printlist();
	//cout << "=======================================" << endl;
	//c.descendingsort();
	//c.printlist();
	//cout << "=======================================" << endl;
	//c.ascendingsort();
	//c.printlist();
	//cout << "=======================================" << endl;
	//c.emptylist();
	//c.printlist();
	//
	//cout << "=================Double Linked list END======================" << endl;
	//
	//circularlinkedlist f;
	//f.randomizor();
	//f.printlist();
	//cout << "=======================================" << endl;
	//f.descendingsort();
	//f.printlist();
	//cout << "=======================================" << endl;
	//f.ascendingsort();
	//f.printlist();
	//cout << "=======================================" << endl;
	//f.emptylist();
	//f.printlist();
	string x;
	ifstream infile;
	infile.open("cat.txt");
	infile >> x;
	cout << x << endl;
	system("pause");

}