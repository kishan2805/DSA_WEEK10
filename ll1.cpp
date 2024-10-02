#include<iostream>
#include<vector>
#include<string>
using namespace std;
class node{
    public:
    int data;
    node* next;

    node(){
        cout<<"static aloo"<<endl;
        this-> next=NULL;
    }
    node(int data){

        cout<<"parametarized constructor call"<<endl;
        this-> data=data;
        this-> next=NULL;
    }
};

void printll(node* start){
    node * temp=start;
    int count =0;
    while(temp!=NULL){
        cout<<temp->data<<endl;
        temp=temp->next;
        count++;
    }
    cout<<"total no. of nodes : "<< count<<endl;
}

void insertstart(node * &start, int data){

    node* four=new node(data);
    four-> next=start;
    if(start==NULL){
        start=four;
        // currently we dont need that as this edge case is already covered by the code even without the if block
    }
    start=four;
    printll(start);
}

void insertend(node* &start, int data){
    node*temp=start;
    node* five=new node(data);
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=five;
}

void insertpos(node * &start,int data, int pos){
    node * new1=new node(data);
    // empty list
    if(start==NULL&& pos ==1){
        start=new1;
    }
    // pos<1
    else if(pos==1){
        new1->next=start;
        start=new1;
    }
    else {
        node* temp = start;
        int count = 1;
        while (count < pos - 1 && temp != NULL) {
            temp = temp->next;
            count++;
        }
        if (temp == NULL) {
            cout << "range out of bound " << endl;
        } else {
            new1->next = temp->next;
            temp->next = new1;
        }
    }
    return ;
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
        start=start->next;
        free(temp);
        return;
    }
    else{
        int count =1;
        temp=temp->next;
        node* prev=start;
        node* curr=start;
        while(curr->next!= NULL && pos !=count){
            prev=curr;
            curr=temp;
            temp=temp->next;
            count++;
        }
        // if(curr==NULL){
        //     cout<<"range out of bound "<<endl;
        //     return;
        // }
        if(pos==count){
            prev->next=temp;
            free(curr);
        }
        else{
            cout<<"range out of bound"<<endl;
            return ;
        }
    }

}

void revell(node *&start){
    node* temp=start;
    // empty LL
    if(start==NULL){
        cout<<"empty list "<<endl;
        return;
    }
    // one element list
    if(start->next==NULL){
        cout<<"single element list"<<endl ;
        return ;
    }
    node* prev=NULL;
    node* cur =start; 
    while(cur!=NULL){
        temp=cur->next;
        cur->next=prev;
        prev=cur;
        cur=temp;

    }
    start=prev;
    return ;


}

void midele(node* &start){
    node* temp=start;
    node* pre=temp;
    int count =1;
    int mid=count/2 +1;
    int newmid;

    while(temp!=NULL){
        newmid =count/2 +1;
        count++;

        if(mid!=newmid){
            pre=pre->next;
            mid=newmid;
        }
        temp=temp->next;
    }
    cout<<pre->data<<endl;
}

// FAST - SLOW APPROACH
void middlele(node *&start){
    node* fast=start;
    node* slow =start;

    while(fast!=NULL){
            fast=fast->next;
            if(fast!=NULL){
                fast=fast->next;
                slow=slow->next;
            }
        }
        cout<<slow-> data<<endl;

        return;
}

// pallindrome check for LL
bool isPalindrome(node* head) {
        // find mid and break
        node* fast=head;
        node* slow=head;
        while(fast->next!=NULL){
            fast=fast->next;
            if(fast->next!=NULL){
                fast=fast->next;
                slow=slow->next;
            }
        }
        // reversing the 2nd ll
        node* cur=slow->next;
        node* pre=NULL;
        // dont forget to null the next of mid node as it acts as termination for comparision
        slow->next=NULL;
        node* temp=NULL;
        while(cur!=NULL){
            temp=cur->next;
            cur->next=pre;
            pre=cur;
            cur=temp;
        }
        // comparing the 2 ll

        while(pre!=NULL){
            if(pre-> data !=head->data){
                return false;
            }
            pre=pre->next;
            head=head->next;
        }

        return true;
}
bool looping (node* &start){
    node* fast=start;
    node* slow=start;
    while(fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
            slow=slow->next;
        }

        if(fast==slow)
            return true;
    }
    return false;
}

