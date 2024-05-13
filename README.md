# <h1 align="center">TUGAS</h1>
<p align="center">Chelsisdeo A.P Sanenek</p>

### Soal SUBCPMK 2

#### 1. Terdapat tiga algoritma sorting yang umum digunakan yakni, Bubble Sort, Selection Sort, dan Merge Sort. Berikan penjelasan alur dari masing-masing algoritma tersebut, dan jelaskan runtime dari best case dan worst case masing-masing algoritma! 

#### 2.	Buatlah fungsi dari salah satu algoritma sorting pada soal nomor 1, dan berikan penjelasan pada program tersebut 

### JAWAB

1. > Bubble Sort: 

#### - Alur:
- Bubble Sort adalah algoritma sorting yang bekerja dengan menukar elemen-elemen berdekatan jika mereka berada dalam urutan yang salah.
- Proses ini berulang hingga seluruh data terurut.
- Pada setiap iterasi, elemen terbesar akan “menggelembung” ke posisi yang benar.
#### - Runtime:
- Best Case: O(n) (ketika array sudah terurut).
- Average Case: O(n^2).
- Worst Case: O(n^2) (ketika array terurut terbalik).
#### - Kelebihan:
Mudah dipahami dan diimplementasikan.
Tidak memerlukan ruang memori tambahan.
Stabil (elemen dengan nilai kunci yang sama mempertahankan urutan relatif).

#### -Kekurangan:
- Lambat untuk data set besar.

> Selection Sort:

#### - Alur:
- Selection Sort adalah algoritma sorting yang berulang kali memilih elemen terkecil (atau terbesar) dari bagian yang belum terurut dan menukarnya dengan elemen pertama dari bagian yang belum terurut.
- Proses ini diulang hingga seluruh data terurut.

#### - Runtime:
- Best Case: O(n) (ketika array sudah terurut).
- Average Case: O(n^2).
- Worst Case: O(n^2) (ketika array terurut terbalik).

> Merge Sort:

#### - Alur:
- Merge Sort adalah algoritma pengurutan yang mengikuti pendekatan divide-and-conquer.
- Prosesnya melibatkan tiga langkah utama: bagi, kalahkan, dan gabung.
- Pertama, array dibagi menjadi dua bagian hingga tidak dapat dibagi lagi.
- Kemudian, setiap subarray diurutkan secara individu menggunakan rekursi.
- Akhirnya, subarray yang sudah terurut digabungkan kembali dalam urutan yang terurut.

#### - Runtime:
- Best Case: O(n log n) (ketika array sudah terurut).
- Average Case: O(n log n).
- Worst Case: O(n log n) (tidak tergantung pada urutan awal array).

2. 
> Berikut Contoh dari Marge sort

``` c++
#include <iostream>
using namespace std;

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Fungsi rekursif untuk melakukan Merge Sort pada array input
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);      
        mergeSort(arr, m + 1, r);  
        merge(arr, l, m, r);       
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Array awal: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    mergeSort(arr, 0, n - 1);

    cout << "Array setelah diurutkan: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}

```

