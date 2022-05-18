#include<stdio.h>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
vector<pair<int,int>> vec;
long long solve=1LL;
long long mod=1000000007;
long long fastPow(long long base) {
    long long result = 1;
    long long exp=mod-2;
    for (; exp; exp >>= 1, base = (base * base) % mod) {
        if (exp & 1) {
            result = (result * base) % mod;
        }
    }
    return result;
}
int main(){
    int N,M;
    cin>>N>>M;
    int temp=N;
    for(int x=2;x*x<=N;x++){
        if(temp%x==0){
            int cnt=0;
            while(temp%x==0){
                temp/=x;
                cnt++;
            }
            vec.push_back({x,cnt});
        }
    }
    if(temp>0) vec.push_back({temp,1});
    if(M==0){
        cout<<1;
    }
    else{
        for(auto i : vec){
            long long now=i.first;
            if(i.first==1) continue;
            long long mtemp=(long long)i.second*(long long)M+1;
            long long stemp=1;
            while(mtemp!=0){
                if(mtemp%2==1){
                    stemp=((stemp%mod)*(now%mod))%mod;
                }
                now=((now%mod)*(now%mod))%mod;
                mtemp/=2;
            }
            stemp=(stemp%mod-1)%mod;
            stemp=((stemp%mod)*(fastPow(i.first-1)%mod))%mod;
            solve=((solve%mod)*(stemp%mod))%mod;
        }
        cout<<solve%mod;
    }
}