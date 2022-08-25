#include<stdio.h>
#include<string>
using namespace std;
int count(int n,int m){
    int ret=0;
    int digit=1;
    int temp=n;
    if(m==0){
        while(temp!=0){
            int now=temp%10;
            if(now==m){
                ret+=(n-temp*digit)+1;
                ret+=(temp/10-1)*digit;
            }
            else{
                ret+=(temp/10)*digit;
            }
            temp/=10;
            digit*=10;
        }
        return ret;
    }
    while(temp!=0){
        int now=temp%10;
        if(now<m){
            ret+=(temp/10)*digit;
        }
        else{
            if(now==m){
                ret+=(n-temp*digit)+1;
                ret+=(temp/10)*digit;
            }
            else{
            ret+=(temp/10+1)*digit; 
            }
        }
        digit*=10;
        temp/=10;
    }
    return ret;
}
int main(){
        int input1;
        scanf("%i",&input1);
        for(int x=0;x<10;x++){
            printf("%i ",count(input1,x));
        }
}