#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<iostream>
using namespace std;
class Node{
public:
int data=0;
Node* left;
Node* right;
Node(int data){
    this->data=data;
    this->left=NULL;
    this->right=NULL;
}
};
bool insert(Node* now,int d){
    if(now==NULL){
        return true;
    }
    if(now->data>d){
        bool a=insert(now->left,d);
        if(a){
            now->left=new Node(d);
        }
        return false;
    }
    if(now->data<d){
        bool a=insert(now->right,d);
        if(a) now->right=new Node(d);
        return false;
    }
    return false;
}
void postorder(Node* now){
    if(now==NULL) return;
    postorder(now->left);
    postorder(now->right);
    cout<<now->data<<'\n';
}
int main(){
    int input;
    cin>>input;
    Node* root= new Node(input);
    while(cin>>input){
        insert(root,input);
    }
    postorder(root);
}
