#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
#include<map>
#include<set>
#include<stack>
#include<queue>
using namespace std;
priority_queue<pair<int,pair<int,int>>> E;
int parent[1001];
int N;
int ufind(int a){
    if(a==parent[a]) return parent[a];
    return parent[a]=ufind(parent[a]);
}
void uunion(int a,int b){
    int k = ufind(a);
    int k2 = ufind(b);
    if(k==k2) return;
    parent[k]=k2;     
}
long long kruskal(){
    long long ret=0;
    int i=0;
    while(i<N-1){
        int src=E.top().second.first;
        int dst=E.top().second.second;
        int cost=E.top().first;
        E.pop();
        int k=ufind(src);
        int k2=ufind(dst);
        if(k==k2) continue;
        i++;
        uunion(k,k2);
        ret+=(long long)-cost;
    }
    return ret;
}
int main(){
    cin>>N;
    for(int x=0;x<N;x++){
        parent[x]=x;
        for(int y=0;y<N;y++){
            int input;
            cin>>input;
            if(x!=y) E.push({-input,{x,y}});
        }
    }
    cout<<kruskal();
}