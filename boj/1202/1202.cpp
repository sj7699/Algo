#include<iostream>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<vector>
using namespace std;
int N,K;
vector<pair<int,int>> mv;
vector<int> c;
int parent[300002];
int ufind(int a){
    if(a==parent[a]){
        return a;
    }
    parent[a]=ufind(parent[a]);
    return parent[a];
    
}
void uunion(int a,int b){
    int k=ufind(a);
    int k2=ufind(b);
    if(k==k2) return;
    parent[k]=k2;
    return;
}
int bn_search(int target){
    int l=0;
    int r=K-1;
    while(l<r){
        int mid=(l+r)/2;
        if(c[mid]<=target) l=mid+1;
        else r=mid;
    }
    return r;
}
int main(){
    cin>>N>>K;
    for(int x=0;x<N;x++){
        int a,b;
        cin>>a>>b;
        mv.push_back({b,a});
    }
    long long solve=0;
    for(int x=0;x<K;x++){
        parent[x]=x;
        int a;
        cin>>a;
        c.push_back(a);
    }
    parent[K]=K;
    sort(mv.begin(),mv.end(),greater<pair<int,int>>());
    sort(c.begin(),c.end());
    for(int x=0;x<N;x++){
        long long w=mv[x].second;
        long long v=mv[x].first;
        if(w>c[K-1]) continue;
        int ind=bn_search(w-1);
        int temp=ufind(ind);
        if(temp==K) continue;
        solve+=v;
        uunion(temp,temp+1);
    }
    cout<<solve;
}