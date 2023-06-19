#include <iostream>
using namespace std;

struct Pengunjung {
    string nama;
    int lamaMenginap;
    string notelp;
    int nomorkamar;
    Pengunjung* next;
};

Pengunjung* head = NULL; //pointer yang menunjuk ke pengunjung pertama dalam daftar.


// Fungsi untuk memeriksa ketersediaan kamar
bool isKamarTersedia(Pengunjung* head, int nomorkamar) {
    Pengunjung* temp = head;
    while (temp != nullptr) {
        if (temp->nomorkamar == nomorkamar) {
            return false;  // Kamar sudah dipesan
        }
        temp = temp->next;
    }
    return true;  // Kamar tersedia
}


// Fungsi untuk menambahkan pengunjung baru ke dalam daftar
// Fungsi ini akan menciptakan sebuah object 'Pengunjung' baru,
// mengisi nilainya dengan 'nama' dan 'lamaMenginap' yang diberikan,
// dan menambahkannya ke akhir daftar menggunakan linked list.
void tambahPengunjung(string nama, int lamaMenginap,string notelp, int nomorkamar) {
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

    cout << "\nPengunjung dengan nama " << nama << " telah ditambahkan di kamar " << nomorkamar << endl;
}

// Fungsi untuk menampilkan kamar-kamar yang tersedia
void tampilKamarTersedia(Pengunjung* head) {
    cout << "\n===============" << endl;
    cout << "Standard Room" << endl;
    cout << "===============" << endl;
    for (int nomorKamar = 1; nomorKamar <= 5; nomorKamar++) {
        if (isKamarTersedia(head, nomorKamar)) {
            cout << "Kamar " << nomorKamar << " tersedia\n";
        }
    }
    cout << "\n=============" << endl;
    cout << "Deluxe Room" << endl;
    cout << "=============" << endl;
    for (int nomorKamar = 6; nomorKamar <= 10; nomorKamar++) {
        if (isKamarTersedia(head, nomorKamar)) {
            cout << "Kamar " << nomorKamar << " tersedia\n";
        }
    }
}

