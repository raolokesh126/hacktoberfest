//program of Singly linked list
#include<iostream>
using namespace std;
class Node
{
	public:
	int info;//data part of node
	Node *next;//address part of node, which is used to store address of next Node
	Node(int value)
	{
		info=value;
		next=NULL;
	}
};
class LinkedList
{
	public:
	Node *start;//this is used to store address of first node always
	LinkedList()
	{
		start=NULL;
	}
	void create_LinkedList();
	void displayList();//thi is used for traversing the linked list
	void add_In_Begining();
	void add_AtTheEnd();
	void add_AtTheSpecifiedPosition(int val, int pos);
	void delete_FromBegining();
	void delete_FromEnd();
	void delete_SpecifiedNode(int nodeNumer);
	int countNode();
};
void LinkedList::create_LinkedList()
{
	Node *temp;
	temp=start;
	int value;
	cout<<"\n enter value of Newnode: ";
	cin>>value;
	Node *Newnode=new Node(value);//this instr. will create new node
	if(start==NULL)
	{
		start=Newnode;//address of first Node stored in the start
	}
	else
	{
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}

		temp->next=Newnode;
	}
	cout<<"\n Newnode has been added at the end of the list";
}
void LinkedList::displayList()
{
	Node *temp=start;
	if(start==NULL)
	{
		cout<<"\n Linked list is empty, there is no Node";
	}
	else
	{
	    cout<<"\n elements in the list are as follows:\n";
		while(temp!=NULL)
		{
		cout<<temp->info<<"\t";
		temp=temp->next;
		}
	}

}
int LinkedList::countNode()
{
	Node *temp=start;
	int count=0;
	while(temp!=NULL)
	{
		temp=temp->next;
		count++;
	}
	return count;
}
void LinkedList::add_In_Begining()
{
	int value;
	cout<<"\n enter value of new node :";
	cin>>value;
	Node *Newnode= new Node(value);
	Newnode->next=start;
	start=Newnode;
	cout<<"\n Newnode has been added at the begining of the list";
}
void LinkedList::add_AtTheEnd()
{
	Node *temp;
	temp=start;
	int value;
	cout<<"\n enter value of Newnode: ";
	cin>>value;
	Node *Newnode=new Node(value);//this instr. will create new node
	if(start==NULL)
	{
		start=Newnode;
	}
	else
	{
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}

		temp->next=Newnode;
	}
	cout<<"\n Newnode has been added at end of the list";
}
void LinkedList::add_AtTheSpecifiedPosition(int val, int pos)
{
	Node *temp=start;
	Node *Newnode=new Node(val);
	int count=countNode();
	if(pos>count)
	{
		cout<<"\n this is the invalid position to insert the node";
	}
	else
	{
		if(start==NULL)
		{
			start=Newnode;
		}
		else if(pos==0)
		{
			Newnode->next=start;
			start=Newnode;
		}
		else
		{
			for(int i=1;i<pos;i++)
			{
				temp=temp->next;
			}
			Newnode->next=temp->next;
			temp->next=Newnode;
		}
		if(pos==0)
		{
			cout<<"\n Newnode has been added in the begining of list as 1st node ";
		}
		else
		{
			cout<<"\n Newnode has been added after node"<<pos;
		}
	}

}
void LinkedList::delete_FromBegining()
{
	Node *temp=start;
	int data;
	if(start==NULL)
	{
		cout<<"\n list is empty, there is no Node to delete";
	}
	else
	{
		start=start->next;//or start=temp->next;
		data=temp->info;
		delete(temp);
		cout<<"\n"<<data<<" has been deleted,";
		cout<<"\n after deletion";
		displayList();
	}
}
void LinkedList::delete_FromEnd()
{
	Node *temp;
	Node *temp1;
	int data;
	if(start==NULL)
	{
		cout<<"\n list is empty, there is no Node to delete";
	}
	else if(start->next==NULL)//this is the first node as well as last
	{
		temp=start;
		start=NULL;
		data=temp->info;
		delete(temp);//the only node in the list has been deleted.
		cout<<"\n"<<data<<" has been deleted";
		cout<<"\n after deletion";
		displayList();
	}
	else
	{
		temp=start;
		while(temp->next->next!=NULL)
		{
			temp=temp->next;
		}
		temp1=temp->next;//address of last node stored in temp1.
		data=temp1->info;
		delete(temp1); // last node has been deleted.
		temp->next=NULL;//In address part of last node NULL value has been stored.
		cout<<"\n"<<data<<" has been deleted,";
		cout<<"\n after deletion";
		displayList();
	}
}
void LinkedList::delete_SpecifiedNode(int nodeNumer)
{
	Node *temp;
	Node *temp1;
	int data;
	int count=countNode();
	if(nodeNumer>count)
	{
		cout<<"\n illegal request or list is empty,so request is not accepted";
		
	}
	else if(start==NULL)
	{
		cout<<"\n list is empty, there is no NODE to delete";
	
	}
	else
	{
		if(nodeNumer==1)//deletion of first node
		{
			temp=start;
			start=start->next;
			data=temp->info;
			delete(temp);
			cout<<"\n"<<data<<" has been deleted ";
		}
		else if(nodeNumer>=2&&nodeNumer==count)//deletion of last node
		{
			temp=start;
			while(temp->next->next!=NULL)
			{
				temp=temp->next;
			}
			temp1=temp->next;//address of last node stored in temp1.
			temp->next=NULL;//In address part of last node NULL value has been stored.
			data=temp1->info;
			delete(temp1); // last node has been deleted.
			cout<<"\n"<<data<<"\t haa been deleted ";
		}
		else if(nodeNumer>=2&&nodeNumer<count)
		{
			temp=start;
			for(int i=1;i<nodeNumer-1;i++)
			{
				temp=temp->next;
			}
			temp1=temp->next;
			temp->next=temp1->next;
			data=temp1->info;
			delete(temp1);
			cout<<"\n"<<data<<" haa been deleted ";
		}
	}
}
int main()
{
	int choice,n;
	int val,pos;
	int nodeNumer;
	LinkedList L1;
	do
	{
		cout<<"\n\n-------Menu options--------"<<endl;
		cout<<"press 1. to create linked list \n";
		cout<<"press 2. to display linked list \n";
		cout<<"press 3. to add node in the Begining of the list\n";
		cout<<"press 4. to add node at the End of the list\n";
		cout<<"press 5. to add node at the specified position in the list\n";
		cout<<"press 6. to Delete the node from the Begining of the list\n";
		cout<<"press 7. to Delete the node from the End of the list\n";
		cout<<"press 8. to Delete the node from the specified position in list\n";
		cout<<"press 9. to exit\n";
		cout<<"\n enter your choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				cout<<"\n how many nodes you want to create and add in the List:";
				cin>>n;
				for(int i=1;i<=n;i++)
				{
					L1.create_LinkedList();
				}
				break;
			case 2:
				L1.displayList();
				break;
			case 3:
				L1.add_In_Begining();
				break;
			case 4:
				L1.add_AtTheEnd();
				break;
			case 5:
				cout<<"\n enter value of node to be inserted: ";
				cin>>val;
				cout<<"\n enter position after which node should be inserted: ";
				cin>>pos;
				L1.add_AtTheSpecifiedPosition(val,pos);
				break;
			case 6:
				L1.delete_FromBegining();
				break;
			case 7:
				L1.delete_FromEnd();
				break;
			case 8:
				cout<<"\n enter the Node number which you want to delete: ";
				cin>>nodeNumer;
				L1.delete_SpecifiedNode(nodeNumer);
				break;

			case 9:
				exit(0);
				break;
			default:
				cout<<"you have enterd wrong choice \n";
		}
	}while(choice!=9);
}
