#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<functional>
using namespace std;
void fast_io() {
  cin.tie(0)->sync_with_stdio(0);
}
int dir[4][2]={{-1,0},{0,-1},{1,0},{0,1}};
int board[105][105];
int dist[105][105][2];
int N,M;
void dijkstra(pair<int,int> start){
    dist[start.first][start.second][0]=board[start.first][start.second];
    dist[start.first][start.second][1]=board[start.first][start.second];
    priority_queue<pair<int,pair<pair<int,int>,int>>> pq;
    pq.push({-board[start.first][start.second],{start,0}});
    while(!pq.empty()){
        auto now=pq.top().second.first;
        int cost=-pq.top().first;
        auto k = pq.top().second.second;
        pq.pop();
        if(dist[now.first][now.second][k]<cost) continue;
        for(int x=0;x<4;x++){
            int nx=dir[x][0]+now.first;
            int ny=dir[x][1]+now.second;
            int dnx=nx+dir[x][0];
            int dny=ny+dir[x][1];
            if(nx<0 || ny<0 || nx>=N || ny>=M) continue;
            if(dist[nx][ny][k]>max(board[nx][ny],cost)){
                dist[nx][ny][k]=max(board[nx][ny],cost);
                pq.push({-max(board[nx][ny],cost),{{nx,ny},k}});
            }
            if(k==1) continue;
            if(dnx<0 || dny<0 || dnx>=N || dny>=M) continue;
            if(dist[dnx][dny][1]>max(board[dnx][dny],cost)){
                dist[dnx][dny][1]=max(board[dnx][dny],cost);
                pq.push({-max(board[dnx][dny],cost),{{dnx,dny},1}});
            }
        }
    }
}
int main(){
    fast_io();
    cin>>N>>M;
    for(int x=0;x<N;x++){
        for(int y=0;y<M;y++){
            //board[x][y]=x+x*y;
            cin>>board[x][y];
            dist[x][y][0]=2e9;
            dist[x][y][1]=2e9;
        } 
    }
    dijkstra({0,0});
    cout<<min(dist[N-1][M-1][0],dist[N-1][M-1][1]);
}