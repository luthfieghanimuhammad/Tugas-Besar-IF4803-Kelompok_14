#include <iostream>
#include <string>
#include "Sutradara.h"
#include "Film.h"
using namespace std;

void adminUbahFilm(ListSutradara &L) {
    string id;
    cout << "\n=== UBAH DATA FILM ===\n";
    cout << "Masukkan ID Film: ";
    cin >> id;
    adrSutradara S = L.first;
    while (S != nullptr) {
        adrFilm F = S->firstFilm;
        while (F != nullptr) {
            if (F->id == id) {
                cin.ignore();
                cout << "Judul Baru  : ";
                getline(cin, F->judul);
                cout << "Tahun Baru  : ";
                cin >> F->tahun;

                cout << "\n[SUKSES] Data film berhasil diperbarui.\n";
                return;
            }
            F = F->next;
        }
        S = S->next;
    }
    cout << "\n[GAGAL] Film dengan ID yang ditentukan tidak ditemukan.\n";
}

void adminTampilSemuaFilm(ListSutradara L) {
    cout << "\n=== DAFTAR SELURUH FILM ===\n";
    adrSutradara S = L.first;
    while (S != nullptr) {
        cout << "\nSutradara: " << S->nama << endl;
        adrFilm F = S->firstFilm;
        if (F == nullptr)
            cout << "  Tidak terdapat data film.\n";
        while (F != nullptr) {
            cout << "  [" << F->id << "] " << F->judul
                 << " (" << F->tahun << ")\n";
            F = F->next;
        }
        S = S->next;
    }
}

void userCariFilmByJudul(ListSutradara L) {
    string judul;
    cin.ignore();
    cout << "\n=== PENCARIAN FILM BERDASARKAN JUDUL ===\n";
    cout << "Masukkan Judul Film: ";
    getline(cin, judul);
    bool ditemukan = false;
    adrSutradara S = L.first;
    while (S != nullptr) {
        adrFilm F = S->firstFilm;
        while (F != nullptr) {
            if (F->judul == judul) {
                cout << "\n[SUKSES] Film ditemukan\n";
                cout << "ID        : " << F->id << endl;
                cout << "Judul     : " << F->judul << endl;
                cout << "Tahun     : " << F->tahun << endl;
                cout << "Sutradara : " << S->nama << endl;
                ditemukan = true;
            }
            F = F->next;
        }
        S = S->next;
    }
    if (!ditemukan)
        cout << "\n[GAGAL] Film dengan judul yang dimasukkan tidak ditemukan.\n";
}

void userTampilSemuaFilmUnik(ListSutradara L) {
    string daftar[3000];
    int jumlah[3000];
    int n = 0;
    adrSutradara S = L.first;
    while (S != nullptr) {
        adrFilm F = S->firstFilm;
        while (F != nullptr) {
            bool ada = false;
            for (int i = 0; i < n; i++) {
                if (daftar[i] == F->judul) {
                    jumlah[i]++;
                    ada = true;
                }
            }
            if (!ada) {
                daftar[n] = F->judul;
                jumlah[n] = 1;
                n++;
            }
            F = F->next;
        }
        S = S->next;
    }
    cout << "\n=== DAFTAR FILM YANG TIDAK DUPLIKAT ===\n";
    for (int i = 0; i < n; i++)
        if (jumlah[i] == 1)
            cout << daftar[i] << endl;
    cout << "\n=== DAFTAR FILM YANG DUPLIKAT ===\n";
    for (int i = 0; i < n; i++)
        if (jumlah[i] > 1)
            cout << daftar[i] << " (" << jumlah[i] << " kali)\n";
}

void userHitungTotalFilm(ListSutradara L) {
    int total = 0;
    adrSutradara S = L.first;
    while (S != nullptr) {
        adrFilm F = S->firstFilm;
        while (F != nullptr) {
            total++;
            F = F->next;
        }
        S = S->next;
    }
    cout << "\n=== TOTAL SELURUH FILM ===\n";
    cout << "Jumlah Film: " << total << endl;
}

void userUrutkanFilmPerSutradara(ListSutradara &L) {
    string id;
    cout << "\n=== PENGURUTAN FILM ===\n";
    cout << "Masukkan ID Sutradara: ";
    cin >> id;
    adrSutradara S = cariSutradaraById(L, id);
    if (S == nullptr) {
        cout << "\n[GAGAL] Sutradara dengan ID yang dimasukkan tidak ditemukan.\n";
        return;
    }
    adrFilm sorted = nullptr;
    while (S->firstFilm != nullptr) {
        adrFilm cur = S->firstFilm;
        S->firstFilm = S->firstFilm->next;
        cur->next = nullptr;
        if (sorted == nullptr || cur->judul < sorted->judul) {
            cur->next = sorted;
            sorted = cur;
        } else {
            adrFilm P = sorted;
            while (P->next != nullptr && P->next->judul < cur->judul)
                P = P->next;
            cur->next = P->next;
            P->next = cur;
        }
    }
    S->firstFilm = sorted;
    cout << "\n[SUKSES] Film berhasil diurutkan berdasarkan judul.\n";
}

void userLihatDetailFilm(ListSutradara L) {
    string id;
    cout << "\n=== DETAIL INFORMASI FILM ===\n";
    cout << "Masukkan ID Film: ";
    cin >> id;
    adrSutradara S = L.first;
    while (S != nullptr) {
        adrFilm F = S->firstFilm;
        while (F != nullptr) {
            if (F->id == id) {
                cout << "\n[SUKSES] Film ditemukan\n";
                cout << "Judul     : " << F->judul << endl;
                cout << "Tahun     : " << F->tahun << endl;
                cout << "Sutradara : " << S->nama << endl;
                return;
            }
            F = F->next;
        }
        S = S->next;
    }
    cout << "\n[GAGAL] Film dengan ID yang dimasukkan tidak ditemukan.\n";
}
