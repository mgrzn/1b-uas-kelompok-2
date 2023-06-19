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

// Deklarasi linked list
Pengunjung* head = NULL;
Pengunjung* tail = NULL;

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

// Fungsi untuk menambahkan pengunjung baru ke dalam linked list dan queue
void tambahPengunjung(string nama, int lamaMenginap, string notelp, int nomorkamar) {
    Pengunjung* pengunjungBaru = new Pengunjung;
    pengunjungBaru->nama = nama;
    pengunjungBaru->lamaMenginap = lamaMenginap;
    pengunjungBaru->notelp = notelp;
    pengunjungBaru->nomorkamar = nomorkamar;
    pengunjungBaru->next = NULL;

    if (isKamarTersedia(nomorkamar)) {
        // Tambahkan pengunjung ke dalam linked list
        if (head == NULL) {
            head = pengunjungBaru;
            tail = pengunjungBaru;
        } else {
            tail->next = pengunjungBaru;
            tail = pengunjungBaru;
        }

        // Tambahkan pengunjung ke dalam queue
        queue<Pengunjung> pengunjungQueue;
        pengunjungQueue.push(*pengunjungBaru);

        cout << "\nPengunjung dengan nama " << nama << " telah ditambahkan di kamar " << nomorkamar << endl;
    } else {
        cout << "Kamar " << nomorkamar << " sudah dipesan\n";
    }
}

// Fungsi untuk menghapus pengunjung dari linked list
void hapusPengunjung(string nama) {
    if (nama == "0") {
        return;
    }

    Pengunjung* curr = head;
    Pengunjung* prev = NULL;
    bool pengunjungDitemukan = false;

    while (curr != NULL) {
        if (curr->nama == nama) {
            if (prev == NULL) {
                // Jika pengunjung yang ingin dihapus berada di head
                head = curr->next;
            } else {
                prev->next = curr->next;
            }
            delete curr;
            pengunjungDitemukan = true;
            break;
        }
        prev = curr;
        curr = curr->next;
    }

    if (pengunjungDitemukan) {
        cout << "Pengunjung dengan nama " << nama << " telah dihapus dari antrian." << endl;
    } else {
        cout << "Pengunjung dengan nama " << nama << " tidak ditemukan." << endl;
    }
}

// Fungsi untuk menampilkan daftar pengunjung yang sedang menginap
void tampilDaftarPengunjung() {
    Pengunjung* temp = head;

    if (temp == NULL) {
        cout << "Tidak ada pengunjung yang sedang menginap." << endl;
        return;
    }

    cout << "\nDaftar Pengunjung yang Sedang Menginap:" << endl;
    while (temp != NULL) {
        cout << "Nama: " << temp->nama << endl;
        cout << "Lama Menginap: " << temp->lamaMenginap << " hari" << endl;
        cout << "Nomor Telepon: " << temp->notelp << endl;
        cout << "Nomor Kamar: " << temp->nomorkamar << endl;
        cout << "-------------------------" << endl;
        temp = temp->next;
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

int main() {
    int pilihan;
    string nama;
    int lamaMenginap;
    string notelp;
    int nomorkamar;
    char ulangi;

    do {
            system("cls");
        cout << "\n=== Aplikasi Hotel ===" << endl;
        cout << "1. Tambah Pengunjung" << endl;
        cout << "2. Hapus Pengunjung" << endl;
        cout << "3. Tampilkan Daftar Pengunjung" << endl;
        cout << "4. Tampilkan Kamar Tersedia" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                do {
                    system("cls");
                    cout << "Pilihan Kamar yang Tersedia" << endl;
                    tampilKamarTersedia();

                    // Memasukkan nomor kamar dan nama pemesan
                    cout << "\n== KETIK 0 UNTUK KEMBALI KE MENU AWAL ==";
                    cout << "\nMasukkan nomor kamar yang ingin dipesan: ";
                    cin >> nomorkamar;

                    if(nomorkamar == 0)
                    {
                        break;
                    }

                    if (nomorkamar>0 && nomorkamar <=10){
                        if (isKamarTersedia(nomorkamar)) {
                            cout << "Masukkan nama pengunjung: ";
                            cin >> nama;
                            cout << "Masukkan lama menginap (dalam hari): ";
                            cin >> lamaMenginap;
                            cout << "Masukkan Nomor HP : ";
                            cin >> notelp;
                            tambahPengunjung(nama, lamaMenginap,notelp, nomorkamar);
                        } else {
                            cout << "Kamar " << nomorkamar << " sudah dipesan\n";
                        }
                    }else {
                        cout << "\nKamar " << nomorkamar << " Tidak tersedia..." << endl;
                        cout << "Harap periksa nomor kamar yang diinput!" << endl;
                    }

                    // Memeriksa apakah pengguna ingin memesan kamar lagi
                    cout << "\nIngin memesan kamar lagi? (y/n): ";
                    cin >> ulangi;
                    } while (ulangi == 'y' || ulangi == 'Y');


                break;
            case 2:
                system("cls");
                if (head == NULL) {
                    cout << "Tidak ada pengunjung di kamar." << endl;
                    system("pause");
                    break;
                }
                cout << "\n== Hapus Pengunjung ==" << endl;
                cout << "== KETIK 0 UNTUK KEMBALI KE MENU AWAL ==\n";
                cout << "Masukkan nama pengunjung yang akan dihapus: ";
                cin >> nama;
                hapusPengunjung(nama);
                system("pause");
                break;
            case 3:
                system("cls");
                cout << "\n== Tampil Data Pengunjung ==" << endl;
                tampilDaftarPengunjung();
                system("pause");
                break;
            case 4:
                system("cls");
                tampilKamarTersedia();
                system("pause");
                break;
            case 0:
                system("cls");
                cout << "Terima kasih! Sampai jumpa." << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
                system("pause");
        }
    } while (pilihan != 0);

    return 0;
}
