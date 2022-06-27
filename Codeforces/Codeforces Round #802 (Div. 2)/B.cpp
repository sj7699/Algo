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
int main(){
    int T;
    cin>>T;
    while(T--){
        int n;
        string input;
        string solve;
        cin>>n>>input;
        if(input[0]=='9'){
            int temp=0;
            for(int x=n-1;x>=0;x--){
                if(x==0){
                    if(temp){
                        solve+='1';
                    }
                    else{
                        solve+='2';
                    }
                    break;
                }
                int now=input[x]-'0'+temp;
                if(now<=1){
                    solve+='0'+1-now;
                    temp=0;
                }
                else{
                    if(now==10){
                        solve+='1';
                    }
                    else{
                        solve+=11-now+'0';
                    }
                    temp=1;
                }
            }
            reverse(solve.begin(),solve.end());
        }
        else{
            for(int x=0;x<n;x++){
                solve+='9'-input[x]+'0';
            }
        }
        cout<<solve<<'\n';
    }
}