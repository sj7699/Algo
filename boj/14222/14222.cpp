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
int arr[51];
bool chk[51];
int main(){
    fast_io();
    int N,K;
    cin>>N>>K;
    for(int x=1;x<=N;x++) cin>>arr[x];
    sort(arr+1,arr+N+1);
    for(int x=1;x<=N;x++) {
        if(chk[arr[x]]){
            int now=arr[x];
            while(now<=N){
                if(!chk[now]){
                    chk[now]=true;
                    break;
                }
                now+=K;
            }
        }
        chk[arr[x]]=true;
    }
    int solve=0;
    for(int x=1;x<=N;x++) if(chk[x]) solve++;
    if(solve!=N) cout<<0;
    else cout<<1;
}
