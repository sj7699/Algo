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
    int T;
    cin>>T;
    while(T--){
        int N,M;
        cin>>N>>M;
        vector<int> vec;
        vector<int> vec2(N+1,0);
        vector<pair<int,int>> vec3;
        vec.push_back(0);
        for(int x=0;x<N;x++){
            int input;
            cin>>input;
            vec.push_back(input);
        }
        for(int x=0;x<M;x++){
            int a,b;
            cin>>a>>b;
            vec2[a]++;
            vec2[b]++;
            vec3.push_back({a,b});
        }
        if(M%2==0) cout<<0<<'\n';
        else{
            priority_queue<int> odd;
            for(int x=1;x<=N;x++){
                if(vec2[x]%2==1) odd.push(-vec[x]);
            }
            for(int x=0;x<M;x++){
                if(vec2[vec3[x].first]%2==0 && vec2[vec3[x].second]%2==0){
                    odd.push(-vec[vec3[x].first]-vec[vec3[x].second]);
                }
            }
            cout<<-odd.top()<<'\n';
        }
    }
}