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
long long mod=1000000007;
int main(){
    fast_io();
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        vector<long long> vec(N,0LL);
        long long mn=0;
        long long mx=0;
        for(int x=0;x<N;x++) {
            int input;
            cin>>input;
            vec[input]=x;
            if(input==0){
                mn=x;
                mx=x;
            }
        }
        long long ans=1;
        for(int x=1;x<N;x++){
            if(mn<=vec[x]&&vec[x]<=mx) ans*=(mx-mn-(long long)x+1LL)%mod;
            ans%=mod;
            mn=min(vec[x],mn);
            mx=max(vec[x],mx);
        }
        cout<<ans<<'\n';
    }
}