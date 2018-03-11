#include<iostream>
#include<cstdlib>

using namespace std;

class Node {
  public:
  int data;
  Node *next;
  Node* createNode(int d) {
    Node *temp = new Node;
    if(temp) {
      temp->data = d;
      temp->next = nullptr;
      return temp;
    } else {
      cout << "new failed. exiting the program" << endl;
      exit(1);
    }
  }
};

class SLL : public Node {
  Node *head, *tail;
  public:
  SLL():head{nullptr}, tail{nullptr} {
  }
  int no_of_nodes() {
    Node *temp = head;
    int c = 1;
    while(temp != tail) {
      c++;
      temp = temp->next;
    }
    return c;
  }
  void insertNode(int d) {
    Node *temp = createNode(d);
    if(head == nullptr) 
      head = tail = temp;
    else {
      tail->next = temp;
      tail = temp;
    }
  }
  void printList() {
    Node *temp = head;
    while(temp != tail) {
      cout << temp->data << "->";
      temp = temp->next;
    }
    cout << tail->data << "->nullptr" << endl;
  }
  void insertFront(int data) {
    Node *temp = createNode(data);
    if(head == nullptr) 
      head = tail = temp;
    else {
      temp->next = head;
      head = temp;
    }
  }
  void insertAtPos(int pos, int data) {
    Node *node_pos = createNode(data);
    int count = no_of_nodes();
    if(pos == count)
      insertNode(data);
    else {
      Node *temp = head;
      for(int i = 1; i < pos; i++)
        temp = temp->next;
      node_pos->next = temp->next;
      temp->next = node_pos;
    }
  }

  void delete_node(int data) {
    if(head->data == data) 
      head = head->next;
    else {          
      Node *temp = head, *prev;
      while(temp != nullptr && temp->data != data) {
        prev = temp;
        temp = temp->next;
      }
      prev->next = temp->next;
      if(temp == tail)
        tail = prev;
    }
  }

  void delete_node_pos(int pos) {
    Node *prev = head;
    int count = no_of_nodes();
    if(pos == 1)
      head = head->next;
    for(int i = 1; prev != nullptr && i < pos - 1; i++)
      prev = prev->next;
    prev->next = prev->next->next;
    if(pos == count)
      tail = prev;
  }
};

int main() {
  SLL *obj = new SLL;
  obj->insertNode(10);
  obj->printList();
  obj->insertFront(20);
  obj->printList();
  obj->insertNode(30);
  obj->printList();
  obj->insertNode(40);
  obj->insertFront(10);
  obj->printList();
  obj->insertNode(50);
  obj->printList();
  obj->insertAtPos(5,200);
  obj->printList();
  obj->delete_node(40);
  obj->printList();
  obj->delete_node_pos(6);
  obj->printList();
  obj->delete_node_pos(2);
  obj->printList();
  return 0;
}
