#include<stdio.h>
#include<vector>
#include<algorithm>
#include<bitset>
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
int N,M,ans;
bool visit[11][11];
int board[11][11];
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int dist[101][101];
int parent[101];
int ufind(int a){
    if(a==parent[a]) return a;
    parent[a]=ufind(parent[a]);
    return parent[a];
}
void uunion(int a,int b){
    int k=ufind(a);
    int k2=ufind(b);
    if(k==k2) return;
    parent[k]=k2;
    return;
}
void kruskal(int c){
    vector<pair<int,pair<int,int>>> edge;
    for(int x=1;x<c;x++){
        for(int y=1;y<c;y++){
            if(dist[x][y]!=1e9){
                edge.push_back({dist[x][y],{x,y}});
            }
        }
    }
    int k=0;
    sort(edge.begin(),edge.end());
    for(int x=0;x<edge.size();x++){
        int src=edge[x].second.first;
        int dst=edge[x].second.second;
        if(ufind(src)!=ufind(dst)){
            uunion(src,dst);
            ans+=edge[x].first;
            k++;
        }
    }
    if(c-2>k) ans=-1;
}
void bfs(pair<int,int> a,int c){
    visit[a.first][a.second]=true;
    queue<pair<int,int>> q;
    q.push(a);
    board[a.first][a.second]=c;
    while(!q.empty()){
        auto now=q.front();
        q.pop();
        for(int x=0;x<4;x++){
            int nx=now.first+dir[x][0];
            int ny=now.second+dir[x][1];
            if(nx<0 || ny<0 || nx>=N || ny>=M) continue;
            if(!visit[nx][ny] && board[nx][ny]!=0){
                visit[nx][ny]=true;
                board[nx][ny]=c;
                q.push({nx,ny});
            }
        }
    }
}
int main(){
    fast_io();
    cin>>N>>M;
    for(int x=0;x<N;x++){
        for(int y=0;y<M;y++) cin>>board[x][y];
    }
    int c=1;
    for(int x=0;x<N;x++){
        for(int y=0;y<M;y++){
            if(!visit[x][y] && board[x][y]){
                bfs({x,y},c++);
            }
        }
    }
    for(int x=1;x<=c;x++){
        parent[x]=x;
        for(int y=1;y<=c;y++) dist[x][y]=1e9;
    }
    for(int x=0;x<N;x++){
        for(int y=0;y<M;y++){
            if(board[x][y]){
                int src=board[x][y];
                for(int z=0;z<4;z++){
                    for(int w=1;w<=max(N,M);w++){
                        int nx=dir[z][0]*w+x;
                        int ny=dir[z][1]*w+y;
                        if(nx<0 || ny<0 || nx>=N || ny>=M) break;
                        if(board[nx][ny]==src) break;
                        if(board[nx][ny]!=src && board[nx][ny]!=0){
                            if(w>2){
                                dist[src][board[nx][ny]]=min(dist[src][board[nx][ny]],w-1);
                                dist[board[nx][ny]][src]=min(dist[board[nx][ny]][src],w-1);
                            }
                            break;
                        }
                    }
                }
            }
        }
    }
    kruskal(c);
    cout<<ans;
}