v#include<iostream>
#include<queue>
#define limit_floor 1000001
using namespace std;
bool visited[limit_floor];
int bfs(int start,int dest,int max_floor,int upf,int df){
    if(start==dest){
        return 0;
    }
    queue<pair<int,int>> Q;
    if(start+upf<=max_floor){
        Q.push({start+upf,1});
        visited[start+upf]=true;
    }
    if(start-df>=1){
        Q.push({start-df,1});
        visited[start-df]=true;
    }
    while(!Q.empty()){
        int temp=Q.front().first;
        int step=Q.front().second;
        Q.pop();
        if(temp==dest){
            return step;
        }
        if(temp+upf<=max_floor && !visited[temp+upf]){
        Q.push({temp+upf,step+1});
        visited[temp+upf]=true;
        }
        if(temp-df>=1 && !visited[temp-df]){
        Q.push({temp-df,step+1});
        visited[temp-df]=true;
        }
    }
    return -1;
}
int main(){
    int  F,S,G,U,D,result;
    cin>>F>>S>>G>>U>>D;
    result=bfs(S,G,F,U,D);
    if(result!=-1){
        printf("%i",result);
    }
    else{
        printf("use the stairs");
    }
}