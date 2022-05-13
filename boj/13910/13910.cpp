#include<stdio.h>
#include<iostream>
#include<set>
#include<algorithm>
using namespace std;
long long INF=1000000000;
long long dp[10001];
int main(){
    int N,M;
    cin>>N>>M;
    vector<int> wok;
    set<int> swok;
    for(int x=0;x<M;x++){
        int input;
        cin>>input;
        wok.push_back(input);
    }
    for(int x=0;x<M;x++){
        swok.insert(wok[x]);
    }
    for(int x=0;x<M;x++){
        for(int y=x+1;y<M;y++){
            swok.insert(wok[x]+wok[y]);
        }
    }
    for(int x=1;x<=N;x++){
        dp[x]=INF;
    }
    for(auto x : swok){
        int now=x;
        if(now>N) continue;
        dp[now]=1;
        for(int y=1;y<=N;y++){
            if(dp[y]!=INF){
                if(y+now<=N){
                    dp[y+now]=min(dp[y]+1,dp[y+now]);
                }
            }
        }
    }  
    if(dp[N]==INF) dp[N]=-1;
    cout<<dp[N];
}
