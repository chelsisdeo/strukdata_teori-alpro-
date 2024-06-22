## soal nomor 1

### penjelasan dan contoh program

Priority queue adalah struktur data yang mengatur elemen berdasarkan nilai prioritas, 
dengan elemen berprioritas tinggi diambil lebih dulu. Struktur data heap, 
divisualisasikan sebagai complete binary tree, digunakan dalam implementasi ini. 
Kode dibawah mengimplementasikan max-heap dalam C++, dengan array H menyimpan elemen 
heap dan heapSize melacak ukurannya. Fungsi parent, leftChild, dan rightChild menghitung indeks 
elemen induk dan anak, sementara fungsi shiftUp dan shiftDown memulihkan properti heap setelah elemen diubah. 
Fungsi insert menambah elemen baru, extractMax menghapus dan mengembalikan elemen maksimum, changePriority 
mengubah prioritas elemen, dan getMax mengembalikan elemen maksimum tanpa menghapusnya. 
Fungsi main menunjukkan penggunaan dasar dengan memasukkan elemen, mengekstraksi maksimum, dan mengubah prioritas elemen.[1]

```c++
#include <iostream>
#include <algorithm>

int H[50];
int heapSize = -1;

int parent(int i) {
    return (i - 1) / 2;
}

int leftChild(int i) {
    return (2 * i) + 1;
}

int rightChild(int i) {
    return (2 * i) + 2;
}

void shiftUp(int i) {
    while (i > 0 && H[parent(i)] < H[i]) {
        std::swap(H[parent(i)], H[i]);
        i = parent(i);
    }
}

void shiftDown(int i) {
    int maxIndex = i;
    int l = leftChild(i);
    if (l <= heapSize && H[l] > H[maxIndex]) {
        maxIndex = l;
    }
    int r = rightChild(i);
    if (r <= heapSize && H[r] > H[maxIndex]) {
        maxIndex = r;
    }
    if (i != maxIndex) {
        std::swap(H[i], H[maxIndex]);
        shiftDown(maxIndex);
    }
}

void insert(int p) {
    heapSize = heapSize + 1;
    H[heapSize] = p;
    shiftUp(heapSize);
}

int extractMax() {
    if (heapSize < 0) {
        std::cerr << "Error: Heap is empty." << std::endl;
        return -1; // or some error value
    }
    int result = H[0];
    H[0] = H[heapSize];
    heapSize = heapSize - 1;
    shiftDown(0);
    return result;
}

void changePriority(int i, int p) {
    int oldp = H[i];
    H[i] = p;
    if (p > oldp) {
        shiftUp(i);
    } else {
        shiftDown(i);
    }
}

int getMax() {
    if (heapSize < 0) {
        std::cerr << "Error: Heap is empty." << std::endl;
        return -1; // or some error value
    }
    return H[0];
}

int main() {
    // Example usage:
    insert(45);
    insert(20);
    insert(14);
    insert(12);
    insert(31);
    insert(7);
    insert(11);
    insert(13);
    insert(7);

    std::cout << "Max element: " << getMax() << std::endl;
    std::cout << "Extracted max: " << extractMax() << std::endl;
    std::cout << "Max element after extraction: " << getMax() << std::endl;

    changePriority(2, 49);
    std::cout << "Max element after priority change: " << getMax() << std::endl;

    return 0;
}
```

referensi

[1] Situmorang, H. (2016). Simulasi Pengurutan Data dengan Algoritma Heap Sort. 
    Jurnal Mahajana Informasi, 1(2), 20-30.


## SOAL no 2


Hash Table adalah struktur data berupa array dengan sel-sel berukuran tetap yang dapat 
berisi data atau key, mirip dengan tabel sementara di MySQL yang memiliki record dan primary key 
untuk operasi insert, update, delete, search, dan link. Kode tersebut mengimplementasikan hash table dalam C++ yang 
memetakan key ke value menggunakan fungsi hash sederhana (hash_func). Setiap elemen dalam hash table 
direpresentasikan sebagai node (Node) dengan atribut key, value, dan next untuk menangani tabrakan hash. 
Operasi yang didukung termasuk penyisipan, pencarian, penghapusan, dan penelusuran.[1]

``` c++
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
```

referensi 

[2] Syahrir, M., & Fatimatuzzahra, F. (2020). 
    Association Rule Integrasi Pendekatan Metode Custom Hashing 
    dan Data Partitioning untuk Mempercepat Proses Pencarian Frekuensi Item-set pada Algoritma Apriori. 
    Matrik: Jurnal Manajemen, Teknik Informatika 
    Dan Rekayasa Komputer, 20(1), 149-158.


## soal nomor 3

### penjelasan dan contoh program

Fungsi rekursif pertama kali diperkenalkan sekitar tahun 1934 oleh seorang matematikawan asal Hungaria, Rosza Peter. Teori ini merupakan pengembangan dari konsep primitive recursive yang sebelumnya telah diusulkan oleh Jacques Herbrand dan kemudian diperluas definisinya oleh Kurt Godel, keduanya adalah matematikawan terkenal dari abad ke-20.[1]

