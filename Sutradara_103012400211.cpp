#include <iostream>
#include "Sutradara.h"
#include "Film.h"
using namespace std;

void deleteAfterSutradara(ListSutradara &L, string idYangDitentukan) {
    adrSutradara P = cariSutradaraById(L, idYangDitentukan);
    if (P == nullptr || P->next == nullptr) {
        cout << "[GAGAL] Tidak terdapat data setelah ID yang ditentukan atau ID tidak ditemukan.\n";
        return;
    }
    adrSutradara Q = P->next;
    P->next = Q->next;
    if (Q->next != nullptr)
        Q->next->prev = P;
    else
        L.last = P;
    hapusSemuaFilm(Q);
    delete Q;
    cout << "[SUKSES] Sutradara setelah ID yang ditentukan berhasil dihapus.\n";
}

void adminUbahSutradara(ListSutradara &L) {
    string id, namaBaru;
    cout << "\n=== UBAH DATA SUTRADARA ===\n";
    cout << "Masukkan ID Sutradara : ";
    cin >> id;
    adrSutradara S = cariSutradaraById(L, id);
    if (S == nullptr) {
        cout << "[GAGAL] ID Sutradara tidak ditemukan.\n";
        return;
    }
    cout << "Nama Baru : ";
    cin >> namaBaru;
    S->nama = namaBaru;
    cout << "[SUKSES] Data sutradara berhasil diperbarui.\n";
}

void adminTampilSemuaSutradara(ListSutradara L) {
    cout << "\n=== DAFTAR SUTRADARA ===\n";
    adrSutradara S = L.first;
    if (S == nullptr) {
        cout << "[INFO] Belum ada data sutradara.\n";
        return;
    }
    while (S != nullptr) {
        cout << "ID: " << S->id << " | Nama: " << S->nama << endl;
        S = S->next;
    }
}

void userCariSutradaraByNama(ListSutradara L) {
    string nama;
    cout << "\n=== CARI SUTRADARA BERDASARKAN NAMA ===\n";
    cout << "Masukkan Nama : ";
    cin >> nama;
    adrSutradara S = L.first;
    bool ditemukan = false;
    while (S != nullptr) {
        if (S->nama == nama) {
            cout << "[DITEMUKAN] ID: " << S->id << " | Nama: " << S->nama << endl;
            ditemukan = true;
        }
        S = S->next;
    }
    if (!ditemukan)
        cout << "[GAGAL] Sutradara dengan nama tersebut tidak ditemukan.\n";
}

void userCariSutradaraById(ListSutradara L) {
    string id;
    cout << "\n=== CARI SUTRADARA BERDASARKAN ID ===\n";
    cout << "Masukkan ID : ";
    cin >> id;
    adrSutradara S = cariSutradaraById(L, id);
    if (S == nullptr)
        cout << "[GAGAL] ID Sutradara tidak ditemukan.\n";
    else
        cout << "[DITEMUKAN] ID: " << S->id << " | Nama: " << S->nama << endl;
}

void userTampilFilmPerSutradara(ListSutradara L) {
    cout << "\n=== DAFTAR FILM PER SUTRADARA ===\n";
    adrSutradara S = L.first;
    if (S == nullptr) {
        cout << "[INFO] Tidak terdapat data sutradara.\n";
        return;
    }

    while (S != nullptr) {
        cout << "\nSutradara : " << S->nama << endl;
        adrFilm F = S->firstFilm;
        if (F == nullptr)
            cout << "  (Tidak memiliki film)\n";
        while (F != nullptr) {
            cout << "  ID: " << F->id
                 << " | Judul: " << F->judul
                 << " | Tahun: " << F->tahun << endl;
            F = F->next;
        }
        S = S->next;
    }
}

void userSutradaraTerbanyakFilm(ListSutradara L) {
    cout << "\n=== SUTRADARA DENGAN TOTAL FILM TERBANYAK ===\n";
    adrSutradara S = L.first;
    int maxFilm = -1;
    while (S != nullptr) {
        int count = 0;
        adrFilm F = S->firstFilm;
        while (F != nullptr) {
            count++;
            F = F->next;
        }
        if (count > maxFilm)
            maxFilm = count;
        S = S->next;
    }
    if (maxFilm < 0) {
        cout << "[INFO] Tidak ada data sutradara.\n";
        return;
    }
    S = L.first;
    while (S != nullptr) {
        int count = 0;
        adrFilm F = S->firstFilm;
        while (F != nullptr) {
            count++;
            F = F->next;
        }
        if (count == maxFilm)
            cout << "ID: " << S->id << " | Nama: " << S->nama << " (" << maxFilm << " film)\n";
        S = S->next;
    }
}











