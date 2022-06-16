#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int M,N;
vector<int> vec;
long long l,r;
__int128 mod=1;
long long cnt=0;
bool f(long long a){
    long long ret=0;
    cnt=0;
    for(int x=0;x<N;x++){
        if(vec[x]-a>0){
            ret+=vec[x]-a;
            cnt+=(vec[x]-a);
        }
    }
    return ret<=M;
}
long long f2(__int128 a){
    __int128 ret=0;
    int cnt2=0;
    for(int x=0;x<N;x++){
        if(cnt2<M-cnt){
            if(a-(__int128)1<(__int128)vec[x]){
                cnt2++;
                ret+=(__int128)(a-(__int128)1)*(a-(__int128)1);
                ret%=mod;
            }
            else{
                ret+=(__int128)((__int128)vec[x]*(__int128)vec[x]);
                ret%=mod;
            }
        }
        else{
            if(a<(__int128)vec[x]){
                ret+=a*a;
                ret%=mod;
            }
            else{
                ret+=(__int128)((__int128)vec[x]*(__int128)vec[x]);
                ret%=mod;
            }
        }
    }
    ret%=mod;
    return (long long)ret;
}
int main(){
    scanf("%i%i",&M,&N);
    for(int x=0;x<64;x++){
        mod*=2;
    }
    for(int x=0;x<N;x++){
        long long input;
        scanf("%lli",&input);
        vec.push_back(input);
        r=max(input,r);
    }
    int mid=(l+r)/2;
    while(l<=r){
        mid=(l+r)/2;
        if(f(mid)){
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    f(l);
    cout<<f2((__int128)l);
}