// Fungsi untuk menghapus pengunjung dari daftar
// Fungsi ini akan mencari pengunjung dengan 'nama' yang diberikan dan menghapusnya dari daftar jika ditemukan.
// Jika pengunjung yang akan dihapus merupakan pengunjung pertama, maka 'head' akan diperbarui.
void hapusPengunjung(string nama) {
    if(nama == "0")
        {
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
void bayarPengunjung(string nama,int nomorkamar) {
    if(nomorkamar == 0)
        {
            return;
        }

    Pengunjung* temp = head;
    int HARGA_STANDART = 100000;
    int HARGA_DELUXE = 250000;
    while (temp != NULL) {
        if (temp->nomorkamar == nomorkamar) {
            if (temp->nomorkamar>0 && temp->nomorkamar<=5){
                int totalHarga = temp->lamaMenginap * HARGA_STANDART;

                // Menghitung total harga dan menerima input uang bayar
                int uangBayar;
                cout << "\n== Standart Room ==" << endl;
                cout << "Nama : " << temp->nama << endl;
                cout << "Kamar " << nomorkamar << endl;
                cout << "Nomor HP : " << temp->notelp << endl;
                cout << "Lama Menginap : " << temp->lamaMenginap << " Hari" << endl;
                cout << "========================================" << endl;
                cout << "Total Harga: " << totalHarga << " IDR" << endl;
                cout << "========================================" << endl;
                cout << "Masukkan jumlah uang yang dibayarkan: ";
                cin >> uangBayar;

                // Memvalidasi pembayaran
                if (uangBayar >= totalHarga) {
                    int kembalian = uangBayar - totalHarga;
                    cout << "Pembayaran berhasil. Kembalian: " << kembalian << " IDR" << endl;

                    // Menghapus pengunjung dari kamar
                    hapusPengunjung(temp->nama);
                    return;
                } else {
                    cout << "Pembayaran tidak cukup. Silakan bayar dengan jumlah yang sesuai." << endl;
                    return;
                }
            }
            if (temp->nomorkamar>5 && temp->nomorkamar<=10){
                int totalHarga = temp->lamaMenginap * HARGA_DELUXE;

                // Menghitung total harga dan menerima input uang bayar
                int uangBayar;
                cout << "\n== Deluxe Room ==" << endl;
                cout << "Nama : " << temp->nama << endl;
                cout << "Kamar " << temp->nomorkamar << endl;
                cout << "Nomor HP : " << temp->notelp << endl;
                cout << "Lama Menginap : " << temp->lamaMenginap << " Hari" << endl;
                cout << "========================================" << endl;
                cout << "Total Harga: " << totalHarga << " IDR" << endl;
                cout << "========================================" << endl;
                cout << "Masukkan jumlah uang yang dibayarkan: ";
                cin >> uangBayar;

                // Memvalidasi pembayaran
                if (uangBayar >= totalHarga) {
                    int kembalian = uangBayar - totalHarga;
                    cout << "Pembayaran berhasil. Kembalian: " << kembalian << " IDR" << endl;

                    // Menghapus pengunjung dari kamar
                    hapusPengunjung(temp->nama);
                    return;
                } else {
                    cout << "Pembayaran tidak cukup. Silakan bayar dengan jumlah yang sesuai." << endl;
                    return;
                }
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

    cout << "Data Pengunjung di Kamar Hotel:\n" << endl;
    Pengunjung* temp = head;
    while (temp != NULL) {
        if (temp->nomorkamar>0 && temp->nomorkamar<=5){
            cout << "Kamar " << temp->nomorkamar << "(Standart Room)" << endl;
            cout << "Nama: " << temp->nama << endl;
            cout << "Nomor HP : " << temp->notelp << endl;
            cout << "Lama Menginap: " << temp->lamaMenginap << " hari\n" << endl;
        }
        if (temp->nomorkamar>5 && temp->nomorkamar<=10){
            cout << "Kamar " << temp->nomorkamar << "(Deluxe Room)" << endl;
            cout << "Nama: " << temp->nama << endl;
            cout << "Nomor HP : " << temp->notelp << endl;
            cout << "Lama Menginap: " << temp->lamaMenginap << " hari\n" << endl;
        }

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
    string notelp;
    int lamaMenginap;
    int nomorkamar;
    char ulangi;

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
                do {
                    system("cls");
                    cout << "Pilihan Kamar yang Tersedia" << endl;
                    tampilKamarTersedia(head);

                    // Memasukkan nomor kamar dan nama pemesan
                    cout << "\n== KETIK 0 UNTUK KEMBALI KE MENU AWAL ==";
                    cout << "\nMasukkan nomor kamar yang ingin dipesan: ";
                    cin >> nomorkamar;

                    if(nomorkamar == 0)
                    {
                        break;
                    }

                    if (nomorkamar>0 && nomorkamar <=10){
                        if (isKamarTersedia(head, nomorkamar)) {
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
                cout << "\n== Tampil Data Pengunjung ==" << endl;
                tampilData();
                system("pause");
                break;
            case 3:
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
            case 4:
                system("cls");
                cout << "\n== Bayar ==" << endl;
                cout << "== KETIK 0 UNTUK KEMBALI KE MENU AWAL ==\n";
                cout << "Masukkan nama pengunjung yang akan melakukan pembayaran: ";
                cin >> nomorkamar;
                bayarPengunjung(nama,nomorkamar);
                system("pause");
                break;
            case 5:
                system("cls");
                cout << "Terima kasih! Sampai jumpa." << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
                system("pause");
        }
    } while (pilihan != 5); // Menu akan terus ditampilkan sampai pengguna memilih untuk keluar (menu 5).

    return 0;
}
