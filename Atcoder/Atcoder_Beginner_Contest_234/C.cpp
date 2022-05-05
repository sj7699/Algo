#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>
#include<stack>
using namespace std;
int main(){
    long long input;
    stack<int> stk;
    cin>>input;
    while(input>0){
        if(input%2==1){
            stk.push(2);
        }
        else stk.push(0);
        input/=2;
    }
    while(!stk.empty()){
        printf("%i",stk.top());
        stk.pop();
    }
}