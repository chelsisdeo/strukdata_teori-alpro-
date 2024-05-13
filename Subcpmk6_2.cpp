#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

// Fungsi untuk menghitung nilai ekspresi postfix
double evaluatePostfix(string postfix) {
    stack<double> s;
    for (char c : postfix) {
        if (isdigit(c)) {
            s.push(c - '0'); // Konversi karakter angka ke bilangan
        } else {
            double operand2 = s.top(); s.pop();
            double operand1 = s.top(); s.pop();
            switch (c) {
                case '+': s.push(operand1 + operand2); break;
                case '-': s.push(operand1 - operand2); break;
                case '*': s.push(operand1 * operand2); break;
                case '/': s.push(operand1 / operand2); break;
                case '^': s.push(pow(operand1, operand2)); break;
            }
        }
    }
    return s.top();
}

int main() {
    string postfixExpression = "23*5+";
    cout << "Hasil evaluasi: " << evaluatePostfix(postfixExpression) << endl;
    return 0;
}
