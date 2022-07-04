#include<stdio.h>
#include<vector>
#include<algorithm>
#include<bitset>
#include<string>
#include<iostream>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<functional>
using namespace std;
void fast_io() {
  cin.tie(0)->sync_with_stdio(0);
}
int N;
vector<vector<int>> E;
bool bomb[200001];
int ans;
vector<int> cantgo;
bool chk(int a){
    bool wego[200001];
    vector<int> visit(N+1,2e9);
    queue<pair<int,int>> q2;
    for(int x=1;x<=N;x++) {
        wego[x]=false;
        if(bomb[x] && cantgo[x]>=a){
            q2.push({x,0});
            visit[x]=0;
        }
        else{
            visit[x]=2e9;
        }
    }    
    while(!q2.empty()){
        int now=q2.front().first;
        int dist=q2.front().second;
        q2.pop();
        if(dist==a) break;
        wego[now]=true;
        for(auto i : E[now]){
            if(visit[i]>dist+1 && bomb[i]){
                visit[i]=dist+1;
                q2.push({i,dist+1});
            }
        }
    }
    for(int x=1;x<=N;x++){
        if(bomb[x] && !wego[x]) return false;
    }
    return true;
}
int main(){
    cin>>N;
    queue<pair<int,int>> q;
    cantgo.push_back(0);
    for(int x=1;x<=N;x++){
        cin>>bomb[x];
        if(!bomb[x]){
            q.push({x,0});
            cantgo.push_back(0);
        }
        else cantgo.push_back(2e9);
        E.push_back(vector<int>());
    }
    E.push_back(vector<int>());
    for(int x=0;x<N-1;x++){
        int src,dst;
        cin>>src>>dst;
        E[src].push_back(dst);
        E[dst].push_back(src);
    }
    while(!q.empty()){
        int now=q.front().first;
        int dist=q.front().second;
        q.pop();
        for(auto i : E[now]){
            if(dist+1<cantgo[i]){
                cantgo[i]=dist+1;
                q.push({i,dist+1});
            }
        }
    }
    int l=1;
    int r=N;
    while(l<=r){
        int mid=(l+r)/2;
        if(chk(mid)){
            ans=max(ans,mid);
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    cout<<ans;
}