#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct databuku {
    string judul;
    string penulis;
    string penerbit;
    int tahunterbit;
};

void buatfile() {
    ofstream buatfile("FileBuku.txt", ios::app); 
    buatfile.close();
}

void tambahbuku(const databuku & buku) {
    fstream TambahBuku("FileBuku.txt", ios::app);
    TambahBuku << buku.judul << "|" << buku.penulis << "|" << buku.penerbit << "|" << buku.tahunterbit << endl;
    TambahBuku.close();
}

struct Peminjaman {
    string namaPeminjam;
    string judulBuku;
    string tanggalPinjam;
};

void tambahPeminjaman() {
    Peminjaman peminjaman;
    ofstream file("peminjaman.txt"); 
    if (!file) {
        cerr << "Tidak dapat membuka file!" << endl;
        return;
    }

    cout << "Masukkan nama peminjam: ";
    getline(cin, peminjaman.namaPeminjam);
    cout << "Masukkan judul buku: ";
    getline(cin, peminjaman.judulBuku);
    cout << "Masukkan tanggal pinjam (DD-MM-YYYY): ";
    getline(cin, peminjaman.tanggalPinjam);


    file << peminjaman.namaPeminjam << endl;
    file << peminjaman.judulBuku << endl;
    file << peminjaman.tanggalPinjam << endl;

    file.close();
    cout << "Data peminjaman berhasil ditambahkan!" << endl;
}

void tampilkanPeminjaman() {
    Peminjaman peminjaman;
    ifstream file("peminjaman.txt"); 
    if (!file) {
        cerr << "Tidak dapat membuka file!" << endl;
        return;
    }

    cout << "Data Peminjaman Buku:" << endl;
    while (getline(file, peminjaman.namaPeminjam)) {
        getline(file, peminjaman.judulBuku);
        getline(file, peminjaman.tanggalPinjam);
        cout << "Nama Peminjam: " << peminjaman.namaPeminjam << endl;
        cout << "Judul Buku: " << peminjaman.judulBuku << endl;
        cout << "Tanggal Pinjam: " << peminjaman.tanggalPinjam << endl;
        cout << "------------------------" << endl;
    }

    file.close();
}

void daftarbuku() {
    ifstream DaftarBuku("FileBuku.txt"); 
    string outputTeks;
    while (getline (DaftarBuku, outputTeks)){
        cout << outputTeks;
    } 
DaftarBuku.close();
}


int main() {
   
    return 0;
}
