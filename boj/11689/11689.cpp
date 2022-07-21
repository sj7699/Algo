#include<stdio.h>
#include<queue>
#include<vector>
#include<iostream>
#include<map>
#include<set>
#include<stack>
#include<algorithm>
using namespace std;
void fast_io() {
  cin.tie(0)->sync_with_stdio(0);
}
long long N,K;
vector<long long> vec;
int main(){
    fast_io();
    cin>>N;
    set<long long> s;
    long long temp=N;
    for(long long x=2;x*x<=N;x++){
        if(temp%x==0){
            s.insert(x);
            while(temp%x==0){
                temp/=x;
            }
        }
    }
    if(temp!=1) s.insert(temp);
    for(auto i : s) vec.push_back(i);
    K=(int)vec.size();
    long long ans=0;
    for(int x=1;x<(1<<K);x++){
        int temp=x;
        long long now=0;
        long long now2=1;
        int cnt=0;
        for(int y=0;y<K;y++){
            int bnow=(1<<y);
            if(bnow & temp){
                cnt++;
                now2*=vec[y];
            }
        }
        now=(N/now2);
        if(cnt%2==0){
            ans-=now;
        }
        else{
            ans+=now;
        } 
    }
    cout<<N-ans;
}