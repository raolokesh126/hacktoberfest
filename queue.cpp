#include<bits/stdc++.h>
using namespace std;

class Queue{
  public:
  //properties
    int rear;
    int front;
    int size;
    int *arr;
//behaviours
//making constructor
   Queue()
    {
    rear=-1;
    front=-1;
    size=5;
    arr=new int[size];
    }
void enqueue(int x)
   {
     if(rear==size-1) //Queue is not empty
    {
        cout<<"queue is full for:"<< x <<endl;
    }
    else //queue if full
    {
      rear++;
      arr[rear]=x;
    }
   }
 void dequeue()
   {
     if(front==rear) //either for (front=rear=-1) and for another index also
       {
        cout<<"queue is empty!"<<endl;
       }
       front++;
   }
int Front()
   {
    if(front==rear)
    {
      cout<<"queue is empty!"<<endl;
      return -1;
    }
    else
    {
        return arr[front]; 
    }
   }
bool isEmpty()
{
    if(front==rear)
      return true;
    return false;
}
bool isFull()
{
    if(rear==size-1)
      return true;
    return false;
}
void print()
{
    if(front==rear)
    {
      cout<<"queue is empty!"<<endl;
    }
    int tmp=front;
    while (tmp!=rear)
    {
       cout<<arr[tmp]<<" ";
       tmp++;
    }
}
};
int main()
{
    //follow codewith hary  vedio for references
  Queue q;
  q.enqueue(1);
  q.enqueue(2);
  q.enqueue(3);
  q.enqueue(4);
  q.enqueue(5);
  q.enqueue(6);

q.dequeue();
cout<<"queue front element is: "<<q.Front()<<endl;
cout<<"queue is: ";
q.print();
cout<<"is queue empty: "<<q.isEmpty()<<endl;
cout<<"is queue is full: "<<q.isFull()<<endl;
    return 0;
}