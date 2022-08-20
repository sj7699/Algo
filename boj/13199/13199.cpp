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
int main(){
    fast_io();
    int T;
    cin>>T;
    while(T--){
        long long P,M,F,C;
        cin>>P>>M>>F>>C;
        long long a=M/P+M/P*C/F;
        long long b;
        if(M/P*C >=F){
            b=M/P+(M/P*C-F)/(F-C)+1;
        }
        else b=M/P;
        cout<<max(0LL,b-a)<<'\n';
    }
}
