#include <iostream>
using namespace std;

// Fungsi untuk melakukan Binary Search pada array input
int binarySearch(int arr[], int low, int high, int x) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x)
            return mid;  // Elemen ditemukan pada indeks 'mid'
        else if (arr[mid] < x)
            low = mid + 1;  // Cari di setengah kanan
        else
            high = mid - 1;  // Cari di setengah kiri
    }
    return -1;  // Elemen tidak ditemukan dalam array
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
