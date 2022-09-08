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
vector<vector<pair<int,int>>> E(5001,vector<pair<int,int>>());
bool chk[5001];
int dist[5001];
int main(){
    fast_io();
    cin>>N>>M;
    for(int x=0;x<M;x++){
        int src,dst,cost;
        cin>>src>>dst>>cost;
        E[src].push_back({dst,cost});
        E[dst].push_back({src,cost});
    }
    int p,q;
    cin>>p>>q;
    vector<int> hv(p,0);
    vector<int> cv(q,0);
    priority_queue<pair<int,int>> pq;
    for(auto & i : hv) {
        cin>>i;
        chk[i]=true;
    }
    for(auto & i : cv) {
        cin>>i;
        pq.push({0,i});
    }
    for(int x=1;x<=N;x++) dist[x]=2e9;
    int solve=2e9;
    int mn=2e9;
    while(!pq.empty()){
        int now=pq.top().second;
        int cost=-pq.top().first;
        pq.pop();
        if(dist[now]<cost) continue;
        if(mn>=cost && chk[now]){
            solve=min(solve,now);
            mn=min(mn,cost);
        }
        for(auto i : E[now]){
            if(i.second+cost<dist[i.first]){
                dist[i.first]=i.second+cost;
                pq.push({-dist[i.first],i.first});
            }
        }
    }
    cout<<solve;
}