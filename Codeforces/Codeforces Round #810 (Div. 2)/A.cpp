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
int main(){
    fast_io();
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        if(N==1){
            cout<<"1\n";
            continue;
        }
        if(N%2==1){
            cout<<1<<" ";
            for(int x=2;x<=N;x++){
                if(x%2==0) cout<<x+1<<" ";
                else cout<<x-1<<" ";
            }
            continue;
        }
        for(int x=1;x<=N;x++){
            if(x%2==1) cout<<x+1<<" ";
            else cout<<x-1<<" ";
        }
        cout<<'\n';
    }
}