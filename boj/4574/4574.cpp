#include<stdio.h>
#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int board[10][10];
bool visit[9][9];
bool cchk[9][9];
bool rchk[9][9];
bool bchk[3][3][9];
bool ee=false;
void recur(){
    if(ee) return;
    int cnt=0;
    for(int x=0;x<9;x++){
        int rcnt=0;
        for(int y=0;y<9;y++){
            if(board[x][y]) 
            {
                rcnt++;
                cnt++;
                continue;
            }
            if(x<=7 || y<=7){
                if(x<=7 && y==8){
                    if(board[x+1][y]) return;
                }
                if(y<=7 && x==8){
                    if(board[x][y+1]) return;
                }
                if(y<=7 && x==7){
                    if(board[x+1][y] && board[x][y+1]) return;
                }
            }
            if(x<=7){
                if(!board[x+1][y]){
                    for(int z=0;z<=8;z++){
                        if(!rchk[x][z] && !cchk[y][z] && !bchk[x/3][y/3][z]){
                            for(int w=0;w<=8;w++){
                                if(z!=w && !visit[min(z,w)][max(z,w)] && !cchk[y][w] && !rchk[x+1][w] && !bchk[(x+1)/3][y/3][w]){
                                    visit[min(z,w)][max(z,w)]=true;
                                    cchk[y][z]=true;
                                    rchk[x][z]=true;
                                    rchk[x+1][w]=true;
                                    cchk[y][w]=true;
                                    board[x][y]=z+1;
                                    board[x+1][y]=w+1;    
                                    bchk[x/3][y/3][z]=true;
                                    bchk[(x+1)/3][y/3][w]=true;
                                    recur();  
                                    if(ee) return;
                                    visit[min(z,w)][max(z,w)]=false;
                                    cchk[y][z]=false;
                                    rchk[x][z]=false;
                                    rchk[x+1][w]=false;
                                    cchk[y][w]=false;
                                    board[x][y]=0;
                                    board[x+1][y]=0;
                                    bchk[x/3][y/3][z]=false;
                                    bchk[(x+1)/3][y/3][w]=false;
                                }
                            }
                        }
                    }
                }
            }
            if(y<=7){
                if(!board[x][y+1]){
                    for(int z=0;z<=8;z++){
                        if(!rchk[x][z] && !cchk[y][z] &&!bchk[x/3][y/3][z]){
                            for(int w=0;w<=8;w++){
                                if(z!=w && !visit[min(z,w)][max(z,w)] && !cchk[y+1][w] && !rchk[x][w] && !bchk[x/3][(y+1)/3][w]){
                                    visit[min(z,w)][max(z,w)]=true;
                                    cchk[y][z]=true;
                                    rchk[x][z]=true;
                                    rchk[x][w]=true;
                                    cchk[y+1][w]=true;
                                    board[x][y]=z+1;
                                    board[x][y+1]=w+1;
                                    bchk[x/3][y/3][z]=true;
                                    bchk[x/3][(y+1)/3][w]=true;
                                    recur();
                                    if(ee) return;
                                    visit[min(z,w)][max(z,w)]=false;
                                    cchk[y][z]=false;
                                    rchk[x][z]=false;
                                    rchk[x][w]=false;
                                    cchk[y+1][w]=false;
                                    board[x][y]=0;
                                    board[x][y+1]=0;
                                    bchk[x/3][y/3][z]=false;
                                    bchk[x/3][(y+1)/3][w]=false;
                                }
                            }
                        }
                    }
                    
                }
            }
            if(rcnt!=9) return;
        }
    }
    if(cnt==81){
        ee=true;
        return;
    }
}
int main(){
    int N=1;
    int cnt=1;
    while(N!=0){
        cin>>N;
        if(N==0) break;
        for(int x=0;x<9;x++){
            for(int y=0;y<9;y++){
                board[x][y]=0;
                cchk[x][y]=false;
                rchk[x][y]=false;
                visit[x][y]=false;
            }
        }
        for(int x=0;x<3;x++){
            for(int y=0;y<3;y++){
                for(int z=0;z<9;z++){
                    bchk[x][y][z]=false;
                }
            }
        }
        for(int x=0;x<N;x++){
            int n1,n2;
            string loc1,loc2;
            cin>>n1>>loc1>>n2>>loc2;
            int rloc1=loc1[0]-'A';
            int rloc2=loc2[0]-'A';
            int cloc1=loc1[1]-'1';
            int cloc2=loc2[1]-'1';
            board[rloc1][cloc1]=n1;
            board[rloc2][cloc2]=n2;
            rchk[rloc1][n1-1]=true;
            rchk[rloc2][n2-1]=true;
            cchk[cloc1][n1-1]=true;
            cchk[cloc2][n2-1]=true;
            bchk[rloc1/3][cloc1/3][n1-1]=true;
            bchk[rloc2/3][cloc2/3][n2-1]=true;
            visit[min(n1,n2)-1][max(n1,n2)-1]=true;
        }
        for(int x=0;x<9;x++){
            int n=x+1;
            string loc;
            cin>>loc;
            int rloc=loc[0]-'A';
            int cloc=loc[1]-'1';
            board[rloc][cloc]=n;
            rchk[rloc][n-1]=true;
            cchk[cloc][n-1]=true;
            bchk[rloc/3][cloc/3][n-1]=true;
        }
        recur();
        cout<<"Puzzle "<<cnt<<'\n';
        for(int x=0;x<9;x++){
            for(int y=0;y<9;y++){
                cout<<board[x][y];
            }
            cout<<'\n';
        }
        cnt++;
        ee=false;
    }
}