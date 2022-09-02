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
long long N,P;
long long arr[1001];
int main(){
    fast_io();
    cin>>N>>P;
    for(int x=N;x>=0;x--){
        long long input;
        cin>>input;
        if(x==0){
            cout<<input%P<<'\n';
        }
        arr[x%(P-1)] += input;
    }
    for(long long x=1;x<P;x++){
        long long temp=0;
        long long temp2=1;
        for(long long y=0;y<P;y++){
            temp+=arr[y]*temp2;
            temp2=(temp2*x)%P;
        }
        cout<<temp%P<<'\n';
    }
}
