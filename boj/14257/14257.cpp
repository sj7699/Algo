#include <stdio.h>
#include<queue>
#include<iostream>
#include<stack>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
void fast_io() {
  cin.tie(0)->sync_with_stdio(0);
}
int main() {
    fast_io();
    long long s,x;
    cin>>s>>x;
    long long k=s-x;
    int bt=0;
    for(int i=45;i>=0;i--){
        if(x&(long long)(1LL<<i)){
            bt++;
            continue;
        }
        if(k>=(long long)(1LL<<(i+1))){
            k-=(long long)(1LL<<(i+1));
        }
    }
    long long solve=0;
    if(s==x) solve-=2;
    if(k==0) solve+=(long long)(1LL<<bt);;
    cout<<solve;
}