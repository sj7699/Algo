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
int N,Lx,Ly;
struct rec{
int lx,ly,px,py,z;
};
vector<rec> vec;
int main(){
    fast_io();
    cin>>Lx>>Ly>>N;
    rec temp={Lx,Ly,0,0,0};
    vec.push_back(temp);
    int ans=-1;
    for(int x=0;x<N;x++){
        int lx,ly,lz,px,py;
        cin>>lx>>ly>>lz>>px>>py;
        int mx=-1;
        for(auto i : vec){
            int a=max(i.px,px)-min(i.px+i.lx,px+lx);
            int b=max(i.py,py)-min(i.py+i.ly,py+ly);
            if(a<0 && b<0){
                mx=max(i.z,mx);
            }
        }
        ans=max(ans,mx+lz);
        temp={lx,ly,px,py,mx+lz};
        vec.push_back(temp);
    }
    cout<<ans;
}
