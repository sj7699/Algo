#include<stdio.h>
#include<queue>
#include<iostream>
using namespace std;
char board[1001][1001];
bool visit[1001][1001][2];
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int N,M;
int bfs(){
    queue<pair<pair<int,int>,pair<int,int>>> Q;
    Q.push({{0,0},{1,0}});
    visit[0][0][0]=true;
    while(!Q.empty()){
        int nowx=Q.front().first.first;
        int nowy=Q.front().first.second;
        int dist=Q.front().second.first;
        int broke=Q.front().second.second;
        Q.pop();
        if(nowx==N-1 && nowy==M-1){
            return dist;
        }
        for(int x=0;x<4;x++){
            int nx=dir[x][0]+nowx;
            int ny=dir[x][1]+nowy;
            if(nx<0 || ny<0 || nx>=N || ny>=M) continue;
            if(broke){        
                if(board[nx][ny]=='0' && !visit[nx][ny][1] && !visit[nx][ny][0]){
                    Q.push({{nx,ny},{dist+1,broke}});
                    visit[nx][ny][1]=true;
                }
            }
            else{
                if(!visit[nx][ny][0]){
                    if(board[nx][ny]=='0'){
                        Q.push({{nx,ny},{dist+1,broke}});
                        visit[nx][ny][0]=true;
                    }
                    else{
                        Q.push({{nx,ny},{dist+1,1}});
                        visit[nx][ny][1]=true;
                    }
                }
            }
        }
    }
    return -1;
}
int main(){
    cin>>N>>M;
    for(int x=0;x<N;x++){
        cin>>board[x];
    }
    cout<<bfs();
}