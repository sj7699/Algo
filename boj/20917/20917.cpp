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
int T;
int arr[200001];
int N,S;
bool chk(int a){
    auto e=arr+N;
    int cnt=0;
    auto now=arr;
    while(now!=e){
        now=lower_bound(now,arr+N,*now+a);
        cnt++;
    }
    if(cnt>=S) return true;
    else return false;
}
int main(){
    fast_io();
    cin>>T;
    while(T--){
        cin>>N>>S;
        for(int x=0;x<N;x++) cin>>arr[x];
        sort(arr,arr+N);
        int l=1;
        int r=arr[N-1]-arr[0];
        int ans=1;
        while(l<=r){
            int mid=(l+r)/2;
            if(chk(mid)){
                l=mid+1;
                ans=max(ans,mid);
            }
            else r=mid-1;
        }
        cout<<ans<<'\n';
    }
}
