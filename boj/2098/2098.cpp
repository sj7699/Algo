#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int edge[17][17];
int dp[17][65536];
int N;
int tsp(int now,int visit){  
    if(visit==(1<<N)-1){
        return edge[now][0];
    }
    if(dp[now][visit] != 2e9) return dp[now][visit];

    for(int x=0;x<N;x++){
        if(visit&(1<<x)) continue;
        if(!edge[now][x]) continue;
        int ret= tsp(x,visit|(1<<x));
        if(ret) dp[now][visit]=min(edge[now][x]+ret,dp[now][visit]);
    }
    return dp[now][visit];
}
int main(){
    cin>>N;
    for(int x=0;x<N;x++){
        for(int y=0;y<N;y++) cin>>edge[x][y];
        for(int y=0;y<65536;y++) dp[x][y]=2e9;
    }
    printf("%i",tsp(0,1));
}