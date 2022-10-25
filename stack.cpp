#include<bits/stdc++.h>
using namespace std;
class Stack{
//properties
public:
   int top;
   int size;
   int *arr;

//behaviour  
//making constructor
Stack()
{
  top=-1;
  size=5;
  arr=new int[size];
}
void Push(int x)
{
    if(top+1>=size)
    {
        cout<<"stack overflow for: "<< x <<endl;
    }
    else
    {
        top++;
        arr[top]=x;
    }
}
int Top()
{
   if(top==-1)
   {
     cout<<"stack under flow"<<endl; 
     return -1;
   }
     else
       return arr[top];
}
void pop()
{
   if(top==-1)
     cout<<"stack is underflow"<<endl;
     else
       top=top-1; 
}
int Size()
{
  return top+1;
}
bool isEmpty()
{
    if(top==-1)
       return true;
    else
       return false;
}
void print()
{
  if(top==-1)
    cout<<"stack is empty!"<<endl;
   else //print the stack
   {
    int tmp=top;
     while(tmp!=-1)
     {
        cout<<arr[tmp--]<<" ";
     }
     cout<<endl;
   }
}
};

int main()
{
     Stack s;
     s.Push(2);
     s.Push(3);
     s.Push(4);
     s.Push(1);
     s.Push(5);
     s.Push(6);
     
     s.pop();
     cout<<"stack is: ";
     s.print();
     cout<<"top element of the stack: "<<s.Top()<<endl;
     cout<<"stack size is: "<<s.Size()<<endl;
     cout<<"is stack empty: "<<s.isEmpty()<<endl;

    return 0;
}