#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>
#include<iostream>
using namespace std;
vector<int> vec;
int N,M;
bool f(int a){
    int ret=0;
    int now=0;
    int cnt=0;
    vector<int> temp;
    for(int x=0;x<N;x++){
        now+=vec[x];
        if(now>a){
            now=vec[x];
            ret++;
            temp.push_back(cnt);
            cnt=1;
        }
        else cnt++;
    }
    if(now){
        ret++;
    }
    return ret<=M;
}
void f2(int a){
    int cnt=0;
    int now=0;
    int ret=0;
    int k=0;
    for(int x=0;x<N;x++){
        now+=vec[x];
        if(now>a){
            ret++;
            cout<<cnt<<" ";
            now=vec[x];
            cnt=1;
        }
        else{
            cnt++;
        }
        if(N-x==M-ret){
            if(cnt>1){
                cout<<cnt<<" ";
                ret++;
            }
            k=M-ret;
            break;
        }
    }
    for(int x=0;x<k;x++) cout<<1<<" ";
}
int main(){
    cin>>N>>M;
    int l=0;
    for(int x=0;x<N;x++){
        int input;
        cin>>input;
        vec.push_back(input);
        l=max(input,l);
    }
    int r=1e9;
    int mid=(l+r)/2;
    while(l<=r){
        mid=(l+r)/2;
        if(f(mid)){
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    cout<<l<<'\n';
    f2(l);
}