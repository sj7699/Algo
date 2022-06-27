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
        int n;
        cin>>n;
        vector<long long> vec(n,0LL);
        for(auto &i : vec){
            cin>>i;
        }
        long long left=0;
        long long right=0;
        long long solve=0;
        long long temp=vec[0];
        for(int x=0;x<n;x++){
            if(temp>vec[x]-right){
                left+=temp-(vec[x]-right);
            }
            else{
                right+=(vec[x]-right)-temp;
            }
            temp=(vec[x]-right);
        }
        solve+=left+right;
        if(vec[0]-left>=0){
            solve+=vec[0]-left;
        }
        else{
            solve+=-(vec[0]-left);
        }        
        cout<<solve<<'\n';
    }
}