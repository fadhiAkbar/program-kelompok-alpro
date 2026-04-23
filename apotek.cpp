#include <iostream>
using namespace std;

void pilihMenu() {
    cout << "===== Kasir Apotek =====" << endl;
    cout << "1. Obat Pusing" << endl;
    cout << "2. Obat Batuk Pilek" << endl;
    cout << "3. Obat Lambung" << endl;
    cout << "Mau nyari obat apa kak? : ";    
}

int menuObatDetail() {
    int pilih;

    cout << "===== Kategori jenis obat =====" << endl;
    cout << "1. Obat Pil" << endl;
    cout << "2. Obat Sirup" << endl;
    cout << "Pilih Jenis apa? : ";
    cin >> pilih;
    cout << endl;
    cout << endl;
    return pilih;
}

int menuObatPusingPil() {
    int pilihNamaObat;

    cout << "===== Menu obat pusing =====" << endl;
    cout << "1. Sanmol" << endl;
    cout << "2. Bodrex" << endl;
    cout << "3. Paramex" << endl;
    cout << "4. Panadol Extra" << endl;
    cout << "Pilih mau obat pusing apa? : ";
    cin >> pilihNamaObat;
    cout << endl;
    cout << endl;
    return pilihNamaObat;
}

int menuObatPusingSirup() {
    int pilihNamaObat2;

    cout << "===== Menu obat pusing =====" << endl;
    cout << "1. Sanmol Sirup" << endl;
    cout << "2. Tempra Forte" << endl;
    cout << "3. Panadol anak sirup" << endl;
    cout << "4. Termorex" << endl;
    cout << "Pilih mau obat pusing apa? : ";
    cin >> pilihNamaObat2;
    cout << endl;
    cout << endl;
    return pilihNamaObat2;
}


int main() {
    string ketentuan;
    
    do {
    int pilihObat;
    pilihMenu();
    cin >> pilihObat;
    
    if (pilihObat == 1) {
        int jenisObat = menuObatDetail();
        int metode;

        if (jenisObat == 1) {
            int namaObat = menuObatPusingPil();
            int harga = 0;

            if (namaObat == 1) {
                harga = 5000;
                cout << "Kamu memilih Sanmol";    
                
            } else if (namaObat == 2) {
                harga = 7000;
                cout << "Kamu memilih Bodrex";    
                
            } else if (namaObat == 3) {
                harga = 6000;
                cout << "Kamu memilih Paramex";    
                
            } else if (namaObat == 4) {
                harga = 8000;
                cout << "Kamu memilih Panadol Extra";    
                
            } else {
                cout << "Pilihan Tidak ada";
            }
            
            cout << "Total Harga : " << harga << endl;

            cout << "Mau bayar dengan apa? : " << endl;
            cout << "1. Cash" << endl;
            cout << "2. QRIS : " << endl;
            cout << "Pilih : ";
            cin >> metode;

            if (metode == 1) {
                int uang;
                cout << "Masukkan uang anda : ";
                cin >> uang;
    
                if (uang >= harga) {
                    int kembalian = uang - harga;
                    cout << "Kembalian : " << kembalian << endl;
                } else {
                    cout << "Uang tidak cukup" << endl;
                }
            } else if (metode == 2) {
                cout << "Silahkan Scan pada barcode tersebut" << endl;
                cout << "Pembayaran Berhasil" << endl;
            } else {
                cout << "Metode tidak Valid" << endl;
            }
            
            
        } else if (jenisObat == 2) {
            int namaObat2 = menuObatPusingSirup();
            int harga = 0;
            
            if (namaObat2 == 1) {
                harga = 5000;
                cout << "Kamu memilih Sanmol Sirup";    
                
            } else if (namaObat2 == 2) {
                harga = 6000;
                cout << "Kamu memilih Tempra Forte";    
                
            } else if (namaObat2 == 3) {
                harga = 7000;
                cout << "Kamu memilih Panadol anak sirup";    
                
            } else if (namaObat2 == 4) {
                harga = 8000;
                cout << "Kamu memilih Termorex";    
                
            } else {
                cout << "Pilihan Tidak ada";
            }
            
            cout << "Total Harga : " << harga << endl;
            
            cout << "Mau bayar dengan apa? : " << endl;
            cout << "1. Cash" << endl;
            cout << "2. QRIS" << endl;
            cout << "Pilih : ";
            cin >> metode;
            
            if (metode == 1) {
                int uang;
                cout << "Masukkan uang anda : ";
                cin >> uang;
                
                if (uang >= harga) {
                    int kembalian = uang - harga;
                    cout << "Kembalian : " << kembalian << endl;
                } else {
                    cout << "Uang tidak cukup" << endl;
                }

            } else if (metode == 2) {
                cout << "Silahkan Scan pada barcode tersebut" << endl;
                cout << "Pembayaran Berhasil" << endl;
            } else {
                cout << "Metode tidak Valid" << endl;
            }
             
        } else {
            cout << "Tidak ada di pilihan";
        }
        
        
        
    } else if (pilihObat == 2) {
        menuObatDetail();
    } else if (pilihObat == 3) {
        menuObatDetail();
    } else {
        cout << "Pilihan tidak ada";
    }
    
    cout << "Apakah ada tambahan lagi? : ";
    cin >> ketentuan;
    } while (ketentuan == "Ya" || ketentuan == "Yes" || ketentuan == "Y" || ketentuan == "y");
}