#include<stdio.h>
#include<queue>
using namespace std;
bool visited[400001];
int bfs(int start,int dest){    
    queue<pair<int,int>> Q;
    pair<int,int> t;
    if(start==dest){
        return 0;
    }
    if(start!=0){
        Q.push({start-1,1});
        visited[start-1]=true;
    }
    Q.push({start+1,1});
    visited[start+1]=true;
    Q.push({start*2,1});
    visited[start*2]=true;
    while(!Q.empty()){
        t=Q.front();
        if(t.first==dest){
            return t.second;
        }
        if(!visited[t.first+1] && (t.first)<=dest*2){
            Q.push({t.first+1,t.second+1});
            visited[t.first+1]=true;
        }
        if(t.first!=0){
            if(!visited[t.first-1] && (t.first-1)>=0){
                Q.push({t.first-1,t.second+1});
                visited[t.first-1]=true;
            }
            
        }
        if(!visited[t.first*2] && (t.first*2)<=dest*2){
            Q.push({t.first*2,t.second+1});
            visited[t.first*2]=true;
        }
        Q.pop();
    }
    return 0;
}
int main(){
    int N,K,max_p;
    scanf("%i%i",&N,&K);
    printf("%i",bfs(N,K));
}