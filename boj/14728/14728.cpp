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
int arr[10001];
int N,T;
int main(){
    fast_io();
    cin>>N>>T;
    int ans=0;
    for(int x=0;x<N;x++){
        int input,score;
        cin>>input>>score;
        for(int y=0;y<=T;y++){
            if(arr[y] && y-input>=0){
                arr[y-input]=max(arr[y-input],arr[y]+score);
                ans=max(ans,arr[y-input]);
            }
        }
        if(input<=T){
            arr[T-input]=max(arr[T-input],score);
            ans=max(ans,arr[T-input]);
        }
    }
    cout<<ans;
}
