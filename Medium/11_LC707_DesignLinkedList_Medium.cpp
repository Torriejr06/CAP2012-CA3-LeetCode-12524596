
#include <iostream>
using namespace std;

class MyLinkedList {

private:

    // Node structure
    struct Node {
        int val;
        Node* next;

        Node(int x) {
            val = x;
            next = NULL;
        }
    };

    Node* head;
    int size;

public:

    // Constructor
    MyLinkedList() {
        head = NULL;
        size = 0;
    }

    // Get value at a particular index
    int get(int index) {

        if (index < 0 || index >= size) {
            return -1;
        }

        Node* current = head;

        for (int i = 0; i < index; i++) {
            current = current->next;
        }

        return current->val;
    }

    // Insert at the beginning
    void addAtHead(int val) {

        Node* newNode = new Node(val);

        newNode->next = head;
        head = newNode;

        size++;
    }

    // Insert at the end
    void addAtTail(int val) {

        Node* newNode = new Node(val);

        if (head == NULL) {
            head = newNode;
        }
        else {
            Node* current = head;

            while (current->next != NULL) {
                current = current->next;
            }

            current->next = newNode;
        }

        size++;
    }

    // Insert at a particular index
    void addAtIndex(int index, int val) {

        if (index < 0) {
            index = 0;
        }

        if (index > size) {
            return;
        }

        if (index == 0) {
            addAtHead(val);
            return;
        }

        Node* current = head;

        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }

        Node* newNode = new Node(val);

        newNode->next = current->next;
        current->next = newNode;

        size++;
    }

    // Delete a node at a particular index
    void deleteAtIndex(int index) {

        if (index < 0 || index >= size) {
            return;
        }

        Node* temp;

        if (index == 0) {
            temp = head;
            head = head->next;
        }
        else {
            Node* current = head;

            for (int i = 0; i < index - 1; i++) {
                current = current->next;
            }

            temp = current->next;
            current->next = temp->next;
        }

        delete temp;
        size--;
    }

    // Display linked list
    void display() {

        Node* current = head;

        while (current != NULL) {
            cout << current->val << " -> ";
            current = current->next;
        }

        cout << "NULL" << endl;
    }

    // Destructor: free remaining nodes
    ~MyLinkedList() {

        while (head != NULL) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {

    MyLinkedList list;

    list.addAtHead(10);
    list.addAtTail(30);
    list.addAtIndex(1, 20);

    cout << "Linked List: ";
    list.display();

    cout << "Value at index 1: "
         << list.get(1) << endl;

    list.deleteAtIndex(1);

    cout << "After deletion: ";
    list.display();

    return 0;
}
