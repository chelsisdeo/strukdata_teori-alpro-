penjelasan dan contoh program

Hash Table adalah struktur data berupa array dengan sel-sel berukuran tetap yang dapat 
berisi data atau key, mirip dengan tabel sementara di MySQL yang memiliki record dan primary key 
untuk operasi insert, update, delete, search, dan link. Kode tersebut mengimplementasikan hash table dalam C++ yang 
memetakan key ke value menggunakan fungsi hash sederhana (hash_func). Setiap elemen dalam hash table 
direpresentasikan sebagai node (Node) dengan atribut key, value, dan next untuk menangani tabrakan hash. 
Operasi yang didukung termasuk penyisipan, pencarian, penghapusan, dan penelusuran.[1]


#include <iostream>
using namespace std;
const int MAX_SIZE = 10;

// Fungsi hash sederhana
int hash_func(int key) {
    return key % MAX_SIZE;
}

// Struktur data untuk setiap node
struct Node {
    int key;
    int value;
    Node* next;
    Node(int key, int value) : key(key), value(value), next(nullptr) {}
};

// Class hash table
class HashTable {
private:
    Node** table;
public:
    HashTable() {
        table = new Node*[MAX_SIZE]();
    }
    ~HashTable() {
        for (int i = 0; i < MAX_SIZE; i++) {
            Node* current = table[i];
            while (current != nullptr) {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] table;
    }

    // Insertion
    void insert(int key, int value) {
        int index = hash_func(key);
        Node* current = table[index];
        while (current != nullptr) {
            if (current->key == key) {
                current->value = value;
                return;
            }
            current = current->next;
        }
        Node* node = new Node(key, value);
        node->next = table[index];
        table[index] = node;
    }

    // Searching
    int get(int key) {
        int index = hash_func(key);
        Node* current = table[index];
        while (current != nullptr) {
            if (current->key == key) {
                return current->value;
            }
            current = current->next;
        }
        return -1;
    }

    // Deletion
    void remove(int key) {
        int index = hash_func(key);
        Node* current = table[index];
        Node* prev = nullptr;
        while (current != nullptr) {
            if (current->key == key) {
                if (prev == nullptr) {
                    table[index] = current->next;
                } else {
                    prev->next = current->next;
                }
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
    }

    // Traversal
    void traverse() {
        for (int i = 0; i < MAX_SIZE; i++) {
            Node* current = table[i];
            while (current != nullptr) { 
                cout << current->key << ": " << current->value << endl;
                current = current->next;             }
        }
    }
};

int main() {
    HashTable ht;
    // Insertion
    ht.insert(1, 10);
    ht.insert(2, 20);
    ht.insert(3, 30);

    // Searching
    cout << "Get key 1: " << ht.get(1) << endl;
    cout << "Get key 4: " << ht.get(4) << endl;
    
    // Deletion
    ht.remove(4);
    
    // Traversal
    ht.traverse();
    
    return 0;
}

referensi 

[1] Syahrir, M., & Fatimatuzzahra, F. (2020). 
    Association Rule Integrasi Pendekatan Metode Custom Hashing 
    dan Data Partitioning untuk Mempercepat Proses Pencarian Frekuensi Item-set pada Algoritma Apriori. 
    Matrik: Jurnal Manajemen, Teknik Informatika 
    Dan Rekayasa Komputer, 20(1), 149-158.