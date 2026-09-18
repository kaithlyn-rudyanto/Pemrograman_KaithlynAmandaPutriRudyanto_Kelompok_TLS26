#include <iostream>

using namespace std;

// Fungsi untuk menghitung indeks yang tereliminasi
int findEliminated(int position, int K, int remaining) {
    return (position + K - 1) % remaining;
}

int main() {
    int N, K;
    cout << "N : ";
    cin >> N;
    cout << "K : ";
    cin >> K;

    // Inisialisasi array astronot (1 sampai N)
    int *astronauts = new int[N];
    for (int i = 0; i < N; i++) {
        astronauts[i] = i + 1;
    }

    int remaining = N;
    int position = 0; 

    cout << "Urutan eliminasi: ";
    while (remaining > 1) {
        // 1. Cari indeks yang tereliminasi
        int eliminated = findEliminated(position, K, remaining);
        int eliminatedNumber = astronauts[eliminated];
        
        cout << eliminatedNumber << " ";

        // 2. Hapus astronot yang tereliminasi (geser elemen ke kiri)
        for (int i = eliminated; i < remaining - 1; i++) {
            astronauts[i] = astronauts[i + 1];
        }

        // 3. Kurangi jumlah sisa astronot
        remaining--;

        // 4. Perbarui nilai K sesuai aturan genap/ganjil
        if (eliminatedNumber % 2 == 0) {
            K += 2;
        } else {
            K -= 1;
        }

        // Batas minimal K adalah 2
        if (K < 2) {
            K = 2;
        }

        // 5. Posisi awal hitungan berikutnya adalah indeks tempat astronot tadi tereliminasi
        // Gunakan % remaining untuk menangani kasus jika indeks melebihi sisa astronot
        position = eliminated % remaining;
    }

    cout << endl;
    cout << "Last astronaut: " << astronauts[0] << endl;

    // Dealer memori dinamis
    delete[] astronauts;
    
    return 0;
}