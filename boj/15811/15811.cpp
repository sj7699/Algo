#include <stdio.h>
#include<queue>
#include<iostream>
#include<stack>
#include<vector>
#include<set>
using namespace std;
void fast_io() {
  cin.tie(0)->sync_with_stdio(0);
}
string A,B,C;
int chk[130];//ctoi
bool chk2[10];
bool solve;
int al,bl,cl,sl;
set<char> s;
vector<char> vec;
string rev(string a){
    string ret;
    stack<char> stk;
    for(auto i : a) stk.push(i);
    while(!stk.empty()){
        ret+=stk.top();
        stk.pop();
    }
    return ret;
}
void bf(int now){
    if(now==sl){
        int k=0;
        long long temp=0;
        long long temp2=0;
        long long digit=1;
        long long digit2=1;
        for(int x=0;x<max(al,bl);x++){
            int nowa=0;
            int nowb=0;
            int nowc=0;
            if(x<al){
                nowa=chk[A[x]];
            }
            if(x<bl){
                nowb=chk[B[x]];
            }
            temp+=(long long)((nowa+nowb+k)%10)*digit;
            k=(nowa+nowb+k)/10;
            digit*=10LL;
        }
        if(k){
            temp+=k*digit;
        }
        for(auto i : C){
            temp2+=(long long)chk[i]*digit2;
            digit2*=10LL;
        }
        if(temp!=temp2) return;
        solve=true;
        return;
    }
    for(int x=0;x<10;x++){
        if(chk2[x]) continue;
        chk[vec[now]]=x;
        chk2[x]=true;
        bf(now+1);
        chk2[x]=false;
    }
}
int main() {
    fast_io();
    cin>>A>>B>>C;
    A=rev(A);
    B=rev(B);
    C=rev(C);
    al=(int)A.size();
    bl=(int)B.size();
    cl=(int)C.size();
    for(auto i : A) s.insert(i);
    for(auto i : B) s.insert(i);
    for(auto i : C) s.insert(i);
    sl=(int)s.size();
    if(sl>10){
        cout<<"NO";
        return 0;
    }
    for(auto i : s){
        vec.push_back(i);
    }
    bf(0);
    if(solve){
        cout<<"YES";
    }
    else cout<<"NO";
}