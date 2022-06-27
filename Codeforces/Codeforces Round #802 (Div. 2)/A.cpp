#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
#include<map>
#include<set>
#include<stack>
#include<queue>
using namespace std;
int main(){
    int T;
    cin>>T;
    while(T--){
        long long n,m;
        cin>>n>>m;
        cout<<(m*(m+1)/2)-m+((n*(n+1))/2*m)<<'\n';
    }
}