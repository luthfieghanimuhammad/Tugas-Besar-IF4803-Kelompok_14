#include <iostream>
#include <string>
#include "Sutradara.h"
#include "Film.h"
using namespace std;

adrFilm findFilm(adrSutradara S, string idFilm){
    if(S == nullptr) return nullptr;
    adrFilm F = S->firstFilm;
    while (F != nullptr){
        if (F->id == idFilm){
            return F;
        }
        F = F->next;
    }
    return nullptr;
}

void adminDeleteFirstFilm(ListSutradara &L){
    string idS;
    cout << "ID Sutradara: ";
    cin >> idS;
    adrSutradara S = findSutradara(L, idS);
    if(S == nullptr){
        cout << "Sutradara tidak ditemukan!\n";
        return;
    }
    if (S->firstFilm == nullptr){
        cout << "Tidak ada film untuk dihapus!\n";
        return;
    }
    adrFilm temp = S->firstFilm;
    S->firstFilm = temp->next;
    delete temp;
    cout << "Film pertama berhasil dihapus!\n";
}

void adminDeleteLastFilm(ListSutradara &L){
    string idS;
    cout << "ID Sutradara: ";
    cin >> idS;
    adrSutradara S = findSutradara(L, idS);
    if(S == nullptr){
        cout << "Sutradara tidak ditemukan!\n";
        return;
    }
    if(S->firstFilm == nullptr){
        cout << "Tidak ada film untuk dihapus!\n";
        return;
    }
    if(S->firstFilm->next == nullptr){
        delete S->firstFilm;
        S->firstFilm = nullptr;
    }else{
        adrFilm temp = S->firstFilm;
        while (temp->next->next != nullptr){
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }
    cout << "Film terakhir berhasil dihapus!\n";
}

void adminDeleteAfterFilm(ListSutradara &L){
    string idS, idPatokan;
    cout << "ID Sutradara: ";
    cin >> idS;
    adrSutradara S = findSutradara(L, idS);
    if(S == nullptr){
        cout << "Sutradara tidak ditemukan!\n";
        return;
    }
    cout << "ID Film Patokan: ";
    cin >> idPatokan;
    adrFilm Prec = findFilm(S, idPatokan);
    if(Prec == nullptr || Prec->next == nullptr){
        cout << "Film patokan tidak ditemukan atau tidak ada film setelahnya!\n";
        return;
    }
    adrFilm temp = Prec->next;
    Prec->next = temp->next;
    delete temp;
    cout << "Film berhasil dihapus!\n";
}

void adminTampilSemuaFilm(ListSutradara L){
    cout << "\n+=============================================+";
    cout << "\n|             DATA SEMUA FILM                 |";
    cout << "\n+=============================================+\n";
    if(L.first == nullptr){
        cout << "| Belum ada data sutradara dan film.          |\n";
        cout << "+=============================================+\n";
        return;
    }
    adrSutradara S = L.first;
    bool adaFilm = false;
    while(S != nullptr){
        cout << "\n+---------------------------------------------+\n";
        cout << "| Sutradara: " << S->nama << " (ID: " << S->id << ")\n";
        adrFilm F = S->firstFilm;
        if(F == nullptr){
            cout << "|   Tidak ada film.\n";
        } else {
            int nomor = 1;
            while(F != nullptr){
                cout << "|   " << nomor << ". " << F->judul
                     << " (" << F->tahun << ") - ID: " << F->id << "\n";
                F = F->next;
                nomor++;
                adaFilm = true;
            }
        }
        cout << "+---------------------------------------------+\n";
        S = S->next;
    }
    if(!adaFilm){
        cout << "\n| Belum ada film yang terdaftar.              |\n";
        cout << "+=============================================+\n";
    }
}
