#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>
#include<iostream>
using namespace std;
vector<int> vecx;
vector<int> vecy;
int lim;
int N;
int fx(int a){
    int ret=0;
    for(int x=0;x<N;x++){
        ret+=abs(a-vecx[x]);
    }
    return ret;
}
int fy(int a){
    int ret=0;
    for(int x=0;x<N;x++){
        ret+=abs(a-vecy[x]);
    }
    return ret;
}
int main(){
    scanf("%i",&N);
    for(int x=0;x<N;x++){
        int ix,iy,pxy;
        scanf("%i%i%i",&ix,&iy,&pxy);
        for(int y=0;y<pxy;y++){
            lim++;
            vecx.push_back(ix);
            vecy.push_back(iy);
        }
    }
    sort(vecx.begin(),vecx.end());
    sort(vecy.begin(),vecy.end());
    N=lim;
    if(N%2!=0) N++;
    int solvex=vecx[(N-1)/2];
    int solvey=vecy[(N-1)/2];
    printf("%i %i",solvex,solvey);
}