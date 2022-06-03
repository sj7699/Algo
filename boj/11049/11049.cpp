#include<iostream>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<vector>
using namespace std;
long long arr[501][2];
long long dp[501][501];
int main(){
    int N;
    cin>>N;
    for(int x=0;x<N;x++) cin>>arr[x][0]>>arr[x][1];
    for(int x=2;x<N+1;x++){
        for(int y=0;y<=N-x;y++){
            long long temp=4e9;
            for(int z=y;z<=y+x-2;z++){
                temp=min(arr[y][0]*arr[z][1]*arr[y+x-1][1]+dp[y][z]+dp[z+1][y+x-1],temp);
            }
            dp[y][y+x-1]=temp;
        }
    }
    cout<<dp[0][N-1];
}