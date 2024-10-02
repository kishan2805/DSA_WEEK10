#include<iostream>
#include<string>
using namespace std;

class node{
    public:
    int data;
    node *next;

    node(){
        // this->data=NULL;
        this->next=NULL;
    }
    node(int data){
        this->data=data;
        this->next=NULL;
    }

};

int main(){
    node* one=new node(4);
    node* two=new node(6);
    node* three=new node(8);
    node * start = one ;

    

}