#include<stdio.h>
#include<queue>
#include<vector>
#include<iostream>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
long long mod=1e9+7LL;
long long dp[301][8000][2];
int main(){
    long long N,M;
    cin>>N>>M;
    string input;
    cin>>input;
    long long k=0;
    for(auto i : input){
        k+='z'-i;
    }
    M=min(k,M);
    for(int x=input[0];x<='z';x++){
        int now=x-input[0];
        if(x=='z'){
            dp[0][now][1]=1;
        }
        else{
            dp[0][now][0]=1;
        }
    }
    for(int x=1;x<N;x++){
        for(int y=0;y<8000;y++){
            if(dp[x-1][y][0]){
                for(int z=input[x];z<='z';z++){
                    int now=z-input[x];
                    if(z=='z'){
                        dp[x][y+now][1]=(dp[x][y+now][1]+dp[x-1][y][0])%mod;
                        continue;
                    }
                    dp[x][y+now][0]=(dp[x][y+now][0]+dp[x-1][y][0])%mod;          
                }
            }
            if(dp[x-1][y][1]){
                for(int z=input[x];z<='z';z++){
                    int now=z-input[x];
                    dp[x][y+now][1]=(dp[x][y+now][1]+dp[x-1][y][1])%mod;          
                }
            }
        }
    }
    long long solve=dp[N-1][M][0];
    for(int x=M;x>=0;x--){
        solve=(solve+dp[N-1][x][1])%mod;
    }
    cout<<solve;
}