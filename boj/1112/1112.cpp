#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>
#include<iostream>
using namespace std;
int main(){
    long long N,M;
    cin>>N>>M;
    long long ps=0;
    long long ms=0;
    long long sm=1;
    long long temp=N;
    if(N<0 && M>0){
        temp=-N;
        printf("-");
    }
    if(N==0){
        printf("0");
        return 0;
    }
    for(int x=0;x<111;x++){
        if(M<0){
            if(sm<0) ms+=sm*(-M-1);
            else ps+=sm*(-M-1);
            if(N<0){
                if(ms<=temp) break;
            }
            if(N>0){
                if(ps>=temp) break;
            }
        }
        else{
            ps+=sm*(M-1);
            if(ps>=temp) break;
        }
        sm*=M;
    }
    while(sm){
        long long now=temp/sm;
        //printf("%lli %lli %lli %lli %lli\n",temp,now,sm,ms,ps);
        if(sm<0){
            ms-=sm*(-M-1);
            temp-=sm*(temp/sm);
            if(ms>temp){
                temp-=sm;
                now++;
            }
        }
        if(sm>0){
            if(M>0) ps-=sm*(M-1);
            else ps-=sm*(-1-M);
            temp-=sm*(temp/sm);
            if(ps<temp){
                temp-=sm;
                now++;
            }
        }
        //printf("%lli %lli %lli %lli %lli\n",temp,now,sm,ms,ps);
        printf("%lli",now);
        sm/=M;
    }
}