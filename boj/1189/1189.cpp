#include<stdio.h>
#include<iostream>
#include<set>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
char board[6][6];
bool visit[6][6];
int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int R,C,K;
int solve;
void dfs(int nowx,int nowy,int step){
    if(board[nowx][nowy]=='T') return;
    if(nowx==0 && nowy==C-1){
        if(step==K) solve++;
        return;
    }
    for(int x=0;x<4;x++){
        int nextx=dir[x][0]+nowx;
        int nexty=dir[x][1]+nowy;
        if(nextx<0 || nexty<0 || nextx>=R || nexty>=C){
            continue;
        }
        if(!visit[nextx][nexty]){
            visit[nextx][nexty]=true;
            dfs(nextx,nexty,step+1);
            visit[nextx][nexty]=false;
        }
    }
}
int main(){
    cin>>R>>C>>K;
    for(int x=0;x<R;x++){
        cin>>board[x];
    }
    visit[R-1][0]=true;
    dfs(R-1,0,1);
    cout<<solve;
}
