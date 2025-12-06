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
    cout << "[SUKSES] Node film berhasil dibuat.\n";
    return F;
}

adrFilm cariFilmById(adrSutradara S, string id) {
    adrFilm F = S->firstFilm;
    while (F != nullptr) {
        if (F->id == id)
            return F;
        F = F->next;
    }
    return nullptr;
}

void insertFirstFilm(adrSutradara S, adrFilm F) {
    F->next = S->firstFilm;
    S->firstFilm = F;
    cout << "[SUKSES] Film ditambahkan di posisi awal.\n";
}

void insertLastFilm(adrSutradara S, adrFilm F) {
    if (S->firstFilm == nullptr) {
        S->firstFilm = F;
    } else {
        adrFilm P = S->firstFilm;
        while (P->next != nullptr)
            P = P->next;
        P->next = F;
    }
    cout << "[SUKSES] Film ditambahkan di posisi akhir.\n";
}

void insertAfterFilm(adrSutradara S, string idYangDitentukan, adrFilm F) {
    adrFilm P = S->firstFilm;
    while (P != nullptr && P->id != idYangDitentukan)
        P = P->next;
    if (P == nullptr) {
        cout << "[GAGAL] ID yang ditentukan tidak ditemukan. Penambahan film dibatalkan.\n";
        return;
    }
    F->next = P->next;
    P->next = F;
    cout << "[SUKSES] Film berhasil ditambahkan setelah ID yang ditentukan.\n";
}

void deleteFirstFilm(adrSutradara S) {
    if (S->firstFilm == nullptr) {
        cout << "[GAGAL] Tidak ada data film untuk dihapus.\n";
        return;
    }
    adrFilm P = S->firstFilm;
    S->firstFilm = P->next;
    delete P;
    cout << "[SUKSES] Film pada posisi awal berhasil dihapus.\n";
}

void deleteLastFilm(adrSutradara S) {
    if (S->firstFilm == nullptr) {
        cout << "[GAGAL] Tidak ada data film untuk dihapus.\n";
        return;
    }
    if (S->firstFilm->next == nullptr) {
        delete S->firstFilm;
        S->firstFilm = nullptr;
        cout << "[SUKSES] Film pada posisi akhir berhasil dihapus.\n";
        return;
    }
    adrFilm P = S->firstFilm;
    adrFilm Q = nullptr;
    while (P->next != nullptr) {
        Q = P;
        P = P->next;
    }
    Q->next = nullptr;
    delete P;
    cout << "[SUKSES] Film pada posisi akhir berhasil dihapus.\n";
}

void deleteAfterFilm(adrSutradara S, string idYangDitentukan) {
    adrFilm P = S->firstFilm;
    while (P != nullptr && P->id != idYangDitentukan)
        P = P->next;
    if (P == nullptr || P->next == nullptr) {
        cout << "[GAGAL] Tidak ada film setelah ID yang ditentukan atau ID tidak ditemukan.\n";
        return;
    }
    adrFilm Q = P->next;
    P->next = Q->next;
    delete Q;
    cout << "[SUKSES] Film setelah ID yang ditentukan berhasil dihapus.\n";
}

