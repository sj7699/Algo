#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<set>
using namespace std;
vector<string> gw;
vector<string> gg;
int main(){
    int N,W;
    cin>>N>>W;
    //ios_base :: sync_with_stdio(false);
    //cin.tie(NULL);
    //cout.tie(NULL);
    for(int x=0;x<N;x++){
        string input1,input2;
        cin>>input1>>input2;
        gw.push_back(input1);
        gg.push_back(input2);
    }
    for(int x=0;x<W;x++){
        string input;
        cin>>input;
        bool k=true;
        for(int y=0;y<N;y++){
            string gnow=gw[y];
            string ggnow=gg[y];
            string ret="-----";
            string chk="-----";
            for(int z=0;z<5;z++){
                if(gnow[z]==input[z]){
                    ret[z]='G';
                    chk[z]='G';
                }
            }
            for(int z=0;z<5;z++){
                for(int w=0;w<5;w++){
                    if(gnow[z]==input[w] && ret[z]=='-' && chk[w]=='-'){
                        ret[z]='Y';
                        chk[w]='Y';
                    }
                }
            }
            if(ret!=ggnow){
                k=false;
                break;
            }
        }
        if(k){
            cout<<input<<'\n';
        }
    }
}