#include<stdio.h>
#include<queue>
#include<vector>
#include<iostream>
#include<map>
#include<set>
#include<stack>
#include<algorithm>
using namespace std;
void fast_io() {
  cin.tie(0)->sync_with_stdio(0);
}
int main(){
    fast_io();
    int N;
    cin>>N;
    priority_queue<int> pq;
    for(int x=0;x<N;x++){
        int input;
        cin>>input;
        pq.push(input);
    }
    int solve=0;
    for(int x=0;x<N;x++){
        if(pq.top()>x){
            solve+=pq.top()-x;
        }
        else break;
        pq.pop();
    }
    cout<<solve;
}