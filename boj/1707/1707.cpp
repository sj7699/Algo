#include<stdio.h>
#include<vector>
#include<algorithm>
#include<bitset>
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
int main(){
    fast_io();
    int K;
    cin>>K;
    while(K--){
        int N,E;
        cin>>N>>E;
        vector<vector<int>> edge(N+1,vector<int>());
        vector<int> visit(N+1,0);
        for(int x=0;x<E;x++){
            int src,dst;
            cin>>src>>dst;
            edge[src].push_back(dst);
            edge[dst].push_back(src);
        }
        if(N<=2){
            cout<<"No\n";
            continue;
        }
        bool chk=false;
        int p=1;
        for(int x=1;x<=N;x++){
            if(visit[x]==0){
                queue<pair<int,int>> Q;
                Q.push({x,0});
                while(!Q.empty()){
                    int now=Q.front().first;
                    int dist=Q.front().second;
                    Q.pop();
                    if(dist%2==0){
                        visit[now]=p;
                    }
                    else visit[now]=p+1;
                    for(auto i : edge[now]){
                        if(visit[i]==visit[now]){
                            chk=true;
                            break;
                        }
                        if(visit[i]==0){
                            Q.push({i,dist+1});
                        }
                    }
                }
                if(chk) break;
            }
            p+=2;
        }
        if(chk){
            cout<<"NO\n";
        }
        else cout<<"YES\n";
    }
}