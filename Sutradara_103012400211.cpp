#include <iostream>
#include <string>
#include "Sutradara.h"
#include "Film.h"
using namespace std;

void insertAfterSutradara(ListSutradara &L, string idPatokan, adrSutradara S){
    adrSutradara P = cariSutradaraById(L, idPatokan);
    if(P != nullptr){
        S->next = P->next;
        S->prev = P;
        if(P->next != nullptr){
            P->next->prev = S;
        }else{
            L.last = S;
        }
        P->next = S;
    }
}

void deleteFirstSutradara(ListSutradara &L){
    if(L.first != nullptr){
        adrSutradara P = L.first;
        if(L.first == L.last){
            L.first = nullptr;
            L.last = nullptr;
        }else{
            L.first = L.first->next;
            L.first->prev = nullptr;
        }
        delete P;
    }
}

void deleteLastSutradara(ListSutradara &L){
    if(L.last != nullptr){
        adrSutradara P = L.last;
        if(L.first == L.last){
            L.first = nullptr;
            L.last = nullptr;
        }else{
            L.last = L.last->prev;
            L.last->next = nullptr;
        }
        delete P;
    }
}

void deleteAfterSutradara(ListSutradara &L, string idPatokan){
    adrSutradara P = cariSutradaraById(L, idPatokan);
    if(P != nullptr && P->next != nullptr){
        adrSutradara Q = P->next;
        P->next = Q->next;
        if(Q->next != nullptr){
            Q->next->prev = P;
        }else{
            L.last = P;
        }
        delete Q;
    }
}

void adminTampilSemuaSutradara(ListSutradara L){
    cout << "\n===== DATA SUTRADARA =====\n";
    if(L.first == nullptr){
        cout << "Belum ada data sutradara.\n";
        cout << "==========================\n";
        return;
    }
    adrSutradara P = L.first;
    int nomor = 1;
    while(P != nullptr){
        cout << nomor << ". ID: " << P->id
             << " | Nama: " << P->nama
             << " | Umur: " << P->umur << endl;
        P = P->next;
        nomor++;
    }
    cout << "==========================\n";
}

adrSutradara findSutradara(ListSutradara L, string id){
    adrSutradara P = L.first;
    while(P != nullptr){
        if(P->id == id){
            return P;
        }
        P = P->next;
    }
    return nullptr;
}

void adminDeleteFirstSutradara(ListSutradara &L){
    if(L.first == nullptr){
        cout << "List kosong!\n";
        return;
    }
    deleteFirstSutradara(L);
    cout << "Sutradara pertama berhasil dihapus!\n";
}

void adminDeleteLastSutradara(ListSutradara &L){
    if(L.first == nullptr){
        cout << "List kosong!\n";
        return;
    }
    deleteLastSutradara(L);
    cout << "Sutradara terakhir berhasil dihapus!\n";
}

void adminDeleteAfterSutradara(ListSutradara &L){
    string idPatokan;
    cout << "ID Sutradara Patokan: ";
    cin >> idPatokan;
    adrSutradara P = cariSutradaraById(L, idPatokan);
    if(P == nullptr){
        cout << "Sutradara patokan tidak ditemukan!\n";
        return;
    }
    if(P->next == nullptr){
        cout << "Tidak ada sutradara setelah " << idPatokan << "!\n";
        return;
    }
    deleteAfterSutradara(L, idPatokan);
    cout << "Sutradara setelah " << idPatokan << " berhasil dihapus!\n";
}