### Rekursif Langsung (Direct Recursion) 
```C++
#include <iostream>

using namespace std;

void countdown(int n) {
    if (n == 0) {
        return;
    }

    cout << n << " ";
    countdown(n -1);
}

int main() {
    cout << "Rekursif langsung: ";
    countdown(5);
    cout << endl;
    return 0;
}
```

Pertama, kita memasukkan file header <iostream>, yang berisi definisi 
fungsi-fungsi untuk input/output (I/O). Kemudian, kita mendefinisikan fungsi 
countdown yang melakukan rekursi mundur dari angka 5 hingga 1. Jika nilai n sama dengan 0, 
fungsi berhenti. Setiap langkah rekursi mencetak nilai n di layar. Fungsi utama (main) 
mencetak teks "Rekursif langsung: " dan memanggil fungsi countdown dengan argumen 5. 
Hasil keluaran dari program ini adalah "Rekursif langsung: 5 4 3 2 1".

## Guided 2

### 2. Rekursif Tidak Langsung (Indirect Recursion)


```c++
#include <iostream>

using namespace std;

void functionB(int n);

void functionA(int n) {
    if (n > 0) {
        cout << n << " ";
        functionB(n - 1);
    }
}

void functionB(int n) {
    if (n > 0) {
        cout << n << " ";
        functionA(n / 2);
    }
}

int main() {
    int num = 3;
    cout << "Rekursif tidak langsung: ";
    functionA(num);
    return 0;
}
```

Code di atas mengilustrasikan rekursi tidak langsung. Fungsi functionA mencetak angka dari 3 hingga 1, sementara functionB memanggil functionA dengan argumen setengah dari nilai n. Output dari program ini adalah "Rekursif tidak langsung: 3 2 1".

[3] KA, A. T. S. Penerapan Fungsi Rekursi pada Droste Effect.

## soal nomor 4
Graf atau graph adalah struktur data yang merepresentasikan hubungan antar objek melalui node (atau vertex) dan sambungan antar node tersebut dalam bentuk edge (atau sisi). Dalam ilmu komputer, pohon (atau tree) adalah struktur data yang umum dan kuat yang menyerupai pohon nyata. Struktur ini terdiri dari kumpulan node yang terhubung dan terurut, di mana setiap node memiliki maksimal satu simpul induk dan nol atau lebih simpul anak dalam urutan tertentu. Secara sederhana, pohon dapat disebut sebagai graf terhubung yang tidak memiliki siklus.[4]


```c++
#include <iostream>
#include <iomanip>

using namespace std;

string simpul[7] = {
    "Ciamis", "Bandung", "Tasikmalaya", "Cianjur", "Purwokerto", "Yogyakarta"
};

int busur[7][7] = {
    {0, 7, 8, 0, 0, 0, 0},
    {0, 0, 5, 0, 0, 15, 0},
    {0, 6, 0, 0, 5, 0, 0},
    {0, 5, 0, 0, 2, 4, 0},
    {23, 0, 0, 10, 0, 0, 8},
    {0, 0, 0, 0, 7, 0, 3},
    {0, 0, 0, 0, 9, 4, 0},
};

void tampilGraph() {
    for (int baris = 0; baris < 7; baris ++) {
        cout << " " << setiosflags(ios::left) << setw(15) << simpul[baris] << ":";
        for (int kolom = 0; kolom < 7; kolom ++) {
            if (busur [baris][kolom] != 0) {
                cout << " " << simpul[kolom] << "(" << busur[baris][kolom] << ")";
            }
        }
        cout << endl;
    }
}

int main() {
    tampilGraph();
    return 0;
}

```
<<<<<<< HEAD
Kode berikut adalah contoh implementasi graf menggunakan matriks ketetanggaan dalam C++. Simpul-simpul graf diwakili oleh array string dan hubungan antar simpul oleh matriks bobot. Fungsi tampilGraph() digunakan untuk menampilkan graf dalam bentuk matriks ketetanggaan beserta bobotnya. Dalam fungsi main(), tampilGraph() dipanggil untuk menampilkan graf yang telah dibuat.
=======
Kode di atas adalah contoh implementasi graf menggunakan matriks ketetanggaan dalam C++. Simpul-simpul graf diwakili oleh array string dan hubungan antar simpul oleh matriks bobot. Fungsi tampilGraph() digunakan untuk menampilkan graf dalam bentuk matriks ketetanggaan beserta bobotnya. Dalam fungsi main(), tampilGraph() dipanggil untuk menampilkan graf yang telah dibuat.
>>>>>>> e1057fafc35e69f90dcd6da40ab89826e24d8609

### referensi

[4] Susanto, L. A., Wiharja, K. R. S., & Puspitasari, S. Y. (2015). Implementasi Dan Analisis Visualisasi Graph Pada Graph Statis Menggunakan Representasi Visual Treemap. eProceedings of Engineering, 2(3).
