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
        int N;
        cin>>N;
        if(N%7==0){
            cout<<N<<'\n';
            continue;
        }
        int solve=N-N%10;
        cout<<7-solve%7+solve<<'\n';
    }
}