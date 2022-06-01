#include<vector>
#include<iostream>
using namespace std;
bool bpn[4200001];
vector<int> pn;
int main(){
    int N;
    cin>>N;
    for(int x=2;x<=4200000;x++){
        if(bpn[x]) continue;
        else pn.push_back(x);
        for(int y=x*2;y<=4200000;y+=x){
            bpn[y]=true;
        }
    }
    int l=0;
    int r=0;
    int solve=0;
    int temp=pn[0];
    while(l<=r){
        if(pn[r]>N) break;
        if(temp>N){
            temp-=pn[l];
            l++;
        }
        else if(temp==N){
            solve++;
            r++;
            temp+=pn[r];
        }
        else{
            r++;
            temp+=pn[r];
        }
    }
    cout<<solve;
}