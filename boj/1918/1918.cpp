#include<stdio.h>
#include<string>
#include<iostream>
#include<stack>
using namespace std;
int main(){
    string input;
    cin>>input;
    stack<char> stk;
    for(int x=0;x<input.size();x++){
        if(input[x]>='A' && input[x]<='Z'){
            cout<<input[x];
            continue;
        }
        if(input[x]=='('){
            stk.push('(');
            continue;
        }
        if(input[x]==')'){
            while(stk.top()!='('){
                cout<<stk.top();
                stk.pop();
                if(stk.empty()) break;
            }
            stk.pop();
        }
        if(input[x]=='*' || input[x]=='/'){
            if(stk.empty()) {
                stk.push(input[x]);
                continue;
            }
            if(stk.top()=='+' || stk.top()=='-' || stk.top()=='('){
                stk.push(input[x]);
                continue;
            }
            else{
                while(stk.top()=='*'|| stk.top()=='/'){
                    cout<<stk.top();
                    stk.pop();
                    if(stk.empty()) break;
                }
                stk.push(input[x]);
            }
            continue;
        }
        if(input[x]=='+' || input[x]=='-'){
            if(stk.empty()){
                stk.push(input[x]);
                continue;
            }
            if(stk.top()!='('){
                while(stk.top()!='('){
                    cout<<stk.top();
                    stk.pop();
                    if(stk.empty()) break;
                }
                stk.push(input[x]);
                continue;
            }
            else{
                stk.push(input[x]);
            }
        }
    }
    while(!stk.empty()){
        cout<<stk.top();
        stk.pop();
    }
}