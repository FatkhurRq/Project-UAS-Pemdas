#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Buku {
    int id;
    string judul;
    string penulis;
    string penerbit;
    int tahunTerbit;
    string status; // "tersedia" atau "dipinjam"
    string tanggalPinjam; // Tanggal peminjaman
};

void buatFile() {
    ofstream file("data_buku.txt", ios::app);
    file.close();
}

void tambahBuku(const Buku &buku) {
    ofstream file("data_buku.txt", ios::app);
    file << buku.id << "|" << buku.judul << "|" << buku.penulis << "|" 
         << buku.penerbit << "|" << buku.tahunTerbit << "|" << buku.status 
         << "|" << buku.tanggalPinjam << endl;
    file.close();
}

void tampilkanDaftarBuku() {
    ifstream file("data_buku.txt");
    if (!file) {
        cerr << "Tidak dapat membuka file!" << endl;
        return;
    }

    cout << "Daftar Buku:" << endl;
    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
}

void pinjamBuku() {
    tampilkanDaftarBuku();
    int idBuku;
    cout << "Masukkan ID buku yang ingin dipinjam: ";
    cin >> idBuku;

    // Membaca semua buku ke dalam array
    Buku database[100];
    int jumlahBuku = 0;
    ifstream file("data_buku.txt");
    while (file >> database[jumlahBuku].id) {
        file.ignore(); // Mengabaikan karakter '|'
        getline(file, database[jumlahBuku].judul, '|');
        getline(file, database[jumlahBuku].penulis, '|');
        getline(file, database[jumlahBuku].penerbit, '|');
        file >> database[jumlahBuku].tahunTerbit;
        file.ignore(); // Mengabaikan karakter '|'
        getline(file, database[jumlahBuku].status, '|');
        getline(file, database[jumlahBuku].tanggalPinjam);
        jumlahBuku++;
    }
    file.close();

    // Memperbarui status buku
    bool ditemukan = false;
    for (int i = 0; i < jumlahBuku; i++) {
        if (database[i].id == idBuku) {
            ditemukan = true;
            if (database[i].status == "tersedia") {
                database[i].status = "dipinjam";
                cout << "Masukkan tanggal pinjam (DD-MM-YYYY): ";
                cin >> database[i].tanggalPinjam;
                cout << "Buku '" << database[i].judul << "' berhasil dipinjam." << endl;
            } else {
                cout << "Buku '" << database[i].judul << "' sudah dipinjam." << endl;
            }
            break;
        }
    }
    if (!ditemukan) {
        cout << "ID buku tidak ditemukan." << endl;
    }

    // Menyimpan kembali data ke file
    ofstream outFile("data_buku.txt");
    for (int i = 0; i < jumlahBuku; i++) {
        outFile << database[i].id << "|" << database[i].judul << "|" 
                << database[i].penulis << "|" << database[i].penerbit << "|" 
                << database[i].tahunTerbit << "|" << database[i].status << "|" 
                << database[i].tanggalPinjam << endl;
    }
    outFile.close();
}

void pengembalianBuku() {
    tampilkanDaftarBuku();
    int idBuku;
    cout << "Masukkan ID buku yang ingin dikembalikan: ";
    cin >> idBuku;

    // Membaca semua buku ke dalam array
    Buku database[100];
    int jumlahBuku = 0;
    ifstream file("data_buku.txt");
    while (file >> database[jumlahBuku].id) {
        file.ignore(); // Mengabaikan karakter '|'
        getline(file, database[jumlahBuku].judul, '|');
        getline(file, database[jumlahBuku].penulis, '|');
        getline(file, database[jumlahBuku].penerbit, '|');
        file >> database[jumlahBuku].tahunTerbit;
        file.ignore(); // Mengabaikan karakter '|'
        getline(file, database[jumlahBuku].status, '|');
        getline(file, database[jumlahBuku].tanggalPinjam);
        jumlahBuku++;
    }
    file.close();

    // Memperbarui status buku
    bool ditemukan = false;
    for (int i = 0; i < jumlahBuku; i++) {
        if (database[i].id == idBuku) {
            ditemukan = true;
            if (database[i].status == "dipinjam") {
                database[i].status = "tersedia";
                database[i].tanggalPinjam = ""; // Reset tanggal pinjam
                cout << "Buku '" << database[i].judul << "' berhasil dikembalikan." << endl;
            } else {
                cout << "Buku '" << database[i].judul << "' sudah tersedia." << endl;
            }
            break;
        }
    }
    if (!ditemukan) {
        cout << "ID buku tidak ditemukan." << endl;
    }

    // Menyimpan kembali data ke file
    ofstream outFile("data_buku.txt");
    for (int i = 0; i < jumlahBuku; i++) {
        outFile << database[i].id << "|" << database[i].judul << "|" 
                << database[i].penulis << "|" << database[i].penerbit << "|" 
                << database[i].tahunTerbit << "|" << database[i].status << "|" 
                << database[i].tanggalPinjam << endl;
    }
    outFile.close();
}

void menuUtama() {
    while (true) {
        cout << "\nMenu Utama" << endl;
        cout << "1. Tambah Buku" << endl;
        cout << "2. Pinjam Buku" << endl;
        cout << "3. Pengembalian Buku" << endl;
        cout << "4. Lihat Daftar Buku" << endl;
        cout << "5. Keluar" << endl;

        int pilihan;
        cout << "Pilih opsi (1/2/3/4/5): ";
        cin >> pilihan;
        cin.ignore(); // Mengabaikan newline setelah input

        switch (pilihan) {
            case 1: {
                Buku buku;
                cout << "Masukkan ID Buku: ";
                cin >> buku.id;
                cin.ignore();
                cout << "Masukkan Judul Buku: ";
                getline(cin, buku.judul);
                cout << "Masukkan Penulis Buku: ";
                getline(cin, buku.penulis);
                cout << "Masukkan Penerbit Buku: ";
                getline(cin, buku.penerbit);
                cout << "Masukkan Tahun Terbit: ";
                cin >> buku.tahunTerbit;
                buku.status = "tersedia";
                buku.tanggalPinjam = ""; // Kosongkan tanggal pinjam
                tambahBuku(buku);
                break;
            }
            case 2:
                pinjamBuku();
                break;
            case 3:
                pengembalianBuku();
                break;
            case 4:
                tampilkanDaftarBuku();
                break;
            case 5:
                cout << "Keluar dari program." << endl;
                return;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    }
}

int main() {
    buatFile();
    menuUtama();
    return 0;
}