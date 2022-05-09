#include<stdio.h>
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<queue>
#include<set>
using namespace std;
set<int> s;
bool aj[77777];
int main(){
    int A,B;
    cin>>A>>B;
    if(A>B){
        int temp=A;
        A=B;
        B=temp;
    }
    for(int x=1;x<=77777;x++){
        for(int y=2;x*y*y<=77777;y++){
            aj[x*y*y]=true;
        }  
    }
    int solve=0;
    for(int x=1;x<=A;x++){
        if(aj[x]) {
            continue;
        }
        for(long long y=1;x*y*y<=A;y++){
            for(long long z=1;x*z*z<=B;z++){
                solve++;
            }
        }
    }
    cout<<solve;
}