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
int arr[100001];
int pre[100001];
int main(){
    fast_io();
    int N;
    int s=0;
    int mx=0;
    cin>>N;
    for(int x=0;x<N;x++){
        cin>>arr[x];
        s+=arr[x];
        pre[x]+=arr[x];
        pre[x]+=pre[x-1];
        if(x!=0 && x!=N-1) mx=max(mx,arr[x]);
    }
    int now=pre[N-1]-arr[N-1];
    int ans=0;
    for(int x=1;x<N-1;x++){
        ans=max(ans,now-2*arr[x]+pre[x]);
    }
    for(int x=N-1;x>=0;x--){
        pre[x]=arr[x];
        pre[x]+=pre[x+1];
    }
    now=pre[0]-arr[0];
    for(int x=N-2;x>=1;x--){
        ans=max(ans,now-2*arr[x]+pre[x]);
    }
    ans=max(ans,s-arr[0]-arr[N-1]+mx);
    cout<<ans;
}
