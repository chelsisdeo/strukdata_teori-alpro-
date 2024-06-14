def merge_sorted_arrays(A, B):
    # Panjang asli dari A yang memiliki elemen valid
    len_A = len(A) - len(B)
    len_B = len(B)
    
    # Indeks terakhir dari array A setelah penggabungan
    index_merged = len_A + len_B - 1
    
    # Indeks terakhir elemen valid dari array A
    index_A = len_A - 1
    
    # Indeks terakhir dari array B
    index_B = len_B - 1
    
    # Gabungkan A dan B dari belakang ke depan untuk meminimalkan pergeseran elemen
    while index_B >= 0:
        if index_A >= 0 and A[index_A] > B[index_B]:
            A[index_merged] = A[index_A]
            index_A -= 1
        else:
            A[index_merged] = B[index_B]
            index_B -= 1
        index_merged -= 1
    
    return A

# Contoh penggunaan
A = [1, 3, 5, 7, None, None, None]  # A memiliki ruang untuk menampung B
B = [2, 4, 6]
result = merge_sorted_arrays(A, B)
print("Merged and sorted array:", result)