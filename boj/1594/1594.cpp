#include<stdio.h>
#include<iostream>
#include<string>
#include<set>
using namespace std;
int N;
string input;
int sn;
int bt[2001];
string solve;
void recur(string a,int now,int ret){
    string temp;
    if(bt[now]>=ret) return;
    bt[now]=ret;
    if(now==N){
        if(sn<ret){
            sn=ret;
            solve=a;
        }
        return;
    }
    set<int> s;
    for(int x=now;x<now+2;x++){
        if(x==N) return;
        temp.push_back(input[x]);
        s.insert(input[x]);
    }
    if(s.size()==1){
        if(now==0) recur(temp,now+2,ret+2);
        else recur(a+"-"+temp,now+2,ret+2);
    }
    else{
        if(now==0) recur(temp,now+2,ret);
        else recur(a+"-"+temp,now+2,ret);
    }
    if(now+2>=N) return;
    s.insert(input[now+2]);
    temp.push_back(input[now+2]);
    if(s.size()==1){
        if(now==0) recur(temp,now+3,ret+2);
        else recur(a+"-"+temp,now+3,ret+2);
    }
    if(s.size()==2){
        if(now==0) recur(temp,now+3,ret+1);
        else recur(a+"-"+temp,now+3,ret+1);
    }
    if(s.size()==3){
        if(now==0) recur(temp,now+3,ret);
        else recur(a+"-"+temp,now+3,ret);
    }
}
int main(){
    cin>>input;
    N=input.size();
    sn=-1;
    for(int x=0;x<=N;x++) bt[x]=-1;
    recur("",0,0);
    cout<<solve;
}