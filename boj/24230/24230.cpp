#include<stdio.h>
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
bool visit[200001];
int colour[200001];
int r=2e9;
int main(){
    int N;
    scanf("%i",&N);
    vector<vector<int>> edge(N+1,vector<int>());
    int ans=0;
    for(int x=1;x<=N;x++) scanf("%i",&colour[x]);
    for(int x=0;x<N-1;x++){
        int a,b;
        scanf("%i%i",&a,&b);
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    queue<pair<int,int>> Q;
    Q.push({1,colour[1]});
    visit[1]=true;
    if(colour[1]) ans++;
    while(!Q.empty()){
        int now=Q.front().first;
        int nowc=Q.front().second;
        Q.pop();
        for(auto i : edge[now]){
            if(visit[i]) continue;
            if(colour[i]==nowc){
                visit[i]=true;
                Q.push({i,nowc});
            }
            else{
                ans++;
                visit[i]=true;
                Q.push({i,colour[i]});
            }
        }
    }
    printf("%i",ans);
}