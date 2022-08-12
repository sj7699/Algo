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
int arr[5001];
int N,M;
bool chk(int a){
    int mn=1e9;
    int mx=-1;
    int cnt=1;
    for(int x=0;x<N;x++){
        mn=min(mn,arr[x]);
        mx=max(mx,arr[x]);
        if(mx-mn>a){
            cnt++;
            mn=arr[x];
            mx=arr[x];
        }
    }
    if(cnt<=M) return true;
    else return false;
}
int main() {
    fast_io();
    cin>>N>>M;
    int ans=1e9;
    for(int x=0;x<N;x++){
        cin>>arr[x];
    }
    int l=0;
    int r=1e8;
    while(l<=r){
        int mid=(l+r)/2;
        if(chk(mid)){
            r=mid-1;
            ans=min(ans,mid);
        }
        else l=mid+1;
    }
    cout<<ans;
}