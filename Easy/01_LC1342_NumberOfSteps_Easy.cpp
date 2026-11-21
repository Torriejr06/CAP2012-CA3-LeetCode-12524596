#include <iostream>
using namespace std;

class Solution {
public:
    int numberOfSteps(int num) {
        int steps = 0;

        while (num > 0) {
            if (num % 2 == 0) {
                num = num / 2;
            }
            else {
                num = num - 1;
            }

            steps++;
        }

        return steps;
    }
};

int main() {
    int num;

    cout << "Enter a number: ";
    cin >> num;

    Solution obj;

    cout << "Number of steps: "
         << obj.numberOfSteps(num);

    return 0;
}