#include<stdio.h>
#include<queue>
#include<vector>
#include<iostream>
#include<map>
#include<set>
#include<stack>
#include<algorithm>
using namespace std;
void fast_io() {
  cin.tie(0)->sync_with_stdio(0);
}
int gcd(int x,int y){
    if(y==0){
        return x;
    }
    else{
        return gcd(y,x%y);
    }
}
map<pair<int,int>,int> m;
int main(){
    fast_io();
    int N;
    cin>>N;
    long long now=0;
    long long solve=0;
    long long now2=0;
    long long now3=0;
    for(int x=0;x<N;x++){
        int a,b,c;
        cin>>a>>b>>c;
        if(a==0){
            now2++;
            continue;
        }
        if(b==0){
            now3++;
            continue;;
        }
        int k=gcd(abs(a),abs(b));
        long long ta=a/k;
        long long tb=b/k;
        if(ta*tb<0){
            m[{abs(ta),-abs(tb)}]++;
        }
        else m[{abs(ta),abs(tb)}]++;
    }
    long long k=N;
    N-=now2+now3;
    for(auto i : m){
        now+=i.second;
        solve+=(long long)((long long)N-now)*(long long)i.second;
    }
    solve+=(long long)(k-now2-now3)*now2;
    solve+=(long long)(k-now2-now3)*now3;
    solve+=now2*now3;
    cout<<solve;
}