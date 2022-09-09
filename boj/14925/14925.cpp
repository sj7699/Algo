#include <stdio.h>
#include<queue>
#include<iostream>
#include<stack>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
void fast_io() {
  cin.tie(0)->sync_with_stdio(0);
}
int board[1002][1002];
int dp[1002][1002];
int main(){
    fast_io();
    int n,m;
    cin>>n>>m;
    int solve=0;
    for(int x=1;x<=n;x++){
        for(int y=1;y<=m;y++) {
            cin>>board[x][y];
            if(!board[x][y]){
                int now=2e9;
                now=min(dp[x-1][y],now);
                now=min(dp[x][y-1],now);
                now=min(dp[x-1][y-1],now);
                dp[x][y]=now+1;
                solve=max(dp[x][y],solve);
            }
        }
    }
    cout<<solve;
}