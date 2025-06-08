#include <iostream>
#include <conio.h>
#include <iomanip>
#include <vector>
using namespace std;

int Size_Pengeluaran = 0;
int Size_Pemasukkan = 0;

string MenuA[3] = {"Riwayat Pengeluaran", "Riwayat Pemasukkan", "Riwayat Keseluruhan"};
string MenuUtama[3] = {"Tambah Transaksi", "Lihat Riwayat", "Keluar"};

struct Pengeluaran {
    int NominalKeluar;
    string NamaKeluar;
    string Tanggal;
};

struct Pemasukkan {
    int NominalMasuk;
    string NamaMasuk;
    string Tanggal;
};

Pengeluaran* daftarPengeluaran = nullptr;
Pemasukkan* daftarPemasukkan = nullptr;

void logo() {
    cout << R"(
     _____  _  __  _____ 
    / ____|| |/ / / ____|
   | (___  | ' / | (___  
    \___ \ |  <   \___ \ 
    ____) || . \  ____) |
   |_____/ |_|\_\|_____/ 

    Sistem Keuangan Saya
)";
    for (int i = 0; i <= 28; i++) cout << "=";
    cout << endl;
}

int menu_navigasi(const string menu[], int size) {
    int key = 0;
    int arrow = 0;
    while (true) {
        system("cls");
        logo();
        for (int i = 0; i < size; i++) {
            if (i == key)
                cout << "\033[35m> ";
            else
                cout << "\033[0m  ";

            cout << menu[i] << endl;
        }
        cout << "\033[0m";

        arrow = getch();
        if (arrow == 72) { // Up arrow
            key = (key - 1 + size) % size;
        } else if (arrow == 80) { // Down arrow
            key = (key + 1) % size;
        } else if (arrow == 13) { // Enter
            return key;
        }
    }
}

void Tambah_Pengeluaran() {
    system("cls");
    logo();
    cout << "Tambah Pengeluaran\n";
    cout << "==================\n";
    
    int newsize = Size_Pengeluaran + 1;
    Pengeluaran* temp = new Pengeluaran[newsize];

    for (int i = 0; i < Size_Pengeluaran; ++i) {
        temp[i] = daftarPengeluaran[i];
    }

    cout << "Nama Pengeluaran: ";
    cin.ignore();
    getline(cin, temp[Size_Pengeluaran].NamaKeluar);
    
    cout << "Nominal: ";
    cin >> temp[Size_Pengeluaran].NominalKeluar;
    
    cout << "Tanggal (DD/MM/YYYY): ";
    cin >> temp[Size_Pengeluaran].Tanggal;

    delete[] daftarPengeluaran;
    daftarPengeluaran = temp;
    Size_Pengeluaran = newsize;
    
    cout << "\nPengeluaran berhasil ditambahkan!\n";
    cout << "Tekan sembarang tombol untuk kembali...";
    getch();
}

void Tambah_Pemasukkan() {
    system("cls");
    logo();
    cout << "Tambah Pemasukkan\n";
    cout << "=================\n";
    
    int newsize = Size_Pemasukkan + 1;
    Pemasukkan* temp = new Pemasukkan[newsize];

    for (int i = 0; i < Size_Pemasukkan; ++i) {
        temp[i] = daftarPemasukkan[i];
    }

    cout << "Nama Pemasukkan: ";
    cin.ignore();
    getline(cin, temp[Size_Pemasukkan].NamaMasuk);
    
    cout << "Nominal: ";
    cin >> temp[Size_Pemasukkan].NominalMasuk;
    
    cout << "Tanggal (DD/MM/YYYY): ";
    cin >> temp[Size_Pemasukkan].Tanggal;

    delete[] daftarPemasukkan;
    daftarPemasukkan = temp;
    Size_Pemasukkan = newsize;
    
    cout << "\nPemasukkan berhasil ditambahkan!\n";
    cout << "Tekan sembarang tombol untuk kembali...";
    getch();
}

void Tampilkan_Pengeluaran() {
    system("cls");
    logo();
    cout << "Riwayat Pengeluaran\n";
    cout << "===================\n";
    
    if (Size_Pengeluaran == 0) {
        cout << "Tidak ada data pengeluaran.\n";
    } else {
        cout << left << setw(5) << "No" << setw(20) << "Nama" 
             << setw(15) << "Nominal" << setw(12) << "Tanggal" << endl;
        cout << string(52, '-') << endl;
        
        int total = 0;
        for (int i = 0; i < Size_Pengeluaran; i++) {
            cout << left << setw(5) << i+1 
                 << setw(20) << daftarPengeluaran[i].NamaKeluar 
                 << "Rp." << setw(12) << daftarPengeluaran[i].NominalKeluar 
                 << setw(12) << daftarPengeluaran[i].Tanggal << endl;
            total += daftarPengeluaran[i].NominalKeluar;
        }
        
        cout << string(52, '-') << endl;
        cout << "Total Pengeluaran: Rp." << total << endl;
    }
    
    cout << "\nTekan sembarang tombol untuk kembali...";
    getch();
}

