#include<stdio.h>
#include<queue>
#include<vector>
#include<iostream>
using namespace std;
int board[1002][1002];
int ps[1002][1002];
int dp[1002][1002];
int main(){
    int N,M;
    cin>>N>>M;
    for(int x=1;x<=N;x++){
        string input;
        cin>>input;
        for(int y=0;y<M;y++){
            board[x][y+1]=input[y]-'0';
        }
    }
    for(int x=1;x<=N;x++){
        int cnt=0;
        for(int y=M;y>=1;y--){
            if(board[x][y]==1) cnt++;
            ps[x][y]=cnt;
            if(board[x][y-1]!=1){
                cnt=0;
            }
        }
    }
    int ans=0;
    /*for(int x=1;x<=N;x++){
        for(int y=1;y<=M;y++){
            cout<<ps[x][y];
        }
        cout<<'\n';
    }*/
    for(int x=1;x<=M;x++){
        queue<int> q;
        int now=1e9;
        int cnt=0;
        for(int y=1;y<=N;y++){
            if(now<=ps[y][x]){
                cnt++;
            }
            else{
                now=ps[y][x];
                cnt++;
            }
            q.push(ps[y][x]);
            //cout<<x<<" "<<y<<" "<<now<<" "<<cnt<<'\n';
            ans=max(ans,min(cnt,now));
            if(now<cnt){
                int k=0;
                while(!q.empty()){
                    if(q.front()==now){
                        k++;
                        q.pop();
                        break;
                    }
                    else{
                        k++;
                        q.pop();
                    }
                }
                if(q.empty()) now=1e9;
                else now=q.front();
                cnt-=k;
            }
            ans=max(ans,min(cnt,now));
        }
    }
    cout<<ans*ans;
}