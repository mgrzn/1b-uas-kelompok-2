#include <iostream>
#include <queue> // Library untuk queue
using namespace std;

struct Pengunjung {
    string nama;
    int lamaMenginap;
    string notelp;
    int nomorkamar;
    Pengunjung* next;
};

// Deklarasi queue
queue<Pengunjung> pengunjungQueue;
Pengunjung* head = NULL;

// Fungsi untuk memeriksa ketersediaan kamar
bool isKamarTersedia(int nomorkamar) {
    Pengunjung* temp = head;
    while (temp != nullptr) {
        if (temp->nomorkamar == nomorkamar) {
            return false;  // Kamar sudah dipesan
        }
        temp = temp->next;
    }
    return true;  // Kamar tersedia
}

// Fungsi untuk menambahkan pengunjung baru ke dalam antrian
void tambahPengunjung(string nama, int lamaMenginap, string notelp, int nomorkamar) {
    Pengunjung* pengunjungBaru = new Pengunjung;
    pengunjungBaru->nama = nama;
    pengunjungBaru->lamaMenginap = lamaMenginap;
    pengunjungBaru->notelp = notelp;
    pengunjungBaru->nomorkamar = nomorkamar;
    pengunjungBaru->next = NULL;

    if (head == NULL) {
        head = pengunjungBaru;
    } else {
        Pengunjung* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = pengunjungBaru;
    }

    if (isKamarTersedia(nomorkamar)) {
        pengunjungQueue.push(*pengunjungBaru); // Tambahkan pengunjung ke dalam queue
        cout << "\nPengunjung dengan nama " << nama << " telah ditambahkan di kamar " << nomorkamar << endl;
    } else {
        cout << "Kamar " << nomorkamar << " sudah dipesan\n";
    }
}


// Fungsi untuk menampilkan kamar-kamar yang tersedia
void tampilKamarTersedia() {
    cout << "\n===============" << endl;
    cout << "Standard Room" << endl;
    cout << "===============" << endl;
    for (int nomorKamar = 1; nomorKamar <= 5; nomorKamar++) {
        if (isKamarTersedia(nomorKamar)) {
            cout << "Kamar " << nomorKamar << " tersedia\n";
        }
    }
    cout << "\n=============" << endl;
    cout << "Deluxe Room" << endl;
    cout << "=============" << endl;
    for (int nomorKamar = 6; nomorKamar <= 10; nomorKamar++) {
        if (isKamarTersedia(nomorKamar)) {
            cout << "Kamar " << nomorKamar << " tersedia\n";
        }
    }
}

// Fungsi untuk menghapus pengunjung dari antrian
void hapusPengunjung(string nama) {
    if (nama == "0") {
        return;
    }

    queue<Pengunjung> tempQueue; // Queue sementara untuk menyimpan pengunjung
    bool pengunjungDitemukan = false;

    // Looping seluruh pengunjung dalam queue
    while (!pengunjungQueue.empty()) {
        // Ambil pengunjung dari depan queue
        // dan masukkan ke dalam queue sementara
        // jika namanya tidak sama dengan nama yang ingin dihapus
        // jika namanya sama, maka abaikan (hapus)
        Pengunjung pengunjung = pengunjungQueue.front();
        pengunjungQueue.pop();

        if (pengunjung.nama != nama) {
            tempQueue.push(pengunjung);
        } else {
            pengunjungDitemukan = true;
        }
    }

    pengunjungQueue = tempQueue; // Isi queue dengan queue sementara

    if (pengunjungDitemukan) {
        cout << "Pengunjung dengan nama " << nama << " telah dihapus dari antrian." << endl;
    } else {
        cout << "Pengunjung dengan nama " << nama << " tidak ditemukan." << endl;
    }
}

// Fungsi untuk menampilkan daftar pengunjung yang sedang menginap
void tampilDaftarPengunjung() {
    queue<Pengunjung> tempQueue = pengunjungQueue; // Queue sementara untuk menyimpan pengunjung

    // Jika queue kosong, maka tidak ada pengunjung yang sedang menginap
    if (tempQueue.empty()) {
        cout << "Tidak ada pengunjung yang sedang menginap." << endl;
        return;
    }

    cout << "\nDaftar Pengunjung yang Sedang Menginap:" << endl;
    while (!tempQueue.empty()) {
        Pengunjung pengunjung = tempQueue.front();
        tempQueue.pop();
        cout << "Nama: " << pengunjung.nama << endl;
        cout << "Lama Menginap: " << pengunjung.lamaMenginap << " hari" << endl;
        cout << "Nomor Telepon: " << pengunjung.notelp << endl;
        cout << "Nomor Kamar: " << pengunjung.nomorkamar << endl;
        cout << "-------------------------" << endl;
    }
}

int main() {
    int pilihan;
    string nama;
    int lamaMenginap;
    string notelp;
    int nomorkamar;

    do {
            //system("cls");
        cout << "\n=== Aplikasi Pemesanan Hotel ===" << endl;
        cout << "1. Tambah Pengunjung" << endl;
        cout << "2. Hapus Pengunjung" << endl;
        cout << "3. Tampilkan Daftar Pengunjung" << endl;
        cout << "4. Tampilkan Kamar Tersedia" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan Nama Pengunjung: ";
                cin >> nama;
                cout << "Masukkan Lama Menginap (dalam hari): ";
                cin >> lamaMenginap;
                cout << "Masukkan Nomor Telepon: ";
                cin >> notelp;
                cout << "Masukkan Nomor Kamar: ";
                cin >> nomorkamar;
                tambahPengunjung(nama, lamaMenginap, notelp, nomorkamar);
                break;
            case 2:
                cout << "Masukkan Nama Pengunjung yang Ingin Dihapus (0 untuk batal): ";
                cin >> nama;
                hapusPengunjung(nama);
                break;
            case 3:
                tampilDaftarPengunjung();
                break;
            case 4:
                tampilKamarTersedia();
                break;
            case 0:
                cout << "Terima kasih!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    } while (pilihan != 0);

    return 0;
}

