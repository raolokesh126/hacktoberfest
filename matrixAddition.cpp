// Program to add two matrix

#include <bits/stdc++.h>
using namespace std ; 

int main() {
    int row , col;
    cout<<"Enter the number of row of matrix-: ";
    cin>>row;
    cout<<"Enter the number of column of  matrix-: ";
    cin>>col;
    int a[row][col];
    cout<<"Enter the entire first matrix-:\n";
    for (int i=0;i<row;i++) for (int j=0;j<col;j++) cin>>a[i][j];
    int b[row][col];
    cout<<"Enter the entire second matrix-:\n";
    for (int i=0;i<row;i++) for (int j=0;j<col;j++) cin>>b[i][j];
    int result[row][col];
    for (int i=0;i<row;i++) for (int j=0;j<col ; j++) result[i][j] = a[i][j]+b[i][j];
    cout<<"Matrix after addition is -:\n";
    for (int i=0;i<row;i++) {
        for (int j=0;j<col ; j++) cout<<result[i][j]<<" ";
        cout<<endl;
    }
}
