#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
#include<map>
#include<set>
#include<stack>
#include<queue>
using namespace std;
int N,M;
int arr[1200][1200];
int dp[1200][1200];
int dp2[1200][1200][2];
int main(){
    cin>>N>>M;
    for(int x=2;x<=N+1;x++){
        for(int y=2;y<=M+1;y++){
            cin>>arr[x][y];
        }
    }
    int ans=0;
    for(int x=2;x<=M+2;x++){
        for(int y=2;y<=N+1;y++){
            dp[y][x]=max(arr[y][x]+dp[y-1][x-1],arr[y][x]+dp[y+1][x-1]);
            dp[y][x]=max(dp[y][x],dp[y][x-2]+arr[y][x-1]+arr[y][x]);
            ans=max(dp[y][x],ans);
        }
    }
    for(int x=2;x<=M+2;x++){
        for(int y=2;y<=N+1;y++){
            for(int z=0;z<2;z++){
                if(z==0){
                    dp2[y][x][z]=max(dp2[y][x-1][1]+arr[y][x],dp2[y-1][x-1][0]+arr[y][x]);
                }
                if(z==1){
                    dp2[y][x][z]=max(dp2[y][x-1][0]+arr[y][x],dp2[y+1][x-1][1]+arr[y][x]);
                }
                ans=max(ans,dp2[y][x][z]);
            }
        }
    }
    cout<<ans;
}