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
int N,M;
int E[501][501];
int dist[501];
int solve[501][501];
void dijkstra(int start){
    priority_queue<pair<int,int>> pq;
    pq.push({0,start});
    while(!pq.empty()){
        int now=pq.top().second;
        int cost=-pq.top().first;
        pq.pop();
        if(dist[now]<cost) continue;
        for(int x=1;x<=N;x++){
            if(E[now][x]+cost<dist[x]){
                dist[x]=E[now][x]+cost;
                pq.push({-dist[x],x});
            }
        }
    }
}
int main(){
    fast_io();
    cin>>N>>M;
    for(int x=1;x<=N;x++){
        for(int y=1;y<=N;y++) cin>>E[x][y];
    }
    for(int x=1;x<=N;x++){
        for(int y=1;y<=N;y++) dist[y]=2e9;
        dijkstra(x);
        for(int y=1;y<=N;y++) solve[x][y]=dist[y];
    }
    for(int x=1;x<=M;x++){
        int src,dst,time;
        cin>>src>>dst>>time;
        if(solve[src][dst]>time){
            cout<<"Stay here\n";
        }
        else cout<<"Enjoy other party\n";
    }
}
