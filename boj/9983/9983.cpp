#include<stdio.h>
#include<queue>
#include<vector>
#include<iostream>
#include<map>
#include<set>
#include<stack>
#include<algorithm>
using namespace std;
void fast_io() {
  cin.tie(0)->sync_with_stdio(0);
}
int dir[8][2]={{0,1},{1,1},{1,0},{1,-1},{-1,0},{-1,-1},{0,-1},{-1,1}};
int knight[8][2]={{2,1},{1,2},{-2,1},{-2,-1},{2,-1},{1,-2},{-1,-2},{-1,2}};
bool off[16][16];
int main(){
    fast_io();
    string input;
    while(cin>>input){
        int w,h,k;
        k=0;
        cin>>w>>h;
        char board[11][11];
        int gimool[16][2];
        for(int x=0;x<h;x++){
            for(int y=0;y<w;y++){
                cin>>board[x][y];
                if(board[x][y]!='E'){
                    gimool[k][0]=x;
                    gimool[k++][1]=y;
                }
            }
        }
        int solve=k;
        for(int x=0;x<(1<<k);x++){
            int tmp=k;
            bool chk=true;
            for(int y=0;y<h;y++){
                for(int z=0;z<w;z++) off[y][z]=false;
            }
            for(int y=0;y<k;y++){
                if(x&(1<<y)){
                    off[gimool[y][0]][gimool[y][1]]=true;
                }
            }
            for(int y=0;y<k;y++){
                if(x&(1<<y)){
                    tmp--;
                    continue;
                }
                else{
                    int nowx=gimool[y][0];
                    int nowy=gimool[y][1];
                    if(board[nowx][nowy]=='K'){
                        for(int z=0;z<8;z++){
                            int nx=dir[z][0]+nowx;
                            int ny=dir[z][1]+nowy;
                            if(nx<0 || ny<0 || nx>=h || ny>=w) continue;
                            if(board[nx][ny]!='E' && !off[nx][ny]) chk=false;
                        }
                    }
                    if(board[nowx][nowy]=='N'){
                        for(int z=0;z<8;z++){
                            int nx=knight[z][0]+nowx;
                            int ny=knight[z][1]+nowy;
                            if(nx<0 || ny<0 || nx>=h || ny>=w) continue;
                            if(board[nx][ny]!='E'&& !off[nx][ny]) chk=false;
                        }
                    }
                    if(board[nowx][nowy]=='Q'){
                        for(int z=1;z<=10;z++){
                            for(int i=0;i<8;i++){
                                int nx=dir[i][0]*z+nowx;
                                int ny=dir[i][1]*z+nowy;
                                if(nx<0 || ny<0 || nx>=h || ny>=w) continue;
                                if(board[nx][ny]!='E'&& !off[nx][ny]) chk=false;
                            }
                        }
                    }
                    if(board[nowx][nowy]=='R'){
                        for(int z=1;z<=10;z++){
                            for(int i=0;i<8;i+=2){
                                int nx=dir[i][0]*z+nowx;
                                int ny=dir[i][1]*z+nowy;
                                if(nx<0 || ny<0 || nx>=h || ny>=w) continue;
                                if(board[nx][ny]!='E'&& !off[nx][ny]) chk=false;
                            }
                        }
                    }
                    if(board[nowx][nowy]=='B'){
                        for(int z=1;z<=10;z++){
                            for(int i=1;i<8;i+=2){
                                int nx=dir[i][0]*z+nowx;
                                int ny=dir[i][1]*z+nowy;
                                if(nx<0 || ny<0 || nx>=h || ny>=w) continue;
                                if(board[nx][ny]!='E'&& !off[nx][ny]) chk=false;
                            }
                        }
                    }
                }
            }
            if(chk) solve=min(solve,k-tmp);
        }
        cout<<"Minimum Number of Pieces to be removed: "<<solve<<'\n';
        cin>>input;
    }
}