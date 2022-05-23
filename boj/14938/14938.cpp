#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<iostream>
using namespace std;
int n,m,r;
vector<vector<pair<int,int>>> edge;
int item[101];
int solve=0;
int visit[101];
bool res[101];
void bfs(int start){
    for(int x=0;x<=n;x++){
        visit[x]=2e9;
        res[x]=false;
    }
    queue<pair<int,int>> Q;
    Q.push({start,0});
    int ret=0;
    visit[start]=0;
    while(!Q.empty()){
        int now=Q.front().first;
        int dist=Q.front().second;
        res[now]=true;
        Q.pop();
        for(auto i : edge[now]){
            if(visit[i.first]>dist+i.second && (dist+i.second<=m)){
                visit[i.first]=dist+i.second;
                Q.push({i.first,dist+i.second});
            }
        }
    }
    for(int x=1;x<=n;x++){
        if(res[x]) ret+=item[x];
    }
    solve=max(solve,ret);
}
int main(){
    cin>>n>>m>>r;
    for(int x=0;x<=n;x++) edge.push_back(vector<pair<int,int>>());
    for(int x=1;x<=n;x++) cin>>item[x];
    for(int x=0;x<r;x++){
        int src,dst,cost;
        cin>>src>>dst>>cost;
        edge[src].push_back({dst,cost});
        edge[dst].push_back({src,cost});
    }
    for(int x=1;x<=n;x++) bfs(x);
    cout<<solve;
}

