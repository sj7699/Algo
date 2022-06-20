#include<stdio.h>
#include<iostream>
#include<string>
#include<set>
#include<queue>
#include<algorithm>
using namespace std;
vector<string> board;
bool visit[10];
bool visit2[51][51];
int d[10][10];
vector<pair<int,int>> vec;
int cnt,ss,ex,ey,N,M;
int solve=2e9;
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int bfs(int s,int e){
    for(int x=0;x<N;x++){
        for(int y=0;y<M;y++) visit2[x][y]=false;
    }
    visit2[vec[s].first][vec[s].second]=true;
    queue<pair<pair<int,int>,int>> Q;
    Q.push({{vec[s].first,vec[s].second},0});
    while(!Q.empty()){
        int nowx=Q.front().first.first;
        int nowy=Q.front().first.second;
        int nd=Q.front().second;
        if(nowx==vec[e].first && nowy==vec[e].second){
            return nd;
        }
        Q.pop();
        for(int x=0;x<4;x++){
            int nx=dir[x][0]+nowx;
            int ny=dir[x][1]+nowy;
            if(nx<0 || ny<0|| nx>=N || ny>=M){
                continue;
            }
            if(!visit2[nx][ny] && board[nx][ny]!='#'){
                Q.push({{nx,ny},nd+1});
                visit2[nx][ny]=true;
            }
        }
    }
    return 0;
}
void recur(int now,int prod,int dist){
    if(prod==cnt){
        if(vec[now].first==ex && vec[now].second==ey){
            solve=min(solve,dist);
        }
        return;
    }
    for(int x=0;x<cnt;x++){
        if(!visit[x]){
            visit[x]=true;
            recur(x,prod+1,dist+d[now][x]);
            visit[x]=false;
        }
    }
}
int main(){
    cin>>M>>N;
    for(int x=0;x<N;x++){
        string input;
        cin>>input;
        board.push_back(input);
        for(int y=0;y<M;y++){
            if(input[y]=='S'){
                ss=cnt;
            }
            if(input[y]=='E') ex=x,ey=y;
            if(input[y]!='#' && input[y]!='.') {
                vec.push_back({x,y});
                cnt++;
            }
        }
    }
    for(int x=0;x<cnt;x++){
        for(int y=0;y<cnt;y++){
            d[x][y]=bfs(x,y);
        }
    }
    visit[ss]=true;
    recur(ss,1,0);
    cout<<solve;
}