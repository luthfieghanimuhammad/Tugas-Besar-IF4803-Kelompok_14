#include <iostream>
#include <string>
#include "Sutradara.h"
#include "Film.h"
using namespace std;

void menuAdmin(ListSutradara &L);
void menuUser(ListSutradara &L);

int main(){
    ListSutradara adminList;
    ListSutradara userList;
    buatList(adminList);
    buatList(userList);
    bool dummyLoaded = false;
    int pilih = 0;
    while(pilih != 3){
        system("cls");
        cout << "\n+====================================+";
        cout << "\n|          SISTEM MANAJEMEN          |";
        cout << "\n|        SUTRADARA DAN FILM          |";
        cout << "\n+====================================+";
        cout << "\n|          MENU UTAMA                |";
        cout << "\n+====================================+";
        cout << "\n| 1. Menu Admin                      |";
        cout << "\n| 2. Menu User                       |";
        cout << "\n| 3. Keluar                          |";
        cout << "\n+====================================+";
        cout << "\nPilih Menu: ";
        cin >> pilih;

        if(pilih == 1){
            system("cls");
            menuAdmin(adminList);
        }else if(pilih == 2){
            if(!dummyLoaded){
                loadDummyData(userList);
                dummyLoaded = true;
            }
            system("cls");
            menuUser(userList);
        }else if(pilih == 3){
            cout << "\n+====================================+";
            cout << "\n|     Terima kasih telah menggunakan |";
            cout << "\n|          Program ini!              |";
            cout << "\n+====================================+\n";
        }else{
            cout << "\n[!] Pilihan tidak valid!\n";
            system("pause");
        }
    }
    return 0;
}
