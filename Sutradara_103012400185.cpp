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
    string id, nama;
    int umur;
    cout << "ID Sutradara: ";
    cin >> id;
    cin.ignore();
    cout << "Nama Sutradara: ";
    getline(cin, nama);
    cout << "Umur: ";
    cin >> umur;
    adrSutradara S = buatSutradaraNode(id, nama, umur);
    insertFirstSutradara(L, S);
    cout << "Sutradara berhasil ditambahkan di awal!\n";
}

void adminInsertLastSutradara(ListSutradara &L){
    string id, nama;
    int umur;
    cout << "ID Sutradara: ";
    cin >> id;
    cin.ignore();
    cout << "Nama Sutradara: ";
    getline(cin, nama);
    cout << "Umur: ";
    cin >> umur;
    adrSutradara S = buatSutradaraNode(id, nama, umur);
    insertLastSutradara(L, S);
    cout << "Sutradara berhasil ditambahkan di akhir!\n";
}

void adminInsertAfterSutradara(ListSutradara &L){
    string idPatokan, id, nama;
    int umur;
    cout << "ID Sutradara Patokan: ";
    cin >> idPatokan;
    adrSutradara Prec = cariSutradaraById(L, idPatokan);
    if(Prec == nullptr){
        cout << "Sutradara patokan tidak ditemukan!\n";
        return;
    }
    cout << "ID Sutradara Baru: ";
    cin >> id;
    cin.ignore();
    cout << "Nama Sutradara: ";
    getline(cin, nama);
    cout << "Umur: ";
    cin >> umur;
    adrSutradara S = buatSutradaraNode(id, nama, umur);
    insertAfterSutradara(L, idPatokan, S);
    cout << "Sutradara berhasil ditambahkan setelah " << idPatokan << "!\n";
}
