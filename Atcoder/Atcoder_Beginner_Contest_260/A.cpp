#include<stdio.h>
#include<queue>
#include<vector>
#include<iostream>
#include<map>
#include<set>
using namespace std;
long long mod=1e9+7LL;
map<char,int> m;
int main(){
    string input;
    cin>>input;
    for(auto i : input){
        m[i]++;
    }
    for(auto i : m){
        if(i.second==1){
            cout<<i.first;
            return 0;
        }
    }
    cout<<-1;
}