#include <iostream>
#include <stack>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int d) : data(d), next(nullptr) {}
};

bool isPalindrome(Node* head) {
    Node* slow = head;
    stack<int> s;

    while (slow != nullptr) {
        s.push(slow->data);
        slow = slow->next;
    }

    while (head != nullptr) {
        int i = s.top();
        s.pop();
        if (head->data != i) {
            return false;
        }
        head = head->next;
    }

    return true;
}

int main() {
    // Contoh linked list: 1 -> 2 -> 3 -> 2 -> 1
    Node one(1), two(2), three(3), four(2), five(1);
    five.next = nullptr;
    one.next = &two;
    two.next = &three;
    three.next = &four;
    four.next = &five;

    if (isPalindrome(&one)) {
        cout << "Linked list adalah palindrom.\n";
    } else {
        cout << "Linked list bukan palindrom.\n";
    }

    return 0;
}
