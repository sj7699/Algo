#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>
#include<stack>
#include<queue>
#include<set>
using namespace std;
set<long long> solve;
void recur(string a,int d,int last){
    if(last==18) return;
    solve.insert(stoll(a));
    if(a[last]+d<'0' || a[last]+d>'9'){
        return;
    }
    string next=a;
    next+=a[last]+d;
    recur(next,d,last+1);
}
int main(){
    long long input;
    cin>>input;
    for(int x=-8;x<=8;x++){
        for(int y=1;y<=9;y++){
            string temp="";
            temp+=(y+'0');
            recur(temp,x,0);
        }
    }
    cout<<*solve.lower_bound(input);
}