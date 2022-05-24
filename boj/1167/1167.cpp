#include<stdio.h>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
int solve=0;
vector<vector<pair<int,int>>> edge;
int N;
int visit[100001];
int bfs(int start){
    int ret=start;
    int dist=0;
    for(int x=0;x<=N;x++) visit[x]=false;
    visit[start]=true;
    queue<pair<int,int>> Q;
    Q.push({start,0});
    while(!Q.empty()){
        int now=Q.front().first;
        int d=Q.front().second;
        Q.pop();
        if(d>dist){
            dist=d;
            solve=max(solve,d);
            ret=now;
        }
        for(auto i : edge[now]){
            if(!visit[i.first]){
                visit[i.first]=true;
                Q.push({i.first,i.second+d});
            }
        }
    }
    return ret;
}
int main(){
    scanf("%i",&N);
    for(int x=0;x<=N;x++) edge.push_back(vector<pair<int,int>>());
    for(int x=0;x<N;x++){
        int now;
        scanf("%i",&now);
        int input=1;
        while(input!=-1){
            scanf("%i",&input);
            if(input==-1) break;
            int dist;
            scanf("%i",&dist);
            edge[now].push_back({input,dist});
        }
    }
    bfs(bfs(1));
    printf("%i",solve);
}