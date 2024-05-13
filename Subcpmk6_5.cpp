#include <iostream>
#include <stack>
using namespace std;

string decimalToBinary(int decimal) {
    stack<int> s;
    while (decimal > 0) {
        s.push(decimal % 2);
        decimal /= 2;
    }
    string binary;
    while (!s.empty()) {
        binary += to_string(s.top());
        s.pop();
    }
    return binary;
}

int main() {
    int decimalNumber = 42;
    cout << "Biner dari " << decimalNumber << ": " << decimalToBinary(decimalNumber) << endl;
    return 0;
}
