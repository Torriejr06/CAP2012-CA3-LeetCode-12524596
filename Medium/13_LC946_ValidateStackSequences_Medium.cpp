
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed,
                                vector<int>& popped) {

        stack<int> st;

        int j = 0;

        for (int i = 0; i < pushed.size(); i++) {

            // Push elements into the stack
            st.push(pushed[i]);

            // Pop while the top matches the required sequence
            while (!st.empty() &&
                   j < popped.size() &&
                   st.top() == popped[j]) {

                st.pop();
                j++;
            }
        }

        return st.empty();
    }
};

int main() {

    vector<int> pushed = {1, 2, 3, 4, 5};
    vector<int> popped = {4, 5, 3, 2, 1};

    Solution obj;

    bool result = obj.validateStackSequences(pushed, popped);

    if (result) {
        cout << "Valid stack sequences." << endl;
    }
    else {
        cout << "Invalid stack sequences." << endl;
    }

    return 0;
}
