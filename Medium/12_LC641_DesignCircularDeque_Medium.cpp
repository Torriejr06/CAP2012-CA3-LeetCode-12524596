
#include <iostream>
#include <vector>
using namespace std;

class MyCircularDeque {

private:
    vector<int> arr;
    int front;
    int count;
    int capacity;

public:

    // Constructor
    MyCircularDeque(int k) {
        capacity = k;
        arr.resize(k);
        front = 0;
        count = 0;
    }

    // Insert element at the front
    bool insertFront(int value) {

        if (isFull()) {
            return false;
        }

        front = (front - 1 + capacity) % capacity;
        arr[front] = value;
        count++;

        return true;
    }

    // Insert element at the rear
    bool insertLast(int value) {

        if (isFull()) {
            return false;
        }

        int rear = (front + count) % capacity;
        arr[rear] = value;
        count++;

        return true;
    }

    // Delete element from the front
    bool deleteFront() {

        if (isEmpty()) {
            return false;
        }

        front = (front + 1) % capacity;
        count--;

        return true;
    }

    // Delete element from the rear
    bool deleteLast() {

        if (isEmpty()) {
            return false;
        }

        count--;

        return true;
    }

    // Get front element
    int getFront() {

        if (isEmpty()) {
            return -1;
        }

        return arr[front];
    }

    // Get rear element
    int getRear() {

        if (isEmpty()) {
            return -1;
        }

        int rear = (front + count - 1) % capacity;

        return arr[rear];
    }

    // Check whether deque is empty
    bool isEmpty() {
        return count == 0;
    }

    // Check whether deque is full
    bool isFull() {
        return count == capacity;
    }
};

int main() {

    MyCircularDeque dq(3);

    dq.insertLast(10);
    dq.insertLast(20);
    dq.insertFront(30);

    cout << "Front element: " << dq.getFront() << endl;
    cout << "Rear element: " << dq.getRear() << endl;

    dq.deleteLast();

    cout << "After deleting rear: " << dq.getRear() << endl;

    cout << "Is deque empty? "
         << (dq.isEmpty() ? "Yes" : "No") << endl;

    cout << "Is deque full? "
         << (dq.isFull() ? "Yes" : "No") << endl;

    return 0;
}
