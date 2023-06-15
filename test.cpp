#include <iostream>
using namespace std;

struct Pengunjung {
    string nama;
    int lamaMenginap;
    Pengunjung* next;
};

Pengunjung* head = NULL; //pointer yang menunjuk ke pengunjung pertama dalam daftar.

// Fungsi untuk menambahkan pengunjung baru ke dalam daftar
// Fungsi ini akan menciptakan sebuah object 'Pengunjung' baru,
// mengisi nilainya dengan 'nama' dan 'lamaMenginap' yang diberikan,
// dan menambahkannya ke akhir daftar menggunakan linked list.
void tambahPengunjung(string nama, int lamaMenginap) {
    Pengunjung* pengunjungBaru = new Pengunjung;
    pengunjungBaru->nama = nama;
    pengunjungBaru->lamaMenginap = lamaMenginap;
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

    cout << "Pengunjung dengan nama " << nama << " telah ditambahkan." << endl;
}

// Fungsi untuk menghapus pengunjung dari daftar
// Fungsi ini akan mencari pengunjung dengan 'nama' yang diberikan dan menghapusnya dari daftar jika ditemukan.
// Jika pengunjung yang akan dihapus merupakan pengunjung pertama, maka 'head' akan diperbarui.
void hapusPengunjung(string nama) {
    if (head == NULL) {
        cout << "Tidak ada pengunjung di kamar." << endl;
        return;
    }

    Pengunjung* temp = head;
    Pengunjung* prev = NULL;

    // Menghapus pengunjung jika dia merupakan head dari daftar
    if (temp != NULL && temp->nama == nama) {
        head = temp->next;
        delete temp;
        cout << "Pengunjung dengan nama " << nama << " telah dihapus." << endl;
        return;
    }

    // Mencari pengunjung yang akan dihapus
    while (temp != NULL && temp->nama != nama) {
        prev = temp;
        temp = temp->next;
    }

    // Jika pengunjung tidak ditemukan
    if (temp == NULL) {
        cout << "Pengunjung dengan nama " << nama << " tidak ditemukan." << endl;
        return;
    }

    // Menghapus pengunjung dari daftar
    prev->next = temp->next;
    delete temp;
    cout << "Pengunjung dengan nama " << nama << " telah dihapus." << endl;
}

// Fungsi untuk melakukan pembayaran dan menghapus pengunjung dari daftar
// Fungsi ini akan mencari pengunjung dengan 'nama' yang diberikan, menghitung total harga berdasarkan 'lamaMenginap',
// dan meminta pengunjung memasukkan jumlah uang yang dibayarkan.
// Jika pembayaran mencukupi, maka pengunjung akan dihapus dari daftar.
void bayarPengunjung(string nama) {
    Pengunjung* temp = head;
    int HARGA_PER_HARI = 100000;
    while (temp != NULL) {
        if (temp->nama == nama) {
            int totalHarga = temp->lamaMenginap * HARGA_PER_HARI;

            // Menghitung total harga dan menerima input uang bayar
            int uangBayar;
            cout << "Total Harga: " << totalHarga << " IDR" << endl;
            cout << "Masukkan jumlah uang yang dibayarkan: ";
            cin >> uangBayar;

            // Memvalidasi pembayaran
            if (uangBayar >= totalHarga) {
                int kembalian = uangBayar - totalHarga;
                cout << "Pembayaran berhasil. Kembalian: " << kembalian << " IDR" << endl;

                // Menghapus pengunjung dari kamar
                hapusPengunjung(nama);
                return;
            } else {
                cout << "Pembayaran tidak cukup. Silakan bayar dengan jumlah yang sesuai." << endl;
                return;
            }
        }
        temp = temp->next;
    }

    cout << "Pengunjung dengan nama " << nama << " tidak ditemukan." << endl;
}

// Fungsi untuk menampilkan data pengunjung yang ada di kamar
// Fungsi ini akan menelusuri linked list dan mencetak informasi pengunjung, termasuk 'nama' dan 'lamaMenginap'.
void tampilData() {
    if (head == NULL) {
        cout << "Tidak ada pengunjung di kamar." << endl;
        return;
    }

    cout << "Data Pengunjung di Kamar Hotel:" << endl;
    Pengunjung* temp = head;
    while (temp != NULL) {
        cout << "Nama: " << temp->nama << ", Lama Menginap: " << temp->lamaMenginap << " hari" << endl;
        temp = temp->next;
    }
}

void checkIn(){
    // Type here
}

void checkOut(){
    // Type here

}

int main() {
    int pilihan;
    string nama;
    int lamaMenginap;

    do {
            system("cls");
        cout << "\n=== APLIKASI HOTEL ===" << endl;
        cout << "1. Tambah Pengunjung" << endl;
        cout << "2. Tampil Data Pengunjung" << endl;
        cout << "3. Hapus Pengunjung" << endl;
        cout << "4. Bayar" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;



        switch (pilihan) {
            case 1:
                cout << "\n== Tambah Pengunjung ==" << endl;
                cout << "Masukkan nama pengunjung: ";
                cin >> nama;
                cout << "Masukkan lama menginap (dalam hari): ";
                cin >> lamaMenginap;
                tambahPengunjung(nama, lamaMenginap);
                break;
            case 2:
                cout << "\n== Tampil Data Pengunjung ==" << endl;
                tampilData();
                break;
            case 3:
                cout << "\n== Hapus Pengunjung ==" << endl;
                cout << "Masukkan nama pengunjung yang akan dihapus: ";
                cin >> nama;
                hapusPengunjung(nama);
                break;
            case 4:
                cout << "\n== Bayar ==" << endl;
                cout << "Masukkan nama pengunjung yang akan melakukan pembayaran: ";
                cin >> nama;
                bayarPengunjung(nama);
                break;
            case 5:
                cout << "Terima kasih! Sampai jumpa." << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
        }
    } while (pilihan != 5); // Menu akan terus ditampilkan sampai pengguna memilih untuk keluar (menu 5).

    return 0;
}
