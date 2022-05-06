#include<stdio.h>
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<queue>
using namespace std;
bool node[11][11];
bool tvisit[11];
int solve=100000000;
int N;
int ingu[11];
int bfs(int start){
    bool visit[11];
    int ret=1;
    for(int x=0;x<=N;x++){
        visit[x]=false;
    }
    visit[start]=true;
    queue<int> Q;
    Q.push(start);
    while(!Q.empty()){
        int now=Q.front();
        Q.pop();
        for(int x=1;x<=N;x++){
            if(!visit[x] && node[now][x] && !tvisit[x]){
                visit[x]=true;
                Q.push(x);
                ret++;
            }
        }
    }
    return ret;
}
void recur(vector<int> vec,int proc){
    if(proc==N+1){
        if(vec.size()==0){
        }
        else{
            int temp=0;
            for(int x=1;x<=N;x++) tvisit[x]=true;
            for(int x=0;x<vec.size();x++){
                tvisit[vec[x]]=false;
                temp+=ingu[vec[x]];
            }
            if(bfs(vec[0])!=vec.size()){
                return;
            }
            for(int x=0;x<=N;x++) tvisit[x]=!tvisit[x];
            int temp2=0;
            for(int x=1;x<=N;x++){
                if(!tvisit[x]){
                    if(bfs(x)==(N-vec.size())){
                        for(int y=1;y<=N;y++){
                            if(!tvisit[y]){
                                temp2+=ingu[y];
                            }
                        }
                        solve=min(solve,abs(temp-temp2));
                        return;
                    }
                    else return;
                }
            }
        }
        return;
    }
    recur(vec,proc+1);
    vec.push_back(proc);
    recur(vec,proc+1);
}
int main(){
    cin>>N;
    for(int x=1;x<=N;x++){
        cin>>ingu[x];
    }
    for(int x=1;x<=N;x++){
        int temp;
        cin>>temp;
        for(int y=0;y<temp;y++){
            int input;
            cin>>input;
            node[x][input]=true;
        }
    }
    recur(vector<int>(),1);
    if(solve==100000000) solve=-1;
    cout<<solve;
}