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
bool chk[10000001];
vector<int> vec;
int main(){
    fast_io();
    chk[1]=true;
    for(int x=2;x<=5000000;x++){
        if(chk[x]) continue;
        for(int y=x*2;y<=10000000;y+=x) chk[y]=true;
    }
    for(int x=1;x<=10000000;x++) if(!chk[x]) vec.push_back(x);
    int T;
    cin>>T;
    int vl=(int)vec.size();
    for(int test=1;test<=T;test++){
        cout<<"Scenario "<<test<<":\n";
        int m;
        cin>>m;
        vector<int> solve(10000001,0);
        for(int x=0;x<m;x++){
            int n;
            cin>>n;
            int now=0;
            for(int x=0;x<n;x++) now+=vec[x];
            solve[now]++;
            for(int x=n;x<vl;x++){
                now+=vec[x];
                now-=vec[x-n];
                if(now>=10000000) break;
                solve[now]++;
            }
        }
        for(int x=2;x<=10000000;x++){
            if(!chk[x] && solve[x]==m){
                cout<<x<<"\n";
                break;
            }
        }
        if(test!=T) cout<<'\n';
    }
}
