#include <iostream>
#include <string>
#include "Sutradara.h"
#include "Film.h"
using namespace std;

adrFilm findFilm(adrSutradara S, string idFilm) {
    if (S == nullptr) return nullptr;
    adrFilm F = S->firstFilm;
    while (F != nullptr) {
        if (F->id == idFilm) {
            return F;
        }
        F = F->next;
    }
    return nullptr;
}

void adminDeleteFirstFilm(ListSutradara &L) {
    string idS;
    cout << "ID Sutradara: ";
    cin >> idS;
    adrSutradara S = findSutradara(L, idS);
    if (S == nullptr) {
        cout << "Sutradara tidak ditemukan!\n";
        return;
    }
    if (S->firstFilm == nullptr) {
        cout << "Tidak ada film untuk dihapus!\n";
        return;
    }
    adrFilm temp = S->firstFilm;
    S->firstFilm = temp->next;
    delete temp;
    cout << "Film pertama berhasil dihapus!\n";
}

void adminDeleteLastFilm(ListSutradara &L) {
    string idS;
    cout << "ID Sutradara: ";
    cin >> idS;
    adrSutradara S = findSutradara(L, idS);
    if (S == nullptr) {
        cout << "Sutradara tidak ditemukan!\n";
        return;
    }
    if (S->firstFilm == nullptr) {
        cout << "Tidak ada film untuk dihapus!\n";
        return;
    }
    if (S->firstFilm->next == nullptr) {
        delete S->firstFilm;
        S->firstFilm = nullptr;
    } else {
        adrFilm temp = S->firstFilm;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }
    cout << "Film terakhir berhasil dihapus!\n";
}

void adminDeleteAfterFilm(ListSutradara &L) {
    string idS, idPatokan;
    cout << "ID Sutradara: ";
    cin >> idS;
    adrSutradara S = findSutradara(L, idS);
    if (S == nullptr) {
        cout << "Sutradara tidak ditemukan!\n";
        return;
    }
    cout << "ID Film Patokan: ";
    cin >> idPatokan;
    adrFilm Prec = findFilm(S, idPatokan);
    if (Prec == nullptr || Prec->next == nullptr) {
        cout << "Film patokan tidak ditemukan atau tidak ada film setelahnya!\n";
        return;
    }
    adrFilm temp = Prec->next;
    Prec->next = temp->next;
    delete temp;
    cout << "Film berhasil dihapus!\n";
}

void adminTampilSemuaFilm(ListSutradara L) {
    adrSutradara S = L.first;
    cout << "\n===== DATA SEMUA FILM =====\n";
    while (S != nullptr) {
        cout << "\nSutradara: " << S->nama << " (ID: " << S->id << ")\n";
        adrFilm F = S->firstFilm;
        if (F == nullptr) {
            cout << "  Tidak ada film.\n";
        } else {
            while (F != nullptr) {
                cout << "  - ID: " << F->id << " | Judul: " << F->judul
                     << " | Tahun: " << F->tahun << endl;
                F = F->next;
            }
        }
        S = S->next;
    }
}
