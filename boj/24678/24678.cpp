#include <bits/stdc++.h>
using namespace std;
void fast_io() {
  cin.tie(0)->sync_with_stdio(0);
}
using namespace std;
int main() {
    fast_io();
    int T;
    cin>>T;
    while(T--){
        int x,y,z;
        cin>>x>>y>>z;
        int e=0;
        if(x%2==0) e++;
        if(y%2==0) e++;
        if(z%2==0) e++;
        if(e>=2) cout<<"R\n";
        else cout<<"B\n";
    }
}