#include<stdio.h>
#include<vector>
#include<algorithm>
#include<bitset>
#include<string>
#include<iostream>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<functional>
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
        if(N%2==1) cout<<-1<<'\n';
        else{
            cout<<0<<" "<<N/2<<" "<<N/2<<'\n';
        }
    }
}