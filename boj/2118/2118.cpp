#include<stdio.h>
#include<algorithm>
using namespace std;
int arr[50001];
int main(){
    int N;
    scanf("%i",&N);
    int s=0;
    for(int x=0;x<N;x++){
        scanf("%i",&arr[x]);
        s+=arr[x];
    }
    int solve=0;
    int now=0;
    int l=0;
    int r=0;
    now=arr[0];
    while(l<N){
        solve=max(solve,min(now,s-now));
        if(now<s/2){
            r++;
            int rnow=r>=N ? r-N : r;
            now+=arr[rnow];
        }
        else{
            now-=arr[l];
            l++;
        }
    }
    printf("%i",solve);
}