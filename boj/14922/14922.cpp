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
int arr[1000001];
int main(){
    int N;
    cin>>N;
    int ans2=0;
    long long ansm2=1e17;
    int ans3=0;
    long long ansm3=1e17;
    for(int x=0;x<N;x++) cin>>arr[x];
    for(int x=1;x<N;x++){
        if(x>=2){
            if(ansm3>=(arr[x-2]+arr[x-1]+arr[x])){
                ans3=x-2;
                ansm3=arr[x-2]+arr[x-1]+arr[x];
            }
            if(ansm2>=arr[x-1]+arr[x]){
                ans2=x-1;
                ansm2=arr[x-1]+arr[x];
            }
        }
    }
    if(ansm2*3>=ansm3*2) cout<<ans3;
    else cout<<ans2;
}
