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
bool dp[202][202];
string a,b,c;
void dfs(int i,int j){
    dp[i][j]=true;
    if(i<a.size()){
        if(a[i]==c[i+j] && !dp[i+1][j]) dfs(i+1,j);
    }
    if(j<b.size()){
        if(b[j]==c[i+j] && !dp[i][j+1]) dfs(i,j+1);
    }
}
int main() {
    fast_io();
    int T;
    cin>>T;
    for(int test=1;test<=T;test++){
        cin>>a>>b>>c;
        for(int x=0;x<=a.size();x++){
            for(int y=0;y<=b.size();y++) dp[x][y]=false;
        }
        dfs(0,0);
        cout<<"Data set "<<test<<": ";
        if(dp[a.size()][b.size()]){
            cout<<"yes\n";
        }
        else cout<<"no\n";
    }
}