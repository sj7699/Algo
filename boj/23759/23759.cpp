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
int dp[500001][11][26];
int main(){
    fast_io();
    int N,K;
    cin>>N>>K;
    int solve=0;
    for(int x=0;x<N;x++){
        string input;
        cin>>input;
        int now=1;
        for(int y=0;y<K;y++){
            if(x==0){
                dp[x][y][input[y]-'a']=1;
            }
            else{
                for(int z='a';z<='z';z++){
                    if(z==input[y]){
                        now=max(now,dp[x-1][y][z-'a']+1);
                    }
                    else dp[x][y][z-'a']=dp[x-1][y][z-'a'];
                }
            }
        }
        solve=max(solve,now);
        for(int y=0;y<K;y++) dp[x][y][input[y]-'a']=now;
    }
    cout<<N-solve;
}