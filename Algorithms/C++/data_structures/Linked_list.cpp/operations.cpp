#include<iostream>
using namespace std;
struct node{
  int data;
  struct node *next;
};
struct node *head=NULL,*tail,*last;
void display(struct node *head){
    while(head!=NULL){
        cout<<head->data<<"->";
        head=head->next;
    }
    cout<<"NULL";
}

void push(int info){
struct node *tail,*ptr;
  if(head==NULL){
    head=(struct node*)malloc(sizeof(struct node));
    head->data=info;
    tail=head;
    tail->next=NULL;
  }
  else{
    ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=info;
    tail->next=ptr;
    tail=ptr;
    tail->next=NULL;
  }
}
void pop(){
  last=head;
  while(last->next->next!=tail){
    last=last->next;
  }
  tail=last;
  free(tail->next);
  tail->next=NULL;
}
int main(){
  push(1);//O(1)
  push(2);
  push(3);
  push(4);
  pop();
  display(head);
}