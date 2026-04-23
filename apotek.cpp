#include <iostream>
#include <fstream>
using namespace std;


void simpanData(string menu, string jenis, string nama, int harga) {
    ofstream file("catatan.txt", ios::app);

    file << "Menu       : " << menu << endl;
    file << "Jenis      : " << jenis << endl;
    file << "Nama Obat  : " << nama << endl;
    file << "Harga      : " << harga << endl;
    file << "--------------------------" << endl;

    file.close();
}


void tampilkanData() {
    ifstream file("catatan.txt");
    string baris;

    cout << "\n===== DATA PEMBELIAN =====\n";

    while (getline(file, baris)) {
        cout << baris << endl;
    }

    file.close();
}


void pilihMenu() {
    cout << "\n===== Kasir Apotek =====" << endl;
    cout << "1. Obat Pusing" << endl;
    cout << "2. Obat Batuk Pilek" << endl;
    cout << "3. Obat Lambung" << endl;
    cout << "4. Lihat Data Pembelian" << endl;
    cout << "Pilih menu : ";
}

int menuObatDetail() {
    int pilih;
    cout << "\n===== Jenis Obat =====" << endl;
    cout << "1. Pil" << endl;
    cout << "2. Sirup" << endl;
    cout << "Pilih : ";
    cin >> pilih;
    return pilih;
}

int menuObatPusingPil() {
    int pilih;
    cout << "\n===== Obat Pusing (Pil) =====" << endl;
    cout << "1. Sanmol" << endl;
    cout << "2. Bodrex" << endl;
    cout << "3. Paramex" << endl;
    cout << "4. Panadol Extra" << endl;
    cout << "Pilih : ";
    cin >> pilih;
    return pilih;
}

int menuObatPusingSirup() {
    int pilih;
    cout << "\n===== Obat Pusing (Sirup) =====" << endl;
    cout << "1. Sanmol Sirup" << endl;
    cout << "2. Tempra Forte" << endl;
    cout << "3. Panadol Anak" << endl;
    cout << "4. Termorex" << endl;
    cout << "Pilih : ";
    cin >> pilih;
    return pilih;
}


void pembayaran(int harga) {
    int metode;
    cout << "\nTotal Harga : " << harga << endl;
    cout << "Metode Pembayaran:\n1. Cash\n2. QRIS\nPilih : ";
    cin >> metode;

    if (metode == 1) {
        int uang;
        cout << "Masukkan uang : ";
        cin >> uang;

        if (uang >= harga) {
            cout << "Kembalian : " << uang - harga << endl;
        } else {
            cout << "Uang tidak cukup!\n";
        }

    } else if (metode == 2) {
        cout << "Silakan scan QRIS...\nPembayaran berhasil!\n";
    } else {
        cout << "Metode tidak valid!\n";
    }
}


int main() {
    string ulang;

    do {
        int pilihObat;
        pilihMenu();
        cin >> pilihObat;

        if (pilihObat == 1) {
            int jenis = menuObatDetail();

            if (jenis == 1) {
                int pilih = menuObatPusingPil();
                int harga = 0;
                string nama = "";

                if (pilih == 1) { harga = 5000; nama = "Sanmol"; }
                else if (pilih == 2) { harga = 7000; nama = "Bodrex"; }
                else if (pilih == 3) { harga = 6000; nama = "Paramex"; }
                else if (pilih == 4) { harga = 8000; nama = "Panadol Extra"; }
                else { cout << "Pilihan tidak ada\n"; }

                cout << "Kamu memilih " << nama << endl;

                pembayaran(harga);
                simpanData("Obat Pusing", "Pil", nama, harga);

            } else if (jenis == 2) {
                int pilih = menuObatPusingSirup();
                int harga = 0;
                string nama = "";

                if (pilih == 1) { harga = 5000; nama = "Sanmol Sirup"; }
                else if (pilih == 2) { harga = 6000; nama = "Tempra Forte"; }
                else if (pilih == 3) { harga = 7000; nama = "Panadol Anak"; }
                else if (pilih == 4) { harga = 8000; nama = "Termorex"; }
                else { cout << "Pilihan tidak ada\n"; }

                cout << "Kamu memilih " << nama << endl;

                pembayaran(harga);
                simpanData("Obat Pusing", "Sirup", nama, harga);
            }

        } else if (pilihObat == 2) {
            /* code */
        } else if (pilihObat == 3) {
            /* code */
        } else if (pilihObat == 4) {
            tampilkanData();
        } else {
            cout << "Menu belum tersedia\n";
        }

        cout << "\nMau transaksi lagi? (Ya/Tidak): ";
        cin >> ulang;

    } while (ulang == "Ya" || ulang == "ya");

    return 0;
}
