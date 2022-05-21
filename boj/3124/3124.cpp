#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int N;
vector<int> vec;
vector<int> vec2;
int main(){
    int N;
    cin>>N;
    int oc=0;
    int ic=0;
    string input,input2;
    cin>>input>>input2;
    for(int x=0;x<N;x++){
        vec.push_back(input[x]-'0');
        if(input[x]-'0') oc++;
    }
    vec2.push_back(input2[N-1]-'0');
    for(int x=0;x<N-1;x++){
        vec2.push_back(input2[x]-'0');
        if(input2[x]-'0') ic++;
    }
    if(oc==N){
        cout<<(long long)ic*(long long)(ic+1)+1LL;
    }
    else{
        bool st=false;
        vector<pair<long long,long long>> svec;
        long long temp=0;
        long long temp2=0;
        for(int x=0;x<N;x++){
            if(vec[x]){
                temp++;
                if(vec2[x]) temp2++;
            }
            else{
                if(temp){
                    temp2+=vec2[x];
                    svec.push_back({temp,temp2});
                }
                temp=0;
                temp2=0;
            }
        }
        if(temp){
            if(vec[0]) st=true;
            svec.push_back({temp,temp2});
        }
        if(svec.size()==0){
            cout<<0;
            return 0;
        }
        long long solve=0;
        if(st){
            svec[0].first=svec[0].first+svec.back().first;
            svec[0].second+=svec.back().second;
            for(int x=0;x<svec.size()-1;x++){
                long long now=(long long)svec[x].second;
                solve+=(now*(now-1LL))/2LL;
            }
        }
        else{
            for(int x=0;x<svec.size();x++){
                long long now=svec[x].second;
                solve+=(now*(now-1LL))/2LL;
            }
        }
        cout<<solve;
    }
}