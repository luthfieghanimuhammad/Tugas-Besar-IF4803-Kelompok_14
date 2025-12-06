#include <iostream>
#include <string>
#include "Film.h"
#include "Sutradara.h"
using namespace std;

adrFilm buatFilmNode(string id, string judul, int tahun) {
    adrFilm F = new Film;
    F->id = id;
    F->judul = judul;
    F->tahun = tahun;
    F->next = nullptr;
    return F;
}

void insertLastFilm(adrSutradara S, adrFilm F) {
    if (S == nullptr) return;
    if (S->firstFilm == nullptr) {
        S->firstFilm = F;
    } else {
        adrFilm temp = S->firstFilm;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = F;
    }
}

void adminInsertFirstFilm(ListSutradara &L) {
    string idS, idF, judul;
    int tahun;
    cout << "ID Sutradara: ";
    cin >> idS;
    adrSutradara S = findSutradara(L, idS);
    if (S == nullptr) {
        cout << "Sutradara tidak ditemukan!\n";
        return;
    }
    cout << "ID Film: ";
    cin >> idF;
    cin.ignore();
    cout << "Judul Film: ";
    getline(cin, judul);
    cout << "Tahun: ";
    cin >> tahun;
    adrFilm F = buatFilmNode(idF, judul, tahun);
    F->next = S->firstFilm;
    S->firstFilm = F;
    cout << "Film berhasil ditambahkan!\n";
}

void adminInsertLastFilm(ListSutradara &L) {
    string idS, idF, judul;
    int tahun;
    cout << "ID Sutradara: ";
    cin >> idS;
    adrSutradara S = findSutradara(L, idS);
    if (S == nullptr) {
        cout << "Sutradara tidak ditemukan!\n";
        return;
    }
    cout << "ID Film: ";
    cin >> idF;
    cin.ignore();
    cout << "Judul Film: ";
    getline(cin, judul);
    cout << "Tahun: ";
    cin >> tahun;
    adrFilm F = buatFilmNode(idF, judul, tahun);
    insertLastFilm(S, F);
    cout << "Film berhasil ditambahkan!\n";
}

void adminInsertAfterFilm(ListSutradara &L) {
    string idS, idPatokan, idF, judul;
    int tahun;
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
    if (Prec == nullptr) {
        cout << "Film patokan tidak ditemukan!\n";
        return;
    }
    cout << "ID Film Baru: ";
    cin >> idF;
    cin.ignore();
    cout << "Judul Film: ";
    getline(cin, judul);
    cout << "Tahun: ";
    cin >> tahun;
    adrFilm F = buatFilmNode(idF, judul, tahun);
    F->next = Prec->next;
    Prec->next = F;
    cout << "Film berhasil ditambahkan!\n";
}
