#include <stdio.h>
#include<iostream>
#include<vector>
using namespace std;
void fast_io() {
  cin.tie(0)->sync_with_stdio(0);
}
int N;
int board[11][11];
int k=-1;
bool solve;
int dir[8][2]={{0,1},{0,-1},{1,0},{-1,0},{1,1},{-1,-1},{1,-1},{-1,1}};
void dfs(int z){
    if(z==k){
        solve=true;
        return;
    }
    for(int x=0;x<N;x++){
        for(int y=0;y<N;y++){
            if(board[x][y]!=2) continue;
            for(int i=0;i<8;i++){
                int nx=x+dir[i][0];
                int ny=y+dir[i][1];
                int nnx=nx+dir[i][0];
                int nny=ny+dir[i][1];
                if(nnx<0 || nny<0 || nnx>=N || nny>=N) continue;
                if(board[nx][ny]==2 && board[nnx][nny]==0){
                    board[nx][ny]=0;
                    board[nnx][nny]=2;
                    board[x][y]=0;
                    dfs(z+1);
                    board[nx][ny]=2;
                    board[nnx][nny]=0;
                    board[x][y]=2;
                }
            }
        }
    }
}
int main() {
    fast_io();
    cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>board[i][j];
            if(board[i][j]==2) k++;
        }
    }
    dfs(0);
    if(solve){
        cout<<"Possible";
    }
    else cout<<"Impossible";
}