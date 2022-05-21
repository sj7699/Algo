#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int K,N;
vector<int> vec;
bool chk(int n){
    long long p=0;
    for(int x=0;x<N;x++){
        if(vec[x]<n) p+=n-vec[x];
        if(p>K) return false;
    }
    return true;
}
void solve(){
    scanf("%i%i",&N,&K);
    int hi=1000000022;
    for(int x=0;x<N;x++){
        int input;
        scanf("%i",&input);
        vec.push_back(input);
        hi=min(input,hi);
    }
    int lo=1;
    hi+=K;
    while(lo<=hi){
        int mid=(lo+hi)/2;
        if(chk(mid)){
            lo=mid+1;
        }
        else{
            hi=mid-1;
        }
    }
    printf("%i",lo-1);
}
int main(){
    solve();
}