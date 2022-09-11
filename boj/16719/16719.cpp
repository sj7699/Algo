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
bool chk[101];
int main(){
    fast_io();
    string input;
    cin>>input;
    int k=(int)input.size();
    for(int x=0;x<k;x++){
        priority_queue<pair<string,int>,vector<pair<string,int>>,greater<pair<string,int>>> pq;
        for(int y=0;y<k;y++){
            if(chk[y]) continue;
            string now;
            for(int z=0;z<k;z++){
                if(chk[z] || y==z) now.push_back(input[z]);
            }
            pq.push({now,y});
        }
        chk[pq.top().second]=true;
        for(int y=0;y<k;y++){
            if(chk[y]) cout<<input[y];
        }
        cout<<'\n';
    }
}