#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

bool isPalindrome(string input) {
    stack<char> s;
    for (char c : input) {
        if (isalpha(c)) {
            s.push(tolower(c));
        }
    }
    string reversed;
    while (!s.empty()) {
        reversed += s.top();
        s.pop();
    }
    return input == reversed;
}

int main() {
    string testString = "A man, a plan, a canal, Panama!";
    cout << "Apakah palindrom? " << (isPalindrome(testString) ? "Ya" : "Tidak") << endl;
    return 0;
}
