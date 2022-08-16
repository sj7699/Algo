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
int N,K;
int arr[300001];
bool chk[300001];
int main(){
    fast_io();
    cin>>N>>K;
    long long ans=0;
    for(int x=0;x<N;x++) cin>>arr[x];
    priority_queue<pair<int,int>> pq;
    for(int x=0;x<N-1;x++){
        pq.push({arr[x+1]-arr[x],x+1});
    }
    int mn=1e9+1;
    int mx=-1;
    for(int x=0;x<K-1;x++){
        chk[pq.top().second]=true;
        pq.pop();
    }
    for(int x=0;x<N;x++){
        if(chk[x]){
            ans+=(long long)(mx-mn);
            mx=arr[x];
            mn=arr[x];
        }
        mx=max(arr[x],mx);
        mn=min(arr[x],mn);
    }
    ans+=(long long)(mx-mn);
    cout<<ans;
}
