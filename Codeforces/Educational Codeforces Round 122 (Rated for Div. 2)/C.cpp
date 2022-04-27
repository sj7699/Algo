#include<stdio.h>
#include<queue>
#include<algorithm>
#include<vector>
#include<set>
#include<iostream>
#include<map>
#include<cmath>
#include<string>
#include<stack>
using namespace std;
int main(){
    int T;
    cin>>T;
    while(T--){
        long long hc,dc,hm,dm,k,w,a;
        cin>>hc>>dc>>hm>>dm>>k>>w>>a;
        bool solve=false;
        for(long long x=0;x<=k;x++){
            long long now_w=x;
            long long now_a=k-x;
            long long now_hc=now_a*a+hc;
            long long now_dc=now_w*w+dc;
            long long ct=hm/now_dc+(hm%now_dc!=0);
            long long mt=now_hc/dm+(now_hc%dm!=0);
            if(mt>=ct){
                solve=true;
                break;
            }
        }
        if(solve) cout<<"YES\n";
        else cout<<"NO\n";
    }
}