#### Output 
![image](https://github.com/chelsisdeo/strukdata_teori-alpro-/assets/161056340/429d00d3-6d4b-4376-8fde-a361a6636331)



#### - Penjelasan:

- Fungsi mergeSort adalah fungsi rekursif yang membagi array input menjadi dua bagian hingga tidak dapat dibagi lagi.
- Setiap subarray diurutkan secara individu menggunakan rekursi.
- Fungsi merge menggabungkan dua subarray yang sudah terurut menjadi satu array terurut.
- Proses penggabungan dilakukan dengan membandingkan dan menggabungkan elemen-elemen dalam urutan yang benar.

#### - Waktu Eksekusi:

- Kasus Terbaik: O(n log n) (ketika array sudah terurut).
- Kasus Rata-rata: O(n log n).
- Kasus Terburuk: O(n log n) (tidak tergantung pada urutan awal array).


## Soal SubCPMK 3

#### 1. Terdapat dua algoritma searching yang umum digunakan yakni, Binary Search dan Linear Search. Berikan penjelasan alur dari masing-masing algoritma tersebut, dan jelaskan runtime dari best case dan worst case masing-masing algoritma!

#### 2.	Buatlah fungsi dari salah satu algoritma searching pada soal nomor 1, dan berikan penjelasan pada program tersebut

### JAWAB

1. 
> Binary Search:

#### - Alur:
- Binary Search adalah algoritma pencarian yang digunakan pada array yang sudah terurut.
- Algoritma ini berulang kali membagi interval pencarian menjadi dua bagian dan memeriksa apakah elemen yang dicari berada di bagian kiri atau kanan.
- Proses ini berlanjut hingga elemen ditemukan atau interval pencarian habis.

#### - Runtime:
- Best Case: O(1) (ketika elemen yang dicari berada di tengah array).
- Average Case: O(log n).
- Worst Case: O(log n) (ketika elemen yang dicari tidak ada dalam array).

#### - Kelebihan:
- Efisien untuk data set besar karena membagi interval pencarian secara eksponensial.
- Cocok untuk data yang sudah terurut.

### - Kekurangan:
Hanya berlaku untuk data yang sudah terurut.


> Linear Search:

#### - Alur:
- Linear Search adalah algoritma pencarian yang berjalan secara berurutan melalui setiap elemen dalam array.
- Dimulai dari elemen pertama, algoritma membandingkan setiap elemen dengan elemen yang dicari hingga elemen ditemukan atau seluruh array diperiksa.

#### - Runtime:
- Best Case: O(1) (ketika elemen yang dicari berada di posisi pertama).
- Average Case: O(n/2) = O(n).
- Worst Case: O(n) (ketika elemen yang dicari berada di posisi terakhir atau tidak ada dalam array).

#### - Kelebihan:
Sederhana dan mudah diimplementasikan.
Cocok untuk data yang belum terurut.
#### - Kekurangan:
Tidak efisien untuk data set besar karena memeriksa setiap elemen secara berurutan.

2. 
```c++
#include <iostream>
using namespace std;

// Fungsi untuk melakukan Binary Search pada array input
int binarySearch(int arr[], int low, int high, int x) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x)
            return mid;  
        else if (arr[mid] < x)
            low = mid + 1;  
        else
            high = mid - 1;  
    }
    return -1; 
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int x = 10;
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = binarySearch(arr, 0, n - 1, x);
    if (result != -1)
        cout << "Elemen ditemukan pada indeks " << result << endl;
    else
        cout << "Elemen tidak ditemukan dalam array" << endl;

    return 0;
}

```
### Output 
![image](https://github.com/chelsisdeo/strukdata_teori-alpro-/assets/161056340/d4804f30-6779-4624-85d6-0bb25ae3d95b)


#### Penjelasan 

Fungsi ini melakukan pencarian elemen x dalam array arr.
Algoritma Binary Search membagi interval pencarian menjadi dua bagian dan memeriksa apakah elemen yang dicari berada di bagian kiri atau kanan.
Fungsi ini menggunakan pendekatan iteratif (melalui while loop) untuk mencari elemen.
Jika elemen ditemukan, fungsi mengembalikan indeksnya. Jika tidak ditemukan, mengembalikan nilai -1.

## SubCPMK 4

1. Berikan penjelasan dari struct dan buatlah sebuah contoh program dari struct! 

### JAWAB

Struct adalah cara untuk mengelompokkan beberapa variabel terkait menjadi satu tempat. Setiap variabel dalam struct dikenal sebagai anggota dari struct tersebut. Berbeda dengan array, struct dapat berisi berbagai jenis data yang berbeda, seperti int, string, bool, dan lainnya. Dengan menggunakan struct, kita dapat mengelompokkan semua informasi terkait di bawah satu nama, seperti Person, dan menggunakannya untuk setiap individu.

``` C++
#include <iostream>

using namespace std;

// Mendefinisikan struktur buku
struct buku {
    string judulBuku;
    string pengarang;
    string penerbit;
    int tebalHalaman;
    int hargaBuku;
};

int main() {
    // Mendeklarasikan variabel favorit dengan tipe buku
    buku favorit;

    // Mengisi data ke dalam variabel favorit
    favorit.judulBuku = "Atomic Habits";
    favorit.pengarang = "James clear";
    favorit.penerbit = "Gramedia Pustaka Utama";
    favorit.tebalHalaman = 352;
    favorit.hargaBuku = 102000;

    // Menampilkan informasi buku favorit
    cout << "\tBuku Favorit Saya" << endl;
    cout << "\tJudul Buku : " << favorit.judulBuku << endl;
    cout << "\tPengarang : " << favorit.pengarang << endl;
    cout << "\tPenerbit : " << favorit.penerbit << endl;
    cout << "\tTebal Halaman: " << favorit.tebalHalaman << " halaman" << endl;
    cout << "\tHarga Buku : Rp " << favorit.hargaBuku << endl;
 
    return 0;
}

```

Kodingan tersebut mendefinisikan sebuah struktur buku dengan lima atribut, seperti judul, pengarang, dan harga. Nilai-nilai atribut tersebut diisi untuk satu buku favorit, kemudian ditampilkan secara terstruktur menggunakan perintah cout. Outputnya adalah informasi tentang buku favorit, termasuk judul, pengarang, penerbit, jumlah halaman, dan harga buku.

### OUTPUT 
![image](https://github.com/chelsisdeo/strukdata_teori-alpro-/assets/161056340/68680736-7a6a-4494-ae93-5ea00870d90d)


## Soal SubCPMK 5

1. Buatlah sebuah program untuk mengecek apakah linked list adalah sebuah palindrom

### JAWAB 
- Dalam metode ini, kita menggunakan stack untuk menyimpan elemen dari setengah pertama linked list.
- Kemudian kita membandingkan elemen dari setengah kedua linked list dengan elemen yang diambil dari stack.
- Jika semua elemen cocok, maka linked list adalah palindrom.

Berikut adalah contoh program dalam bahasa C++ 

```c++
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

```
### Output
![image](https://github.com/chelsisdeo/strukdata_teori-alpro-/assets/161056340/cd58a7ed-f71e-4e37-95f4-55cd99997500)

Dalam codingan ini, pertama, program membuat linked list dengan elemen 1 -> 2 -> 3 -> 2 -> 1. Kemudian, menggunakan stack, program menyimpan nilai dari setengah pertama linked list. Selanjutnya, program membandingkan nilai dari setengah kedua linked list dengan nilai yang diambil dari stack. Jika semua nilai cocok, maka linked list adalah palindrom. Hasil dari kodingan ini akan mencetak “Linked list adalah palindrom.”

## Soal SubCPMK 6

1. Tulislah sebuah program dari operasi stack seperti pop, push, isEmpty, isFull, dll(min 5)!

###   JAWAB

- code 1
``` c++
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

```

### output
![image](https://github.com/chelsisdeo/strukdata_teori-alpro-/assets/161056340/2589a189-2fbc-4bc5-906a-350765170ec2)v

- code 2 (Program untuk menghitung nilai ekspresi matematika dalam notasi postfix )

```c++
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

```

### output 
![image](https://github.com/chelsisdeo/strukdata_teori-alpro-/assets/161056340/cdc71f4b-2fbb-499f-9210-d066f53bed74)

- code 3 (Program untuk membalikkan string menggunakan stack)

``` c++
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

```

### output 
![image](https://github.com/chelsisdeo/strukdata_teori-alpro-/assets/161056340/f95700ef-9d08-48ca-a5b1-83a44a8046a9)


- code 4 (Program untuk mengecek apakah suatu kata atau kalimat adalah palindrom)

```c++
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

```

#### output 
![image](https://github.com/chelsisdeo/strukdata_teori-alpro-/assets/161056340/7ef5032d-d9ca-4e7e-b677-b5f8feef504d)

- code 5 (Program untuk mengubah bilangan desimal menjadi biner menggunakan stack)

``` c++
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

```

#### output
![image](https://github.com/chelsisdeo/strukdata_teori-alpro-/assets/161056340/eaf48a50-7992-420c-ac4b-fe429c72e2d0)

## Soal SubCPMK 7

1. Sebuah selter hewan terlantar, yang mana hanya menerima kucing dan anjing, menerapkan konsep “first in, first out” dalam proses adopsi. Orang-orang yang hendak mengadopsi harus mengikuti aturan berikut: 1) mengadopsi hewan yang paling “tua” (berdasarkan waktu masuk ke selter) dan tidak dapat memilih kucing atau anjing; 2) memilih antara kucing atau anjing, namun akan menerima yang paling tua. Buatlah data struktur untuk mengimplementasikan kondisi tersebut, silahkan menggunakan beberapa operasi queue seperti enquee, dequeueAny, dequeueDog, dan dequeueCat

### jawab

```c++
#include <iostream>
#include <queue>
#include <string>
using namespace std;

// Struktur data untuk hewan
struct Animal {
    string name;
    int arrivalTime; // Waktu kedatangan
};

class AnimalShelter {
private:
    queue<Animal> dogs; // Antrian anjing
    queue<Animal> cats; // Antrian kucing
    int timestamp; // Waktu saat hewan masuk

public:
    AnimalShelter() {
        timestamp = 0;
    }

    // Menambahkan hewan ke selter
    void enqueue(string name, string type) {
        Animal newAnimal;
        newAnimal.name = name;
        newAnimal.arrivalTime = timestamp++;

        if (type == "dog") {
            dogs.push(newAnimal);
        } else if (type == "cat") {
            cats.push(newAnimal);
        }
    }

    // Mengambil hewan tertua (berdasarkan waktu kedatangan)
    Animal dequeueAny() {
        if (dogs.empty() && cats.empty()) {
            cout << "Selter kosong!" << endl;
            return {"", -1};
        }

        if (dogs.empty()) {
            return dequeueCat();
        } else if (cats.empty()) {
            return dequeueDog();
        }

        if (dogs.front().arrivalTime < cats.front().arrivalTime) {
            return dequeueDog();
        } else {
            return dequeueCat();
        }
    }

    // Mengambil anjing tertua
    Animal dequeueDog() {
        if (dogs.empty()) {
            cout << "Tidak ada anjing di selter!" << endl;
            return {"", -1};
        }
        Animal oldestDog = dogs.front();
        dogs.pop();
        return oldestDog;
    }

    // Mengambil kucing tertua
    Animal dequeueCat() {
        if (cats.empty()) {
            cout << "Tidak ada kucing di selter!" << endl;
            return {"", -1};
        }
        Animal oldestCat = cats.front();
        cats.pop();
        return oldestCat;
    }
};

int main() {
    AnimalShelter shelter;

    // Contoh penggunaan
    shelter.enqueue("Buddy", "dog");
    shelter.enqueue("Whiskers", "cat");
    shelter.enqueue("Max", "dog");
    shelter.enqueue("Luna", "cat");

    Animal adoptedPet = shelter.dequeueAny();
    cout << "Hewan yang diadopsi: " << adoptedPet.name << endl;

    Animal adoptedDog = shelter.dequeueDog();
    cout << "Anjing yang diadopsi: " << adoptedDog.name << endl;

    Animal adoptedCat = shelter.dequeueCat();
    cout << "Kucing yang diadopsi: " << adoptedCat.name << endl;

    return 0;
}

```

#### output
![image](https://github.com/chelsisdeo/strukdata_teori-alpro-/assets/161056340/849fdc47-0e92-4ec9-aac6-ac3cf22580c8)

Kode di atas merupakan implementasi dari sebuah sistem penampungan hewan (animal shelter) menggunakan antrian (queue) untuk mengatur antrian hewan yang masuk

