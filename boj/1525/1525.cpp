#include<stdio.h>
#include<queue>
#include<vector>
#include<iostream>
#include<map>
#include<set>
#include<stack>
#include<algorithm>
using namespace std;
void fast_io() {
  cin.tie(0)->sync_with_stdio(0);
}
set<long long> s;
int arr[3][3];
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int main(){
    fast_io();
    int solve=-1;
    long long a=100000000;
    long long b=0;
    for(int x=0;x<3;x++){
        for(int y=0;y<3;y++){
            long long input;
            cin>>input;
            b+=a*input;
            a/=10LL;
        }
    }
    queue<pair<long long,int>> Q;
    Q.push({b,0});
    s.insert(b);
    while(!Q.empty()){
        int now=Q.front().first;
        int dist=Q.front().second;
        if(now==123456780){
            solve=dist;
            break;
        }
        Q.pop();
        pair<int,int> zxy;
        for(int y=0;y<3;y++){
            for(int z=0;z<3;z++){
                arr[y][z]=now%10;
                if(now%10==0){
                    zxy={y,z};
                }
                now/=10;
            }
        }
        for(int x=0;x<4;x++){
            int cx=zxy.first+dir[x][0];
            int cy=zxy.second+dir[x][1];
            if(cx<0 || cy<0 || cx>=3 || cy>=3) continue;
            arr[zxy.first][zxy.second]=arr[cx][cy];
            arr[cx][cy]=0;
            a=1;
            b=0;
            for(int y=0;y<3;y++){
                for(int z=0;z<3;z++){
                    b+=a*(long long)arr[y][z];
                    a*=10LL;
                }
            }
            arr[cx][cy]=arr[zxy.first][zxy.second];
            arr[zxy.first][zxy.second]=0;
            if(s.find(b)==s.end()){
                Q.push({b,dist+1});
                s.insert(b);
            }
        }
    }
    cout<<solve;
}