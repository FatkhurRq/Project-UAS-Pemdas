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
   
    return 0;
}
