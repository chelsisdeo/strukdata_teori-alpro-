// penjelasan dan contoh program

Priority queue adalah struktur data yang mengatur elemen berdasarkan nilai prioritas, 
dengan elemen berprioritas tinggi diambil lebih dulu. Struktur data heap, 
divisualisasikan sebagai complete binary tree, digunakan dalam implementasi ini. 
Kode dibawah mengimplementasikan max-heap dalam C++, dengan array H menyimpan elemen 
heap dan heapSize melacak ukurannya. Fungsi parent, leftChild, dan rightChild menghitung indeks 
elemen induk dan anak, sementara fungsi shiftUp dan shiftDown memulihkan properti heap setelah elemen diubah. 
Fungsi insert menambah elemen baru, extractMax menghapus dan mengembalikan elemen maksimum, changePriority 
mengubah prioritas elemen, dan getMax mengembalikan elemen maksimum tanpa menghapusnya. 
Fungsi main menunjukkan penggunaan dasar dengan memasukkan elemen, mengekstraksi maksimum, dan mengubah prioritas elemen.[1]

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


referensi

[1] Situmorang, H. (2016). Simulasi Pengurutan Data dengan Algoritma Heap Sort. 
    Jurnal Mahajana Informasi, 1(2), 20-30.
