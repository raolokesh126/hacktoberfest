// Given a string, we need to reverse the string word wise

#include <iostream>
#include <cstring>
using namespace std;

void reverseEachWord(char input[]) {
    int end,start=0;
    for(int i=0;i<=strlen(input);i++)
    {
        if(input[i]==' ' || input[i]=='\0')  // As sson as a space is enquired we need to reverse the word before the space
        {
            end=i-1;
            while(start<end)
            {
                char temp=input[end];
                input[end]=input[start];
                input[start]=temp;
                start++;
                end--;
            }
            start=i+1;  // Now we are updating our start to now point to the position after the space
        }
    }
}

int main() {
    int size = 1e6;
    char str[size];
    cin.getline(str, size);
    reverseEachWord(str);
    cout << str;
}