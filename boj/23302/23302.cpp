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
int R,C;
vector<vector<vector<pair<int,int>>>> vec;
bool visit[1000][800];
bool solve=false;
void dfs(pair<int,int> src,pair<int,int> now){
    //cout<<src.first<<" "<<src.second<<" "<<now.first<<" "<<now.second<<'\n';
    visit[now.first][now.second]=true;
    for(auto i : vec[now.first][now.second]){
        if(visit[i.first][i.second]){
            if(i.first==src.first && i.second == src.second) solve=true;
        }
        else dfs(src,i);
    }
}
int main(){
    fast_io();
    cin>>R>>C;
    for(int x=0;x<=R;x++){
        vec.push_back(vector<vector<pair<int,int>>>());
        for(int y=0;y<=C;y++) {
            vec[x].push_back(vector<pair<int,int>>());
        }
    }
    for(int x=1;x<=R;x++){
        for(int y=1;y<=C;y++){
            string temp;
            cin>>temp;
            if(temp[0]=='.') continue;
            int r1=0;
            int c1=0;
            int r2=0;
            int c2=0;
            int sl=(int)temp.size();
            int nn=1;
            int aa=1;
            bool chk=false;
            for(int x=sl-1;x>=0;x--){
                if('0'<=temp[x] && temp[x]<='9'){
                    if(!chk) r1+=(temp[x]-'0')*nn;
                    else r2+=(temp[x]-'0')*nn;
                    nn*=10;
                }
                if('A'<=temp[x] && temp[x]<='Z'){
                    if(!chk) c1+=(temp[x]-'A'+1)*aa;
                    else c2+=(temp[x]-'A'+1)*aa;
                    aa*=26;
                }
                if(temp[x]=='+'){
                    chk=true;
                    nn=1;
                    aa=1;
                }
            }
            vec[r1][c1].push_back({x,y});
            if(chk) vec[r2][c2].push_back({x,y});
            //cout<<temp<<'\n';
            //cout<<r1<<" "<<c1<<" "<<r2<<" "<<c2<<" "<<x<<" "<<y<<'\n';
        }
    }
    for(int x=1;x<=R;x++){
        for(int y=1;y<=C;y++){
            if(!visit[x][y]){
                dfs({x,y},{x,y});
            }
        }
    }
    if(solve) cout<<"yes";
    else cout<<"no";
}