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
bool chk[100001];
bool chk2[100001];
int main(){
    fast_io();
    chk[1]=true;
    chk2[1]=true;
    int A,B;
    cin>>A>>B;
    for(int x=2;x<=50000;x++){
        if(chk[x]) continue;
        for(int y=x*2;y<=100000;y+=x){
            chk[y]=true;
        }
    }
    for(int x=A;x<=B;x++){
        int now=x;
        int cnt=0;
        for(int y=2;y*y<=x;y++){
            if(now==1) break;
            while(now%y==0){
                now/=y;
                cnt++;
            }
        }
        if(now!=1) cnt++;
        if(chk[cnt]) chk2[x]=true;
    }
    int solve=0;
    for(int x=A;x<=B;x++){
        if(!chk2[x]) solve++;
    }
    cout<<solve;
}