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
int arr[150][150];
int dist[150][150];
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int main() {
    fast_io();
    int T=0;
    while(true){
        T++;
        int N;
        cin>>N;
        if(N==0) break;
        for(int x=0;x<N;x++){
            for(int y=0;y<N;y++){
                cin>>arr[x][y];
                dist[x][y]=2e9;
            }
        }
        priority_queue<pair<int,pair<int,int>>> pq;
        pq.push({-arr[0][0],{0,0}});
        dist[0][0]=arr[0][0];
        while(!pq.empty()){
            auto now=pq.top();
            int nowx=now.second.first;
            int nowy=now.second.second;
            int cost=-now.first;
            pq.pop();
            if(dist[nowx][nowy]<cost) continue;
            for(int x=0;x<4;x++){
                int nxx=dir[x][0]+nowx;
                int nxy=dir[x][1]+nowy;
                if(nxx<0 || nxy<0 || nxx>=N || nxy>=N){
                    continue;
                }
                if(dist[nxx][nxy]>arr[nxx][nxy]+cost){
                    dist[nxx][nxy]=arr[nxx][nxy]+cost;
                    pq.push({-dist[nxx][nxy],{nxx,nxy}});
                }
            }
        }
        cout<<"Problem "<<T<<": "<<dist[N-1][N-1]<<'\n'; 
    }
}