#include<stdio.h>
#include<vector>
#include<algorithm>
#include<bitset>
#include<string>
#include<iostream>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<functional>
using namespace std;
void fast_io() {
  cin.tie(0)->sync_with_stdio(0);
}
vector<vector<int>> vec;
int zc;
long long mean;
int N,M,T;
void check();
void rotate(int xi,int d,int k){
    if(d==0) d=1;
    else d=-1;
    for(int x=0;x<N;x++){
        if((x+1)%xi!=0) continue;
        vector<int> temp(M,0);
        for(int y=0;y<M;y++){
            int nx=y+d*k;
            if(nx<0) nx=M-(-nx%M);
            else nx=nx%M;
            temp[nx]=vec[x][y];
        }
        vec[x]=temp;
    }
    check();
}
void check(){
    bool chk[51][51];
    for(int x=0;x<N;x++){
        for(int y=0;y<M;y++) chk[x][y]=false;
    }
    bool chk2=false;
    for(int x=0;x<N;x++){
        for(int y=0;y<M;y++){
            if(vec[x][y]==0) continue;
            if(x!=0){
                if(vec[x][y]==vec[x-1][y]){
                    chk2=true;
                    chk[x][y]=true;
                    chk[x-1][y]=true;
                }
            }
            int ny = y+1==M ? 0 : y+1;
            if(vec[x][y]==vec[x][ny]){
                chk2=true;
                chk[x][y]=true;
                chk[x][ny]=true;
            }
        }
    }
    if(chk2){
        for(int x=0;x<N;x++){
            for(int y=0;y<M;y++){
                if(chk[x][y]){
                    zc++;
                    mean=mean-(long long)vec[x][y];
                    vec[x][y]=0;
                }
            }
        }
    }
    else{
        vector<vector<int>> temp(N,vector<int>(M,0));
        for(int x=0;x<N;x++){
            for(int y=0;y<M;y++){
                if(vec[x][y]==0) continue;
                long long now=(long long)(N*M-zc)*(long long)vec[x][y];
                if(now<mean){
                    temp[x][y]=1;
                }
                if(now>mean){
                    temp[x][y]=-1;
                }
            }
        }       
        for(int x=0;x<N;x++){
            for(int y=0;y<M;y++){
                if(temp[x][y]!=0){
                    mean=mean+(long long)temp[x][y];
                    vec[x][y]+=temp[x][y];
                }
            }
        }
    }
}
int main(){
    fast_io();
    cin>>N>>M>>T;
    for(int x=0;x<N;x++){
        vector<int> temp;
        for(int y=0;y<M;y++){
            int input;
            cin>>input;
            temp.push_back(input);
            mean=mean+(long long)input;
        }
        vec.push_back(temp);
    }
    for(int x=0;x<T;x++){
        int xi,d,k;
        cin>>xi>>d>>k;
        if(zc==N*M) continue;
        rotate(xi,d,k);
    }
    cout<<mean;
}