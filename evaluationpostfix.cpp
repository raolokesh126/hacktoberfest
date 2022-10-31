#include<iostream>
#include<cstdio>
#include<cctype>
#include<cmath>
#include<cstdlib>
#define MAX 100

using namespace std;

struct postfix
        {
    int stack[MAX];
    int top,n;
    char *s;
        }p;
void init_post()
{
    p.top=-1;
}
void init_exp(char *str)
{
    p.s=str;
}
void push(int number)
{
    p.top++;
    p.stack[p.top]=number;
}
int pop()
{
    int number=p.stack[p.top];
    p.top--;
    return number;
}
void calculate()
{
    int n1, n2, x;
    while(*(p.s))
    {
        if(*(p.s)==' ' || *(p.s)=='	')
        {
            p.s++;
            continue;
        }
        if(isdigit(*(p.s)))
        {
            p.n=*(p.s)-'0';
            push(p.n);
        }
        else
        {
            n1=pop();
            n2=pop();
            switch(*(p.s))
            {
                case '+':
                    x=n2+n1 ;
                    break;
                    case '-':
                        x=n2-n1 ;
                        break;
                        case '*':
                            x=n2*n1 ;
                            break;
                            case '/':
                                x=n2/n1 ;
                                break;
                                case '%':
                                    x=n2%n1 ;
                                    break;
                                    case '^':
                                        x=(int)pow(n2,n1) ;
                                        break;
                                        default:
                                            cout<<"Invalid operator !!\n" ;
                                            exit(1);
            }
            push(x);
        }
        p.s++;
    }
}
void disp_result()
{
    p.n=pop();
    cout<<"\nResult = "<<p.n;
}
int main()
{
    char exp[MAX];
    init_post();
    cout<<"Enter the postfix formed expression : ";
    cin>>exp;
    init_exp(exp);

    calculate();

    disp_result();
    return 0;
}
