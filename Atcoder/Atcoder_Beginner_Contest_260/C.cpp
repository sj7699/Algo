#include<stdio.h>
#include<queue>
#include<vector>
#include<iostream>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
long long mod=1e9+7LL;
long long N,X,Y;
long long solve=0;
void B(long long k,int step);
void R(long long k,int step){
    if(step<=1) return;
    R(k,step-1);
    B(k*X,step);
}
void B(long long k,int step){
    if(step<=1){
        if(step==1) solve+=k;
        return;
    }
    R(k,step-1);
    B(k*Y,step-1);
}
int main(){
    cin>>N>>X>>Y;
    R(1LL,N);
    cout<<solve;
}