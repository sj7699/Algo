#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
int op[4];
int arr[12];
int N;
int mins=2000000000;
int maxs=-2000000000;
void dfs(int proc,int num){
    if(proc==N){
        mins=min(mins,num);
        maxs=max(maxs,num);
        return;
    }
    for(int x=0;x<4;x++){
        if(op[x]){
            if(x==0){
                op[x]--;
                dfs(proc+1,num+arr[proc]);
                op[x]++;
            }
            if(x==1){
                op[x]--;
                dfs(proc+1,num-arr[proc]);
                op[x]++;
            }
            if(x==2){
                op[x]--;
                dfs(proc+1,num*arr[proc]);
                op[x]++;
            }
            if(x==3){
                op[x]--;
                dfs(proc+1,num/arr[proc]);
                op[x]++;
            }
        }
    }
}
int main(){
    cin>>N;
    for(int x=0;x<N;x++){
        cin>>arr[x];
    }
    for(int x=0;x<4;x++) cin>>op[x];
    dfs(1,arr[0]);
    cout<<maxs<<'\n';
    cout<<mins<<'\n';
}