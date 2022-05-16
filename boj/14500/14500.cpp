#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
int board[500][500];
bool visit[500][500];
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int fu[4][3][2]={{{0,1},{0,2},{-1,1}},{{0,1},{0,2},{1,1}},{{1,0},{2,0},{1,1}},{{1,0},{2,0},{1,-1}}};
int solve=0;
int N,M;
void dfs(int x,int y,int step,int num){
    if(step==4){
        solve=max(solve,num);
        return;
        }
    for(int z=0;z<4;z++){
        int nowx=x+dir[z][0];
        int nowy=y+dir[z][1];
        if(nowx<0 || nowy<0 || nowx>=N || nowy>=M) continue;
        if(!visit[nowx][nowy]){
            visit[nowx][nowy]=true;
            dfs(nowx,nowy,step+1,num+board[nowx][nowy]);
            visit[nowx][nowy]=false;
        }
    }
}
int main(){
    cin>>N>>M;
    for(int x=0;x<N;x++){
        for(int y=0;y<M;y++) cin>>board[x][y];
    }
    for(int x=0;x<N;x++){
        for(int y=0;y<M;y++) {
            visit[x][y]=true;
            dfs(x,y,1,board[x][y]);
            visit[x][y]=false;
            for(int z=0;z<4;z++){
                int temp=board[x][y];
                bool chk=false;
                for(int w=0;w<3;w++){
                    int nowx=x+fu[z][w][0];
                    int nowy=y+fu[z][w][1];
                    if(nowx<0 || nowy<0 || nowx>=N || nowy>=M){
                        chk=true;
                        break;
                    }
                    temp+=board[nowx][nowy];
                }
                if(!chk){
                    solve=max(temp,solve);
                }
            }
            }
    }
    cout<<solve;
}