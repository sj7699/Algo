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
bool chk[150];
int main(){
    fast_io();
    int N;
    string s;
    cin>>N>>s;
    chk['y']=true;
    chk['i']=true;
    chk['u']=true;
    chk['o']=true;
    chk['p']=true;
    chk['h']=true;
    chk['k']=true;
    chk['j']=true;
    chk['l']=true;
    chk['b']=true;
    chk['n']=true;
    chk['m']=true;
    if(N==1){
        cout<<0;
        return 0;
    }
    else{
        if(chk[s[N-2]] && !chk[s[N-1]]) cout<<1;
        else cout<<0;
    }
}
