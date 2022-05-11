#include<stdio.h>
#include<iostream>
#include<queue>
#include<vector>
#include<map>
#define INF 200000000;
using namespace std;
int H,W;
char board[501][501];
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int d[501][501];
void dijkstra(int startx,int starty)
{
    priority_queue<pair<int,pair<int,int>>>pq; // 거리, 노드 인덱스    
    pq.push({0,{startx,starty}}); //시작 노드로 가기위한 최단 경로는 0으로 설정하여, 큐에 삽입.
    d[startx][starty]=0;   
    while(!pq.empty())
    {
        int dist = -pq.top().first; //현재 노드까지의 비용
        int nowx = pq.top().second.first; // 현재 노드
        int nowy=pq.top().second.second;
        pq.pop(); 
        if(d[nowx][nowy]<dist) // 이미 최단경로를 체크한 노드인 경우 패스
            continue;  
        bool chk=false;
        for(int x=0;x<4;x++){
            int nextx=nowx+dir[x][0];
            int nexty=nowy+dir[x][1];
            if(nextx<0 || nexty<0 || nextx>=H || nexty>=W) continue;
            if(board[nextx][nexty]=='#') chk=true;
        }
        for(int i=0; i<4; i++)
        {
            int nextx=nowx+dir[i][0];
            int nexty=nowy+dir[i][1];
            if(nextx<0 || nexty<0 || nextx>=H || nexty>=W) continue;
            if(board[nextx][nexty]=='#') continue;
            int cost =dist; // 거쳐서 가는 노드의 비용을 계산
            bool chk2=false;
            for(int x=0;x<4;x++){
                int nexx=nextx+dir[x][0];
                int nexy=nexty+dir[x][1];
                if(nexx<0 || nexy<0 || nexx>=H || nexy>=W) continue;
                if(board[nexx][nexy]=='#') chk2=true;
            }
            if(!chk || !chk2) cost++;
            if(cost<d[nextx][nexty]) // 비용이 더 작다면 최단경로 테이블 값을 갱신.
            {
                d[nextx][nexty]=cost;
                pq.push({-cost,{nextx,nexty}});
            }
        }
    }
}
int main(){
    cin>>H>>W;
    int sx,sy,dx,dy;
    for(int x=0;x<H;x++){
        cin>>board[x];
        for(int y=0;y<W;y++){
            if(board[x][y]=='S'){
                sx=x;
                sy=y;
            }
            if(board[x][y]=='E'){
                dx=x;
                dy=y;
            }
            d[x][y]=INF;
        }
    }
    dijkstra(sx,sy);
    cout<<d[dx][dy];
}