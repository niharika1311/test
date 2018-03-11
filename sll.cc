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

  bool search_element(int data) {
  Node *temp = head;
  while(temp) {
  if(temp->data == data)
    return true;
  else
    temp = temp->next;
  }
  return false;
}

void swap_nodes(int a, int b) {
  Node *temp1 = head, *temp2 = head, *prev1, *prev2;
  while(temp1 != nullptr && temp1->data != a) {
    prev1 =temp1;
    temp1 = temp1->next;
  }
  while(temp2 != nullptr && temp2->data != b) {
    prev2 =temp2;
    temp2 = temp2->next;
  }
  temp2->next = prev1->next->next;
  prev1->next = temp2;
  temp1->next = prev2->next->next;
  prev2->next = temp1;
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
/*  obj->delete_node(40);
  obj->printList();
  obj->delete_node_pos(6);
  obj->printList();
  obj->delete_node_pos(2);
  obj->printList();
*/  cout << obj->search_element(200) << endl;
  obj->printList();
  obj->swap(10, 200);
  obj->printList();
  return 0;
}
