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

void daftarbuku() {
    ifstream DaftarBuku("FileBuku.txt"); 
    string outputTeks;
    while (getline (DaftarBuku, outputTeks)){
        cout << outputTeks;
    } 
DaftarBuku.close();
}


int main() {
    buatfile();

    string judul, penulis, penerbit;
    int tahunterbit;

    cout << "Masukkan judul buku: ";
    getline(cin, judul); 
    cout << "Masukkan nama penulis: ";
    getline(cin, penulis);

    cout << "Masukkan nama penerbit: ";
    getline(cin, penerbit);

    cout << "Masukkan tahun terbit buku: ";
    cin >> tahunterbit;

    databuku buku;
    buku.judul = judul;
    buku.penulis = penulis;
    buku.penerbit = penerbit;
    buku.tahunterbit = tahunterbit;

    tambahbuku(buku);

    cout << "Buku berhasil ditambahkan ke file!" << endl;

    return 0;
}