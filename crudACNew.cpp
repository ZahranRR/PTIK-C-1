#include <iostream>
#include <cstring>

using namespace std;

// Struktur untuk menyimpan informasi AC
struct AirConditioner {
    int id;
    char brand[50];
    char type[50];
    float capacity;
    float price;
};

const int MAX_AC = 100;
AirConditioner acDatabase[MAX_AC];
int acCount = 0;

// Fungsi untuk menambahkan data AC
void addAC() {
    if (acCount < MAX_AC) {
        AirConditioner newAC;
        newAC.id = acCount + 1;

        cout << "Masukkan Brand AC: ";
        cin.ignore();
        cin.getline(newAC.brand, sizeof(newAC.brand));

        cout << "Masukkan Tipe AC: ";
        cin.getline(newAC.type, sizeof(newAC.type));

        cout << "Masukkan Kapasitas AC (ton): ";
        cin >> newAC.capacity;

        cout << "Masukkan Harga AC: ";
        cin >> newAC.price;

        acDatabase[acCount] = newAC;
        acCount++;

        cout << "Data AC berhasil ditambahkan." << endl;
    } else {
        cout << "Database AC penuh, tidak dapat menambahkan data baru." << endl;
    }
}

// Fungsi untuk menampilkan semua data AC
void displayAllAC() {
    if (acCount > 0) {
        cout << "Data AC:" << endl;
        for (int i = 0; i < acCount; i++) {
            cout << "ID: " << acDatabase[i].id << endl;
            cout << "Brand: " << acDatabase[i].brand << endl;
            cout << "Tipe: " << acDatabase[i].type << endl;
            cout << "Kapasitas: " << acDatabase[i].capacity << " ton" << endl;
            cout << "Harga: $" << acDatabase[i].price << endl;
            cout << "------------------------" << endl;
        }
    } else {
        cout << "Database AC kosong." << endl;
    }
}
