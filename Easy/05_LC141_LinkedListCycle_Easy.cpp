
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
    bool hasCycle(ListNode* head) {

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {

            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                return true;
            }
        }

        return false;
    }
};

int main() {

    // Create linked list: 1 -> 2 -> 3 -> 4
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    // Create a cycle: 4 points back to 2
    head->next->next->next->next = head->next;

    Solution obj;

    if (obj.hasCycle(head)) {
        cout << "Cycle detected in the linked list." << endl;
    }
    else {
        cout << "No cycle detected." << endl;
    }

    return 0;
}
