#include <iostream>
#include <string>
#include "Sutradara.h"
#include "Film.h"
using namespace std;

void buatList(ListSutradara &L){
    L.first = nullptr;
    L.last = nullptr;
}

adrSutradara buatSutradaraNode(string id, string nama, int umur){
    adrSutradara S = new Sutradara;
    S->id = id;
    S->nama = nama;
    S->umur = umur;
    S->firstFilm = nullptr;
    S->next = nullptr;
    S->prev = nullptr;
    return S;
}

adrSutradara cariSutradaraById(ListSutradara L, string id){
    adrSutradara P = L.first;
    while(P != nullptr){
        if(P->id == id){
            return P;
        }
        P = P->next;
    }
    return nullptr;
}

void insertFirstSutradara(ListSutradara &L, adrSutradara S){
    if(L.first == nullptr){
        L.first = S;
        L.last = S;
    }else{
        S->next = L.first;
        L.first->prev = S;
        L.first = S;
    }
}

void insertLastSutradara(ListSutradara &L, adrSutradara S){
    if(L.first == nullptr){
        L.first = S;
        L.last = S;
    }else{
        L.last->next = S;
        S->prev = L.last;
        L.last = S;
    }
}

void adminInsertFirstSutradara(ListSutradara &L){
    string id, nama, umurStr;
    int umur;
    cout << "\n+=============================================+";
    cout << "\n|    INSERT FIRST SUTRADARA (ADMIN)           |";
    cout << "\n+=============================================+\n";
    cout << "|\n";
    cout << "| ID Sutradara: ";
    cin >> id;
    if(cariSutradaraById(L, id) != nullptr){
        cout << "|\n";
        cout << "| [!] Error: ID Sutradara sudah digunakan!\n";
        cout << "| Gunakan ID yang berbeda.\n";
        cout << "|\n";
        cout << "+=============================================+\n";
        return;
    }
    cin.ignore();
    cout << "| Nama Sutradara: ";
    getline(cin, nama);
    cout << "| Umur: ";
    cin >> umurStr;
    bool valid = true;
    for(int i = 0; i < umurStr.length(); i++){
        if(!isdigit(umurStr[i])){
            valid = false;
            break;
        }
    }
    if(!valid){
        cout << "|\n";
        cout << "| [!] Error: Umur harus berupa angka!\n";
        cout << "|\n";
        cout << "+=============================================+\n";
        return;
    }
    umur = stoi(umurStr);
    if(umur < 0 || umur > 150){
        cout << "|\n";
        cout << "| [!] Error: Umur tidak valid!\n";
        cout << "| Harus antara 0-150.\n";
        cout << "|\n";
        cout << "+=============================================+\n";
        return;
    }
    adrSutradara S = buatSutradaraNode(id, nama, umur);
    insertFirstSutradara(L, S);
    cout << "|\n";
    cout << "+=============================================+\n";
    cout << "| [BERHASIL] Sutradara berhasil ditambahkan\n";
    cout << "|            di awal!\n";
    cout << "+=============================================+\n";
}

void adminInsertLastSutradara(ListSutradara &L){
    string id, nama, umurStr;
    int umur;
    cout << "\n+=============================================+";
    cout << "\n|     INSERT LAST SUTRADARA (ADMIN)           |";
    cout << "\n+=============================================+\n";
    cout << "|\n";
    cout << "| ID Sutradara: ";
    cin >> id;
    if(cariSutradaraById(L, id) != nullptr){
        cout << "|\n";
        cout << "| [!] Error: ID Sutradara sudah digunakan!\n";
        cout << "| Gunakan ID yang berbeda.\n";
        cout << "|\n";
        cout << "+=============================================+\n";
        return;
    }
    cin.ignore();
    cout << "| Nama Sutradara: ";
    getline(cin, nama);
    cout << "| Umur: ";
    cin >> umurStr;
    bool valid = true;
    for(int i = 0; i < umurStr.length(); i++){
        if(!isdigit(umurStr[i])){
            valid = false;
            break;
        }
    }
    if(!valid){
        cout << "|\n";
        cout << "| [!] Error: Umur harus berupa angka!\n";
        cout << "|\n";
        cout << "+=============================================+\n";
        return;
    }
    umur = stoi(umurStr);
    if(umur < 0 || umur > 150){
        cout << "|\n";
        cout << "| [!] Error: Umur tidak valid!\n";
        cout << "| Harus antara 0-150.\n";
        cout << "|\n";
        cout << "+=============================================+\n";
        return;
    }
    adrSutradara S = buatSutradaraNode(id, nama, umur);
    insertLastSutradara(L, S);

    cout << "|\n";
    cout << "+=============================================+\n";
    cout << "| [BERHASIL] Sutradara berhasil ditambahkan\n";
    cout << "|            di akhir!\n";
    cout << "+=============================================+\n";
}

void adminInsertAfterSutradara(ListSutradara &L){
    string idPatokan, id, nama, umurStr;
    int umur;
    cout << "\n+=============================================+";
    cout << "\n|    INSERT AFTER SUTRADARA (ADMIN)           |";
    cout << "\n+=============================================+\n";
    cout << "|\n";
    cout << "| ID Sutradara Patokan: ";
    cin >> idPatokan;
    adrSutradara Prec = cariSutradaraById(L, idPatokan);
    if(Prec == nullptr){
        cout << "|\n";
        cout << "| [!] Sutradara patokan tidak ditemukan!\n";
        cout << "|\n";
        cout << "+=============================================+\n";
        return;
    }
    cout << "| ID Sutradara Baru: ";
    cin >> id;
    if(cariSutradaraById(L, id) != nullptr){
        cout << "|\n";
        cout << "| [!] Error: ID Sutradara sudah digunakan!\n";
        cout << "| Gunakan ID yang berbeda.\n";
        cout << "|\n";
        cout << "+=============================================+\n";
        return;
    }
    cin.ignore();
    cout << "| Nama Sutradara: ";
    getline(cin, nama);
    cout << "| Umur: ";
    cin >> umurStr;
    bool valid = true;
    for(int i = 0; i < umurStr.length(); i++){
        if(!isdigit(umurStr[i])){
            valid = false;
            break;
        }
    }
    if(!valid){
        cout << "|\n";
        cout << "| [!] Error: Umur harus berupa angka!\n";
        cout << "|\n";
        cout << "+=============================================+\n";
        return;
    }
    umur = stoi(umurStr);
    if(umur < 0 || umur > 150){
        cout << "|\n";
        cout << "| [!] Error: Umur tidak valid!\n";
        cout << "| Harus antara 0-150.\n";
        cout << "|\n";
        cout << "+=============================================+\n";
        return;
    }
    adrSutradara S = buatSutradaraNode(id, nama, umur);
    insertAfterSutradara(L, idPatokan, S);
    cout << "|\n";
    cout << "+=============================================+\n";
    cout << "| [BERHASIL] Sutradara berhasil ditambahkan\n";
    cout << "|            setelah " << idPatokan << "!\n";
    cout << "+=============================================+\n";
}
