#include <bits/stdc++.h>
using namespace std;
void fast_io() {
  cin.tie(0)->sync_with_stdio(0);
}
using namespace std;
vector<pair<int,int>> vec;
int main() {
    fast_io();
    int N;
    int solve=1000001;
    cin>>N;
    for(int x=0;x<N;x++){
        int ti,si;
        cin>>ti>>si;
        vec.push_back({si,ti});
    }
    sort(vec.begin(),vec.end());
    int before=0;
    for(int x=0;x<N;x++){
        int now=before+vec[x].second;
        if(vec[x].first<now) {
            solve=-1;
            break;
        }
        else solve=min(solve,vec[x].first-now);
        before=now;
    }
    cout<<solve;
}