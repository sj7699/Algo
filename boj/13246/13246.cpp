#include<stdio.h>
#include<vector>
#include<set>
using namespace std;
int N;
long long B;
int mod=1000;
vector<int> mat;
vector<int> I;
vector<int> matmul(vector<int> a,vector<int> b){
    vector<int> ret(N*N,0);
    for(int x=0;x<N;x++){
        for(int y=0;y<N;y++){
            int temp=0;
            for(int z=0;z<N;z++){
                temp+=(a[x*N+z]*b[z*N+y])%mod;
                temp%=mod;
            }
            ret[x*N+y]=temp;
        }
    }
    return ret;
}
vector<int> matpow(vector<int> x, long long n) {
    vector<int> ret=I;
	for (; n; n >>= 1) {
		if (n & 1) ret =matmul(ret,x);
		x=matmul(x,x);
	}
	return ret;
}
vector<int> matadd(vector<int> a,vector<int> b){
    vector<int> ret(N*N,0);
    for(int x=0;x<N*N;x++){
        ret[x]+=(a[x]+b[x])%mod;
        ret[x]%=mod;
    }
    return ret;
}
vector<int> rec(long long now){
    if(now==1){
        return mat;
    }
    vector<int> ret=matmul(rec(now/2),matadd(I,matpow(mat,now/2)));
    if(now%2==0){
        return ret;
    }
    else{
        return matadd(ret,matpow(mat,now));
    }
    return ret;
}
int main(){
    scanf("%i%lli",&N,&B);
    for(int x=0;x<N;x++){
        for(int y=0;y<N;y++){
            int input;
            scanf("%i",&input);
            mat.push_back(input%1000);
            if(x==y) I.push_back(1);
            else I.push_back(0);
        }
    }
    vector<int> solve=rec(B);
    for(int x=0;x<N;x++){
        for(int y=0;y<N;y++){
            printf("%lli ",solve[x*N+y]);
        }
        printf("\n");
    }
}