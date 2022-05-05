#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>
#include<stack>
#include<queue>
using namespace std;
int main(){
    priority_queue<int,vector<int>,greater<int>> pq;
    int N,K,now;
    cin>>N>>K;
    for(int x=0;x<N;x++){
        int input;
        cin>>input;
        if(x>=K){
            if(input>=pq.top()){
                pq.pop();
                pq.push(input);
            }
        }
        if(x<=K-1){
            pq.push(input);
        }
        if(x>=K-1){
            cout<<pq.top()<<'\n';
        }
    }
}