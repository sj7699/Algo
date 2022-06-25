#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<iostream>
using namespace std;
int N,M;
bool party[51];
bool people[51];
vector<vector<int>> wparty;
vector<vector<int>> iparty;
int main(){
    cin>>N>>M;
    for(int x=0;x<=N;x++){
        wparty.push_back(vector<int>());
    }
    for(int x=0;x<=M;x++){
        iparty.push_back(vector<int>());
    }
    queue<int> Q;
    int p;
    cin>>p;
    for(int x=0;x<p;x++){
        int input;
        cin>>input;
        Q.push(input);
        people[input]=true;
    }
    for(int x=1;x<=M;x++){
        int n;
        cin>>n;
        for(int y=0;y<n;y++){
            int input;
            cin>>input;
            iparty[x].push_back(input);
            wparty[input].push_back(x);
        }
    }
    while(!Q.empty()){
        int now=Q.front();
        Q.pop();
        for(auto i : wparty[now]){
            party[i]=true;
            for(auto j : iparty[i]){
                if(!people[j]){
                    Q.push(j);
                    people[j]=true;
                }
            }
        }
    }
    int ans=M;
    for(int x=1;x<=M;x++){
        if(party[x]) ans--;
    }
    cout<<ans;
}
