#include<stdio.h>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<iostream>
#include<string>
#include<map>
using namespace std;
bool pel[2501][2501];
int dp[2501];
int main(){
    string a;
    cin>>a;
    int N=a.size();
    for(int x=0;x<N;x++){
        pel[x][x]=true;
    }
    for(int x=1;x<N;x++){
        for(int y=x-1;y>=0;y--){
            int next=2*x-y;
            if(next>=N) break;
            if(a[y]!=a[next]) break;
            pel[y][next]=true;
        }
        if(a[x]==a[x-1]){
            pel[x-1][x]=true;
            for(int y=x+1;y<=N-1;y++){
                int next=x-1-(y-x);
                if(next<0) break;
                if(a[next]!=a[y]) break;
                pel[next][y]=true;
            }
        }
    }
    dp[0]=1;
    for(int x=1;x<=N-1;x++){
        dp[x]=dp[x-1]+1;
        if(pel[0][x]){
            dp[x]=1;
            continue;
        }
        for(int y=1;y<=x;y++){
            if(pel[y][x]){
                dp[x]=min(dp[x],dp[y-1]+1);
            }
        }
    }
    cout<<dp[N-1];
}
