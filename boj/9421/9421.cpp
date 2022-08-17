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
bool chk[1000001];
bool pn[1000001];
bool visit[1000001];
int f(int a){
    int ret=0;
    while(a){
        ret+=(a%10)*(a%10);
        a/=10;
    }
    return ret;
}
int main(){
    pn[1]=true;
    for(int x=2;x<=500000;x++){
        if(pn[x]) continue;
        for(int y=x*2;y<=1000000;y+=x){
            pn[y]=true;
        }
    }
    int N;
    cin>>N;
    chk[1]=true;
    for(int x=2;x<=1000000;x++){
        vector<int> vec;
        int now=f(x);
        vec.push_back(x);
        visit[x]=true;
        while(now!=1 && !visit[now]){
            vec.push_back(now);
            visit[now]=true;
            now=f(now);
        }
        if(chk[now]){
            for(auto i : vec) chk[i]=true;
        }
    }
    for(int x=2;x<=N;x++){
        if(chk[x] && !pn[x]) cout<<x<<'\n';
    }
}
