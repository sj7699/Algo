#include <iostream>
#include <vector>
#include <queue>
#include<algorithm>
using namespace std;
int main() {
    int T;
    cin >> T;  
    while (T--){
        int N, K;
        cin >> N >> K;
        vector<int> time;
        time.push_back(0);
        for(int x=0;x<N;x++){
            int input;
            cin>>input;
            time.push_back(input);
        }
        vector<int> solve(N+1,0);
        vector<int> indegree(N+1,0);
        vector<vector<int>> vec(N+1,vector<int>());
        for(int x=0;x<K;x++){
            int input,input2;
            cin>>input>>input2;
            vec[input].push_back(input2);
            indegree[input2]++;
        }
        int dst;
        cin>>dst;
        queue<int> Q;
        for(int x=1;x<=N;x++){
            if(indegree[x]==0){
                Q.push(x);
                solve[x]=time[x];
            }
        }
        while(!Q.empty()){
            int now=Q.front();
            Q.pop();
            for(auto i : vec[now]){
                indegree[i]--;
                solve[i]=max(solve[i],time[i]+solve[now]);
                if(indegree[i]==0) Q.push(i);
            }
        }
        cout<<solve[dst]<<'\n';
    }
}