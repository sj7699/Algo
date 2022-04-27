#include<stdio.h>
#include<queue>
#include<algorithm>
#include<vector>
#include<set>
#include<iostream>
#include<map>
#include<cmath>
#include<string>
#include<stack>
using namespace std;
int main(){
    int T;
    cin>>T;
    while(T--){
        string input;
        cin>>input;
        int zcount=0;
        int ocount=0;
        int solve=0;
        for(auto i : input){
            if(i=='0') zcount++;
            if(i=='1') ocount++;
        }
        if(zcount!=ocount) solve=max(solve,min(zcount,ocount));
        else{
            if(input[0]=='0'){
                solve=max(solve,min(zcount-1,ocount));
            }
            else solve=max(solve,min(zcount,ocount-1));
            if(input.back()=='0'){

                solve=max(solve,min(zcount-1,ocount));
            }
            else solve=max(solve,min(zcount,ocount-1));
        }
        cout<<solve<<'\n';
    }
}