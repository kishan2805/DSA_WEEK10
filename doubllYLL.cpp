#include<iostream>
#include<string>
using namespace std;

class node{
    public:
    int daa;
    node* left;
    node* right;

    node(int data){
        this->daa=data;
        this->left=NULL;
        this->right=NULL;
        
    }
    node(){
        // this->daa=data;
        this->left=NULL;
        this->right=NULL;
    }

};

// inserting into doublly LL
void insertll(node * &start,int data, int pos){
    node* new1=new node(data);
    if(pos<=0){
        cout<<"invalid index "<<endl;
        return ;
    }
    // if LL is empty
    if(start==NULL){
        start=new1;
        return;
    }
    // insert in front 
    if(pos==1){
        new1->right=start;
        start->left=new1;
        start=new1;
        return;
    }
    // insert at a position other than front 
    int count =1;
    node* temp=start;
    node* pre=start;
    while(pos!=count && temp->right!=NULL){
        pre=temp;
        temp=temp->right;
        count++;
    }
    if(count==pos){
        pre->right=new1;
        new1->right=temp;
        new1->left=pre;
        temp->left=new1;
    }
    else if (count==pos-1){
        temp->right=new1;
        new1->left=temp;
        return;
    }
    else{
        cout<<"range out of bound "<<endl;
        return;
    }
}
void deletepos(node * &start,int pos){
    node * temp =start;
    // empty LL
    if(start==NULL ){
        cout<<"EMPTY LL"<<endl;
        return;
    }
    if(pos<=0){
        cout<<"postion not valid "<<endl;
        return ;
    }
    // remove from 1st pos (pos==1)
    if(pos==1){
        start=start->right;
        free(temp);
        return;
    }
    else{
        int count =1;
        temp=temp->right;
        node* prev=start;
        node* curr=start;
        while(curr->right!= NULL && pos !=count){
            prev=curr;
            curr=temp;
            temp=temp->right;
            count++;
        }
        if (pos == count) {
            prev->right = temp;  // temp is the next node after curr
            if (temp != NULL) {
                temp->left = prev;
            }
            free(curr);
        }
        else{
            cout<<"range out of bound"<<endl;
            return ;
        }
    }

}
void printll(node* start){
    node * temp=start;
    int count =0;
    while(temp!=NULL){
        cout<<temp->daa<<endl;
        temp=temp->right;
        count++;
    }
    cout<<"total no. of nodes : "<< count<<endl;
}


int main(){
    node* one=new node(4);
    // node* two=new node(6);
    // node* three=new node(8);

    node* start=one;
    // one->right=two;
    // two->left=one;
    // node* start=new node;
    // printll(start);
    insertll(start,7,2);
    insertll(start,9,3);
    insertll(start,11,4);
    insertll(start,13,5);
    printll(start);

    // deletepos(start,5);
    // printll(start);




}