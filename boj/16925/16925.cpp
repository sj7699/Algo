#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<set>
using namespace std;
map<string,char> m;
map<string,int> m2;
int main(){
    int N;
    cin>>N;
    vector<vector<string>> vec(2*N,vector<string>());
    vector<string> vec2;
    for(int x=0;x<2*N-2;x++){
        string input;
        cin>>input;
        vec[input.size()].push_back(input);
        vec2.push_back(input);
    }
    string res;
    if(N==2) res=vec2[0]+vec2[1];
    else{
        set<string> s;
        for(int x=0;x<2;x++){
            if(vec[N-1][x].find(vec[N-1][1-x].substr(1))==0){
                string now=vec[N-1][1-x];
                now.push_back(vec[N-1][x][N-2]);
                s.insert(now);
            }
        }
        if(s.size()==1){
            res=*s.begin();
        }
        else{
            if(N%2==0){
                res+=vec[N-2][0]+vec[N-2][1];
            }
            else{
                if(N!=3) res+=vec[N-2][0]+vec[N-2][1].substr(1);
                else{
                    string l,r;
                    for(int z=0;z<2;z++){
                        if(vec[N-1][z].find(vec[N-2][0])==0){
                            res+=vec[N-1][z]+vec[N-2][0];
                            break;
                        }
                    }
                }
            }
        }
    }
    cout<<res<<'\n';
    for(int x=0;x<2*N-2;x++){
        if(m.find(vec2[x])!=m.end()){
            cout<<m[vec2[x]];
            continue;
        }
        if(res.find(vec2[x])==0){
            cout<<"P";
            m[vec2[x]]='S';
        }
        else {
            cout<<"S";
            m[vec2[x]]='P';
        }
    }
}