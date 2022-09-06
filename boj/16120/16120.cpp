#include <stdio.h>
#include<queue>
#include<iostream>
#include<stack>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
void fast_io() {
  cin.tie(0)->sync_with_stdio(0);
}
int main(){
    fast_io();
    string input;
    cin>>input;
    int now=0;
    char last='P';
    if(input.size()<=3){
        if(input=="P") cout<<"PPAP";
        else cout<<"NP";
        return 0;
    }
    for(auto i : input){
        if(i=='P'){
            if(last=='A'){
                if(now>=2){
                    now--;
                }
                else{
                    cout<<"NP";
                    return 0;
                }
            }
            else{
                now++;
            }
        }
        else{
            if(last=='A'){
                cout<<"NP";
                return 0;
            }
        }
        last=i;
    }
    if(input.back()=='A'){
        cout<<"NP";
        return 0;
    }
    if(now==1){
        cout<<"PPAP";
    }else cout<<"NP";
}
