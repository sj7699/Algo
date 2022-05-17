#include<string>
#include<stdio.h>
#include<iostream>
using namespace std;
int cnt[27];
int main(){
    string input;
    string res;
    cin>>input;
    for(int x=0;x<input.size();x++){
        cnt[input[x]-'a']++;
    }
    int l=input.size();
    for(int x=0;x<l;x++){
        bool chk=false;
        for(int y=0;y<26;y++){
            if(!cnt[y]) continue;
            int diff= l-1-x;
            if(x>=l/2 && diff>=0){
                if(y+'a'==res[diff]){
                    continue;
                }
            }
            res+=(y+'a');
            cnt[y]--;
            chk=true;
            break;
        }
        if(!chk){
            res="-1";
            break;
        }
    }
    cout<<res;
}