#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<iostream>
using namespace std;
int N;
int board[3][2];
int main(){
    cin>>N;
    for(int x=0;x<3;x++){
        cin>>board[x][0];
        board[x][1]=board[x][0];
    }
    for(int x=1;x<N;x++){
        int input[3][2];
        for(int y=0;y<3;y++){
            cin>>input[y][1];
        }
        for(int y=0;y<3;y++){
            int mx=0;
            int mn=2e9;
            for(int z=0;z<3;z++){
                if(y+z==2 && y!=z) continue;
                for(int w=0;w<2;w++){
                    mx=max(board[z][w],mx);
                    mn=min(board[z][w],mn);
                }
            }
            input[y][0]=input[y][1]+mx;
            input[y][1]=input[y][1]+mn;
        }
        for(int y=0;y<3;y++){
           board[y][0]=input[y][0];
            board[y][1]=input[y][1];
        }
    }
    int smx=0;
    int smn=2e9;
    for(int x=0;x<3;x++){
        smx=max(smx,board[x][0]);
        smn=min(smn,board[x][1]);
    }
    cout<<smx<<" "<<smn;
}
