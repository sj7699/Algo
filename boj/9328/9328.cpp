#include<stdio.h>
#include<string>
#include<iostream>
#include<algorithm>
#include<set>
#include<queue>
#include<map>
using namespace std;
char board[1001][1001];
bool visit[1001][1001];
bool iskey[27];
int R,C;
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
bool mod;
int solve=0;     
map<int,vector<pair<int,int>>> m;
void bfs(int startx,int starty){
    if(board[startx][starty]>='A' && board[startx][starty]<='Z' && !iskey[board[startx][starty]-'A']){
        m[board[startx][starty]].push_back({startx,starty});
        return;
    }
    if(board[startx][starty]=='*') return;
    if(visit[startx][starty]) return;
    queue<pair<int,int>> Q;
    visit[startx][starty]=true;
    Q.push({startx,starty});
    while(!Q.empty()){
        int nowx=Q.front().first;
        int nowy=Q.front().second;
        if(board[nowx][nowy]=='$') solve++;
        if(board[nowx][nowy]>='a' && board[nowx][nowy]<='z' && !iskey[board[nowx][nowy]-'a']){
            iskey[board[nowx][nowy]-'a']=true;
            for(auto i : m[board[nowx][nowy]-32]){
                Q.push({i.first,i.second});
            }
        }
        Q.pop();
        for(int x=0;x<4;x++){
            int nextx=nowx+dir[x][0];
            int nexty=nowy+dir[x][1];
            if(nextx<0 || nexty<0 || nextx>=R || nexty>=C) continue;
            if(!visit[nextx][nexty] && board[nextx][nexty]>='A' && board[nextx][nexty]<='Z'){
                if(!iskey[board[nextx][nexty]-'A']){
                    m[board[nextx][nexty]].push_back({nextx,nexty});
                    continue;
                }
            }
            if(!visit[nextx][nexty] && board[nextx][nexty]!='*'){
                Q.push({nextx,nexty});
                visit[nextx][nexty]=true;
            }
        }
    }
    return;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve=0;
        cin>>R>>C;
        m.clear();
        for(int x=0;x<='z'-'a';x++){
            iskey[x]=false;
        }
        for(int x=0;x<R;x++){
            string input;
            cin>>input;
            for(int y=0;y<C;y++){
                visit[x][y]=false;
                board[x][y]=input[y];
            }
        }
        for(char x='A';x<='Z';x++){
            m[x]=vector<pair<int,int>>();
        }
        string input;
        cin>>input;
        if(input!="0"){
            for(int x=0;x<input.size();x++){
                iskey[input[x]-'a']=true;
            }
        }
        for(int x=0;x<R;x++){
            bfs(x,0);
            bfs(x,C-1);
        }
        for(int x=0;x<C;x++){
            bfs(0,x);
            bfs(R-1,x);
        }
        cout<<solve<<'\n';
    }
}