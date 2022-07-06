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
int main(){
    fast_io();
    int T;
    cin>>T;
    while(T--){
        int N,M;
        cin>>N>>M;
        int board[51][51];
        for(int x=0;x<M;x+=2){
            if(x/2%2==0){
                board[0][x]=1;
                board[0][x+1]=0;
            }
            else{
                board[0][x]=0;
                board[0][x+1]=1;
            }
        }
        for(int x=1;x<N;x++){
            for(int y=0;y<M;y++){
                if(x%2==1){
                    board[x][y]=(1-board[x-1][y]);
                }
                else{
                    board[x][y]=board[x-1][y];
                }
            }
        }
        for(int x=0;x<N;x++){
            for(int y=0;y<M;y++){
                cout<<board[x][y]<<" ";
            }
            cout<<'\n';
        }
    }
}