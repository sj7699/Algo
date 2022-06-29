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
char board[102][102];
bool visit[102][102];
int dir[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
void fast_io() {
  cin.tie(0)->sync_with_stdio(0);
}
int R,C,K,lr;
vector<pair<int,int>> vec;
vector<int> lvec;
void dfs(int nx,int ny){
    if(visit[nx][ny]) return;
    vec.push_back({nx,ny});
    visit[nx][ny]=true;
    lr=max(nx,lr);
    lvec[ny]=max(lvec[ny],nx);
    for(int x=0;x<4;x++){
        int nxx=nx+dir[x][0];
        int nxy=ny+dir[x][1];
        if(nxx<0 || nxy<0 || nxx>=R || nxy>=C) continue;
        if(!visit[nxx][nxy] && board[nxx][nxy]=='x') dfs(nxx,nxy);
    }
}
void stick(int a,int b){
    if(b%2==1){
        for(int x=0;x<C;x++){
            if(board[a][x]=='x'){
                board[a][x]='.';
                for(int y=0;y<4;y++){
                    vec.clear();
                    int nx=dir[y][0]+a;
                    int ny=dir[y][1]+x;
                    if(nx<0 || ny<0 || nx>=R || ny>=C) continue;
                    if(visit[nx][ny]) continue;
                    if(board[nx][ny]=='.') continue;
                    lr=0;
                    for(int w=0;w<C;w++) lvec[w]=-1;
                    dfs(nx,ny);
                    if(lr==R-1) {
                        continue;
                    }
                    int dist=1e9;
                    for(int w=0;w<C;w++){
                        if(lvec[w]==-1) continue;
                        int temp=0;
                        for(int k=lvec[w]+1;k<R;k++){
                            if(board[k][w]=='x'){
                                dist=min(temp,dist);
                                break;
                            }
                            temp++;
                            if(k==R-1){
                                dist=min(temp,dist);
                            }
                        }
                    }
                    for(auto i : vec){
                        //cout<<i.first<<" "<<i.second<<'\n';
                        board[i.first][i.second]='.';
                    }
                    for(auto i : vec){
                        board[i.first+dist][i.second]='x';
                    }
                    break;
                }
                break;
            }
        }
    }
    if(b%2==0){
        for(int x=C-1;x>=0;x--){
            if(board[a][x]=='x'){
                board[a][x]='.';
                for(int y=0;y<4;y++){
                    vec.clear();
                    int nx=dir[y][0]+a;
                    int ny=dir[y][1]+x;
                    if(nx<0 || ny<0 || nx>=R || ny>=C) continue;
                    if(visit[nx][ny]) continue;
                    if(board[nx][ny]=='.') continue;
                    lr=0;
                    for(int w=0;w<C;w++) lvec[w]=-1;
                    dfs(nx,ny);
                    if(lr==R-1) {
                        continue;
                    }
                    int dist=1e9;
                    for(int w=0;w<C;w++){
                        if(lvec[w]==-1) continue;
                        int temp=0;
                        for(int k=lvec[w]+1;k<R;k++){
                            if(board[k][w]=='x'){
                                dist=min(temp,dist);
                                break;
                            }
                            temp++;
                            if(k==R-1){
                                dist=min(temp,dist);
                            }
                        }
                    }
                    for(auto i : vec){
                        board[i.first][i.second]='.';
                    }
                    for(auto i : vec){
                        board[i.first+dist][i.second]='x';
                    }
                    break;
                }
                break;
            }
        }
    }
    for(int x=0;x<R;x++){
        for(int y=0;y<C;y++) visit[x][y]=false;
    }
}
int main(){
    fast_io();
    cin>>R>>C;
    for(int x=0;x<R;x++){
        cin>>board[x];
    }
    for(int x=0;x<C;x++) lvec.push_back(1e9);
    cin>>K;
    int cnt=0;
    while(K--){
        cnt++;
        int input;
        cin>>input;
        stick(R-input,cnt);
        /*for(int x=0;x<R;x++){
            cout<<board[x]<<'\n';
        }
        cout<<'\n';*/
    }
    for(int x=0;x<R;x++){
        cout<<board[x]<<'\n';
    }
}