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
bool chk[1000001];
vector<long long> solve;
int main(){
    fast_io();
    long long N;
    cin>>N;
    chk[1]=true;
    priority_queue<long long,vector<long long>,greater<long long>> pq;
    for(long long x=2;x*x<=N;x++){
        if(chk[x]) continue;
        for(long long y=x*2LL;y*y<=N;y+=x){
            chk[y]=true;
        }
    }
    long long now=N;
    for(long long x=2;x*x<=N;x++){
        while(now%x==0){
            pq.push(x);
            now/=x;
        }
    }
    if(now!=1) pq.push(now);
    while(!pq.empty()){
        if(pq.size()>3){
            long long a=pq.top();
            pq.pop();
            long long b=pq.top();
            pq.pop();
            solve.push_back(a*b);
        }
        else if(pq.size()==3){
            long long a=pq.top();
            pq.pop();
            long long b=pq.top();
            pq.pop();
            long long c=pq.top();
            pq.pop();
            solve.push_back(a*b*c);
        }
        else if(pq.size()==2){
            long long a=pq.top();
            pq.pop();
            long long b=pq.top();
            pq.pop();
            solve.push_back(a*b);
        }
        else{
            cout<<-1;
            return 0;
        }
    }
    for(auto i : solve){
        cout<<i<<" ";
    }
}
