#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int N,M;
vector<int> memory;
vector<int> cancel;
int dp[10001];
int main(){
    cin>>N>>M;
    for(int x=0;x<N;x++){
        int input;
        cin>>input;
        memory.push_back(input);
    }
    for(int x=0;x<N;x++){
        int input;
        cin>>input;
        cancel.push_back(input);
    }
    for(int x=0;x<N;x++){
        int nowm=memory[x];
        int nowc=cancel[x];
        for(int y=10001;y>=0;y--){
            if(dp[y]){
                int next=y+nowc;
                dp[next]=max(dp[y]+nowm,dp[next]);
            }
        }
        dp[nowc]=max(dp[nowc],nowm);
    }
    for(int x=0;x<=10001;x++){
        if(dp[x]>=M){
            cout<<x;
            break;
        }
    }
    
}