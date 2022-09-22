#include<stdio.h>
using namespace std;
int arr[51];
int N;
bool visit[51];
int solve;
void dfs(int start,int count){
    if(visit[start]){
        if(count>=1) solve++;
        return;
    }
    visit[start]=true;
    dfs(arr[start],count+1);
}
int main(){
    scanf("%i",&N);
    for(int x=0;x<N;x++){
        scanf("%i",&arr[x]);
    }
    for(int x=0;x<N;x++){
        dfs(x,0);
    }
    if(solve==1){
        printf("0");
    }
    else{
        printf("%i",solve);
    }
}