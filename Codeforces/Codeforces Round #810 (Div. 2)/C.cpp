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
        int N,M,K;
        vector<int> vec;
        cin>>N>>M>>K;
        for(int x=0;x<K;x++){
            int input;
            cin>>input;
            vec.push_back(input);
        }
        bool solve=false;
        sort(vec.begin(),vec.end());
        long long temp=0;
        long long temp2=0;
        for(int x=0;x<K;x++){
            if(vec[x]/N>=2){
                temp+=(long long)(vec[x]/N);
                temp2+=(long long)(vec[x]/N-2);
            }
        }
        if(temp>=M){
            if(M%2LL==1){
                if(temp2) solve=true;
            }
            else solve=true;
        }
        temp=0;
        temp2=0;
        for(int x=0;x<K;x++){
            if(vec[x]/M>=2){
                temp+=(long long)(vec[x]/M);
                temp2+=(long long)(vec[x]/M-2LL);
            }
        }
        if(temp>=N){
            if(N%2LL==1){
                if(temp2) solve=true;
            }
            else solve=true;
        }
        if(solve){
            cout<<"Yes\n";
        }
        else cout<<"No\n";
    }
}