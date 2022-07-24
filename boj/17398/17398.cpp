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
bool temp[100001];
int parent[100001];
int urank[100001];
long long solve;
vector<pair<int,int>> E;
int N,M,Q;
int ufind(int a){
    if(a==parent[a]) return parent[a];
    return parent[a]=ufind(parent[a]);
}
void uunion(int a,int b,bool issolve){
    int k=ufind(a);
    int k2=ufind(b);
    if(k==k2) return;
    if(urank[k]>=urank[k2]){
        parent[k2]=k;
        if(issolve) solve+=(long long)urank[k]*(long long)urank[k2];
        urank[k]+=urank[k2];
    }
    else{
        parent[k]=k2;
        if(issolve) solve+=(long long)urank[k]*(long long)urank[k2];
        urank[k2]+=urank[k];
    }
}
int main(){
    fast_io();
    stack<int> stk;
    cin>>N>>M>>Q;
    for(int x=1;x<=N;x++) parent[x]=x,urank[x]=1;
    for(int x=0;x<M;x++){
        int a,b;
        cin>>a>>b;
        E.push_back({a,b});
    }
    for(int x=0;x<Q;x++){
        int input;
        cin>>input;
        stk.push(input-1);
        temp[input-1]=true;
    }
    for(int x=M-1;x>=0;x--){
        if(!temp[x]){
            uunion(E[x].first,E[x].second,false);
        }
    }
    while(!stk.empty()){
        int src=E[stk.top()].first;
        int dst=E[stk.top()].second;
        stk.pop();
        uunion(src,dst,true);
    }
    cout<<solve;
}