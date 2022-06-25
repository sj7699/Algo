#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
#include<map>
#include<stack>
#include<queue>
#include<set>
using namespace std;
int dir[4][2]={{-1,0},{0,-1},{1,0},{0,1}};
int arr[500][500];
int dp[500][500][4];
int main(){
    int N,M;
    scanf("%i%i",&N,&M);
    for(int x=0;x<N;x++){
        for(int y=0;y<M;y++) scanf("%i",&arr[x][y]);
    }
    dp[0][0][0]=1;
    for(int i=0;i<8;i++){
        for(int x=0;x<N;x++){
            for(int y=0;y<M;y++){
                for(int z=0;z<4;z++){
                    int cx=dir[z][0]+x;
                    int cy=dir[z][1]+y;
                    if(cx<0 || cy<0 || cx>=N || cy>=M) continue;
                    if(arr[x][y]>=arr[cx][cy]) continue;
                    int temp=0;
                    for(int w=0;w<4;w++){
                        if(z>=2 && w==z-2) continue;
                        if(z<2 && w==z+2) continue;
                        temp+=dp[cx][cy][w];
                    }
                    dp[x][y][z]=temp;
                }
            }
        }
    }
    int solve=0;
    for(int x=0;x<4;x++) solve+=dp[N-1][M-1][x];
    printf("%i",solve);
}