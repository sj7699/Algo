#include <stdio.h>
#include<queue>
#include<iostream>
#include<vector>
using namespace std;
void fast_io() {
  cin.tie(0)->sync_with_stdio(0);
}
int N,M;
int main() {
    fast_io();
    int T;
    cin>>T;
    for(int test=1;test<=T;test++){
        cin>>N>>M;
        vector<vector<int>> route(M+1,vector<int>());
        vector<vector<pair<int,int>>> E(M+1,vector<pair<int,int>>());
        vector<int> dist(M+1,1e9);
        priority_queue<pair<int,int>> pq;
        for(int x=0;x<N;x++){
            int src,dst,cost;
            cin>>src>>dst>>cost;
            E[src].push_back({dst,cost});
            E[dst].push_back({src,cost});
        }        
        pq.push({0,0});
        route[0].push_back(0);
        while(!pq.empty()){
            int now=pq.top().second;
            int cost=-pq.top().first;
            pq.pop();
            if(dist[now]<cost) continue;
            for(auto i : E[now]){
                if(i.second+cost<dist[i.first]){
                    dist[i.first]=i.second+cost;
                    route[i.first]=route[now];
                    route[i.first].push_back(i.first);
                    pq.push({-dist[i.first],i.first});
                }
            } 
        }
        cout<<"Case #"<<test<<": ";
        for(auto i : route[M-1]){
            cout<<i<<" ";
        }
        if(route[M-1].empty()) cout<<-1;
        cout<<'\n';
    }
}