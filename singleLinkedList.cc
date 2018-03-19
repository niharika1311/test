#include<iostream>
#include<cstdlib>
using namespace std;

struct Node {
    int data;
    Node *next;
};

class linkedList {
    Node *head, *tail;
    public:
    linkedList():head(nullptr), tail(nullptr) {
    }
    Node* createNode(int data) {
        Node *temp = new Node;
        if(temp) {
            temp->data = data;
            temp->next = nullptr;
            return temp;
        } else {
            cout << "new failed.Exiting" << endl;
            exit(1);
        }
    }

    void insertEnd(int data) {
        Node *temp = createNode(data);
        if(head == nullptr) {
            head = tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }

    void printList() {
        Node *temp = head;
        while(temp != nullptr) {
            cout << temp->data << "==>";
            temp = temp->next;
        }
        cout << "nullptr" << endl;
    }

    void insertFront(int data) {
        Node *temp = createNode(data);
        if(head == nullptr) {
            head = tail = temp;
        } else {
            temp->next = head;
            head = temp;
        }
    }

    void insert(int data, int pos) {
//        Node *temp = createNode(data);
        int count = 1;
        Node *p = head;
        while(p != tail) {
            count++;
            p = p->next;
        }
        if(pos == count) {
            insertEnd(data);
        } else {
            p = head;int i;
            for(i = 1; i <= count; i++) 
                p = p->next;
            Node *temp = createNode(data);
            temp->next = p->next;
            p->next = temp;
        cout << temp->data << " is inserted at " << i+1 << "position\n";
        }
    }
};


int main() {
    linkedList *node = new linkedList;
    node->insertEnd(10);
    node->insertFront(11);
    node->insertEnd(20);
    node->insertFront(21);
    node->insertEnd(30);
    node->insertFront(31);
    node->insertEnd(40);
    node->insertFront(41);
    node->printList();
    return 0;
}
