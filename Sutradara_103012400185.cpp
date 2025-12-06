#include <iostream>
#include <string>
#include "Sutradara.h"
#include "Film.h"
using namespace std;

void buatList(ListSutradara &L) {
    L.first = nullptr;
    L.last = nullptr;
    cout << "[INFO] List sutradara berhasil diinisialisasi.\n";
}

adrSutradara buatSutradaraNode(string id, string nama) {
    adrSutradara S = new Sutradara;
    S->id = id;
    S->nama = nama;
    S->firstFilm = nullptr;
    S->next = nullptr;
    S->prev = nullptr;
    return S;
}

adrSutradara cariSutradaraById(ListSutradara L, string id) {
    adrSutradara S = L.first;
    while (S != nullptr) {
        if (S->id == id)
            return S;
        S = S->next;
    }
    return nullptr;
}

void hapusSemuaFilm(adrSutradara S) {
    adrFilm F = S->firstFilm;
    while (F != nullptr) {
        adrFilm temp = F;
        F = F->next;
        delete temp;
    }
    S->firstFilm = nullptr;
}

void insertFirstSutradara(ListSutradara &L, adrSutradara S) {
    if (L.first == nullptr) {
        L.first = S;
        L.last = S;
    } else {
        S->next = L.first;
        L.first->prev = S;
        L.first = S;
    }
    cout << "[SUKSES] Sutradara berhasil ditambahkan di posisi awal.\n";
}

void insertLastSutradara(ListSutradara &L, adrSutradara S) {
    if (L.first == nullptr) {
        L.first = S;
        L.last = S;
    } else {
        L.last->next = S;
        S->prev = L.last;
        L.last = S;
    }
    cout << "[SUKSES] Sutradara berhasil ditambahkan di posisi akhir.\n";
}

void insertAfterSutradara(ListSutradara &L, string idYangDitentukan, adrSutradara S) {
    adrSutradara P = cariSutradaraById(L, idYangDitentukan);
    if (P == nullptr) {
        cout << "[GAGAL] ID sutradara yang ditentukan tidak ditemukan. Penambahan dibatalkan.\n";
        return;
    }
    S->next = P->next;
    S->prev = P;
    if (P->next != nullptr)
        P->next->prev = S;
    else
        L.last = S;
    P->next = S;
    cout << "[SUKSES] Sutradara berhasil ditambahkan setelah ID yang ditentukan.\n";
}

void deleteFirstSutradara(ListSutradara &L) {
    if (L.first == nullptr) {
        cout << "[GAGAL] Tidak terdapat data sutradara untuk dihapus.\n";
        return;
    }
    adrSutradara P = L.first;
    if (L.first == L.last) {
        L.first = nullptr;
        L.last = nullptr;
    } else {
        L.first = P->next;
        L.first->prev = nullptr;
    }
    hapusSemuaFilm(P);
    delete P;
    cout << "[SUKSES] Sutradara pada posisi awal berhasil dihapus.\n";
}

void deleteLastSutradara(ListSutradara &L) {
    if (L.first == nullptr) {
        cout << "[GAGAL] Tidak terdapat data sutradara untuk dihapus.\n";
        return;
    }
    adrSutradara P = L.last;
    if (L.first == L.last) {
        L.first = nullptr;
        L.last = nullptr;
    } else {
        L.last = P->prev;
        L.last->next = nullptr;
    }
    hapusSemuaFilm(P);
    delete P;
    cout << "[SUKSES] Sutradara pada posisi akhir berhasil dihapus.\n";
}


