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
bool board[1002][1002];
bool visit[1002][1002][2];
int dir[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
int main(){
    fast_io();
    int N,M,hx,hy,ex,ey;
    cin>>N>>M>>hx>>hy>>ex>>ey;
    for(int x=1;x<=N;x++){
        for(int y=1;y<=M;y++){
            cin>>board[x][y];
        }
    }
    queue<pair<pair<int,int>,pair<int,int>>> Q;
    visit[hx][hy][0]=true;
    Q.push({{hx,hy},{0,0}});
    int D=-1;
    while(!Q.empty()){
        auto now=Q.front().first;
        auto now2=Q.front().second;
        if(now==make_pair(ex,ey)){
            D=now2.second;
            break;
        }
        for(int x=0;x<4;x++){
            auto i = make_pair(dir[x][0],dir[x][1]);
            int nx=i.first+now.first;
            int ny=i.second+now.second;
            if(nx<1 || ny<1 || nx>N || ny>M) continue;
            if(now2.first==0){
                if(!visit[nx][ny][now2.first]){
                    if(!board[nx][ny]){
                        Q.push({{nx,ny},{board[nx][ny],now2.second+1}});
                        visit[nx][ny][board[nx][ny]]=true;
                    }
                    else{   
                        Q.push({{nx,ny},{1,now2.second+1}});
                        visit[nx][ny][1]=true;
                    }
                }
            }
            else{
                if(!board[nx][ny] && !visit[nx][ny][1] && !visit[nx][ny][0]){       
                    Q.push({{nx,ny},{1,now2.second+1}});
                    visit[nx][ny][1]=true;
                }
            }
        }
        Q.pop();
    }
    cout<<D;
}