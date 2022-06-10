#include<stdio.h>
#include<queue>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
int arr[1002][1002];
int dp[1002][1002];
int dp2[1002][1002];
int main(){
    int N;
    scanf("%i",&N);
    for(int x=1;x<=N;x++){
        for(int y=1;y<=N;y++){
            scanf("%i",&arr[x][y]);
        }
    }
    for(int x=1;x<=N;x++){
        for(int y=1;y<=N;y++){
            int now=max(dp[x-1][y],dp[x][y-1]);
            dp[x][y]=now+arr[x][y];
        }
    }
    for(int x=N;x>=1;x--){
        for(int y=N;y>=1;y--){
            int now=max(dp2[x+1][y],dp2[x][y+1]);
            dp2[x][y]=now+arr[x][y];
        }
    }
    int P;
    scanf("%i",&P);
    int solve=0;
    for(int x=0;x<P;x++){
        int ix,iy;
        scanf("%i%i",&ix,&iy);
        solve=max(solve,dp[ix][iy]+dp2[ix][iy]-arr[ix][iy]);
    }
    printf("%i",solve);
}