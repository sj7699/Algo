#include <stdio.h>
#include<queue>
#include<iostream>
#include<stack>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
void fast_io() {
  cin.tie(0)->sync_with_stdio(0);
}
int main(){
    fast_io();
    int N,K;
    cin>>N>>K;
    priority_queue<pair<int,int>> pq;
    for(int x=1;x<=K;x++){
        int input;
        cin>>input;
        pq.push({input,x});
    }
    vector<int> vec;
    vec.push_back(0);
    for(int x=1;x<=N;x++){
        auto now=pq.top();
        pq.pop();
        if(vec[x-1]==now.second){
            if(pq.empty()){
                cout<<-1;
                return 0;
            }else{
                auto now2=pq.top();
                pq.pop();
                if(now2.first-1!=0) pq.push({now2.first-1,now2.second});
                pq.push(now);
                vec.push_back(now2.second);
            }
        }
        else{
            if(now.first-1!=0) pq.push({now.first-1,now.second});
            vec.push_back(now.second);
        }
    }
    for(int x=1;x<=N;x++){
        cout<<vec[x]<<" ";
    }
}
