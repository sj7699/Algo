#include<stdio.h>
#include<queue>
#include<vector>
#include<iostream>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
long long mod=1e9+7LL;
map<char,int> m;
int main(){
    int N,X,Y,Z;
    cin>>N>>X>>Y>>Z;
    vector<pair<int,int>> mvec;
    vector<pair<int,int>> evec;
    vector<pair<int,int>> tvec;
    set<int> s;
    for(int x=1;x<=N;x++){
        int m;
        cin>>m;
        mvec.push_back({-m,x});
    }
    for(int x=1;x<=N;x++){
        int e;
        cin>>e;
        evec.push_back({-e,x});
        tvec.push_back({-e+mvec[x-1].first,x});
    }
    sort(mvec.begin(),mvec.end());
    sort(evec.begin(),evec.end());
    sort(tvec.begin(),tvec.end());
    int hi=mvec[0].first;
    for(int x=0;x<X;x++){
        s.insert(mvec[x].second);
    }
    int cnt=0;
    for(int x=0;x<N;x++){
        if(cnt==Y) break;
        if(s.find(evec[x].second)==s.end()){
            s.insert(evec[x].second);
            cnt++;
        }
        else{
            continue;
        }
    }
    cnt=0;
    for(int x=0;x<N;x++){
        if(cnt==Z) break;
        if(s.find(tvec[x].second)==s.end()){
            s.insert(tvec[x].second);
            cnt++;
        }
        else{
            continue;
        }
    }
    for(auto i : s){
        cout<<i<<'\n';
    }
}