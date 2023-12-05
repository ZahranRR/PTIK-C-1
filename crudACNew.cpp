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

