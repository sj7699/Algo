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
vector<int> ki(1001,100000000);
void recur(int n,int prod){
    if(n>1000) return;
    if(ki[n]<=prod){
        return;
    }
    ki[n]=min(ki[n],prod);
    for(int x=1;x<=n;x++){
        recur(n+n/x,prod+1);
    }
}
int main(){
    int T;
    cin>>T;
    recur(1,0);
    while(T--){
        int surplus=0;
        int n,k;
        cin>>n>>k;
        vector<int> bi;
        vector<pair<int,int>> kc;
        vector<int> dp(k+1,0);
        for(int x=0;x<n;x++){
            int input;
            cin>>input;
            bi.push_back(ki[input]);
        }
        int temp=n;
        for(int x=0;x<n;x++){
            int input;
            cin>>input;
            if(bi[x]==0){
                surplus+=input;
                temp--;
                continue;
            }
            kc.push_back({bi[x],input});
        }
        sort(kc.begin(),kc.end());
        for(int x=0;x<temp;x++){
            for(int y=k;y>=1;y--){
                if(kc[x].first <=y){
                    dp[y]=max(dp[y],dp[y-kc[x].first]+kc[x].second);
                }
            }
        }
        cout<<dp[k]+surplus<<'\n';
    }
}