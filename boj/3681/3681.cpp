#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
#include<map>
using namespace std;
map<long long,int> m;
int N=0;
string input;
int ans=0;
void recur(int left,int right,int prod){
    int l1=0;
    int r1=0;
    int l2=0;
    int r2=0;
    if(input[left+1]=='['){
        l1=left+1;
        int st=0;
        for(int x=l1;x<=right;x++){
            if(input[x]=='[') st++;
            if(input[x]==']') st--;
            if(st==0){
                r1=x;
                l2=x+2;
                break;
            }
        }
    }
    else{
        l1=left+1;
        for(int x=l1;x<=right;x++){
            if(input[x]==','){
                r1=x-1;
                l2=x+1;
                break;
            }
        }
    }
    if(input[l2]=='['){
        int st=0;
        for(int x=l2;x<=right;x++){
            if(input[x]=='[') st++;
            if(input[x]==']') st--;
            if(st==0){
                r2=x;
                break;
            }
        }
    }
    else{
        for(int x=l2;x<right;x++){
            if(input[x+1]==']'){
                r2=x;
                break;
            }
        }
    }
    //cout<<input.substr(l1,r1-l1+1)<<"   "<<input.substr(l2,r2-l2+1)<<'\n';
    int k=0;
    int k2=0;
    if(input[l1]=='['){
        recur(l1,r1,prod*2);
    }
    else{
        k=stoi(input.substr(l1,r1-l1+1));
        m[(long long)k*(long long)prod]++;
        N++;
    }
    if(input[l2]=='['){
        recur(l2,r2,prod*2);
    }
    else{
        k2=stoi(input.substr(l2,r2-l2+1));
        m[(long long)k2*(long long)prod]++;
        N++;
    }
}
int main(){
    int T;
    cin>>T;
    while(T--){
        ans=2e9;
        N=0;
        m.clear();
        cin>>input;
        if(input[0]=='['){
            recur(0,input.size()-1,1);
        }
        else{
            cout<<"0\n";
            continue;
        }
        for(auto i : m){
            ans=min(N-i.second,ans);
        }
        cout<<ans<<'\n';
    }
}