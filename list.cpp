#include "list.h"

List::List(){
  head= new Node();
  head = NULL;
}

List::~List(){
  delete head;
}

void List::addNextNode(string question, string A, string B, int index){
  
  Node *new_node = new Node(question,A,B);
  Node *temp = head;

  if (head == NULL){
    head=new_node;
  }

  else{
    for(int i=0;i<index;i++){
      temp=temp->down;
    }
    while (temp->next != NULL){
          temp = temp->next;
    }
    temp->next=new_node;
  }
}

void List::addDownNode(string question, string A, string B,int index){

  Node *new_node = new Node(question,A,B);
  Node *temp = head;

  if (head == NULL){
    head=new_node;
  }
  else{
    for(int i=0;i<index;i++){
      temp=temp->next;
    }
    while (temp->down != NULL){
          temp = temp->down;
    }
    temp->down=new_node;
  }
}
