#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<functional>
using namespace std;
void fast_io() {
  cin.tie(0)->sync_with_stdio(0);
}
bool comp(const pair<long long,long long> &a,const pair<long long,long long> &b){
    if(a.first==b.first){
        return a.second<=b.second;
    }
    return a.first<=b.first;
}
int main(){
    fast_io();
    int T;
    cin>>T;
    while(T--){
        int N,S;
        cin>>N>>S;
        priority_queue<pair<long long,long long>> pq;
        vector<long long> t(N,0);
        for(auto & i:t){
            cin>>i;
        }
        vector<pair<long long,long long>> tv;
        for(int x=0;x<N;x++){
            long long input;
            cin>>input;
            tv.push_back({t[x],input});
        }
        sort(tv.begin(),tv.end());
        int now=S;
        long long solve=0;
        for(int x=0;x<N;x++){
            if(tv[x].first<=now){
                pq.push({tv[x].second,tv[x].first});
            }
            else{
                int temp=now;
                while(!pq.empty()){
                    if(temp==tv[x].first){
                        break;
                    }
                    solve+=pq.top().first * (temp-pq.top().second);
                    temp++;
                    pq.pop();
                }
                now=tv[x].first;
                pq.push({tv[x].second,tv[x].first});
            }
        }
        while(!pq.empty()){
            solve+=pq.top().first * (now-pq.top().second);
            pq.pop();
            now++;
        }
        cout<<solve<<'\n';
    }
}