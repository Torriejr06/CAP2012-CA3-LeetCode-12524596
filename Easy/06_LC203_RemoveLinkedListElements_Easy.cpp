
#include <iostream>
using namespace std;

// Create a node
struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {

        // Create a dummy node
        ListNode dummy(0);
        dummy.next = head;

        ListNode* current = &dummy;

        while (current->next != NULL) {

            if (current->next->val == val) {

                ListNode* temp = current->next;
                current->next = current->next->next;
                delete temp;

            }
            else {
                current = current->next;
            }
        }

        return dummy.next;
    }
};

// Display the linked list
void display(ListNode* head) {

    while (head != NULL) {
        cout << head->val << " -> ";
        head = head->next;
    }

    cout << "NULL" << endl;
}

int main() {

    // Create linked list: 1 -> 2 -> 6 -> 3 -> 6
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(6);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(6);

    int val = 6;

    cout << "Original linked list: ";
    display(head);

    Solution obj;

    head = obj.removeElements(head, val);

    cout << "After removing " << val << ": ";
    display(head);

    // Free remaining nodes
    while (head != NULL) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
