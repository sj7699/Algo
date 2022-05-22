#include<stdio.h>
#include<vector>
#include <limits.h>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;
long long A,B,C,D;
long long adist[10001];
bool selected[10001];
long long vv[10001];
long long mul(long long a, long long b) { 
    if(b<=1000000){
        return a*b%C;
    }
    return mul(a,b/1000000)*1000000LL+mul(a,b%1000000)%C;
}
long long dist(long long i,long long j){
    if(i>j){
        long long temp=i;
        i=j;
        j=temp;
    }
    i=vv[i];
    j=vv[j];
    return ((((mul(i,A)%C+mul(j,B))%C)%C)^D);
}
int N;
long long solution(){
    long long ans = 0;
    adist[0] = 0;     // 1번 노드부터 선택
    int now=0;
    selected[now]=true;
    for(int i=0; i<N-1; i++){
        int nx=now;
        long long min_dist = LLONG_MAX;
        for(int j=0; j<N; j++){
            if(!selected[j]){
                long long k=dist(now,j);
                if(adist[j]>k) adist[j]=k;
                if(min_dist>adist[j]){
                    nx=j;
                    min_dist=adist[j];
                }
            }
        }
        now=nx;
        ans+=min_dist;
        selected[nx]=true;
    }
    return ans;
}
int main(){
    scanf("%i%lld%lld%lld%lld",&N,&A,&B,&C,&D);
    for(int x=0;x<N;x++){
        long long input;
        adist[x]=LLONG_MAX;
        scanf("%lld",&input);
        vv[x]=input;
    }
    printf("%lld",solution());
}