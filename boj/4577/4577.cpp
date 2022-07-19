#include<stdio.h>
#include<queue>
#include<vector>
#include<iostream>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
void fast_io() {
  cin.tie(0)->sync_with_stdio(0);
}
char board[16][16];
char board2[16][16];
int dir[200][2];
int main(){
    fast_io();
    dir['U'][0]=-1;
    dir['L'][1]=-1;
    dir['R'][1]=1;
    dir['D'][0]=1;
    int test_case=0;
    while(1){
        test_case++;
        int N,M;
        cin>>N>>M;
        if(N==0 && M==0) break;
        pair<int,int> cur;
        for(int x=0;x<N;x++){
            cin>>board[x];
            for(int y=0;y<M;y++) {
                board2[x][y]=board[x][y];
                if(board[x][y]=='W' || board[x][y]=='B') board2[x][y]='+';
                if(board[x][y]=='w' || board[x][y]=='W') {
                    if(board[x][y]=='w') board2[x][y]='.';
                    cur={x,y};
                }
                if(board[x][y]=='b'){
                    board2[x][y]='.';
                }
            }
        }
        string input;
        cin>>input;
        for(auto i : input){
            bool chk=true;
            for(int x=0;x<N;x++){
                for(int y=0;y<M;y++){
                    if(board2[x][y]=='+'){
                        if(board[x][y]!='b' && board[x][y]!='B'){
                            chk=false;
                            break;
                        }
                    }
                }
            }
            if(chk){
                break;
            }
            int nxx=cur.first+dir[i][0];
            int nxy=cur.second+dir[i][1];
            if(board2[nxx][nxy]=='#') continue;
            if(board[nxx][nxy]=='b' || board[nxx][nxy]=='B'){
                int bxx=nxx+dir[i][0];
                int bxy=nxy+dir[i][1];
                if(board2[bxx][bxy]=='#' || board[bxx][bxy]=='b' || board[bxx][bxy]=='B'){
                    continue;
                }
                board[bxx][bxy]=board[nxx][nxy];
            }
            board[nxx][nxy]=board[cur.first][cur.second];
            board[cur.first][cur.second]='.';
            cur={nxx,nxy};
        }
        bool solve=true;
        for(int x=0;x<N;x++){
            for(int y=0;y<M;y++){
                if(board2[x][y]=='+'){
                    if(board[x][y]!='b' && board[x][y]!='B'){
                        solve=false;
                    }
                }
                if(x==cur.first && y==cur.second){
                    if(board2[x][y]=='+') board[x][y]='W';
                    else board[x][y]='w';
                    continue;
                }
                if(board[x][y]=='b'){
                    if(board2[x][y]=='+') board[x][y]='B';
                    else board[x][y]='b';
                    continue;
                }
                if(board[x][y]=='B'){
                    if(board2[x][y]=='+') board[x][y]='B';
                    else board[x][y]='b';
                    continue;
                }
                board[x][y]=board2[x][y];
            }
        }
        if(solve){
            cout<<"Game "<<test_case<<": complete\n";
        }
        else cout<<"Game "<<test_case<<": incomplete\n";
        for(int x=0;x<N;x++){
            for(int y=0;y<M;y++){
                cout<<board[x][y];
            }
            cout<<'\n';
        }
    }
}