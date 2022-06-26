#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
#include<map>
#include<set>
#include<stack>
#include<queue>
using namespace std;
vector<int> vec;
map<int,int> m;
map<int,long long> l;
map<int,long long> r;
map<int,long long> kl;
map<int,long long> kr;
int main(){
    int N,Q;
    scanf("%i%i",&N,&Q);
    for(int x=0;x<N;x++){
        int a,b;
        scanf("%i%i",&a,&b);
        vec.push_back(b);
        m[b]=a;
    }
    sort(vec.begin(),vec.end());
    long long temp=0;
    long long k=0;
    for(int x=0;x<N;x++){
        if(x==0){
            l[vec[0]]=0;
            k+=m[vec[0]];
            kl[vec[0]]=k;
            continue;
        }
        temp+=(long long)(vec[x]-vec[x-1])*k;
        l[vec[x]]=temp;
        k+=m[vec[x]];
        kl[vec[x]]=k;
    }
    k=0;
    temp=0;
    for(int x=N-1;x>=0;x--){
        if(x!=N-1){
            temp+=(long long)(vec[x+1]-vec[x])*k;
        }
        r[vec[x]]=temp;
        k+=m[vec[x]];
        kr[vec[x]]=k;
    }
    for(int x=0;x<Q;x++){
        int input;
        scanf("%i",&input);
        int rv=upper_bound(vec.begin(),vec.end(),input)-vec.begin();
        if(rv==0){
            printf("%lli\n",r[vec[rv]]+kr[vec[rv]]*(long long)abs(input-vec[0]));
        }
        else if(rv==N){
            printf("%lli\n",l[vec[rv-1]]+kl[vec[rv-1]]*(long long)abs(input-vec[N-1]));
        }
        else{
            printf("%lli\n",l[vec[rv-1]]+r[vec[rv]]+kl[vec[rv-1]]*(long long)abs(input-vec[rv-1])+kr[vec[rv]]*(long long)abs(input-vec[rv]));
        }
    }
}