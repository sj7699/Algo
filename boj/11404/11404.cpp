#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int n,m;
int dist[101][101];
int cost[101][101];
vector<vector<int>> edge;
void bfs(int start){
    queue<pair<int,int>> Q;
    Q.push({start,0});
    dist[start][start]=0;
    while(!Q.empty()){
        int now=Q.front().first;
        int nd=Q.front().second;
        Q.pop();
        for(auto i : edge[now]){
            if(dist[start][i]>(nd+cost[now][i])){
                dist[start][i]=nd+cost[now][i];
                Q.push({i,nd+cost[now][i]});
            }
        }
    }
}
int main(){
    scanf("%i%i",&n,&m);
    for(int x=0;x<=n;x++){
        edge.push_back(vector<int>());
    }
    for(int x=0;x<=100;x++){
        for(int y=0;y<=100;y++){
            dist[x][y]=2e9;
            cost[x][y]=2e9;
        }
    }
    for(int x=0;x<m;x++){
        int src,dst,nc;
        scanf("%i%i%i",&src,&dst,&nc);
        edge[src].push_back(dst);
        cost[src][dst]=min(cost[src][dst],nc);
    }
    for(int x=1;x<=n;x++){
        bfs(x);
    }
    for(int x=1;x<=n;x++){
        for(int y=1;y<=n;y++){
            if(dist[x][y]==2e9) dist[x][y]=0;
            printf("%i ",dist[x][y]);
        }
        printf("\n");
    }
}
