#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
#include<map>
#include<set>
#include<stack>
#include<queue>
using namespace std;
string input;
int low_level;
bool k[200];
bool recur(int l,int r,int level){
    bool ret=false;
    bool first=false;
    int temp=0;
    int templ=0;
    for(int x=l+1;x<=r-1;x++){
        if(input[x]=='('){
            temp++;
            if(temp==1) templ=x;
        }
        else if(input[x]==')'){
            temp--;
            if(temp==0){
                bool pp=recur(templ,x,level+1);
                if(!first){
                    ret=pp;
                    first=true;
                }
                else{
                    if((low_level-level)%2==0){
                        ret=ret&&pp;
                    }
                    else{
                        ret=ret||pp;
                    }
                }
            }
        }
        if(temp==0 && input[x]!='(' && input[x]!=')'){
            if(!first){
                ret=k[input[x]];
                first=true;
            }
            else{
                if((low_level-level)%2==0){
                    ret=ret&&k[input[x]];
                }
                else{
                    ret=ret||k[input[x]];
                }
            }
        }
    }
    return ret;
}
int main(){
    int t=0;
    k['T']=true;
    while(++t){
        cin>>input;
        if(input=="()") break;
        int temp=0;
        low_level=0;
        for(int x=0;x<input.size();x++){
            if(input[x]=='(') temp++;
            if(input[x]==')') temp--;
            low_level=max(low_level,temp);
        }
        if(recur(0,input.size()-1,1)){
            cout<<t<<". true\n";
        }
        else{
            cout<<t<<". false\n";
        }
    }
}