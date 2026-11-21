
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
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {

        ListNode* pA = headA;
        ListNode* pB = headB;

        while (pA != pB) {

            if (pA == NULL) {
                pA = headB;
            }
            else {
                pA = pA->next;
            }

            if (pB == NULL) {
                pB = headA;
            }
            else {
                pB = pB->next;
            }
        }

        return pA;
    }
};

int main() {

    // Shared part: 8 -> 9 -> NULL
    ListNode* common = new ListNode(8);
    common->next = new ListNode(9);

    // List A: 1 -> 2 -> 8 -> 9
    ListNode* headA = new ListNode(1);
    headA->next = new ListNode(2);
    headA->next->next = common;

    // List B: 3 -> 4 -> 8 -> 9
    ListNode* headB = new ListNode(3);
    headB->next = new ListNode(4);
    headB->next->next = common;

    Solution obj;

    ListNode* result = obj.getIntersectionNode(headA, headB);

    if (result != NULL) {
        cout << "Intersection found at node: " << result->val << endl;
    }
    else {
        cout << "No intersection found." << endl;
    }

    // Free memory without deleting shared nodes twice
    delete headA;
    delete headA->next;
    delete headB;
    delete headB->next;
    delete common;
    delete common->next;

    return 0;
}
