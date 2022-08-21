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
int main(){
    fast_io();
    long long a,b;
    cin>>a>>b;
    int ans=0;
    for(long long x=2;x*x<=b;x++){
        for(long long k=a-(a%(x*x));k<=b;k+=(x*x)){
            if(k<a) continue;
            chk[k-a]=true;
        }
    }
    for(int x=0;x<=b-a;x++){
        if(!chk[x]) ans++;
    }
    cout<<ans;
}
