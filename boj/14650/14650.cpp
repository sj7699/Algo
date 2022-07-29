#include<stdio.h>
#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int temp=2;
    for(int x=2;x<n;x++){
        temp=temp*3;
    }
    if(n==1){
        cout<<0;
    }
    else{
        cout<<temp;
    }
}