#include<stdio.h>
#include<string>
#include<iostream>
#include<map>
using namespace std;
map<char,int> m;
map<int,char,greater<int>> m2;
int roman(string a){
    int ret=0;
    int l=a.size();
    for(int x=0;x<l;x++){
        if(x+2<=l){
            if(m[a[x]]<m[a[x+1]]){
                ret+=m[a[x+1]]-m[a[x]];
                x++;
            }
            else{
                ret+=m[a[x]];
            }
        }
        else{
            ret+=m[a[x]];
        }
    }
    return ret;
}
string to_roman(int a){
    string ret;
    for(auto i : m2){
        int now=a/i.first;
        if(now){
            if(i.first==5 || i.first==50 || i.first==500){
                if(a/(i.first/5)==9){
                    continue;
                }
            }
            if(now>3){
                ret+=i.second;
                if(now==4){
                    ret+=m2[i.first*5];
                }
                else{
                    ret+=m2[i.first*10];
                }
            }
            else{
                for(int x=0;x<now;x++){
                    ret+=i.second;
                }
            }
            a-=now*i.first;
        }
    }
    return ret;
}
int main(){
    m['I']=1;
    m['V']=5;
    m['X']=10;
    m['L']=50;
    m['C']=100;
    m['D']=500;
    m['M']=1000;
    m2[1]='I';
    m2[5]='V';
    m2[10]='X';
    m2[50]='L';
    m2[100]='C';
    m2[500]='D';
    m2[1000]='M';
    string a,b;
    cin>>a>>b;
    int s1=roman(a)+roman(b);
    cout<<roman(a)+roman(b)<<'\n';
    cout<<to_roman(s1)<<'\n';
}