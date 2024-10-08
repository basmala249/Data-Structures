#implementation of circular Single Linked List

// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
struct node{
    int data;
    node* link;
};
class circularSingleLinkedList{
    protected: 
      node* first;
      node* last;
      int count = 0;
    public :
      circularSingleLinkedList(){
          first = NULL;
          last = NULL;
      }
      void print(){
          node * curr = first;
          for(int i = 0 ; i < count ; ++i){
              cout << curr -> data << " ";
              curr = curr -> link;
          }
          cout << endl;
      }
      void insertAtEnd(int d){
          node * newNode = new node;
          newNode -> data = d;
          newNode -> link = NULL;
          if(first == NULL){
              first = newNode;
              last = newNode;
          }
          else{
              last -> link = newNode;
              last = newNode;
          }
          newNode -> link = first;
          count++;
      }
      void insertAtBegin(int d){
           node * newNode = new node;
          newNode -> data = d;
          newNode -> link = NULL;
          if(first == NULL){
              first = newNode;
              last = newNode;
              newNode -> link = first;
          }
          else{
              newNode -> link = first;
              first = newNode;
              last -> link = newNode;
          }
          count++;
      }
      void insert(int indx , int d){
          if(indx == 0){
              insertAtBegin(d);
          }
          else if(indx == count){
              insertAtEnd(d);
          }
          else{
              node * current  = first;
              node * newNode = new node;
              newNode -> data = d;
              newNode -> link = NULL;
              node * pre = NULL;
              int temp = 0 ;
              while(current != NULL && temp != indx){
                  pre = current;
                  current = current -> link;
                  temp++;
              }
              if(temp == indx){
                  pre -> link = newNode;
                  newNode -> link = current;
                  count++;
              }
          }
      }
      void deleteFromBegin(){
          node * curr = first;
          if(first == NULL){
              return;
          }
          if(curr -> link == first){
              first = NULL;
              last = NULL;
              delete curr;
          }
          else {
              first = first -> link;
              last -> link = first;
              delete curr;
          }
          count--;
      }
      void deleteFromEnd(){
          node * curr = first;
          node * pre = NULL;
          if(first == NULL){
              return;
          }
          //just one Noode
          if(curr -> link == first){
              first = NULL;
              last = NULL;
              delete curr;
              count--;
              return;
          }
          while(curr != last){
              pre = curr;
              curr = curr -> link;
          }
          pre -> link = first;
          last = pre;
          count--;
          delete curr;
      }
      void deleteAt(int indx ){
          if(indx < 0 or indx > count - 1)return;
          if(indx == 0){
              deleteFromBegin();
          }
          else if(indx == count - 1){
              deleteFromEnd();
          }
          else{
              node * curr = first;
              node * pre = NULL;
              for(int i = 0 ; i < indx ; ++i){
                  pre = curr;
                  curr = curr -> link;
              }
              pre -> link = curr -> link;
              delete curr;
              count--;
          }
      }
};
int main() {
    circularSingleLinkedList r;
    r.insertAtBegin(5);
    r.print();
    //cout << endl;
    r.insertAtBegin(4);r.insertAtBegin(1);
    r.insertAtEnd(9);r.insertAtEnd(51);
    r.insert(2,15);
    r.deleteAt(3);
    r.deleteAt(4);
    r.deleteAt(0);
     r.print();
    return 0;
}
