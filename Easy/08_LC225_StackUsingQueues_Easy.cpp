
#include <iostream>
#include <queue>
using namespace std;

class MyStack {
private:
    queue<int> q;

public:

    // Insert an element
    void push(int x) {

        q.push(x);

        int size = q.size();

        // Move previous elements behind the new element
        for (int i = 0; i < size - 1; i++) {

            q.push(q.front());
            q.pop();
        }
    }

    // Remove the top element
    int pop() {

        int value = q.front();
        q.pop();

        return value;
    }

    // Return the top element
    int top() {
        return q.front();
    }

    // Check whether stack is empty
    bool empty() {
        return q.empty();
    }
};

int main() {

    MyStack st;

    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top element: " << st.top() << endl;

    cout << "Removed element: " << st.pop() << endl;

    cout << "New top element: " << st.top() << endl;

    cout << "Is stack empty? ";

    if (st.empty()) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }

    return 0;
}
