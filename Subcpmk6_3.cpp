#include <iostream>
#include <stack>
using namespace std;

string reverseString(string input) {
    stack<char> s;
    for (char c : input) {
        s.push(c);
    }
    string reversed;
    while (!s.empty()) {
        reversed += s.top();
        s.pop();
    }
    return reversed;
}

int main() {
    string inputString = "Hello, World!";
    cout << "String terbalik: " << reverseString(inputString) << endl;
    return 0;
}
