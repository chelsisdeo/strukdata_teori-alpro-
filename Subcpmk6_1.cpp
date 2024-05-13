#include <iostream>
using namespace std;

// Deklarasi stack dengan struct dan array
struct Stack {
    int data[5];
    int top;
};

// Inisialisasi stack
void initialize(Stack& s) {
    s.top = -1;
}

// Menambahkan data ke dalam stack (push)
void push(Stack& s, int value) {
    if (s.top == 4) {
        cout << "Stack sudah penuh!" << endl;
    } else {
        s.top++;
        s.data[s.top] = value;
        cout << "Data [" << value << "] telah ditambahkan ke dalam stack." << endl;
    }
}

// Mengeluarkan data dari stack (pop)
void pop(Stack& s) {
    if (s.top == -1) {
        cout << "Stack kosong!" << endl;
    } else {
        cout << "Data [" << s.data[s.top] << "] telah diambil dari stack." << endl;
        s.top--;
    }
}

// Mengecek apakah stack kosong
bool isEmpty(Stack& s) {
    return (s.top == -1);
}

// Mengecek apakah stack penuh
bool isFull(Stack& s) {
    return (s.top == 4);
}

int main() {
    Stack myStack;
    initialize(myStack);

    // Contoh penggunaan
    push(myStack, 10);
    push(myStack, 20);
    push(myStack, 30);

    pop(myStack);
    pop(myStack);

    if (isEmpty(myStack)) {
        cout << "Stack kosong." << endl;
    } else {
        cout << "Stack tidak kosong." << endl;
    }

    return 0;
}
