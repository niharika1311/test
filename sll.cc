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
};

int main() {
  SLL *obj = new SLL;
  obj->insertNode(10);
  obj->printList();
  obj->insertNode(20);
  obj->printList();
  obj->insertNode(30);
  obj->printList();
  obj->insertNode(40);
  obj->printList();
  obj->insertNode(50);
  obj->printList();
  return 0;
}
