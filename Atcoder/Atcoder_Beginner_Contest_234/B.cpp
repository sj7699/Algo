#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
    int N;
    cin>>N;
    vector<pair<int,int>> vec;
    vector<long double> vecld;
    for(int x=0;x<N;x++){
        int inputx,inputy;
        cin>>inputx>>inputy;
        for(int y=0;y<x;y++){
            vecld.push_back(sqrtl((vec[y].first-inputx)*(vec[y].first-inputx)+(vec[y].second-inputy)*(vec[y].second-inputy)));
        }
        vec.push_back({inputx,inputy});
    }
    sort(vecld.begin(),vecld.end(),greater<long double>());
    printf("%.6LF",vecld[0]);
}