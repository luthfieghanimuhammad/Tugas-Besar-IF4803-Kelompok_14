#include <iostream>
#include <string>
#include "Sutradara.h"
#include "Film.h"
using namespace std;

void menuAdmin(ListSutradara &L) {
    int pilihan = 0;
    while(pilihan != 18){
        cout << "\n";
        cout << "+-------------------------------------------+\n";
        cout << "|                MENU ADMIN                 |\n";
        cout << "+-------------------------------------------+\n";
        cout << "|                [SUTRADARA]                |\n";
        cout << "| 1.  Insert First Sutradara                |\n";
        cout << "| 2.  Insert Last Sutradara                 |\n";
        cout << "| 3.  Insert After Sutradara                |\n";
        cout << "| 4.  Delete First Sutradara                |\n";
        cout << "| 5.  Delete Last Sutradara                 |\n";
        cout << "| 6.  Delete After Sutradara                |\n";
        cout << "+-------------------------------------------+\n";
        cout << "|                  [FILM]                   |\n";
        cout << "| 7.  Insert First Film ke Sutradara        |\n";
        cout << "| 8.  Insert Last Film ke Sutradara         |\n";
        cout << "| 9.  Insert After Film ke Sutradara        |\n";
        cout << "| 10. Delete First Film dari Sutradara      |\n";
        cout << "| 11. Delete Last Film dari Sutradara       |\n";
        cout << "| 12. Delete After Film dari Sutradara      |\n";
        cout << "+-------------------------------------------+\n";
        cout << "|              [TAMPIL & CARI]              |\n";
        cout << "| 13. Tampilkan Semua Sutradara             |\n";
        cout << "| 14. Tampilkan Semua Film                  |\n";
        cout << "| 15. Cari Sutradara Berdasarkan ID         |\n";
        cout << "| 16. Cari Film Berdasarkan ID              |\n";
        cout << "+-------------------------------------------+\n";
        cout << "| 18. Kembali                               |\n";
        cout << "+-------------------------------------------+\n";
        cout << "Pilih Menu: ";
        cin >> pilihan;
        if(cin.fail()){
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "\n[!] Input harus berupa angka!\n";
            system("pause");
            pilihan = 0;
            continue;
        }
        cout << endl;
        if(pilihan == 1){
            adminInsertFirstSutradara(L);
        }
        else if(pilihan == 2){
            adminInsertLastSutradara(L);
        }
        else if(pilihan == 3){
            adminInsertAfterSutradara(L);
        }
        else if(pilihan == 4){
            adminDeleteFirstSutradara(L);
        }
        else if (pilihan == 5){
            adminDeleteLastSutradara(L);
        }
        else if (pilihan == 6){
            adminDeleteAfterSutradara(L);
        }
        else if (pilihan == 7){
            adminInsertFirstFilm(L);
        }
        else if (pilihan == 8){
            adminInsertLastFilm(L);
        }
        else if (pilihan == 9){
            adminInsertAfterFilm(L);
        }
        else if (pilihan == 10){
            adminDeleteFirstFilm(L);
        }
        else if (pilihan == 11){
            adminDeleteLastFilm(L);
        }
        else if (pilihan == 12){
            adminDeleteAfterFilm(L);
        }
        else if (pilihan == 13){
            adminTampilSemuaSutradara(L);
        }
        else if (pilihan == 14){
            adminTampilSemuaFilm(L);
        }
        else if (pilihan == 15){
            string cari;
            cout << "Masukkan ID Sutradara: ";
            cin >> cari;
            adrSutradara hasil = findSutradara(L, cari);
            if (hasil != nullptr) {
                cout << "Ditemukan: " << hasil->id << " - " << hasil->nama << endl;
            } else {
                cout << "Sutradara tidak ditemukan.\n";
            }
        }
        else if(pilihan == 16){
            string idSutradara, idFilm;
            cout << "Masukkan ID Sutradara: ";
            cin >> idSutradara;
            adrSutradara sutradara = findSutradara(L, idSutradara);
            if(sutradara == nullptr){
                cout << "Sutradara tidak ditemukan.\n";
            }else{
                cout << "Masukkan ID Film: ";
                cin >> idFilm;
                adrFilm film = findFilm(sutradara, idFilm);
                if (film != nullptr){
                    cout << "Ditemukan: " << film->id << " - " << film->judul << endl;
                }else{
                    cout << "Film tidak ditemukan.\n";
                }
            }
        }
        else if (pilihan == 18){
            cout << "Kembali ke menu utama...\n";
        }
        else{
            cout << "Pilihan tidak valid!\n";
        }
    }
}
