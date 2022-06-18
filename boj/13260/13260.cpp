#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<set>
using namespace std;
vector<int> vec;
int dp[1001][1001];
int dp2[1001][1001];
int main(){
    int N,M;
    cin>>N>>M;
    vector<int> vec;
    vec.push_back(0);
    for(int x=0;x<M;x++){
        int input;
        cin>>input;
        vec.push_back(input);
    }
    vec.push_back(N);
    M+=2;
    sort(vec.begin(),vec.end());
    for(int x=0;x<M;x++){
        for(int y=x;y<M;y++){
            dp[x][y]=0;
        }
    }
    for(int x=2;x<=M;x++){
        for(int y=0;y+x<M;y++){
            dp[y][y+x]=2e9;
            for(int z=y;z<=y+x;z++){
                dp[y][y+x]=min(dp[y][y+x],dp[y][z]+dp[z][y+x]);
            }
            dp[y][y+x]+=vec[y+x]-vec[y];
        }
    }
    cout<<dp[0][M-1];
}