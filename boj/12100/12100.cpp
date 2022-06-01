#include <iostream>
#include <vector>
#include <queue>
#include<algorithm>
#include<string>
using namespace std;
int N;
int board[21][21];
bool chk[21][21];
int lim=5;
int solve;
void recur(int dir,int step){
    if(step==lim){
        return;
    }
    int sav[21][21];
    for(int x=0;x<N;x++){
        for(int y=0;y<N;y++){
            chk[x][y]=false;
            sav[x][y]=board[x][y];
        }
    }
    if(dir==0){
        for(int x=1;x<N;x++){
            for(int y=0;y<N;y++){
                if(!board[x][y]) continue;
                for(int z=x;z>=1;z--){
                    if(board[z-1][y] && !chk[z-1][y]){
                        if(board[z][y]==board[z-1][y]){
                            board[z-1][y]*=2;
                            board[z][y]=0;
                            chk[z-1][y]=true;
                        }
                        break;
                    }
                    if(board[z-1][y]) break;
                    board[z-1][y]=board[z][y];
                    board[z][y]=0;
                }
            }
        }
    }
    if(dir==1){
        for(int x=N-2;x>=0;x--){
            for(int y=0;y<N;y++){
                if(!board[x][y]) continue;
                for(int z=x;z<=N-2;z++){
                    if(board[z+1][y] && !chk[z+1][y]){
                        if(board[z][y]==board[z+1][y]){
                            board[z+1][y]*=2;
                            board[z][y]=0;
                            chk[z+1][y]=true;
                        }
                        break;
                    }
                    if(board[z+1][y]) break;
                    board[z+1][y]=board[z][y];
                    board[z][y]=0;
                }
            }
        }
    }
    if(dir==2){
        for(int x=1;x<N;x++){
            for(int y=0;y<N;y++){
                if(!board[y][x]) continue;
                for(int z=x;z>=1;z--){
                    if(board[y][z-1] && !chk[y][z-1]){
                        if(board[y][z]==board[y][z-1]){
                            board[y][z-1]*=2;
                            board[y][z]=0;
                            chk[y][z-1]=true;
                        }
                        break;
                    }
                    if(board[y][z-1]) break;
                    board[y][z-1]=board[y][z];
                    board[y][z]=0;
                }
            }
        }
    }
    if(dir==3){
        for(int x=N-2;x>=0;x--){
            for(int y=0;y<N;y++){
                if(!board[y][x]) continue;
                for(int z=x;z<=N-2;z++){
                    if(board[y][z+1] && !chk[y][z+1]){
                        if(board[y][z]==board[y][z+1]){
                            board[y][z+1]*=2;
                            board[y][z]=0;
                            chk[y][z+1]=true;
                        }
                        break;
                    }
                    if(board[y][z+1]) break;
                    board[y][z+1]=board[y][z];
                    board[y][z]=0;
                }
            }
        }
    }
    for(int x=0;x<4;x++){
        recur(x,step+1);
    }
    for(int x=0;x<N;x++){
        for(int y=0;y<N;y++){
            solve=max(solve,board[x][y]);
            board[x][y]=sav[x][y];
        }
    }
}
int main(){
    cin>>N;
    for(int x=0;x<N;x++){
        for(int y=0;y<N;y++){
            cin>>board[x][y];
        }
    }
    for(int x=0;x<4;x++){
        recur(x,0);
    }
    cout<<solve;
}