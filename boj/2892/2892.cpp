#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;
bool chk[129];
int num(string a){
    int l=a.size();
    int now=1;
    int ret=0;
    for(int x=l-1;x>=0;x--){
        int cur=a[x];
        if(cur>='0' && cur<='9') cur=cur-'0';
        else cur=cur-'A'+10;
        ret+=now*cur;
        now*=16;
    }
    return ret;
}
int main(){
    int N;
    cin>>N;
    for(int x=64;x<=95;x++) chk[x]=true;
    for(int x=0;x<N;x++){
        string a;
        cin>>a;
        int now=num(a);
        if(!chk[now]){
            cout<<'.';
            continue;
        }
        cout<<'-';
    }
}