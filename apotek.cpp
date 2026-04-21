#include <iostream>
using namespace std;

void pilihMenu() {
    cout << "===== Kasir Apotek =====" << endl;
    cout << "1. Obat Pusing" << endl;
    cout << "2. Obat Batuk Pilek" << endl;
    cout << "3. Obat Lambung" << endl;
    cout << "Mau nyari obat apa kak?";    
}

int menuObatDetail() {
    int pilih;

    cout << "===== Kategori jenis obat =====" << endl;
    cout << "1. Obat Pil" << endl;
    cout << "2. Obat Tablet" << endl;
    cout << "3. Obat Sirup" << endl;
    cout << "Pilih Jenis apa?";
    cin >> pilih;
    return pilih;
}

int menuObatPusingPil() {
    int pilihNamaObat;

    cout << "===== Menu obat pusing =====" << endl;
    cout << "1. Sanmol" << endl;
    cout << "2. Bodrex" << endl;
    cout << "3. Paramex" << endl;
    cout << "4. Panadol Extra" << endl;
    cout << "Pilih mau obat pusing apa?";
    cin >> pilihNamaObat;
    return pilihNamaObat;
}

int menuObatPusingSirup() {
    int pilihNamaObat2;

    cout << "===== Menu obat pusing =====" << endl;
    cout << "1. Sanmol Sirup" << endl;
    cout << "2. Tempra Forte" << endl;
    cout << "3. Panadol anak sirup" << endl;
    cout << "4. Termorex" << endl;
    cout << "Pilih mau obat pusing apa?";
    cin >> pilihNamaObat2;
    return pilihNamaObat2;
}

int totalHarga() {
    
}


int main() {
    int pilihObat;
    pilihMenu();
    cin >> pilihObat;

    if (pilihObat == 1) {
        int jenisObat = menuObatDetail();

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
    
    
    



}