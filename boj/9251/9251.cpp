#include<stdio.h>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
int dp[1001][1001];
int main(){
    string A,B;
    cin>>A>>B;
    int solve=0;
    for(int x=0;x<A.size();x++){
        for(int y=0;y<B.size();y++){
            if(A[x]==B[y]){
                dp[x+1][y+1]=dp[x][y]+1;
            }
            else{
                dp[x+1][y+1]=max(dp[x][y+1],dp[x+1][y]);
            }
            solve=max(solve,dp[x+1][y+1]);
        }
    }
    cout<<solve;
}