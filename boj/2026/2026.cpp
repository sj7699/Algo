#include <stdio.h>
#include<queue>
#include<iostream>
#include<stack>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
void fast_io() {
  cin.tie(0)->sync_with_stdio(0);
}
int K,N,F;
bool chk[901][901];
bool solve=false;
int arr[63];
void dfs(int now){
    if(solve) return;
    if(now==K){
        solve=true;
        for(int x=0;x<K;x++) cout<<arr[x]<<'\n';
        return;
    }
    if(now==0){
        for(int x=1;x<=N;x++){
            arr[0]=x;
            dfs(now+1);
        }
    }
    else{
        for(int x=arr[now-1]+1;x<=N;x++){
            bool chk2=true;
            for(int y=0;y<now;y++){
                if(!chk[x][arr[y]]) chk2=false;
            }
            if(chk2){
                arr[now]=x;
                dfs(now+1);
            }
        }
    }
}
int main(){
    fast_io();
    cin>>K>>N>>F;
    for(int x=0;x<F;x++){
        int src,dst;
        cin>>src>>dst;
        chk[src][dst]=true;
        chk[dst][src]=true;
    }
    dfs(0);
    if(!solve) cout<<-1;
}
