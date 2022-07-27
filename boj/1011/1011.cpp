#include<stdio.h>
#include<queue>
int square(long long n){
    long long temp=1;
    long long temp2=temp*temp;
    int count=0;
    while(1){
        temp2=temp*temp;
        if(temp2>n){
            break;
        }
        count++;
        temp++;
    }
    return count;
}
using namespace std;
int main(){
    int T,X,Y,D,temp;
    int N=0;
    scanf("%i",&T);
    for(int x=0;x<T;x++){
        scanf("%i%i",&X,&Y);
        D=Y-X;
        temp=square(D);
        N=2*temp-1;
        D=D-temp*temp;
        if(D>0 && D<=temp){
            N++;
        }
        if(D>temp && D<2*temp+1){
            N+=2;
        }
        printf("%i\n",N);
    }
}