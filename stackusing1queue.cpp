#include<bits/stdc++.h>
using namespace std;
class Stack{
  public:
  queue<int> q;
void push(int x)
  {
    q.push(x);
    int size=q.size();  //make theme reverse
    while(size>1)
    {
      int tmp=q.front();
      q.pop();
      q.push(tmp); 
      size--; 
    }  
  }
void pop()
  {
    q.pop();
    return;
  }
int top()
  {
    return q.front();  
  }
bool isEmpty()
  {
    if(q.size()==0)
        return 1;
        else return 0;
  }
int size()
{
    return q.size();
}
};
int main()
{
    //write your code here
    Stack s;
    s.push(1);
    s.push(2);
    s.push(5);
    s.push(-1);
    s.push(3);
    
    cout<<s.size();
    s.pop();
    cout<<s.top();
    cout<<s.isEmpty();
    return 0;
}