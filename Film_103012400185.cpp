#include <iostream>
#include <string>
#include "Film.h"
#include "Sutradara.h"
using namespace std;

adrFilm buatFilmNode(string id, string judul, int tahun){
    adrFilm F = new Film;
    F->id = id;
    F->judul = judul;
    F->tahun = tahun;
    F->next = nullptr;
    return F;
}

void insertLastFilm(adrSutradara S, adrFilm F){
    if(S == nullptr) return;
    if(S->firstFilm == nullptr){
        S->firstFilm = F;
    }else{
        adrFilm temp = S->firstFilm;
        while (temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = F;
    }
}

void adminInsertFirstFilm(ListSutradara &L){
    string idS, idF, judul, tahunStr;
    int tahun;
    cout << "\n+=============================================+";
    cout << "\n|      INSERT FIRST FILM (ADMIN)              |";
    cout << "\n+=============================================+\n";
    cout << "|\n";
    cout << "| ID Sutradara: ";
    cin >> idS;
    adrSutradara S = findSutradara(L, idS);
    if(S == nullptr){
        cout << "|\n";
        cout << "| [!] Sutradara tidak ditemukan!\n";
        cout << "|\n";
        cout << "+=============================================+\n";
        return;
    }
    cout << "| ID Film: ";
    cin >> idF;
    adrSutradara temp = L.first;
    bool idSudahAda = false;
    while(temp != nullptr){
        if(findFilm(temp, idF) != nullptr){
            idSudahAda = true;
            break;
        }
        temp = temp->next;
    }
    if(idSudahAda){
        cout << "|\n";
        cout << "| [!] Error: ID Film sudah digunakan!\n";
        cout << "| Gunakan ID yang berbeda.\n";
        cout << "|\n";
        cout << "+=============================================+\n";
        return;
    }
    cin.ignore();
    cout << "| Judul Film: ";
    getline(cin, judul);
    cout << "| Tahun: ";
    cin >> tahunStr;
    bool valid = true;
    for(int i = 0; i < tahunStr.length(); i++){
        if(!isdigit(tahunStr[i])){
            valid = false;
            break;
        }
    }
    if(!valid){
        cout << "|\n";
        cout << "| [!] Error: Tahun harus berupa angka!\n";
        cout << "|\n";
        cout << "+=============================================+\n";
        return;
    }
    tahun = stoi(tahunStr);
    adrFilm F = buatFilmNode(idF, judul, tahun);
    F->next = S->firstFilm;
    S->firstFilm = F;
    cout << "|\n";
    cout << "+=============================================+\n";
    cout << "| [BERHASIL] Film berhasil ditambahkan\n";
    cout << "|            di awal!\n";
    cout << "+=============================================+\n";
}

void adminInsertLastFilm(ListSutradara &L){
    string idS, idF, judul, tahunStr;
    int tahun;
    cout << "\n+=============================================+";
    cout << "\n|       INSERT LAST FILM (ADMIN)              |";
    cout << "\n+=============================================+\n";
    cout << "|\n";
    cout << "| ID Sutradara: ";
    cin >> idS;
    adrSutradara S = findSutradara(L, idS);
    if(S == nullptr){
        cout << "|\n";
        cout << "| [!] Sutradara tidak ditemukan!\n";
        cout << "|\n";
        cout << "+=============================================+\n";
        return;
    }
    cout << "| ID Film: ";
    cin >> idF;
    adrSutradara temp = L.first;
    bool idSudahAda = false;
    while(temp != nullptr){
        if(findFilm(temp, idF) != nullptr){
            idSudahAda = true;
            break;
        }
        temp = temp->next;
    }
    if(idSudahAda){
        cout << "|\n";
        cout << "| [!] Error: ID Film sudah digunakan!\n";
        cout << "| Gunakan ID yang berbeda.\n";
        cout << "|\n";
        cout << "+=============================================+\n";
        return;
    }
    cin.ignore();
    cout << "| Judul Film: ";
    getline(cin, judul);
    cout << "| Tahun: ";
    cin >> tahunStr;
    bool valid = true;
    for(int i = 0; i < tahunStr.length(); i++){
        if(!isdigit(tahunStr[i])){
            valid = false;
            break;
        }
    }
    if(!valid){
        cout << "|\n";
        cout << "| [!] Error: Tahun harus berupa angka!\n";
        cout << "|\n";
        cout << "+=============================================+\n";
        return;
    }
    tahun = stoi(tahunStr);
    adrFilm F = buatFilmNode(idF, judul, tahun);
    insertLastFilm(S, F);
    cout << "|\n";
    cout << "+=============================================+\n";
    cout << "| [BERHASIL] Film berhasil ditambahkan\n";
    cout << "|            di akhir!\n";
    cout << "+=============================================+\n";
}

void adminInsertAfterFilm(ListSutradara &L){
    string idS, idPatokan, idF, judul, tahunStr;
    int tahun;
    cout << "\n+=============================================+";
    cout << "\n|      INSERT AFTER FILM (ADMIN)              |";
    cout << "\n+=============================================+\n";
    cout << "|\n";
    cout << "| ID Sutradara: ";
    cin >> idS;
    adrSutradara S = findSutradara(L, idS);
    if(S == nullptr){
        cout << "|\n";
        cout << "| [!] Sutradara tidak ditemukan!\n";
        cout << "|\n";
        cout << "+=============================================+\n";
        return;
    }
    cout << "| ID Film Patokan: ";
    cin >> idPatokan;
    adrFilm Prec = findFilm(S, idPatokan);
    if(Prec == nullptr){
        cout << "|\n";
        cout << "| [!] Film patokan tidak ditemukan!\n";
        cout << "|\n";
        cout << "+=============================================+\n";
        return;
    }
    cout << "| ID Film Baru: ";
    cin >> idF;
    adrSutradara temp = L.first;
    bool idSudahAda = false;
    while(temp != nullptr){
        if(findFilm(temp, idF) != nullptr){
            idSudahAda = true;
            break;
        }
        temp = temp->next;
    }
    if(idSudahAda){
        cout << "|\n";
        cout << "| [!] Error: ID Film sudah digunakan!\n";
        cout << "| Gunakan ID yang berbeda.\n";
        cout << "|\n";
        cout << "+=============================================+\n";
        return;
    }
    cin.ignore();
    cout << "| Judul Film: ";
    getline(cin, judul);
    cout << "| Tahun: ";
    cin >> tahunStr;
    bool valid = true;
    for(int i = 0; i < tahunStr.length(); i++){
        if(!isdigit(tahunStr[i])){
            valid = false;
            break;
        }
    }
    if(!valid){
        cout << "|\n";
        cout << "| [!] Error: Tahun harus berupa angka!\n";
        cout << "|\n";
        cout << "+=============================================+\n";
        return;
    }
    tahun = stoi(tahunStr);
    adrFilm F = buatFilmNode(idF, judul, tahun);
    F->next = Prec->next;
    Prec->next = F;
    cout << "|\n";
    cout << "+=============================================+\n";
    cout << "| [BERHASIL] Film berhasil ditambahkan\n";
    cout << "|            setelah " << idPatokan << "!\n";
    cout << "+=============================================+\n";
}
