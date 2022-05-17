#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
int lis[1000002];
int arr[1000002];
int N;
int solve=1;
int bnsearch(int target){
    int left=0;
    int right=N-1;
    int mid;
    while(right-left>=0){
        mid=(right+left)/2;
        if(lis[mid]<target){
            left=mid+1;
        }
        else{
            right=mid-1;
        }
    }
    return right;
}
int main(){
    cin>>N;
    for(int x=0;x<N;x++){
        cin>>arr[x];
        lis[x]=2000000000;
    }
    lis[N]=2000000000;
    lis[0]=arr[0];
    for(int x=1;x<N;x++){
        int index=bnsearch(arr[x]);
        lis[index+1]=arr[x];
    }
    for(int x=0;x<N+1;x++){
        if(lis[x]==2000000000){
            solve=x;
            break;
        }
    }
    cout<<solve;
}
