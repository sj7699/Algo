#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>
#include<iostream>
using namespace std;
vector<int> vec;
int main(){
    int N;
    cin>>N;
    for(int x=0;x<N;x++){
        int input;
        cin>>input;
        vec.push_back(input);
    }
    if(N==1){
        cout<<1;
        return 0;
    }
    if(N==2){
        cout<<2;
        return 0;
    }
    int solve=2;
    sort(vec.begin(),vec.end());
    for(int x=0;x<N-2;x++){
        int now=vec[x]+vec[x+1];
        for(int y=x+2;y<N;y++){
            if(now<=vec[y]) break;
            solve=max(solve,y-x+1);
        }
    }
    cout<<solve;
}