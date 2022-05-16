#include<stdio.h>
#include<iostream>
#include<set>
#include<algorithm>
#include<vector>
using namespace std;
vector<pair<int,int>> vec;
int dir[4][2]={{-1,1},{-1,-1},{1,1},{1,-1}};
int N,M,L,K;
int main(){
    cin>>N>>M>>L>>K;
    int solve=K-1;
    for(int x=0;x<4;x++){
        dir[x][0]*=L;
        dir[x][1]*=L;
    }
    for(int x=0;x<K;x++){
        int input,input2;
        cin>>input>>input2;
        vec.push_back({input,input2});
    }
    sort(vec.begin(),vec.end());
    for(int x=0;x<K;x++){
        for(int y=0;y<K;y++){
            int nx=vec[x].first;
            int ny=vec[y].second;
            int cnt=0;
            for(int z=0;z<K;z++){
                int cx=vec[z].first;
                int cy=vec[z].second;
                if(nx<=cx && nx+L>=cx && ny<=cy && ny+L>=cy){
                    cnt++;
                }
            }
            solve=min(solve,K-cnt);
        }
    }
    cout<<solve;
}