void startofloop(node* &start){
    node* fast=start;
    node* slow=start;
    int flag=1;
    while(fast!=NULL ){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
            slow=slow->next;
        }
        if(slow==fast){
            cout<<"loop is present "<< endl;
            // flag=0;
            break;
        }
    }
    slow=start;
    while(fast!=slow){
        slow=slow->next;
        fast=fast->next;
    }
    cout<<fast->data;
    return ;

}
void removingloop(node* &start){
    node* fast=start;
    node* slow=start;
    int flag=1;
    while(fast!=NULL ){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
            slow=slow->next;
        }
        if(slow==fast){
            cout<<"loop is present "<< endl;
            // flag=0;
            break;
        }
    }
    slow=start;
    while(fast->next!=slow){
        //here we found the last node 
        //  then we are making its next as null
        slow=slow->next;
        fast=fast->next;
    }
    fast->next=NULL;
    cout<<fast->data;
    return ;

}

// adding 1 to a no 
void add1(node* &start){
    // reversing the LL
    revell(start);
    // adding 1 to it
    node* temp=start;
    while(temp->next!=NULL){
        if(temp->data <9){
            temp->data=temp->data+1;
            revell(start);
            printll(start);
            return;
        }
        else{
            temp->data=0;
            temp=temp->next;
        }
    }
    // now what if the last node has 9 
    if(temp->data==9){
        temp->data=0;
        insertend(start,1);
    }
    else {
        temp->data=temp->data+1;
    }

    // reversing to make it the actual no 
    revell(start);
    // printing the ans 
    printll(start);

    return ;

}

//kth element from the end 
void kthele(node* start,int k){
    if(k<0){
        return ;
    }
    revell(start);
    int count =0;
    node* temp=start;
    while(count!=k && temp!=NULL){
        count++;
        temp=temp->next;
    }
    if(k==count){
        cout<<temp->data;
        // return;
    }
    else{
        cout<<"out of bound ";
    }

    revell(start);
    cout<<"in function"<<endl;
    printll(start);
    return ;


}



int main(){
    // node a;  //static  or
    // node* start=new node(); 


    node* one=new node(1); 
    node* two=new node(2); 
    node* three=new node(3); 

    // f->next =three;

    one->next=two;
    two->next=three;

// start of the linked list

    node* start=one;
    // printll(start);
    // printll(start);

    // insertstart(start,10);
    // printll(start);
    // insertend(start,20);
    // printll(start);

    // node *newly=new node();
    // insertstart(newly,60);
    // printll(newly);
    // cout<<(newly->next)->data;
    // string s="kishan";

    // node *head=NULL;
    // insertstart(head,8);
    // insertend(head,11);
    // printll(head);

    // insert at ba position
    // insertpos(start,4,4);
    // insertpos(start,5,5);
    // insertpos(start,6,6);
    // insertpos(start,100,4);
    // insertpos(start,111,4);
    printll(start);

    // deletepos(start,0);
    // printll(start);

    // revell(start);
    // printll(start);

    // finding mid of a linkeed list 
    // midele(start);

    // FAST - SLOW appproach 
    // middlele(start);

    // checking pallindroem 
    // bool ans=isPalindrome(start);
    // cout<<ans;

    // finding loop in LL

    // bool ans=looping(start);
    // cout<<ans;

    // finding starting point of the loop 
    // startofloop(start);

    // add1(start);

// kth element from the end 

    // kthele(start,1);
    // cout<<endl;
    // printll(start);

    
    

}