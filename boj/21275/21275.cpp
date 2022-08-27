// This file is a "Hello, world!" in C++ language by GCC for wandbox.
#include <iostream>
#include <cstdlib>
#include <string>
#include<vector>
using namespace std;
vector<long long> vec;
int main()
{
    char B[71];
    char C[71];
    cin>>B>>C;
    string str_b(B);
    string str_c(C);
    int count=0;
    int b_digit=0;
    int c_digit=0;
    long long X;
    for(int x=2;x<=36;x++){
        for(int y=2;y<=36;y++){
            long long sum_b=0;
            long long sum_c=0;
            long long digit=1;
            for(int z=str_b.size()-1;z>=0;z--){
                long long tempsum=str_b[z] >= 97 ? str_b[z]-87 : str_b[z]-48;
                if(tempsum>=x){
                    sum_b=-1;
                    break;
                }
                tempsum*=digit;
                sum_b+=tempsum;
                digit*=x;
            } 
            digit=1;
            for(int z=str_c.size()-1;z>=0;z--){
                long long tempsum=str_c[z] >= 97 ? str_c[z]-87 : str_c[z]-48;
                if(tempsum>=y){
                    sum_c=-2;
                    break;
                }
                tempsum*=digit;
                sum_c+=tempsum;
                digit*=y;
            }
            if(sum_b==sum_c){
                if(x!=y){
                    count++;
                    b_digit=x;
                    c_digit=y;   
                    X=sum_b;
                }
            }
        }
    }
    if(count==0){
        cout<<"Impossible";
    }
    else if(count==1){
        cout<<X<<" "<<b_digit<<" "<<c_digit;
    }
    else{
        cout<<"Multiple";
    }
}