void Tampilkan_Pemasukkan() {
    system("cls");
    logo();
    cout << "Riwayat Pemasukkan\n";
    cout << "==================\n";
    
    if (Size_Pemasukkan == 0) {
        cout << "Tidak ada data pemasukkan.\n";
    } else {
        cout << left << setw(5) << "No" << setw(20) << "Nama" 
             << setw(15) << "Nominal" << setw(12) << "Tanggal" << endl;
        cout << string(52, '-') << endl;
        
        int total = 0;
        for (int i = 0; i < Size_Pemasukkan; i++) {
            cout << left << setw(5) << i+1 
                 << setw(20) << daftarPemasukkan[i].NamaMasuk 
                 << "Rp." << setw(12) << daftarPemasukkan[i].NominalMasuk 
                 << setw(12) << daftarPemasukkan[i].Tanggal << endl;
            total += daftarPemasukkan[i].NominalMasuk;
        }
        
        cout << string(52, '-') << endl;
        cout << "Total Pemasukkan: Rp." << total << endl;
    }
    
    cout << "\nTekan sembarang tombol untuk kembali...";
    getch();
}

void Tampilkan_Semua() {
    system("cls");
    logo();
    cout << "Riwayat Keuangan\n";
    cout << "================\n";
    
    int totalPemasukkan = 0;
    int totalPengeluaran = 0;
    
    cout << "Pemasukkan:\n";
    if (Size_Pemasukkan == 0) {
        cout << "Tidak ada data pemasukkan.\n";
    } else {
        for (int i = 0; i < Size_Pemasukkan; i++) {
            cout << "- " << daftarPemasukkan[i].NamaMasuk << ": Rp." 
                 << daftarPemasukkan[i].NominalMasuk << " (" 
                 << daftarPemasukkan[i].Tanggal << ")\n";
            totalPemasukkan += daftarPemasukkan[i].NominalMasuk;
        }
    }
    
    cout << "\nPengeluaran:\n";
    if (Size_Pengeluaran == 0) {
        cout << "Tidak ada data pengeluaran.\n";
    } else {
        for (int i = 0; i < Size_Pengeluaran; i++) {
            cout << "- " << daftarPengeluaran[i].NamaKeluar << ": Rp." 
                 << daftarPengeluaran[i].NominalKeluar << " (" 
                 << daftarPengeluaran[i].Tanggal << ")\n";
            totalPengeluaran += daftarPengeluaran[i].NominalKeluar;
        }
    }
    
    cout << "\nTotal Pemasukkan: Rp." << totalPemasukkan << endl;
    cout << "Total Pengeluaran: Rp." << totalPengeluaran << endl;
    cout << "Saldo: Rp." << (totalPemasukkan - totalPengeluaran) << endl;
    
    cout << "\nTekan sembarang tombol untuk kembali...";
    getch();
}

void menu_transaksi() {
    string menu[] = {"Tambah Pemasukkan", "Tambah Pengeluaran", "Kembali"};
    while (true) {
        int pilihan = menu_navigasi(menu, 3);
        
        if (pilihan == 0) {
            Tambah_Pemasukkan();
        } else if (pilihan == 1) {
            Tambah_Pengeluaran();
        } else {
            break;
        }
    }
}

void menu_riwayat() {
    string menu[] = {"Lihat Pemasukkan", "Lihat Pengeluaran", "Lihat Semua", "Kembali"};
    while (true) {
        int pilihan = menu_navigasi(menu, 4);
        
        if (pilihan == 0) {
            Tampilkan_Pemasukkan();
        } else if (pilihan == 1) {
            Tampilkan_Pengeluaran();
        } else if (pilihan == 2) {
            Tampilkan_Semua();
        } else {
            break;
        }
    }
}

int main() {
    while (true) {
        int pilihan = menu_navigasi(MenuUtama, 3);
        
        if (pilihan == 0) {
            menu_transaksi();
        } else if (pilihan == 1) {
            menu_riwayat();
        } else {
            // Clean up memory before exiting
            if (daftarPengeluaran != nullptr) {
                delete[] daftarPengeluaran;
            }
            if (daftarPemasukkan != nullptr) {
                delete[] daftarPemasukkan;
            }
            break;
        }
    }
    return 0;
}
