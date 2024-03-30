#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

// Funkcija za izvajanje counting sorta za specifičen bit
void countingSortByBit(std::vector<unsigned char>& A, int k, std::vector<unsigned char>& B) {
    std::vector<unsigned char> output(A.size());
    int count[2] = {0};

    // Ustvarjanje polja bitov D na osnovi k-tega bita vsakega elementa v A
    std::vector<int> D(A.size());
    for (size_t i = 0; i < A.size(); i++) {
        D[i] = (A[i] >> k) & 1;
        count[D[i]]++;
    }

    // Izračun prefix sum
    count[1] += count[0];

    // Urejanje glede na bit in shranjevanje v polje B
    for (int i = A.size() - 1; i >= 0; i--) {
        B[--count[D[i]]] = A[i];
    }

    // Posodabljanje A z urejenimi vrednostmi iz B
    A = B;
}

// Glavna funkcija za radix sort
void radixSort(std::vector<unsigned char>& A) {
    std::vector<unsigned char> B(A.size()); // Dodatno polje za sortiranje
    for (int k = 0; k < 8; k++) {
        countingSortByBit(A, k, B);
    }
}

int main(int argc, char* argv[]) {
   
    std::ifstream inputFile(argv[1]);
    std::ofstream outputFile("out.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Napaka pri odpiranju vhodne datoteke." << std::endl;
        return 1;
    }

    std::vector<unsigned char> A; // Polje vhodnih števil
    unsigned int num;
    


   
}


