#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#define MAX 100
#define JUMLAH_CABANG 3
class Apotek {
private:
    string kodeObat[MAX];
    string namaObat[MAX];
    string jenisObat[MAX];
    int hargaObat[MAX];
    int kategoriObat[MAX];          
    int stokCabang[MAX][JUMLAH_CABANG]; 
    int jumlahObatSekarang = 0;

    string pembeliTransaksi[MAX];
    string namaObatTransaksi[MAX];
    int jumlahBeliTransaksi[MAX];
    int totalBayarTransaksi[MAX];
    int jumlahTransaksi = 0;

public:
    void tambahObatManual(string kode, string nama, string jenis, int harga, int kategori,
                       int stok1, int stok2, int stok3) {
    int index = jumlahObatSekarang;

    kodeObat[index] = kode;
    namaObat[index] = nama;
    jenisObat[index] = jenis;
    hargaObat[index] = harga;
    kategoriObat[index] = kategori;

    stokCabang[index][0] = stok1;
    stokCabang[index][1] = stok2;
    stokCabang[index][2] = stok3;

    jumlahObatSekarang = jumlahObatSekarang + 1;
}

void inisialisasiDataObat() {
    tambahObatManual("OB001", "Paracetamol",  "Tablet", 5000,  1, 50, 40, 30);
    tambahObatManual("OB002", "Amoxicillin",  "Kapsul", 12000, 2, 20, 15, 10);
    tambahObatManual("OB003", "Vitamin C",    "Tablet", 8000,  1, 60, 50, 45);
    tambahObatManual("OB004", "Omeprazole",   "Kapsul", 15000, 2, 25, 20, 18);
    tambahObatManual("OB005", "Ibuprofen",    "Tablet", 7000,  1, 35, 30, 25);
}

int totalStok(int index) {
    int total = 0;
    for (int c = 0; c < JUMLAH_CABANG; c++) {
        total = total + stokCabang[index][c];
    }
    return total;
}

void tampilkanInfoObat(int index) {
    cout << "[" << kodeObat[index] << "] " << namaObat[index]
         << " (" << jenisObat[index] << ") - Rp" << hargaObat[index];

    if (kategoriObat[index] == 2) {
        cout << " | Kategori: Obat Keras (wajib resep dokter)" << endl;
    } else {
        cout << " | Kategori: Obat Bebas" << endl;
    }
}

void tampilkanMenuObat() {
    cout << "\n===== MENU OBAT YANG TERSEDIA =====\n";
    for (int i = 0; i < jumlahObatSekarang; i++) {
        string kategoriText;
        if (kategoriObat[i] == 2) {
            kategoriText = "Obat Keras";
        } else {
            kategoriText = "Obat Bebas";
        }
        cout << (i + 1) << ". " << namaObat[i] << " (" << jenisObat[i] << ") - Rp"
             << hargaObat[i] << " [" << kategoriText << "]" << endl;
    }
}

// ================= TAMPILKAN DATA - ITERATIF =================
void tampilkanIteratif() {
    cout << "\n===== DAFTAR OBAT (ITERATIF) =====\n";
    for (int i = 0; i < jumlahObatSekarang; i++) {
        tampilkanInfoObat(i);
        cout << "   Stok total: " << totalStok(i)
             << " (C1:" << stokCabang[i][0]
             << " C2:" << stokCabang[i][1]
             << " C3:" << stokCabang[i][2] << ")\n";
    }
}

// ================= TAMPILKAN DATA - REKURSIF =================
void tampilkanRekursif(int index) {
    if (index >= jumlahObatSekarang) { // basis
        return;
    }
    tampilkanInfoObat(index);
    cout << "   Stok total: " << totalStok(index) << endl;
    tampilkanRekursif(index + 1); // rekursi
}

// ================= SORTING BERDASARKAN HARGA (ITERATIF, BUBBLE SORT) =================
void urutkanHarga() {
    for (int i = 0; i < jumlahObatSekarang - 1; i++) {
        for (int j = 0; j < jumlahObatSekarang - i - 1; j++) {
            if (hargaObat[j] > hargaObat[j + 1]) {
                // tukar semua data obat baris j dan j+1
                string tempKode = kodeObat[j];
                kodeObat[j] = kodeObat[j + 1];
                kodeObat[j + 1] = tempKode;

                string tempNama = namaObat[j];
                namaObat[j] = namaObat[j + 1];
                namaObat[j + 1] = tempNama;

                string tempJenis = jenisObat[j];
                jenisObat[j] = jenisObat[j + 1];
                jenisObat[j + 1] = tempJenis;

                int tempHarga = hargaObat[j];
                hargaObat[j] = hargaObat[j + 1];
                hargaObat[j + 1] = tempHarga;

                int tempKategori = kategoriObat[j];
                kategoriObat[j] = kategoriObat[j + 1];
                kategoriObat[j + 1] = tempKategori;

                // ikut menukar baris stok cabang agar tetap sinkron
                for (int c = 0; c < JUMLAH_CABANG; c++) {
                    int tempStok = stokCabang[j][c];
                    stokCabang[j][c] = stokCabang[j + 1][c];
                    stokCabang[j + 1][c] = tempStok;
                }
            }
        }
    }
    cout << "Data obat berhasil diurutkan berdasarkan harga (termurah -> termahal)!\n";
}

// ================= CARI INDEX OBAT - REKURSIF =================
int cariIndexRekursif(int index, string keyword) {
    if (index >= jumlahObatSekarang) { // basis
        return -1;
    }
    if (namaObat[index] == keyword) {
        return index;
    }
    return cariIndexRekursif(index + 1, keyword); // rekursi
}

void cariObat() {
    string keyword;
    cout << "Masukkan nama obat yang dicari: ";
    cin.ignore();
    getline(cin, keyword);

    int hasil = cariIndexRekursif(0, keyword);
    if (hasil == -1) {
        cout << "Obat tidak ditemukan!\n";
    } else {
        cout << "Ditemukan:\n";
        tampilkanInfoObat(hasil);
        cout << "Stok total: " << totalStok(hasil) << endl;
    }
}

// ================= POINTER: KURANGI STOK LEWAT ALAMAT VARIABEL =================
void kurangiStokCabang(int *stok, int jumlah) {
    *stok = *stok - jumlah;
}

// ================= SIMPAN TRANSAKSI KE FILE =================
void simpanTransaksiKeFile(int index) {
    ofstream file("transaksi.txt", ios::app);
    file << "Pembeli     : " << pembeliTransaksi[index] << endl;
    file << "Obat        : " << namaObatTransaksi[index] << endl;
    file << "Jumlah Beli : " << jumlahBeliTransaksi[index] << endl;
    file << "Total Bayar : Rp" << totalBayarTransaksi[index] << endl;
    file << "--------------------------" << endl;
    file.close();
}

// ================= TRANSAKSI PENJUALAN (SEKUEN + KONDISIONAL) =================
void transaksiJual() {
    if (jumlahObatSekarang == 0) {
        cout << "Belum ada data obat.\n";
        return;
    }

    string namaDicari;
    cout << "Masukkan nama obat yang ingin dibeli: ";
    cin.ignore();
    getline(cin, namaDicari);

    int index = cariIndexRekursif(0, namaDicari);
    if (index == -1) {
        cout << "Obat tidak ditemukan!\n";
        return;
    }

    int jumlahBeli;
    cout << "Stok total tersedia : " << totalStok(index) << endl;
    cout << "Masukkan jumlah beli: ";
    cin >> jumlahBeli;

    if (jumlahBeli <= 0) {
        cout << "Jumlah beli tidak valid!\n";
        return;
    }
    if (jumlahBeli > totalStok(index)) {
        cout << "Stok tidak mencukupi!\n";
        return;
    }
    if (jumlahTransaksi >= MAX) {
        cout << "Data transaksi sudah penuh!\n";
        return;
    }

    // ambil stok dari cabang yang tersedia satu per satu (iteratif),
    // pengurangannya lewat pointer
    int sisa = jumlahBeli;
    for (int c = 0; c < JUMLAH_CABANG && sisa > 0; c++) {
        int ambil;
        if (sisa < stokCabang[index][c]) {
            ambil = sisa;
        } else {
            ambil = stokCabang[index][c];
        }
        kurangiStokCabang(&stokCabang[index][c], ambil);
        sisa = sisa - ambil;
    }

    string pembeli;
    cout << "Masukkan nama pembeli: ";
    cin.ignore();
    getline(cin, pembeli);

    int total = hargaObat[index] * jumlahBeli;

    int t = jumlahTransaksi;
    pembeliTransaksi[t] = pembeli;
    namaObatTransaksi[t] = namaObat[index];
    jumlahBeliTransaksi[t] = jumlahBeli;
    totalBayarTransaksi[t] = total;

    simpanTransaksiKeFile(t);
    jumlahTransaksi = jumlahTransaksi + 1;

    cout << "Transaksi berhasil! Total bayar: Rp" << total << endl;
}

// ================= RIWAYAT TRANSAKSI (ITERATIF DARI FILE) =================
void tampilkanRiwayat() {
    ifstream file("transaksi.txt");
    string baris;
    cout << "\n===== RIWAYAT TRANSAKSI =====\n";
    while (getline(file, baris)) {
        cout << baris << endl;
    }
    file.close();
}
};

