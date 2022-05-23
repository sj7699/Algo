#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<iostream>
using namespace std;
int visit[100001];
int N,K;
int solve=0;
void bfs(){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> Q;
    Q.push({0,N});
    visit[N]=0;
    while(!Q.empty()){
        int now=Q.top().second;
        int dist=Q.top().first;
        if(dist>visit[K]) return;
        if(now==K){
            solve++;
        }
        Q.pop();
        if(now<100000){
            if(visit[now+1]>dist+1){
                visit[now+1]=dist+1;
                Q.push({dist+1,now+1});
            }
        }
        if(now>0){
            if(visit[now-1]>dist+1){
                visit[now-1]=dist+1;
                Q.push({dist+1,now-1});
            }
        }
        if(now*2<=100000){
            if(visit[now*2]>dist){
                visit[now*2]=dist;
                Q.push({dist,now*2});
            }
        }
    }
}
int main(){
    cin>>N>>K;
    for(int x=0;x<=100000;x++) visit[x]=2e9;
    bfs();
    cout<<visit[K];
}

