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

// Fungsi untuk mengupdate data AC berdasarkan ID
void updateAC() {
    if (acCount > 0) {
        int updateID;
        cout << "Masukkan ID AC yang akan diupdate: ";
        cin >> updateID;

        for (int i = 0; i < acCount; i++) {
            if (acDatabase[i].id == updateID) {
                cout << "Masukkan Brand AC baru: ";
                cin.ignore();
                cin.getline(acDatabase[i].brand, sizeof(acDatabase[i].brand));

                cout << "Masukkan Tipe AC baru: ";
                cin.getline(acDatabase[i].type, sizeof(acDatabase[i].type));

                cout << "Masukkan Kapasitas AC baru (ton): ";
                cin >> acDatabase[i].capacity;

                cout << "Masukkan Harga AC baru: ";
                cin >> acDatabase[i].price;

                cout << "Data AC berhasil diupdate." << endl;
                return;
            }
        }

        cout << "ID AC tidak ditemukan." << endl;
    } else {
        cout << "Database AC kosong." << endl;
    }
}

// Fungsi untuk menghapus data AC berdasarkan ID
void deleteAC() {
    if (acCount > 0) {
        int deleteID;
        cout << "Masukkan ID AC yang akan dihapus: ";
        cin >> deleteID;

        for (int i = 0; i < acCount; i++) {
            if (acDatabase[i].id == deleteID) {
                for (int j = i; j < acCount - 1; j++) {
                    acDatabase[j] = acDatabase[j + 1];
                }
                acCount--;

                cout << "Data AC berhasil dihapus." << endl;
                return;
            }
        }

        cout << "ID AC tidak ditemukan." << endl;
    } else {
        cout << "Database AC kosong." << endl;
    }
}

int main() {
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Tambah Data AC\n";
        cout << "2. Tampilkan Semua Data AC\n";
        cout << "3. Update Data AC\n";
        cout << "4. Hapus Data AC\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu (1-5): ";
        cin >> choice;

        switch (choice) {
            case 1:
                addAC();
                break;
            case 2:
                displayAllAC();
                break;
            case 3:
                updateAC();
                break;
            case 4:
                deleteAC();
                break;
            case 5:
                cout << "Program selesai." << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan pilih kembali." << endl;
        }

    } while (choice != 5);

    return 0;
}
