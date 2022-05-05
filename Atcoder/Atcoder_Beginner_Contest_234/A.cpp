#include<stdio.h>
#include<iostream>
using namespace std;
long long solve(long long input){
    return input*input+2LL*input+3LL;
}
int main(){
    long long input;
    cin>>input;
    cout<<solve(solve(solve(input)+input)+solve(solve(input)));
}