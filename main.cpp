#include <iostream>
#include <string>
#include "Sutradara.h"
#include "Film.h"
using namespace std;

void menuAdmin(ListSutradara &L);
void menuUser(ListSutradara &L);

int main() {
    ListSutradara L;
    buatList(L);
    bool dummyLoaded = false;
    int pilih = 0;
    while (pilih != 3) {
        system("cls");
        cout << "\n====================================";
        cout << "\n             MENU UTAMA             ";
        cout << "\n====================================";
        cout << "\n1. Menu Admin";
        cout << "\n2. Menu User";
        cout << "\n3. Keluar";
        cout << "\n====================================";
        cout << "\nPilih Menu: ";
        cin >> pilih;

        if (pilih == 1) {
            system("cls");
            menuAdmin(L);
        } else if (pilih == 2) {
            if (!dummyLoaded) {
                loadDummyData(L);
                dummyLoaded = true;
            }
            system("cls");
            menuUser(L);
        } else if (pilih == 3) {
            cout << "Program Selesai\n";
        } else {
            cout << "Pilihan tidak valid\n";
        }
    }
    return 0;
}
