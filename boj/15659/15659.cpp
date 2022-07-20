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
int N;
int arr[12];
int stk[12];
int mx=-2e9;
int mn=2e9;
void recur(int a,int b,int c,int d,int prod){
    if(prod==N-1){
        int ret=0;
        stack<int> temp;
        stack<pair<int,int>> div;
        for(int x=0;x<N;x++){
            temp.push(arr[x]);
        }
        for(int x=prod-1;x>=0;x--){
            if(stk[x]<3){
                int k=temp.top();
                while(!div.empty()){
                    auto t = div.top();
                    if(t.second==3){
                        k*=t.first;
                    }
                    else{
                        if(t.first==0) return;
                        k/=t.first;
                    }
                    div.pop();
                }
                temp.pop();
                if(stk[x]==1) ret+=k;
                else ret-=k;
            }  
            if(stk[x]>=3){
                div.push({temp.top(),stk[x]});
                temp.pop();
            }
        }
        if(!temp.empty()){
            int k=temp.top();
            while(!div.empty()){
                    auto t = div.top();
                    if(t.second==3){
                        k*=t.first;
                    }
                    else{
                        if(t.first==0) return;
                        k/=t.first;
                    }
                    div.pop();
            }
            ret+=k;
        }
        mx=max(ret,mx);
        mn=min(ret,mn);
        return;
    }
    if(a){
        stk[prod]=1;
        recur(a-1,b,c,d,prod+1);
    }
    if(b){
        stk[prod]=2;
        recur(a,b-1,c,d,prod+1);
    }
    if(c){
        stk[prod]=3;
        recur(a,b,c-1,d,prod+1);
    }
    if(d){
        stk[prod]=4;
        recur(a,b,c,d-1,prod+1);
    }
}
int main(){
    fast_io();
    cin>>N;
    for(int x=0;x<N;x++) cin>>arr[x];
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    recur(a,b,c,d,0);
    cout<<mx<<'\n'<<mn;
}