// ================= MENU UTAMA =================
int main() {
    Apotek apotek;
    apotek.inisialisasiDataObat(); // data obat langsung terisi, tidak perlu input manual

    int pilihan;

    do {
        cout << "\n========= MENU JUAL BELI OBAT =========\n";
        cout << "1. Tampilkan Menu Obat yang Ada\n";
        cout << "2. Tampilkan Data Obat (Iteratif)\n";
        cout << "3. Tampilkan Data Obat (Rekursif)\n";
        cout << "4. Urutkan Obat Berdasarkan Harga\n";
        cout << "5. Cari Obat Berdasarkan Nama (Rekursif)\n";
        cout << "6. Transaksi Penjualan (Jual Obat)\n";
        cout << "7. Tampilkan Riwayat Transaksi\n";
        cout << "9. Keluar\n";
        cout << "Pilihan : ";
        cin >> pilihan;

        switch (pilihan) { // KONDISIONAL
            case 1: apotek.tampilkanMenuObat(); break;
            case 2: apotek.tampilkanIteratif(); break;
            case 3: apotek.tampilkanRekursif(0); break;
            case 4: apotek.urutkanHarga(); break;
            case 5: apotek.cariObat(); break;
            case 6: apotek.transaksiJual(); break;
            case 7: apotek.tampilkanRiwayat(); break;
            case 9: cout << "Terima kasih!\n"; break;
            default: cout << "Pilihan tidak valid!\n";
        }

    } while (pilihan != 9); // PERULANGAN ITERATIF

    return 0;
}   